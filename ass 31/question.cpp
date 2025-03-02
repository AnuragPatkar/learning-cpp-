// TODO: C++ Assignment 3

// TODO: Assignment-31: More on Functions in C++

/* //! 1. Define a function to sort an array of integers in ascending or descending order depending on bool type argument (true for ascending and false for descending). Use default argument to implement it.
#include <iostream>
using namespace std;
void sort_array(int arr[], int num, bool ascending = true)
{
    int i, j, temp;
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ascending == true)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            else
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }

        }
    }
}
int main()
{
    int arr[5];
    cout << "Enter Elements: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    cout << "Original Array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort_array(arr, 5,false);
    cout << "Descending Order: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort_array(arr, 5);
    cout << "Ascending Order: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
} */

/* //! 2. Define a function to sort an array of strings in ascending or descending order depending on bool type argument (true for ascending and false for descending). Use default argument to implement it.
#include <iostream>
#include <string.h>
using namespace std;
void sort_string(char str[], int num, bool ascending = true)
{
    int i, j, temp;
    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if ((ascending && str[i] > str[j]) || (!ascending && str[i] < str[j]))
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
int main()
{
    char str[20];
    cout << "Enter string: ";
    cin.getline(str, sizeof(str));
    cout << "You Enterd: " << str << endl;
    sort_string(str, strlen(str));
    cout << "Sorted string in ascending order: " << str << endl;
    sort_string(str, strlen(str), false);
    cout << "Sorted string in Descending order: " << str << endl;
    return 0;
} */

/* //! 3. Define a function to rotate an array by n positions in the d direction. Implement position and direction using default arguments. Argument d can be -1 or 1 denoting left or right direction. Argument n should be the last argument with default value 1.
#include <iostream>
using namespace std;
void rotate_array(int arr[], int size, int p, int d)
{
    int new_arr[size];
    int i, j, temp;
    if (d == 1)
    {
        for (i = 0; i < size; i++)
        {
            if (i < p)
                new_arr[i] = arr[size - p + i];
            else
                new_arr[i] = arr[i - p];
        }
        
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            if (i < size - p)
                new_arr[i] = arr[p + i];
            else
                new_arr[i] = arr[i - p - 1];
        }
    }
    for (i = 0; i < size; i++)
        {
            cout << new_arr[i] << " ";
        }
}

int main()
{
    int position_num, direction;
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Enter position number: ";
    cin >> position_num;
    cout << "Enter direction (-1 for left, 1 for right): ";
    cin >> direction;

    rotate_array(arr, 5, position_num, direction);
    return 0;
}

#include <iostream>
using namespace std;

void rotate_array(int arr[], int size, int d = 1, int n = 1)
{
    int new_arr[size];
    n = n % size; // Handle cases where n > size

    if (d == 1)
    { // Right rotation
        for (int i = 0; i < size; i++)
        {
            new_arr[(i + n) % size] = arr[i];
        }
    }
    else
    { // Left rotation
        for (int i = 0; i < size; i++)
        {
            new_arr[i] = arr[(i + n) % size];
        }
    }

    // Print rotated array
    for (int i = 0; i < size; i++)
    {
        cout << new_arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    // Default values: rotate right by 1
    rotate_array(arr, 5);

    // Rotate left by 2
    rotate_array(arr, 5, -1, 2);

    // Rotate right by 3
    rotate_array(arr, 5, 1, 3);

    return 0;
} */

/* //! 4. Define a function to calculate LCM of three numbers.
#include <iostream>
using namespace std;
void lcm(int a, int b, int c)
{
    int i, max;
    max = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    for (i = max; i <= a * b * c; i++)
    {
        if (i % a == 0 && i % b == 0 && i % c == 0)
        {
            cout << "Lcm of " << a << "," << b << "," << c << "," << "is: " << i << endl;
            break;
        }
    }
}
int main()
{
    int a, b, c;
    cout << "Enter three Numbers: ";
    cin >> a >> b >> c;
    lcm(a, b, c);
    return 0;
} */

