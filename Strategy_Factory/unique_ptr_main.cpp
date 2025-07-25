// main.cpp
#include <iostream>
#include <string>
#include <memory>
#include "ProductModel.h" // 包含更新后的枚举头文件

// ===================================================================
// I. 策略模式 (Strategy Pattern)
// ===================================================================

/**
 * @brief 策略接口 (The Strategy Interface)
 * * 定义了一个所有产品规格“策略”都必须实现的通用接口。
 */
class IProductSpecStrategy {
public:
    virtual ~IProductSpecStrategy() = default;

    // 纯虚函数，任何具体的产品策略都必须提供自己的规格信息。
    virtual std::string get_spec_string() const = 0;
};

/**
 * @brief 具体策略A：小米15的规格
 */
class Xiaomi15Strategy : public IProductSpecStrategy {
public:
    std::string get_spec_string() const override {
        return "xiaomi15:8elite";
    }
};

/**
 * @brief 具体策略B：小米14的规格
 */
class Xiaomi14Strategy : public IProductSpecStrategy {
public:
    std::string get_spec_string() const override {
        return "xiaomi14:8gen3";
    }
};

/**
 * @brief 具体策略C：SU7 Ultra的规格
 */
class Su7UltraStrategy : public IProductSpecStrategy {
public:
    std::string get_spec_string() const override {
        return "su7ultra:v8s";
    }
};


// ===================================================================
// II. 工厂模式 (Factory Pattern)
// ===================================================================

/**
 * @brief 策略工厂 (The Strategy Factory)
 * * 它的职责是根据请求的产品型号，创建对应的规格策略实例。
 */
class StrategyFactory {
public:
    /**
     * @brief 创建一个产品规格策略实例。
     * @param model 我们从枚举中选择的产品型号。
     * @return 返回一个指向策略接口的智能指针。
     */
    static std::unique_ptr<IProductSpecStrategy> createStrategy(ProductModel model) {
        switch (model) {
            case ProductModel::Xiaomi15:
                return std::make_unique<Xiaomi15Strategy>();
            case ProductModel::Xiaomi14:
                return std::make_unique<Xiaomi14Strategy>();
            case ProductModel::Su7Ultra:
                return std::make_unique<Su7UltraStrategy>();
            default:
                return nullptr;
        }
    }
};


// ===================================================================
// III. 客户端代码 (Client Code)
// ===================================================================

/*
// **非常僵硬、不灵活的写法**
void printProductSpec_Rigid(ProductModel model) {
    if (model == ProductModel::Xiaomi15) {
        Xiaomi15Strategy xiaomi15; // 创建一个具体的对象
        std::cout << xiaomi15.get_spec_string() << std::endl;
    } else if (model == ProductModel::Xiaomi14) {
        Xiaomi14Strategy xiaomi14; // 创建另一个具体的对象
        std::cout << xiaomi14.get_spec_string() << std::endl;
    } else if (model == ProductModel::Su7Ultra) {
        Su7UltraStrategy su7; // 创建第三个具体的对象
        std::cout << su7.get_spec_string() << std::endl;
    }
    // ... 未来每增加一个新产品，都要在这里加一个 else if ...
}
*/
void printProductSpec(ProductModel model) {
    // 1. 创建一个“万能插座”（基类智能指针）
    std::unique_ptr<IProductSpecStrategy> strategy;

    // 2. 工厂根据型号，new一个具体的设备，然后把它的地址给“插座”
    strategy = StrategyFactory::createStrategy(model);

    // 3. 通过“插座”统一操作设备，完全不用关心插座后面到底连的是谁
    if (strategy) {
        // 找到 strategy 指针所指向的那个对象，然后调用它的 get_spec_string() 方法。
        std::cout << strategy->get_spec_string() << std::endl;
    }
}

int main() {
    // 客户端代码现在可以轻松地查询不同产品的规格。
    
    printProductSpec(ProductModel::Xiaomi15);
    
    printProductSpec(ProductModel::Xiaomi14);
    
    printProductSpec(ProductModel::Su7Ultra);

    return 0;
}