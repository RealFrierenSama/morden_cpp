#include <iostream>
#include <string>

// --- Engine (引擎) 类定义 ---
class Engine {
private:
    std::string type;     // 引擎类型, 例如 "V6", "Electric"
    int horsepower;       // 马力

public:
    // 构造函数
    Engine(std::string engineType = "Unknown", int hp = 0) : type(engineType), horsepower(hp) {
        std::cout << "Engine constructor called: Type: " << type << ", HP: " << horsepower << std::endl;
    }

    // 启动引擎的方法
    void start() const { // const 因为它不修改 Engine 对象的状态
        if (horsepower > 0) {
            std::cout << "Engine (" << type << ", " << horsepower << "hp) started!" << std::endl;
        } else {
            std::cout << "Engine (" << type << ") cannot start (0 horsepower)." << std::endl;
        }
    }

    // 关闭引擎的方法
    void stop() const { // const
        std::cout << "Engine (" << type << ") stopped." << std::endl;
    }

    // 获取引擎信息的简单方法
    void displayEngineInfo() const {
        std::cout << "  Engine Type: " << type << ", Horsepower: " << horsepower << "hp" << std::endl;
    }
};


// --- Car (汽车) 类定义 ---
class Car {
private:
    std::string model;     // 汽车型号
    std::string color;     // 汽车颜色
    Engine carEngine;      // 对象组合: Car 类包含一个 Engine 对象作为成员

public:
    // Car 类的构造函数
    // 注意成员初始化列表如何初始化 carEngine 对象
    // 如果 Engine 类有合适的构造函数，carEngine 会在这里被隐式或显式构造
    Car(std::string carModel, std::string carColor, const Engine& engineDetails)
        : model(carModel), color(carColor), carEngine(engineDetails) { // carEngine 使用 Engine 的拷贝构造函数
        std::cout << "Car constructor called: Model: " << model << ", Color: " << color << std::endl;
    }

    // 另一个构造函数，允许直接传递引擎参数来构造 carEngine
    Car(std::string carModel, std::string carColor, std::string engineType, int engineHp)
        : model(carModel), color(carColor), carEngine(engineType, engineHp) { // carEngine 在此直接构造
         std::cout << "Car constructor (with engine params) called: Model: " << model << ", Color: " << color << std::endl;
    }


    // 启动汽车 (会调用其引擎的 start 方法)
    void startCar() const { // const，因为它不直接修改 Car 的成员，但会调用 carEngine 的 const 方法
        std::cout << model << " is trying to start..." << std::endl;
        carEngine.start(); // 调用其内部 Engine 对象的 start 方法
    }

    // 关闭汽车
    void stopCar() const {
        std::cout << model << " is stopping..." << std::endl;
        carEngine.stop();
    }

    // 显示汽车信息 (包括引擎信息)
    void displayCarInfo() const {
        std::cout << "\n--- Car Details ---" << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Color: " << color << std::endl;
        carEngine.displayEngineInfo(); // 调用 Engine 对象的成员函数
        std::cout << "-------------------" << std::endl;
    }
};


// === 主函数：演示类的使用 ===
int main() {
    std::cout << "--- Creating an Engine object first ---" << std::endl;
    Engine myEngine1("V8", 450);
    myEngine1.start();

    std::cout << "\n--- Creating Car1 using a pre-existing Engine object ---" << std::endl;
    Car car1("Mustang", "Red", myEngine1); // myEngine1 被拷贝到 car1.carEngine
    car1.displayCarInfo();
    car1.startCar();
    car1.stopCar();

    std::cout << "\n--- Creating Car2 by providing engine details directly ---" << std::endl;
    // car2 的引擎将在 Car 的构造函数初始化列表中直接创建
    Car car2("Tesla Model S", "Black", "Electric", 762);
    car2.displayCarInfo();
    car2.startCar();

    std::cout << "\n--- Creating Car3 with default engine ---" << std::endl;
    // 如果 Car 有一个接受默认 Engine 的构造函数，或者 Engine 有一个好的默认构造函数
    // 这里我们使用第二个 Car 构造函数，并给引擎一些默认值
    Car car3("City Car", "Blue", "1.0L Inline-3", 70);
    car3.displayCarInfo();
    car3.startCar();


    std::cout << "\nProgram finished. Objects will be destructed." << std::endl;
    // 当 main 结束时，car1, car2, car3, myEngine1 会被销毁。
    // Car 对象的析构会先于其成员对象 (carEngine) 的析构（如果 Engine 的析构不平凡的话）。
    // 但由于这些类没有显式析构函数打印消息，我们将只看到构造函数的消息。
    return 0;
}