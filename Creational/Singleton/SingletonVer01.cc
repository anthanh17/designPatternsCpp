#include <iostream>
#include <string>
#include <mutex>
#include <memory>

class Database {
private:
	static std::shared_ptr<Database> _instancePtr;
	int _record{};
	std::string _name{};
	static std::mutex _locker;

	Database (std::string name) {
		_name = name;
		_record = 0;
	}
	friend std::shared_ptr<Database> std::make_shared<Database>(std::string&);
public:
	void editRecord (std::string operation) {
		std::cout << "Performing a " << operation
				  << "operation on record " << _record
				  << " in database " << _name << std::endl;
	}

	std::string getName(void) const { return _name; }
	
	static std::shared_ptr<Database> getInstance (std::string name) {
	    //std::lock_guard<std::mutex> lock(_locker);
		_locker.lock();
		if (nullptr == _instancePtr)
			_instancePtr = std::make_shared<Database> (name);
		_locker.unlock();
		return _instancePtr;
	}
};

std::shared_ptr<Database> Database::_instancePtr {nullptr};
std::mutex Database::_locker;

int main() {

	std::shared_ptr<Database> database;

	// Init Products obj
	database = Database::getInstance("Products");
	std::cout << "This is the: " << database->getName() << " database" << std::endl;
	
	// init Tesst obj => Singletance create only Products 
	database = Database::getInstance("Test");
	std::cout << "This is the: " << database->getName() << " database" << std::endl;
	return 0;
}
