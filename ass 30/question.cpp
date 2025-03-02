// TODO: C++ Assignment 2

// TODO: Assignment-30: Functions in C++

/* //! 1. Define a function to check whether a given number is a Prime number or not.
#include <iostream>
using namespace std;
void check_prime(int num)
{
    int i;
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << "This not prime Number";
            break;
        }
    }
    if (i == num)
        cout << "This is prime number:";
}
int main()
{
    int num, i;
    cout << "Enter a Number: ";
    cin >> num;
    check_prime(num);
    return 0;
} */

/*  //! 2. Define a function to find the highest value digit in a given number.
#include <iostream>
using namespace std;

void highest_value_digit(int num)
{
    // Handle negative numbers
    if (num < 0) {
        num = -num;
    }

    int max = 0;  // Start with the smallest possible digit
    while (num > 0) {
        int digit = num % 10;  // Get the last digit
        if (digit > max) {
            max = digit;  // Update max if the current digit is greater
        }
        num /= 10;  // Remove the last digit
    }
    cout << "Highest value digit: " << max << endl;
}

int main()
{
    int num;
    cout << "Enter a Number: ";
    cin >> num;
    highest_value_digit(num);
    return 0;
} */

/* //! 3. Define a function to calculate x raised to the power y.
#include <iostream>
using namespace std;
void raised_power(int num,int power)
{
    int  result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= num;
    }
    cout << num << " raised to the power " << power << " is: " << result;
}
int main()
{
    int num, power;
    cout << "Enter Number: ";
    cin >> num;
    cout << "Enter Power: ";
    cin >> power;
    raised_power(num,power);
    return 0;
} */

/* //! 4. Define a function to print Pascal Triangle up to N lines.
#include <iostream>
using namespace std;

// Function to print Pascal's Triangle
void pascal_triangle(int n)
{
    for (int line = 1; line <= n; line++)
    {
        int C = 1; // Used to represent C(line, i)
        for (int i = 1; i <= n - line; i++)
        {
            cout << " "; // Print leading spaces for alignment
        }
        for (int i = 1; i <= line; i++)
        {
            cout << C << " ";       // Print the current value of C
            C = C * (line - i) / i; // Calculate the next value of C
        }
        cout << endl; // Move to the next line
    }
}

int main()
{
    int n;
    cout << "Enter Number of lines: ";
    cin >> n;
    pascal_triangle(n);
    return 0;
}/*

#include <iostream>
using namespace std;

// Function to calculate binomial coefficient (nCr)
int binomialCoeff(int n, int r) {
    int res = 1;
    if (r > n - r)
        r = n - r; // Since C(n, r) == C(n, n-r)

    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to print Pascal's Triangle
void pascal_triangle(int n) {
    for (int i = 0; i < n; i++) {
        // Print spaces for alignment
        for (int j = 0; j < n - i - 1; j++)
            cout << "  ";

        // Print Pascal's Triangle values
        for (int j = 0; j <= i; j++)
            cout << binomialCoeff(i, j) << "   ";

        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter Number of lines: ";
    cin >> n;
    pascal_triangle(n);
    return 0;
} */

/* //! 5. Define a function to check whether a given number is a term in a Fibonacci series or not.
#include <iostream>
using namespace std;
int check_Fibonacci_series(int num)
{
    int a = -1, b = 1, c = a + b;
    for (int i = 0; c <= num; i++)
    {
        if (num == c)
            return 1;
        a = b;
        b = c;
        c = a + b;
    }
    return 0;
}
int main()
{
    int num;
    cout << "Enter a Number: ";
    cin >> num;
    int check = check_Fibonacci_series(num);
    if (check != 0)
        cout << num << " is in Fibonaccie series." << endl;
    else
        cout << num << " is not in Fibonaccie series." << endl;
    return 0;
} */

/*  //! 6. Define a function to swap data of two int variables using call by reference.
#include <iostream>
using namespace std;
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Original a: " << a << " b: " << b << endl;
    swap(a, b);
    cout << "After Swapping a: " << a << " b: " << b << endl;
    return 0;
} */

/* //! 7. Write a function using the default argument that is able to add 2 or 3 numbers.
#include <iostream>
using namespace std;
void add(int a,int b, int c=0)
{
    int sum;
    sum=a+b+c;
    cout<<"Sum: "<<sum;
}
int main()
{
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b>>c;
    add(a,b);
    add(a,b,c);
    return 0;
} */

/* //! 8. Define overloaded functions to calculate the area of a circle, the area of a rectangle, and the area of a triangle.
#include <iostream>
using namespace std;
float area(float r)
{
    float circle_area = 3.14 * r * r;
    return circle_area;
}
int area(int a, int b)
{
    return a * b;
}
float area(float b, float h)
{
    return (b * h) / 2;
}
int main()
{
    float r;
    cout << "Enter Radius: ";
    cin >> r;
    float area_of_circle = area(r);
    printf("Area of circle: %.2f\n", area_of_circle);

    int a, b;
    cout << "Enter length and width of ractangle: ";
    cin >> a >> b;
    int area_of_rectangle = area(a, b);
    printf("Area of rectangle: %d\n", area_of_rectangle);

    float base, height;
    cout << "Enter Base and height of triangle: ";
    cin >> base >> height;
    float area_of_triangle = area(base, height);
    printf("Area of triangle: %.2f\n", area_of_triangle);

    return 0;
}
 */

/* //! 9. Write functions using function overloading to find the maximum of two numbers where both numbers can be integers or real.
#include <iostream>
using namespace std;
int max(int x,int y)
{
    return x>y?x:y;
}
float max(float x,float y)
{
    return x>y?x:y;
}
int main()
{
    int a,b;
    float x,y;
    cout<<"Enter int values: ";
    cin>>a>>b;
    int max_int=max(a,b);
    cout<<"Max number: "<<max_int<<endl;

    cout<<"Enter float values: ";
    cin>>x>>y;
    float max_float=max(x,y);
    cout<<"Max number: "<<max_float;
    return 0;
} */

/* //! 10. Write functions using function overloading to add two numbers having different data types.
#include <iostream>
using namespace std;
int add(int x,int y)
{
    return x+y;
}
float add(float x,float y)
{
    return x+y;
}
int main()
{
    int a,b;
    float x,y;
    cout<<"Enter int values: ";
    cin>>a>>b;
    int sum_of_int=add(a,b);
    cout<<"sum: "<<sum_of_int<<endl;

    cout<<"Enter float values: ";
    cin>>x>>y;
    float sum_of_float=add(x,y);
    cout<<"sum: "<<sum_of_float;
    return 0;
} */