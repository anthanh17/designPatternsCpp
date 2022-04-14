#include <iostream>
#include <string>
#include <memory>

class ElectronicProduct {
private:
	std::string _phone;
	std::string _tablet;
	std::string _screen;
	std::string _laptop;
public:
	ElectronicProduct() = default;
	~ElectronicProduct() = default;

	void setPhone (std::string phone) { _phone = phone; }
	void setTablet (std::string tablet) { _tablet = tablet; }
	void setScreen (std::string screen) { _screen = screen; }
	void setLaptop (std::string laptop) { _laptop = laptop; }

	void ShowInfor(void) {
		std::cout << "\nPhone: " << _phone;
		std::cout << "\nTablet: " << _tablet;
		std::cout << "\nScreen: " << _screen;
		std::cout << "\nLaptop: " << _laptop;
	}
};

class ShopBuilder {
public:
	ShopBuilder() = default;
	virtual ~ShopBuilder() = default;

	virtual void buildPhone() = 0;
	virtual void buildTablet() = 0;
	virtual void buildScreen() = 0;
	virtual void buildLaptop()  = 0;
	virtual std::shared_ptr<ElectronicProduct> getProduct() = 0;
};

class HanoiShop final : public ShopBuilder {
private:
	std::shared_ptr<ElectronicProduct> _eProduct;
public:
	HanoiShop() { _eProduct = std::make_shared<ElectronicProduct>(); }
	~HanoiShop() = default;

	void buildPhone() override { _eProduct->setPhone("galaxy S22 untral"); }
	void buildTablet() override { _eProduct->setTablet("galaxy tab"); }
	void buildScreen() override { _eProduct->setScreen("Toshiba LCD oled"); }
	void buildLaptop() override { _eProduct->setLaptop("MSI"); }
	std::shared_ptr<ElectronicProduct> getProduct() {
		return _eProduct;
	}
};

class HcmShop final : public ShopBuilder {
private:
	std::shared_ptr<ElectronicProduct> _eProduct;
public:
	HcmShop() { _eProduct = std::make_shared<ElectronicProduct>(); }
	~HcmShop() = default;

	void buildPhone() override { _eProduct->setPhone("Iphone 12 promax"); }
	void buildTablet() override { _eProduct->setTablet("Ipad"); }
	void buildScreen() override { _eProduct->setScreen("Samsung LCD"); }
	void buildLaptop() override { _eProduct->setLaptop("Alienware"); }
	std::shared_ptr<ElectronicProduct> getProduct() {
		return _eProduct;
	}
};

class ContractorShop {
private:
	std::shared_ptr<ShopBuilder> _shopBuilder;
public:
	ContractorShop(std::shared_ptr<ShopBuilder> houseBuilder) {
		_shopBuilder = houseBuilder;
	}
	~ContractorShop() = default;

	std::shared_ptr<ElectronicProduct> getProduct() {
		return _shopBuilder->getProduct();
	}
	void buildProduct() {
		_shopBuilder->buildPhone();
		_shopBuilder->buildTablet();
		_shopBuilder->buildScreen();
		_shopBuilder->buildLaptop();
	}
};

int main() {
	std::shared_ptr<ShopBuilder> hanoiShop = std::make_shared<HanoiShop>();
	std::shared_ptr<ShopBuilder> hcmShop = std::make_shared<HcmShop>();

	auto pShopHN = std::make_shared<ContractorShop>(hanoiShop);
	auto pShopHCM = std::make_shared<ContractorShop>(hcmShop);

	pShopHN->buildProduct();
	pShopHN->getProduct()->ShowInfor();

	std::cout << "\n\n";

	pShopHCM->buildProduct();
	pShopHCM->getProduct()->ShowInfor();

	return 0;
}
