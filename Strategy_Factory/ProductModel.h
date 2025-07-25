// ProductModel.h
#ifndef PRODUCT_MODEL_H
#define PRODUCT_MODEL_H

// 定义一个枚举类来表示所有可选的产品型号。
// 这为我们的工厂提供了一个清晰、类型安全的方式来指定需要哪种策略。
enum class ProductModel {
    Xiaomi15,   // 小米15
    Xiaomi14,   // 小米14
    Su7Ultra    // SU7 Ultra
};

#endif // PRODUCT_MODEL_H