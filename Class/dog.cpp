#include <iostream>
#include <string> // 为了使用 std::string

// 定义一个名为 Dog 的类
class Dog {
// 公有成员: 这些成员可以从类的外部访问
public:
    // 构造函数：当创建 Dog 类的对象时自动调用
    // 它用于初始化对象的成员变量
    Dog(std::string dogName, int dogAge) {
        name = dogName;
        age = dogAge;
        std::cout << name << " 对象被创建了！" << std::endl;
    }

    // 成员函数：让狗叫
    void bark() {
        std::cout << name << " 说：汪汪！" << std::endl;
    }

    // 成员函数：获取狗的年龄
    int getAge() {
        return age;
    }

    // 成员函数：设置狗的年龄
    void setAge(int newAge) {
        if (newAge > 0 && newAge < 30) { // 做一个简单的年龄校验
            age = newAge;
        } else {
            std::cout << "无效的年龄！" << std::endl;
        }
    }

    // 成员函数：显示狗的信息
    void displayInfo() {
        std::cout << "名字: " << name << ", 年龄: " << age << std::endl;
    }

// 私有成员: 这些成员只能在类的内部访问
// 这是封装的概念，有助于保护数据
private:
    std::string name; // 狗的名字
    int age;          // 狗的年龄
}; // 类定义结束时需要分号

// 主函数：程序的入口点
int main() {
    // 创建 Dog 类的对象 (实例化)
    // "buddy" 是狗的名字，3 是狗的年龄
    Dog myDog("Buddy", 3);

    // 调用对象的公有成员函数
    myDog.displayInfo(); // 显示 Buddy 的信息
    myDog.bark();        //让 Buddy 叫

    // 修改狗的年龄
    myDog.setAge(4);
    std::cout << "Buddy 现在 " << myDog.getAge() << " 岁了。" << std::endl;

    // 尝试设置一个无效的年龄
    myDog.setAge(-1);

    // 创建另一个 Dog 对象
    Dog anotherDog("Lucy", 1);
    anotherDog.displayInfo();
    anotherDog.bark();

    return 0; // 表示程序成功执行
}