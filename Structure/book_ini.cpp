#include <iostream>
#include <string>
using namespace std;
struct Book
{
    string title;
    int pages;
    double price;
};
void print_book(Book b)
{
    cout << "title: " << b.title<< endl;
    cout << "pages: " <<b.pages << endl;
    cout << "price: " << b.price << endl;
    cout << endl;
}
int main()
{
    Book mybook0;
    mybook0.title = "Crime and Punishment";
    mybook0.pages = 31273;
    mybook0.price = 100.25;
    print_book(mybook0);


    //另一种初始化的方式
    Book mybook1 = {"1984",31,28.3};
    print_book(mybook1);
    return 0;
}
