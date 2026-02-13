#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    string title;
    float price;

    void display()
    {
        cout << "Book Title : " << title << endl;
        cout << "Price : " << price << endl;
    }
};

int main()
{
    
    Book b1;
    b1.title = "C++ Basics";
    b1.price = 450.50;

    cout << "Using Object:" << endl;
    b1.display();
    Book *ptr = &b1;
    cout << "\nUsing Pointer:" << endl;
    ptr->display();

    return 0;
}
