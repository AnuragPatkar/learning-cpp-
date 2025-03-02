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
}