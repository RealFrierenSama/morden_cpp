#include <iostream>
#include <cmath> // 为了使用 sqrt (平方根)
#include <iomanip> // 为了 std::fixed 和 std::setprecision

class Vector2D {
private:
    double x; // x分量
    double y; // y分量

public:
    // --- 1. 构造函数 ---

    // (a) 默认构造函数
    Vector2D() : x(0.0), y(0.0) { // 使用成员初始化列表
        std::cout << "默认构造函数: Vector2D(0, 0) 已创建." << std::endl;
    }

    // (b) 参数化构造函数
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) { // 成员初始化列表
        std::cout << "参数化构造函数: Vector2D(" << x << ", " << y << ") 已创建." << std::endl;
    }

    // (c) 拷贝构造函数
    // 当用一个已存在的同类对象来初始化一个新对象时被调用。
    // 例如: Vector2D v2 = v1; 或 Vector2D v3(v1);
    // 如果不显式定义，编译器会生成一个默认的拷贝构造函数（通常是浅拷贝）。
    // 对于像这个类这样只有简单数据成员的，默认的通常就够了，但显式定义有助于理解。
    Vector2D(const Vector2D& other) {
        x = other.x;
        y = other.y;
        std::cout << "拷贝构造函数: 从 Vector2D(" << other.x << ", " << other.y
                  << ") 拷贝创建了 Vector2D(" << x << ", " << y << ")." << std::endl;
    }

    // --- 2. 析构函数 ---
    ~Vector2D() {
        std::cout << "析构函数: Vector2D(" << x << ", " << y << ") 已销毁." << std::endl;
        // 对于这个类，不需要特殊的资源清理
    }

    // --- 3. 成员函数 ---

    // Getter 方法 (const 表示它们不修改对象状态)
    double getX() const { return x; }
    double getY() const { return y; }

    // Setter 方法
    void setX(double newX) { this->x = newX; } // this->x 明确指向成员变量 x
    void setY(double newY) { this->y = newY; }

    // 计算向量的模（长度）
    double magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    // --- 4. 运算符重载 ---

    // (a) 拷贝赋值运算符 (=)
    // 当将一个已存在的对象赋值给另一个已存在的对象时调用。
    // 例如: v2 = v1;
    // 返回对自身的引用以支持链式赋值 (例如 a = b = c)。
    Vector2D& operator=(const Vector2D& other) {
        std::cout << "拷贝赋值运算符: Vector2D(" << this->x << ", " << this->y
                  << ") 被赋值为 Vector2D(" << other.x << ", " << other.y << ")." << std::endl;
        // 1. 防止自赋值 (虽然对于这个简单类不是严格必需，但好习惯)
        if (this == &other) { // &other 获取 other 对象的地址
            return *this;     // this 是指向当前对象的指针，*this 是对象本身
        }
        // 2. 拷贝数据
        this->x = other.x;
        this->y = other.y;
        // 3. 返回对当前对象的引用
        return *this;
    }

    // (b) 向量加法 (+)
    // 返回一个新的 Vector2D 对象，它是两个向量的和。
    // 可以作为成员函数或友元函数。这里作为成员函数。
    Vector2D operator+(const Vector2D& other) const {
        std::cout << "调用 operator+ for Vector2D(" << this->x << ", " << this->y
                  << ") + Vector2D(" << other.x << ", " << other.y << ")" << std::endl;
        return Vector2D(this->x + other.x, this->y + other.y); // 返回一个临时的新Vector2D对象
    }

    // (c) 向量相等性比较 (==)
    bool operator==(const Vector2D& other) const {
        // 考虑到浮点数比较的精度问题，通常不直接用 == 比较 double
        // 但为了示例简单，这里直接比较。实际应用中可能需要一个小误差范围 (epsilon)。
        return (this->x == other.x && this->y == other.y);
    }

    // (d) 向量不等性比较 (!=)
    bool operator!=(const Vector2D& other) const {
        return !(*this == other); // 利用已定义的 operator==
    }


    // --- 友元函数 (用于重载 <<) ---
    // `std::ostream& operator<<` 通常被重载为友元函数或非成员函数，
    // 因为它的左操作数是 `std::ostream` 对象 (例如 `std::cout`)，而不是 `Vector2D` 对象。
    // 友元函数可以访问类的私有成员。
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);
};

// 重载输出流运算符 << 的定义 (作为友元函数)
std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    os << "Vector(" << std::fixed << std::setprecision(2) << vec.x
       << ", " << std::fixed << std::setprecision(2) << vec.y << ")";
    return os;
}


// === 主函数：演示 Vector2D 类的使用 ===
int main() {
    std::cout << "--- 创建向量 v1 (参数化构造) ---" << std::endl;
    Vector2D v1(3.0, 4.0);
    std::cout << "v1: " << v1 << " (模: " << v1.magnitude() << ")" << std::endl;

    std::cout << "\n--- 创建向量 v2 (拷贝构造自 v1) ---" << std::endl;
    Vector2D v2 = v1; // 调用拷贝构造函数
    // Vector2D v2(v1); // 等效于上一行，也是拷贝构造

    std::cout << "v2: " << v2 << std::endl;

    std::cout << "\n--- 创建向量 v3 (默认构造) ---" << std::endl;
    Vector2D v3;
    std::cout << "v3 (初始): " << v3 << std::endl;

    std::cout << "\n--- 将 v1 赋值给 v3 (拷贝赋值运算符) ---" << std::endl;
    v3 = v1; // 调用拷贝赋值运算符
    std::cout << "v3 (赋值后): " << v3 << std::endl;

    std::cout << "\n--- 向量加法 ---" << std::endl;
    Vector2D v4(1.0, -2.0);
    Vector2D sum_v1_v4 = v1 + v4; // 调用 v1.operator+(v4)
    std::cout << v1 << " + " << v4 << " = " << sum_v1_v4 << std::endl;

    std::cout << "\n--- 向量比较 ---" << std::endl;
    Vector2D v5(3.0, 4.0);
    std::cout << v1 << " == " << v2 << " ? " << (v1 == v2) << std::endl; // true
    std::cout << v1 << " == " << v4 << " ? " << (v1 == v4) << std::endl; // false
    std::cout << v1 << " != " << v4 << " ? " << (v1 != v4) << std::endl; // true

    std::cout << "\n--- 演示自赋值 ---" << std::endl;
    v1 = v1; // 测试拷贝赋值运算符中的自赋值保护
    std::cout << "v1 (自赋值后): " << v1 << std::endl;


    std::cout << "\n--- 程序结束 (对象将按创建相反顺序销毁) ---" << std::endl;
    return 0;
}