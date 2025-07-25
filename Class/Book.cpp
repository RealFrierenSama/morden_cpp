#include <iostream>
#include <string>
#include <vector> // 只是为了在 main 函数中展示对象数组

// === Book 类定义 ===
class Book {
private:
    std::string title;         // 书名 (私有成员)
    std::string author;        // 作者 (私有成员)
    int publicationYear;     // 出版年份 (私有成员)
    bool isAvailable;        // 是否可借阅 (私有成员)

    // 静态成员变量：属于类本身，而不是类的任何特定对象。
    // 用于追踪创建了多少本书籍对象。
    static int bookCount;

public:
    // --- 1. 构造函数 (Constructors) ---
    // 构造函数用于初始化对象。一个类可以有多个构造函数（重载）。

    // (a) 默认构造函数
    // 当不提供参数创建对象时调用。
    Book() {
        title = "未知书名";
        author = "未知作者";
        publicationYear = 0;
        isAvailable = true;
        bookCount++; // 每创建一个对象，计数器增加
        std::cout << "默认构造函数调用: 创建了一本空信息的书。" << std::endl;
    }

    // (b) 参数化构造函数
    // 用于在创建对象时提供初始值。
    Book(std::string initialTitle, std::string initialAuthor, int initialYear) {
        // 使用 this 指针来区分成员变量和参数名（如果它们相同）
        // this 指针指向调用该成员函数的对象本身。
        this->title = initialTitle;
        this->author = initialAuthor;
        this->publicationYear = initialYear;
        this->isAvailable = true;
        bookCount++; // 每创建一个对象，计数器增加
        std::cout << "参数化构造函数调用: 《" << this->title << "》 已创建。" << std::endl;
    }

    // --- 2. 析构函数 (Destructor) ---
    // 当对象生命周期结束时（例如，离开作用域或被 delete），析构函数会自动调用。
    // 通常用于释放对象占用的资源。
    // 一个类只有一个析构函数，它没有参数，也没有返回值。
    ~Book() {
        bookCount--; // 对象被销毁，计数器减少
        std::cout << "析构函数调用: 《" << title << "》 已被销毁。当前书籍数量: " << bookCount << std::endl;
        // 如果在这里分配了动态内存（例如用 new），则应在此处用 delete 释放。
    }

    // --- 3. 成员函数 (Member Functions) ---

    // (a) Setter 方法 (修改器): 用于修改私有成员变量的值
    void setTitle(std::string newTitle) {
        if (!newTitle.empty()) {
            this->title = newTitle;
        }
    }

    void setAuthor(std::string newAuthor) {
        if (!newAuthor.empty()) {
            this->author = newAuthor;
        }
    }

    void setPublicationYear(int newYear) {
        if (newYear > 0 && newYear <= 2025) { // 简单校验
            this->publicationYear = newYear;
        } else {
            std::cout << "警告: 无效的出版年份 " << newYear << std::endl;
        }
    }

    // (b) Getter 方法 (访问器): 用于获取私有成员变量的值
    // "const" 关键字用在成员函数末尾，表示该函数不会修改对象的任何成员变量。
    // 这是一种良好的实践，称为 "const correctness"。
    std::string getTitle() const {
        return this->title;
    }

    std::string getAuthor() const {
        return this->author;
    }

    int getPublicationYear() const {
        return this->publicationYear;
    }

    bool getAvailability() const {
        return this->isAvailable;
    }

    // (c) 其他行为方法
    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            std::cout << "《" << title << "》 已被借出。" << std::endl;
        } else {
            std::cout << "《" << title << "》 当前不可借阅。" << std::endl;
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            std::cout << "《" << title << "》 已被归还。" << std::endl;
        } else {
            std::cout << "《" << title << "》 无需归还 (已在库)。" << std::endl;
        }
    }

    void displayBookInfo() const { // const 成员函数
        std::cout << "\n--- 书籍信息 ---" << std::endl;
        std::cout << "书名: " << title << std::endl;
        std::cout << "作者: " << author << std::endl;
        std::cout << "出版年份: " << publicationYear << std::endl;
        std::cout << "状态: " << (isAvailable ? "可借阅" : "已借出") << std::endl;
        std::cout << "------------------" << std::endl;
    }

    // --- 4. 静态成员函数 (Static Member Function) ---
    // 静态成员函数可以直接通过类名调用，而不需要创建类的对象。
    // 它们只能访问静态成员变量或其他静态成员函数。
    static int getBookCount() {
        // 注意：静态成员函数没有 this 指针，因为它不与任何特定对象关联。
        // return this->bookCount; // 这会是错误的
        return bookCount;
    }
};

// --- 初始化静态成员变量 ---
// 静态成员变量必须在类的外部定义和初始化（通常在 .cpp 文件中）。
int Book::bookCount = 0; // 初始化书籍计数器为0


// === 主函数：演示 Book 类的使用 ===
int main() {
    std::cout << "程序开始。当前书籍数量: " << Book::getBookCount() << std::endl; // 通过类名调用静态方法

    // 1. 使用参数化构造函数创建对象
    Book book1("C++ Primer", "Stanley B. Lippman", 2012);
    Book book2("Effective C++", "Scott Meyers", 2005);

    std::cout << "创建两本书后，书籍数量: " << Book::getBookCount() << std::endl;

    // 2. 使用公有方法
    book1.displayBookInfo();
    book2.displayBookInfo();

    book1.borrowBook();
    book1.displayBookInfo();
    book1.borrowBook(); // 再次借阅
    book1.returnBook();
    book1.displayBookInfo();

    // 3. 使用 Setter 和 Getter
    book2.setPublicationYear(2006); // 修改出版年份
    std::cout << "\n《" << book2.getTitle() << "》的新出版年份是: " << book2.getPublicationYear() << std::endl;

    // 4. 使用默认构造函数创建对象
    std::cout << "\n--- 创建一本默认书籍 ---" << std::endl;
    Book book3; // 调用默认构造函数
    book3.displayBookInfo();
    book3.setTitle("学习JavaScript");
    book3.setAuthor("某某某");
    book3.setPublicationYear(2023);
    book3.displayBookInfo();

    std::cout << "创建三本书后，书籍数量: " << Book::getBookCount() << std::endl;


    // 5. 演示对象作用域和析构函数
    // 当 main 函数结束时，book1, book2, book3 会按其创建的相反顺序被销毁，
    // 它们的析构函数会被自动调用。

    std::cout << "\n--- 演示动态分配和析构 ---" << std::endl;
    Book* bookPtr = new Book("动态分配的书", "堆内存", 2024); // 在堆上创建对象
    std::cout << "创建动态分配的书后，书籍数量: " << Book::getBookCount() << std::endl;
    bookPtr->displayBookInfo();
    delete bookPtr; // 显式调用析构函数并释放内存
    bookPtr = nullptr; // 良好习惯，防止悬挂指针

    std::cout << "显式删除动态分配的书后，书籍数量: " << Book::getBookCount() << std::endl;


    std::cout << "\n程序即将结束..." << std::endl;
    return 0;
    // main 函数结束时，栈上的 book1, book2, book3 会被销毁
}