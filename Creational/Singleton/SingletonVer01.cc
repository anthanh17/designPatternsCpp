#include <iostream>
#include <string>
#include <mutex>

class Database {
private:
	static Database* _instancePtr;
	int _record{};
	std::string _name{};
	static std::mutex _locker;

	Database (std::string name) {
		_name = name;
		_record = 0;
	}
public:
	void editRecord (std::string operation) {
		std::cout << "Performing a " << operation
				  << "operation on record " << _record
				  << " in database " << _name << std::endl;
	}

	std::string getName(void) const { return _name; }
	
	static Database* getInstance (std::string name) {
		_locker.lock();
		if (nullptr == _instancePtr)
			_instancePtr = new Database (name);
		_locker.unlock();
		return _instancePtr;
	}
};

Database* Database::_instancePtr {nullptr};
std::mutex Database::_locker;

int main() {

	Database* database;

	// Init Products obj
	database = Database::getInstance("Products");
	std::cout << "This is the: " << database->getName() << " database" << std::endl;
	
	// init Tesst obj => Singletance create only Products 
	database = Database::getInstance("Test");
	std::cout << "This is the: " << database->getName() << " database" << std::endl;
	return 0;
}
