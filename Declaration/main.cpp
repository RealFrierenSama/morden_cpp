#include "greeter.h"

// g++ main.cpp greeter.cpp -o main -std=c++23

int main() {
    // 调用我们声明和实现的函数
    say_hello("gemini");

    std::string myName = "elon";
    say_hello(myName);

    return 0; // 程序正常退出
}