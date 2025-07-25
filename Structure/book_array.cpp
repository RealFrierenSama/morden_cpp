#include <iostream>
#include <string>
using namespace std;
// 结构体数组
struct Book
{
    string title;
    int pages;
    double price;
};
void book_info(Book b)
{
    cout << "title: " << b.title<< endl;
    cout << "pages: " <<b.pages << endl;
    cout << "price: " << b.price << endl;
}
int main()
{
    //另一种初始化的方式
    Book book_list[2];
    book_list[0] = {"Math",999,20.1};
    book_list[1] = {"English",20,28.1};

    for(int i = 0;i < 2;i++)
    {
        int index = i + 1;
        cout << "Book index: " << index << endl;
        book_info(book_list[i]);
        cout << endl;
    }
    return 0;
}
