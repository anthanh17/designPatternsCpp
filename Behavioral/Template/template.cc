#include <iostream>
#include <memory>
using namespace std;

class RobotTemplate {
public:
 
    void start() {
        cout << "Starting ..." << endl;
    }
    
    void stop() {
        cout << "Stopping ..." << endl;
    }
    
    virtual void getParts() {
        cout << "Getting parts ..." << endl;
    }
    
    virtual void assemble() {
        cout << "Assembling ..." << endl;
    }
    
    virtual void test() {
        cout << "Testing ..." << endl;
    }
 
    virtual std::string getName() = 0;
 
    void go() {
        start();
        getParts();
        assemble();
        test();
        stop();
    }
};

class AutomotiveRobot final : public RobotTemplate
{
public:
    AutomotiveRobot() {}

    void getParts() override {
        cout << "Getting a carburetor ..." << endl;
    }

    void assemble() override {
        cout << "Installing the carburetor ..." << endl;
    }

    void test() override {
        cout << "Revving the engine ..." << endl;
    }

    std::string getName() override {
        return "Automotive Robot";
    }
};


class CookieRobot : public RobotTemplate
{
public:
    CookieRobot() {}
 
    void getParts() override {
        cout << "Getting flour and sugar ..." << endl;
    }
 
    void assemble() override {
        cout << "Baking a cookie ..." << endl;
    }
 
    void test() override {
        cout << "Crunching a cookie ..." << endl;
    }
 
    std::string getName() override {
        return "Cookie Robot";
    }
};

int main()
{    
    const auto automotiveRobot = std::make_shared<AutomotiveRobot>();
    const auto cookieRobot = std::make_shared<CookieRobot>();

    cout << automotiveRobot->getName() << ":" << endl;
    automotiveRobot->go();
    cout << "---------------------" << endl;
    cout << cookieRobot->getName() << ":" << endl;
    cookieRobot->go();
    return 0;
}
