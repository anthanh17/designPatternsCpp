#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

class IObserver {
public:
	IObserver() = default;
	virtual ~IObserver() = default;

	virtual void update(std::string operation, std::string record) = 0;
};
class ISubject {
public:
	ISubject() = default;
	virtual ~ISubject() = default;

	virtual void registerObserver(std::shared_ptr<IObserver> o) = 0;  
	virtual void removeObserver(std::shared_ptr<IObserver> o) = 0; 
	virtual void notifyObserver(void) = 0; 
};

class Database final : public ISubject {
private:
	std::vector<std::shared_ptr<IObserver>> _mObserver;
	std::string _operation{};
	std::string _record{};
public:
	Database() = default;

	void registerObserver(std::shared_ptr<IObserver> o) override {
		_mObserver.push_back(o);
	}

	void removeObserver(std::shared_ptr<IObserver> o) override {
		const auto observer = std::find(_mObserver.begin(), _mObserver.end(), o);
		if(observer != _mObserver.end()) {
			_mObserver.erase(observer, observer + 1);
		}
	}

	void notifyObserver(void) override {
		for (const auto& o : _mObserver)
		{
			o->update(_operation, _record);
		}
	}

	void editRecord(std::string operation, std::string record) {
		_operation = operation;
		_record = record;
		notifyObserver();
	}
};

class Client final : public IObserver {
public:
	Client() = default;
	~Client() = default;

	void update(std::string operation, std::string record) override {
		std::cout << "\nClient - operation: <" << operation << "> record: <" << record << ">"; 
	}
};

class Developer final : public IObserver {
public:
	Developer() = default;
	~Developer() = default;

	void update(std::string operation, std::string record) override {
		std::cout << "\nDeveloper - operation: <" << operation << "> record: <" << record << ">"; 
	}
};

class Boss final : public IObserver {
public:
	Boss() = default;
	~Boss() = default;

	void update(std::string operation, std::string record) override {
		std::cout << "\nBoss - operation: <" << operation << "> record: <" << record << ">"; 
	}
};


int main() {
	const auto database = std::make_shared<Database>();

	const auto client = std::make_shared<Client>();
	const auto dev = std::make_shared<Developer>();
	const auto boss = std::make_shared<Boss>();

	database->registerObserver(client);
	database->registerObserver(dev);
	database->registerObserver(boss);

	database->editRecord("delete", "record-001");

	//remove client
	std::cout << "\n\nRemove client";
	database->removeObserver(client);
	database->editRecord("modify", "record-007");

	return 0;
}
