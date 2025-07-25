// main.cpp (使用 new 和 delete 的传统版本)
#include <iostream>
#include <string>
#include <memory>
#include "ProductModel.h" // 包含产品型号的枚举头文件

// ===================================================================
// I. 策略模式 (Strategy Pattern) - [这部分保持不变]
// ===================================================================

class IProductSpecStrategy {
public:
    virtual ~IProductSpecStrategy() = default;
    virtual std::string get_spec_string() const = 0;
};

class Xiaomi15Strategy : public IProductSpecStrategy {
public:
    std::string get_spec_string() const override { return "8elite"; }
};

class Xiaomi14Strategy : public IProductSpecStrategy {
public:
    std::string get_spec_string() const override { return "8gen3"; }
};

class Su7UltraStrategy : public IProductSpecStrategy {
public:
    std::string get_spec_string() const override { return "v8s"; }
};

// ===================================================================
// II. 工厂模式 (Factory Pattern) - [修改点]
// ===================================================================

class StrategyFactory {
public:
    /**
     * @brief 创建一个策略实例，并返回一个原始指针。
     * @param model 我们从枚举中选择的产品型号。
     * @return 返回一个指向策略接口的原始指针。调用者有责任释放这块内存！
     */
    static IProductSpecStrategy* createStrategy(ProductModel model) {
        switch (model) {
            case ProductModel::Xiaomi15:
                // 使用 new 在堆上创建对象，返回它的地址
                return new Xiaomi15Strategy();
            case ProductModel::Xiaomi14:
                return new Xiaomi14Strategy();
            case ProductModel::Su7Ultra:
                return new Su7UltraStrategy();
            default:
                return nullptr;
        }
    }
};

// ===================================================================
// III. 客户端代码 (Client Code) - [修改点]
// ===================================================================

/**
 * @brief 使用原始指针来操作策略的函数
 */
void printProductSpec(ProductModel model) {
    // 1. 创建一个原始的基类指针，并初始化为nullptr
    IProductSpecStrategy* strategy = nullptr;

    // 2. 工厂用 new 创建一个具体的设备，然后把它的地址赋给我们的指针
    strategy = StrategyFactory::createStrategy(model);

    // 3. 检查指针是否有效（工厂是否成功创建了对象）
    if (strategy) {
        // 4. 通过指针调用方法，这部分和之前完全一样
        std::cout << "产品型号 " << static_cast<int>(model) << " 的规格是: " << strategy->get_spec_string() << std::endl;
        
        // 5. 【核心】手动释放内存！
        // 这是使用原始指针最重要也最容易忘记的一步。
        // 如果没有这句 delete，每次调用本函数都会造成一次内存泄漏。
        delete strategy;

        // 6. (可选但推荐) 将指针设为nullptr，防止后续误用这个无效的指针
        strategy = nullptr; 

    } else {
        std::cerr << "错误：未知的产品型号！" << std::endl;
    }
}

int main() {
    printProductSpec(ProductModel::Xiaomi15);
    printProductSpec(ProductModel::Xiaomi14);
    printProductSpec(ProductModel::Su7Ultra);
    return 0;
}