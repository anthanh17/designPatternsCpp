#include <iostream>
#include <vector>
class Product {
public:
        virtual ~Product() = default;
        virtual void Operation() const = 0;
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

int main() {
        std::vector<Product*> array;
        int choice;
        while (true) {
                std::cout << "\nProdeuct01 (1) - Product02 (2) -Exit (0): ";
                std::cin >> choice;
                if (choice == 0)
                        break;
                else if (choice == 1)
                        array.push_back(new Product01);
                else if (choice == 2)
                        array.push_back(new Product02);
        }

        for (const auto &i : array){
                i->Operation();
        }
        return 0;
}