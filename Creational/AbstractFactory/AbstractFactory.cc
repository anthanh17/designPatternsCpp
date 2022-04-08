#include <iostream>
#include <memory>

class Button {
public:
	virtual ~Button() = default;
	Button() = default;
};

class LightButton : public Button {
public:
	LightButton() {
		std::cout << "\nThis is Light Button! ";
	}
};

class DarkButton : public Button {
public:
	DarkButton() {
		std::cout << "\nThis is Dark Button! ";
	}
};

class ScrollBar {
public:
	virtual ~ScrollBar() = default;
	ScrollBar() = default;
};

class LightScrollBar : public ScrollBar {
public:
	LightScrollBar() {
		std::cout << "\nThis is Light ScrollBar! ";
	}
};

class DarkScrollBar : public ScrollBar {
public:
	DarkScrollBar() {
		std::cout << "\nThis is Dark ScrollBar! ";
	}
};

class WidgetFactory {
public:
	~WidgetFactory() = default;
	virtual std::shared_ptr<Button> createButton() = 0;
	virtual std::shared_ptr<ScrollBar> createScrollBar() = 0;
};

class LightTheme final : public WidgetFactory {
public:
	~LightTheme() = default;
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<LightButton>();
	}
	std::shared_ptr<ScrollBar> createScrollBar() override {
		return std::make_shared<LightScrollBar>();
	}
};

class DarkTheme final : public WidgetFactory{
public:
	~DarkTheme() = default;
	std::shared_ptr<Button> createButton() override {
		return std::make_shared<DarkButton>();
	}
	std::shared_ptr<ScrollBar> createScrollBar() override {
		return std::make_shared<DarkScrollBar>();
	}
};
	
int main() {
	
	auto factoryLightPtr = std::make_shared<LightTheme>();
	auto factoryDarkPtr = std::make_shared<DarkTheme>();

	auto buttonLight = factoryLightPtr->createButton();
	auto scrollBarLight = factoryLightPtr->createScrollBar();
	
	auto buttonDark = factoryDarkPtr->createButton();
	auto scrollBarDark = factoryDarkPtr->createScrollBar();
	
	return 0;
}
