//! Assignment-34: constructor

/* //?1. Define a class Cuboid with length, breadth and height as instance member variables. Define constructors to initialise member variables.
#include <iostream>
using namespace std;
class Cuboid
{
private:
    int length, breadth, height;

public:
    Cuboid(int x, int y, int z)
    {
        length = x;
        breadth = y;
        height = z;
    }   
    void showdata();
};
void Cuboid::showdata()
{
    cout << "length :"<<length<<endl;
    cout << "breadth :"<<breadth<<endl;
    cout << "height :"<<height<<endl;
}
int main()
{
    Cuboid c1(4, 5, 6);
    c1.showdata();
    return 0;
} */

/* //?2. Define a class Customer with instance members cust_id, name, email, mobile. Define non parameterised constructor and parameterised constructor in the class.
#include <iostream>
#include <string.h>
using namespace std;
class Customer
{
private:
    int cust_id;
    char name[20];
    char email[20];
    char mobile[10];

public:
    Customer()
    {
        cust_id = 0;
        strcpy(name, "no name");
        strcpy(email, "no email");
        strcpy(mobile, "no mobile number");
    }
    Customer(int x)
    {
        cust_id = x;
        strcpy(name, "no name");
        strcpy(email, "no email");
        strcpy(mobile, "no mobile number");
    }
    Customer(int x, const char *a, const char *b)
    {
        cust_id = x;
        strcpy(name, a);
        strcpy(email, b);
        strcpy(mobile, "no mobile number");
    }
    Customer(int x, const char *a, const char *b, const char *c)
    {
        cust_id = x;
        strcpy(name, a);
        strcpy(email, b);
        strcpy(mobile, c);
    }

    void showdata();
};
void Customer::showdata()
{
    cout << "customer id :" << cust_id << endl;
    cout << "customer name :" << name << endl;
    cout << "Email Id:" << email << endl;
    cout << "Mobile Number: " << mobile << endl;
}
int main()
{
    Customer c1, c2(101), c3(102, "Anurag", "A@gmail.com"), c4(105, "bhanu", "anurag@gmail.com", "9098906256");
    c1.showdata();
    c2.showdata();
    c3.showdata();
    c4.showdata();
    return 0;
} */

/* //?3. Define a class Time with hr,min, seç as instance member variables. Define constructor to initialise time object.
#include <iostream>
using namespace std;
class Time
{
private:
    int hr, min, sec;

public:
    Time(int h, int m, int s)
    {
        hr=h;
        min=m;
        sec=s;
    }
    void showdata();
};
void Time::showdata()
{
    cout << "Time: " << hr << ":" << min << ":" << sec << endl;
}
int main()
{
    Time t1(5, 30, 6);
    t1.showdata();
    return 0;
} */

/* //?4. Define a class Book with bookid, title and price as instance member variables. Define non parameterised and parameterised constructor in the class. 
#include <iostream>
#include <string.h>
using namespace std;
class Book
{
private:
    int book_id;
    char title[20];
    float price;

public:
    Book()
    {
        book_id = 0;
        strcpy(title, "no title");
        price = 0;
    }
    Book(int x)
    {
        book_id = x;
        strcpy(title, "no title");
        price = 0;
    }
    Book(int x, const char *a, float y)
    {
        book_id = x;
        strcpy(title, a);
        price = y;
    }
    Book(int x, const char *a)
    {
        book_id = x;
        strcpy(title, a);
        price = 0;
    }

    void showdata();
};
void Book::showdata()
{
    cout << "Book id :" << book_id << endl;
    cout << "Title :" << title << endl;
    cout << "Price:" << price << endl;
}
int main()
{
    Book b1, b2(101), b3(102, "Anurag", 500.0), b4(105, "bhanu");
    b1.showdata();
    b2.showdata();
    b3.showdata();
    b4.showdata();
    return 0;
} */

/* //?5. Define a class Complex with instance variables for real and imaginary part of a complex number. Define only one parameterised constructor in the class to initialise complex object. Also define showData method in the class to display object data Now create an array of Complex class with size 5 and display values of each object
#include <iostream>
using namespace std;
class Complex
{
private:
    int a,b;

public:
    Complex(int x,int y)
    {
        a=x;
        b=y;

    }
    void showdata();
};
void Complex::showdata()
{
    cout<<a<<"+"<<b<<"i"<<endl;
}
int main()

{
    Complex c1(5,6);
    Complex a[]={Complex(7,6),Complex(5,3),Complex(6,2),Complex(9,4),Complex(4,8)};
    c1.showdata();
    for(int i=0;i<5;i++)
    {
        a[i].showdata();
    }
    return 0;
} */

