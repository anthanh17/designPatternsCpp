#include <iostream>
#include <vector>

class Product {
public:
    virtual ~Product() = default;
    virtual void Operation() const = 0;
    static Product *FactoryMethod(int choice);
};

class Product01 final : public Product {
public:
    void Operation() const override {
        std::cout << "Result: product01\n";
    }
};

class Product02 final : public Product {
public:
    void Operation() const override {
        std::cout << "Result: Product02\n";
    }
};

Product *Product::FactoryMethod(int choice){
    if (choice == 1)
        return new Product01;
    else if (choice == 2)
        return new Product02;
}

int main() {
    std::vector<Product*> array;
    int choice;
    while (true) {
        std::cout << "\nProdeuct01 (1) - Product02 (2) -Exit (0): ";
        std::cin >> choice;
        if (choice == 0)
            break;
        array.push_back(Product::FactoryMethod(choice));
    }

    for (const auto &i : array){
        i->Operation();
    }
    return 0;
}