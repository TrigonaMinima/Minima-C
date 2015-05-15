/*
* New and Delete with 2D array
* "+" operator overloaded with operator function
* "*" operator overloaded with friend function
* set_new_handler() used
* prefix ++ and postfix ++ operators overloaded
*/


# include <iostream>

using namespace std;

class subscript
{
public:
    int *b;
    subscript(int s)
    {
        b = new int[s];

        for(int i = 0; i < s; i++)
            b[i] = i;
    }

    int getEle(int i)
    {
        return b[i];
    }

    ~subscript()
    {
        delete [] b;
    }

    int operator[](int i)
    {
        if(i < 10)
            return b[i];
        else
        {
            cout << "Out of bounds!!";
            return b[0];
        }
    }
};

int main()
{
    subscript a(10);

    cout << a[1] << endl << a[11];

    return 0;
}