/* //?6. Define a class Numbers with size and arr pointer as instance variables. Provide constructor to initialise instance members, dynamically allocate an array of given size and store address in arr variable of object. Also define destructor to deallocate memory of array. Implement deep copy using copy constructor to avoid memory issues
#include <iostream>
using namespace std;

class Numbers {
private:
    int size;
    int* arr;

public:
    // Parameterized constructor
    Numbers(int s) {
        size = s;
        arr = new int[size]; // Dynamic memory allocation
        cout << "Constructor: Memory allocated for size " << size << endl;
    }

    // Copy constructor (Deep Copy)
    Numbers(const Numbers& obj) {
        size = obj.size;
        arr = new int[size]; // Allocate new memory
        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i]; // Copy data
        }
        cout << "Copy Constructor: Deep copy performed" << endl;
    }

    // Destructor
    ~Numbers() {
        delete[] arr; // Free allocated memory
        cout << "Destructor: Memory deallocated" << endl;
    }

    // Method to set values in the array
    void setValues() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Method to display array elements
    void showValues() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Numbers num1(5); // Create object with dynamic array
    num1.setValues(); // Input values
    num1.showValues(); // Display values

    Numbers num2 = num1; // Invoke deep copy constructor
    num2.showValues(); // Display copied object’s values

    return 0;
} */

/* //?7. Define a class student and write a program to enter student details using constructor and define member function to display all the details.
#include <iostream>
#include<string.h>
using namespace std;
class Student
{
private:
    int roll_no;
    char name[20];
    float percentage;

public:
    Student(int x, const char *str, float y)
    {
       roll_no=x;
       strcpy(name,str);
       percentage=y;

    }
    void showdata();
};
void Student::showdata()
{
    cout << "Roll number :" << roll_no << endl;
    cout << "Name:" << name<< endl;
    cout << "Persentage :" << percentage << endl;
}
int main()
{
    int r;
    char n[20];
    float p;
    cout<<"Enter Roll Number: ";
    cin>>r;
    cin.ignore();
    cout<<"Enter Your Name: ";
    cin.getline(n,20);
    cout<<"Enter Percentage: ";
    cin>>p;



    Student s1(r, n, p);
    s1.showdata();
    return 0;
} */

/* //?8. Define a class Date with d, m, y as instance variables. Initialise members using initialisers.
#include <iostream>
using namespace std;
class Date
{
private:
    int d, m, y;

public:
    Date(int day, int month, int year) : d(day), m(month), y(year) {}
    void showdata();
};
void Date::showdata()
{
    cout << "Date:" << d << "/" << m << "/" << y << endl;
}
int main()
{
    Date d1(15, 10, 2002);
    d1.showdata();
    return 0;
} */

/* //?9. Define a class Room for a hotel management project with room number, room type, is_AC, price as instance variables. Initialise instance variables using constructor.
#include <iostream>
using namespace std;
class Room
{
private:
    int room_number;
    string room_type;
    bool is_AC;
    int price;

public:
    Room(int r_n, string r_t,bool ac, int p) : room_number(r_n), room_type(r_t),is_AC(ac), price(p) {}
    void showdata();
};
void Room::showdata()
{
    cout<<"Room Number: "<<room_number<<endl;
    cout<<"Room Type: "<<room_type<<endl;
    cout<<"is_AC: "<<(is_AC?"Yes":"No")<<endl;
    cout<<"Price: "<<price<<endl;
}
int main()
{
    Room d1(101, "standard",true, 5000);
    d1.showdata();
    return 0;
} */

/* //?10. Define Circle class with radius as instance variable. Define two constructors in the class -non parameterised and parameterised.
#include <iostream>
#include <string.h>
using namespace std;
class Circle
{
private:
    float radius;

public:
    Circle():radius(0){}
    Circle(float r):radius(r){}
    void showdata();
};
void Circle::showdata()
{
    cout<<"Radius: "<<radius<<endl;
}
int main()
{
    Circle c1,c2(6.5);
    c1.showdata();
    c2.showdata();
    return 0;
} */