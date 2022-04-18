#include <iostream>
#include <string>
#include <memory>

class IState {
public:
	virtual void getForm(void) = 0;
	virtual void checkForm(void) = 0;
	virtual void rentApartment(void) = 0;
	virtual void dispenseKeys() = 0;
}

class IRentalRobot {
public:
	virtual void getForm(void) = 0;
	virtual void checkForm(void) = 0;
	virtual void setState(std::shared_ptr<IState> state) = 0;

	virtual std::shared_ptr<IState> getState(void) = 0;
	virtual std::shared_ptr<IState> getWaitting(void) = 0;
	virtual std::shared_ptr<IState> getReceivingForm(void) = 0;
	virtual std::shared_ptrt<IState> getRentApartment(void = 0;)
}

int main() {

	return 0;
}
