/*
* New and Delete with 2D array
* "+" operator overloaded with operator function
* "*" operator overloaded with friend function
* set_new_handler() used
* prefix ++ and postfix ++ operators overloaded
*/

# include <iostream>
# include <cstdlib>
# include <iomanip>

using namespace std;
int max = 100;

void out_of_memory()
{
    cout << "Out of memory!";
    exit(1);
}

class matrix
{
    int** mat, size;
public:
    matrix(int s)
    {
        size = s;
        mat = new int*[size];

        for(int i = 0; i < size; i++)
            mat[i] = new int[size];

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                mat[i][j] = i + j;
        }
    }

    ~matrix()
    {
        for(int i = 0; i < size; i++)
            delete [] mat[size];
    }
    // prefix
    matrix operator++();
    // postfix
    matrix operator++(int);

    matrix operator+(matrix m2)
    {
        matrix m(10);
        for(int i = 0; i < m.size; i++)
        {
            for(int j = 0; j < m.size; j++)
                m.mat[i][j] = mat[i][j] + m2.mat[i][j];
        }
        return m;
    }

    friend matrix operator*(matrix m1, matrix m2);

    friend ostream operator<<(ostream& obj, matrix m);

    void print()
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                cout << setw(3) << mat[i][j] << " ";
            cout << endl;
        }
        cout << "++++\n";
    }
};

matrix operator*(matrix m1, matrix m2)
{
    matrix m(10);
    for(int i = 0; i < m.size; i++)
    {
        for(int j = 0; j < m.size; j++)
            m.mat[i][j] = m1.mat[i][j] * m2.mat[i][j];
    }
    return m;
}

matrix matrix::operator++()
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            ++mat[i][j];
    }
    return *this;
}

matrix matrix::operator++(int)
{
    matrix m(10);
    m.mat = mat;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            ++mat[i][j];
    }
    return m;
}

ostream matrix::operator<<(ostream& obj, matrix m)
{
    for(int i = 0; i < m.size; i++)
    {
        for(int j = 0; j < m.size; j++)
            obj << setw(3) << m.mat[i][j] << " ";
        obj << endl;
    }
    obj << "++++\n";
    return obj;
}



int main()
{
    set_new_handler(out_of_memory);

    matrix m1(10), m2(10), m3(10), m4(10);
    m1.print();
    m2.print();

    m3 = m1 + m2;
    m3.print();

    m4 = m1 * m2;
    m4.print();
    m1.print();
    m2.print();

    ++m1;
    m1.print();

    m2++;
    m2.print();

    cout << m4;

    return 0;
}