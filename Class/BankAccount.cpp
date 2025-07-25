#include <iostream>
#include <string>
#include <iomanip> // 为了使用 std::fixed 和 std::setprecision 来格式化输出货币

class BankAccount {
// 公有成员: 可以从类的外部访问和调用
public:
    // 构造函数: 初始化一个新的 BankAccount 对象
    BankAccount(std::string accNum, std::string ownerName, double initialBalance) {
        accountNumber = accNum;
        owner = ownerName;
        // 初始余额不能为负
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            std::cout << "警告: 初始余额不能为负。已将余额设置为0。" << std::endl;
        }
        std::cout << "账户 " << accountNumber << " 为 " << owner << " 创建成功。" << std::endl;
    }

    // 公有方法: 存款
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "存款 " << amount << " 成功。";
            displayBalance();
        } else {
            std::cout << "存款金额必须为正数。" << std::endl;
        }
    }

    // 公有方法: 取款
    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "取款金额必须为正数。" << std::endl;
            return false;
        }
        if (amount <= balance) {
            balance -= amount;
            std::cout << "取款 " << amount << " 成功。";
            displayBalance();
            return true;
        } else {
            std::cout << "取款失败：余额不足。";
            displayBalance();
            return false;
        }
    }

    // 公有方法: 获取当前余额
    double getBalance() {
        return balance;
    }

    // 公有方法: 显示账户信息
    void displayAccountInfo() {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "账户持有人: " << owner << std::endl;
        std::cout << "账户号码:   " << accountNumber << std::endl;
        displayBalance();
        std::cout << "-----------------------------" << std::endl;
    }

// 私有成员: 只能在类的内部 (即被类的成员函数) 访问
private:
    std::string accountNumber; // 账户号码
    std::string owner;         // 账户持有人姓名
    double balance;            // 账户余额

    // 私有辅助方法: 格式化显示余额 (只能在类内部调用)
    void displayBalance() {
        // std::fixed 和 std::setprecision 用于将double格式化为两位小数
        std::cout << "当前余额: " << std::fixed << std::setprecision(2) << balance << std::endl;
    }
}; // 类定义结束

int main() {
    // 创建一个 BankAccount 对象
    BankAccount myAccount("123456789", "张三", 1000.50);

    // 使用公有方法与对象交互
    myAccount.displayAccountInfo();

    myAccount.deposit(500.75);
    myAccount.withdraw(200.20);
    myAccount.withdraw(2000.00); // 尝试取款超过余额

    // 尝试直接访问私有成员 (这将导致编译错误)
    // myAccount.balance = 50.0; // 错误! 'balance' 是私有的
    // std::cout << myAccount.accountNumber; // 错误! 'accountNumber' 是私有的

    // 只能通过公有方法获取信息
    std::cout << "\n通过 getBalance() 获取当前余额: "
              << std::fixed << std::setprecision(2) << myAccount.getBalance() << std::endl;

    BankAccount anotherAccount("987654321", "李四", -100.0); // 测试初始余额为负数的情况
    anotherAccount.displayAccountInfo();
    anotherAccount.deposit(200);


    return 0;
}