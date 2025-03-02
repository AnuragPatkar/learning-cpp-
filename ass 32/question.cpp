// TODO: C++ Assignment 4

// TODO: Assignment-32: Classes and Objects

/* //! 1. Define a class Complex to represent a complex number. Declare instance member variables to store real and imaginary part of a complex number. Also define instance member functions to set values of complex number and print values of complex number.
#include <iostream>
using namespace std;
class complex
{
private:
    int a, b;

public:
    void setdata(int x, int y)
    {
        a = x;
        b = y;
    }
    void showdata()
    {
        cout << "a= " << a << " b= " << b;
    }
};
int main()
{
    complex i1;
    i1.setdata(3, 4);
    i1.showdata();
    return 0;
} */

/* //! 2. Define a class Time to represent Time (like 3 hr 45 min 20 sec). Declare appropriate number of instance member variables and also define instance member functions to set values for time and display values of time.
#include <iostream>
using namespace std;
class Time
{
private:
    int h, m, s;

public:
    void setdata(int x, int y, int z)
    {
        h = x;
        m = y;
        s = z;

        // Handle overflow
        if (s >= 60)
        {
            m += s / 60;
            s %= 60;
        }
        if (m >= 60)
        {
            h += m / 60;
            m %= 60;
        }
    }
    void showdata()
    {
        cout << "Time(Hour:Minute:Second): " << h << ":" << m << ":" << s;
    }
};
int main()
{
    Time t1;
    t1.setdata(10, 50, 75);
    t1.showdata();
    return 0;
} */

/* //! 3. Define a class Date to represent date (like d=31, m=12, y=2022). Declare appropriate number of instance member variables and also define instance member functions to set date and get date.
#include <iostream>
using namespace std;
class Date
{
private:
    int d,m,y;

public:
    void setdata(int day, int month, int year)
    {
        d = day;
        m = month;
        y = year;

    }
    void showdata()
    {
        cout << "d="<<d<<" m="<<m<<" y"<<y;
    }
};
int main()
{
    Date d1;
    d1.setdata(31, 12, 2025);
    d1.showdata();
    return 0;
} */

/* //! 4. In question 3, define methods to display date in the following pattern:
//!    1. 31-12-2022
//!    2. 31-Dec-2022
//question 1:-
#include <iostream>
using namespace std;
class Date
{
private:
    int d, m, y;

public:
    void setdata(int day, int month, int year)
    {
        if (month < 1 || month > 12)
        {
            cout << "Invalid month! Setting default date: 01/01/2000" << endl;
            d = 1;
            m = 1;
            y = 2000;
            return;
        }

        // Days in each month
        int daysInMonth[] = {31, (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (day < 1 || day > daysInMonth[month - 1])
        {
            cout << "Invalid day! Setting default date: 01/01/2000" << endl;
            d = 1;
            m = 1;
            y = 2000;
            return;
        }
        d = day;
        m = month;
        y = year;
    }
    void showdata()
    {
        cout << "Date = " << d << "-" << m << "-" << y;
    }
};
int main()
{
    Date d1;
    d1.setdata(29, 10, 2025);
    d1.showdata();
    return 0;
}
// question 2:-
#include <iostream>
using namespace std;
class Date
{
private:
    int d, m, y;

public:
    void setdata(int day, int month, int year)
    {
        if (month < 1 || month > 12)
        {
            cout << "Invalid month! Setting default date: 01/01/2000" << endl;
            d = 1;
            m = 1;
            y = 2000;
            return;
        }

        // Days in each month
        int daysInMonth[] = {31, (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (day < 1 || day > daysInMonth[month - 1])
        {
            cout << "Invalid day! Setting default date: 01/01/2000" << endl;
            d = 1;
            m = 1;
            y = 2000;
            return;
        }
        d = day;
        m = month;
        y = year;
    }
    void showdata()
    {
        string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        cout << "Date = " << d << "-" << months[m-1] << "-" << y;
    }
};
int main()
{
    Date d1;
    d1.setdata(29, 10, 2025);
    d1.showdata();
    return 0;
}
 */

/* //! 5. Define a class Circle with radius as its property. Provide setRadius() and getRadius() methods. Also define methods to return area and circumference of the circle.
#include <iostream>
using namespace std;
class circle
{
private:
    int r;

public:
    void set_radius(int radius)
    {
        r=radius;
    }
    void get_radius()
    {
        cout<<"Radius: "<<r<<endl;
    }
    float area()
    {
      return 3.14*r*r;
    }
    float circumference()
    {
        return 2*3.14*r;
    }
};
int main()
{
    circle c1;
    c1.set_radius(5);
    c1.get_radius();
    float area_of_circle=c1.area();
    cout<<"Area of Circle: "<<area_of_circle<<endl;;
    float circumference_of_circle=c1.circumference();
    cout<<"Circumference of Circle: "<<circumference_of_circle;
    return 0;
} */