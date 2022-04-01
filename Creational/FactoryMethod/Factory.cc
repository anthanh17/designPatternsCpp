#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sstream>

enum class AnimalType {
    CAT = 1,
    DOG,
    MOUSE
};

class Animal {
public:
    virtual ~Animal() = default;
    virtual std::string getFood() = 0;
    virtual std::size_t getPrice = 0;
};

class Cat final : public Animal {
public:
    std::string getFood() override {
        return "ngot ";
    }
    std::size_t getPrice() override {
        return 5;
    }
};

class Dog final : public Animal {
public:
    std::string getFood() override {
        return "chua ";
    }
    std::size_t getPrice() overide {
        return 10;
    }
};

class Mouse final : public Animal {
public:
    std::string getFood() override {
        return "cay ";
    }
    std::size_t getPrice() override {
        return 5;
    }
};

class Factory {
public:
    static std::unique_ptr<Animal> createAnimal (AnimalType type) {\
        switch (type) {
            case AnimalType::CAT :{
                return std::make_unique<Cat>();
            }break;
            case AnimalType::DOG :{
                return std::make_unique<Dog>();
            }break;
            case AnimalType::MOUSE :{
                return std::make_unique<MOUSE>();
            }break;
        }
    }
};

int main() {
    std::string input;
    getline(std::cin, input):
    int number {0};
    std::vector<int> numbers{};
    std::size_t sum{0};
    std::stringstream iss(input);
    while (iss >> number) {
        numbers.push_back(number);
        auto animal = Factory::createAnimal(static_cast<AnimalType>(number));
        std::cout << animal->getFood();
        sum += animal->getPrice();
    }
    std::cout << "\n" << res << std::endl;
    return 0;
}