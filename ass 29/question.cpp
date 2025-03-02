// TODO: C++ Assignment 1

// TODO: Assignment-29: Basics of C++

/* //! 1. Write a C++ program to print Hello MySirG on the screen.
#include<iostream>
using namespace std;
int main()
{
    cout<<"Hello MySirG";
    return 0;
} */

/* //! 2. Write a C++ program to print Hello on the first line and MySirG on the second line using endl.
#include<iostream>
using namespace std;
int main()
{
    cout<<"Hello"<<endl<<"MySirG";
    return 0;
} */

/* //! 3. Write a C++ program to calculate the sum of two numbers.
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter two Numbers: "<<endl;
    cin>>a>>b;
    cout<<"Sum of "<<a<<" and "<<b<<" is "<<a+b<<endl;
    return 0;
} */

/* //! 4. Write a C++ program to calculate the area of a circle.
#include<iostream>
using namespace std;
int main()
{
    float r;
    cout<<"Enter radius Of circle: ";
    cin>>r;
    cout<<"Area of circle is "<< 3.14*r*r;
    return 0;
} */

/* //! 5. Write a C++ program to calculate the volume of a cuboid.
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter Length, Width and Height of Cuboid: ";
    cin>>a>>b>>c;
    cout<<"Volume of Cuboid is "<< a*b*c;
    return 0;
} */

/* //! 6. Write a C++ program to calculate an average of 3 numbers.
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    float avr;
    cout<<"Enter Three Numbers: ";
    cin>>a>>b>>c;
    avr =(a+b+c)/3.0;
    cout<<"Average of Three Numbers is "<< avr;
    return 0;
} */

/* //! 7. Write a C++ program to calculate the square of a number.
#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"Enter a Number: ";
    cin>>a;
    cout<<"Squre of "<<a<<" is "<< a*a;
    return 0;
} */

/* //! 8. Write a C++ program to swap values of two int variables without using a third variable.
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter Two Numbers: ";
    cin>>a>>b;
    a=a+b-(b=a);
    cout<<"After swapping: "<<a<<" "<<b;
    return 0;
} */

/* //! 9. Write a C++ program to find the maximum of two numbers.
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter Two Numbers: ";
    cin>>a>>b;
    cout<<"Max Number: "<<(a>b?a:b);
    return 0;
} */

/* //! 10. Write a C++ program to add all the numbers of an array of size 10.
#include<iostream>
using namespace std;
int main()
{
    int a[10],add=0;
    cout<<"Enter 10 Numbers: ";
    for(int i=0;i<10;i++)
    {
         cin>>a[i];
         add+=a[i];
    }
    cout<<"Sum of 10 Numbers: "<<add; 
    return 0;
} */