/* //! 5. Define a function to print all the prime factors of a given number. [For example, num = 36, prime factors are 2, 3]
#include <iostream>
using namespace std;
void prime_factor(int a)
{
    int i;
    for (i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            cout << i<<" ";
            a /=i;
            i--;
        }
    }
}
int main()
{
    int a;
    cout << "Enter a number: ";
    cin >> a;

    prime_factor(a);
    return 0;
} */

/* //! 6. Define a function to calculate HCF of two numbers.
#include <iostream>
using namespace std;
void hcf(int a, int b)
{
    int i, max;
    max = a > b ? a : b;
    for (i = max; i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            cout << "HCF of " << a << "," << b << " : " << i << " ";
            break;
        }
    }
}
int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    hcf(a, b);
    return 0;
} */

/* //! 7. Define overloaded functions to calculate the volume of a cuboid, cone, and sphere.
#include <iostream>
using namespace std;
int volume(int a, int b, int c)
{
    return a * b * c;
}
float volume(float r,float h)
{
    return 3.14*r*r*h/3;
}
float volume(float r)
{
    return 3.14*r*r*r*4/3;
}
int main()
{
    int a, b, c;
    cout << "Enter length,width and height: ";
    cin >> a >> b >> c;

    int volume_of_cuboid = volume(a, b, c);
    cout << "Volume of Cuboid: " << volume_of_cuboid << endl;

    float r, h;
    cout << "Enter radius and length of cone: ";
    cin >> r >> h;

    float volume_of_cone = volume(r,h);
    cout << "Volume of Cone: " << volume_of_cone << endl;

    
    cout << "Enter radius of sphere: ";
    cin >> r ;

    float volume_of_sphere = volume(r);
    cout << "Volume of Cone: " << volume_of_sphere << endl;
    return 0;
} */

/* //! 8. Define a function to print a substring from startIndex (inclusive) to endIndex (exclusive). Define the function in such a way that if the second argument is not provided, the string will print till the last possible index.
#include <iostream>
#include <string.h>
using namespace std;
void substring(char str[], int size, int start_index, int end_index)
{
    if (start_index < 0 || end_index > size || start_index > end_index)
    {
        cout << "Invalid indices!" << endl;
        return;
    }

    int i;
    for (i = start_index; i < end_index; i++)
    {
        cout << str[i];
    }
}
int main()
{
    int start_index, end_index;
    char str[20];
    cout << "Enter string: ";
    cin.getline(str, 20);

    cout << "Enter start index: ";
    cin >> start_index;

    cout << "Enter end index: ";
    cin >> end_index;
    substring(str, strlen(str), start_index, end_index);
    return 0;
} */

/* //! 9. Define a function to swap two arrays.
#include <iostream>
#include <string.h>
using namespace std;
void swap_array(int a1[], int a2[], int size)
{
    int i, temp;
    for (i = 0; i < size; i++)
    {
        temp=a1[i];
        a1[i]=a2[i];
        a2[i]=temp;
    }
}
int main()
{
    int a1[5], a2[5];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> a1[i];
    }
    cout << endl;
    cout << "Enter elements of second array: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> a2[i];
    }

    swap_array(a1, a2, 5);
    cout<<"After swapping: ";
    cout<<"first array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a1[i] << " ";
    }
    cout<<"second array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << a2[i] << " ";
    }
    return 0;
} */

/* //! 10. Define a function to merge two sorted arrays of the same size.
#include <iostream>
#include <string.h>
using namespace std;
void swap_array(int a1[], int a2[], int size, int a3[], int s3)
{
    int i, temp;
    for (i = 0; i < s3; i++)
    {
        if(i<size)
          a3[i]=a1[i];
        else
          a3[i]=a2[i-size];
    }
}
int main()
{
    int a1[5], a2[5], a3[10];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> a1[i];
    }
    cout << endl;
    cout << "Enter elements of second array: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> a2[i];
    }

    swap_array(a1, a2, 5, a3, 10);
    cout << "After merge: ";
    for (int i = 0; i < 10; i++)
    {
        cout << a3[i] << " ";
    }
    return 0;
} */