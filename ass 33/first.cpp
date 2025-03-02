#include <iostream>
using namespace std;
class Matrix
{
private:
    int mat[3][3];

public:
    void setdata(int a[3][3]);
    void showdata();
    Matrix add(Matrix);
    Matrix sub(Matrix);
    Matrix multiply(Matrix);
    Matrix transpose();
    bool is_singular();
};
bool Matrix::is_singular()
{
    int det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
              mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
              mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

    if (det == 0)
        return true;
    else
        return false;
}
Matrix Matrix::transpose()
{
    Matrix temp;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.mat[i][j] = mat[j][i];
        }
    }
    return temp;
}
Matrix Matrix::multiply(Matrix m)
{
    Matrix temp;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.mat[i][j] = (mat[i][0] * m.mat[0][j]) + (mat[i][1] * m.mat[1][j]) + (mat[i][2] * m.mat[2][j]);
        }
    }
    return temp;
}
Matrix Matrix::sub(Matrix m)
{
    Matrix temp;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.mat[i][j] = mat[i][j] - m.mat[i][j];
        }
    }
    return temp;
}
Matrix Matrix::add(Matrix m)
{
    Matrix temp;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            temp.mat[i][j] = mat[i][j] + m.mat[i][j];
        }
    }
    return temp;
}
void Matrix::setdata(int a[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat[i][j] = a[i][j];
        }
    }
}
void Matrix::showdata()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Matrix m1, m2, m3;
    int a1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int a2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    m1.setdata(a1);
    m2.setdata(a2);
    cout << "Matrix 1:" << endl;
    m1.showdata();
    cout << "Matrix 2:" << endl;
    m2.showdata();
    cout << "add:" << endl;
    m3 = m1.add(m2);
    m3.showdata();
    cout << "Sub:" << endl;
    m3 = m1.sub(m2);
    m3.showdata();
    cout << "Multiply:" << endl;
    m3 = m1.multiply(m2);
    m3.showdata();
    cout << "Transpose:" << endl;
    m3 = m1.transpose();
    m3.showdata();
    cout << "Is singular:" << endl;
    if (m1.is_singular())
        cout << "This Matrix is singular.";
    else
        cout << "This Matrix is not singular.";

    return 0;
}