#include <iostream>
#include <string>
#include <memory>

class BackendAUserInterface {
public:
	virtual ~BackendAUserInterface() = default;

	virtual void setName(std::string name) = 0;
	virtual std::string getName(void) = 0;
};

class BackendBUserInterface {
public:
	virtual ~BackendBUserInterface() = default;

	virtual void setFirstName(std::string first) = 0;
	virtual void setLastName(std::string last) = 0;
	
	virtual std::string getFirstName(void) = 0;
	virtual std::string getLastName(void) = 0;
};

class UserA final : public BackendAUserInterface {
private:
	std::string _name{};
public:
	void setName(std::string name) override {
		_name = name;
	}

	std::string getName(void) override {
		return _name;
	}
};

// if not use adapter Patterns
class UserB final : public BackendBUserInterface {
private:
	std::string _firstName{};
	std::string _lastName{};
public:
	void setFirstName(std::string first) override {
		_firstName = first;
	}

	void setLastName(std::string last) override {
		_lastName = last;
	}

	std::string getFirstName(void) override {
		return _firstName;
	}

	std::string getLastName(void) override {
		return _lastName;
	}

};

// after user Adapter patterns
class UserAtoBAdapter final : public BackendBUserInterface {
private:
	UserA _userA;
	
	std::string _firstName{};
	std::string _lastName{};
public:
	UserAtoBAdapter (UserA user) {
		_userA = user;

		// split first name and last name
		unsigned int splitPostion = user.getName().find_first_of(" ");
		if(splitPostion != std::string::npos) {
			_firstName = user.getName().substr(0, splitPostion + 1);
			_lastName = user.getName().substr(splitPostion + 1, 
											  user.getName().length() - _firstName.length());
		}
	}

	void setFirstName(std::string first) override {
		_firstName = first;
	}

	void setLastName(std::string last) override {
		_lastName = last;
	}

	std::string getFirstName(void) override {
		return _firstName;
	}

	std::string getLastName(void) override {
		return _lastName;
	}

};

int main() {
	//create User A object
	UserA userA;
	userA.setName("An Nguyen The");

	//create Adapter 
	UserAtoBAdapter adapter(userA);

	std::cout << "First name: " << adapter.getFirstName() << std::endl;
	std::cout << "Last name: " << adapter.getLastName() << std::endl;

	return 0;
}
