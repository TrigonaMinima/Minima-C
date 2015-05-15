/*
* Constructor and Destructor
* Static data member
* Static member function
*/

# include <iostream>

using namespace std;

class count
{
    int a;
public:
    static int cnt;

    count()
    {
        cnt++;
        cout << "Constructor " << cnt << " callled.\n";
    }

    ~count()
    {
        cnt--;
        cout << "Destructor " << cnt << " callled.\n";
    }

    static void getC()
    {
        cout << "The count is: " << cnt << endl;
    }
};

int count :: cnt = 0;


int main(int argc, char const *argv[])
{
    count::getC();
    count();
    count a;
    a.getC();
    a.~count();
    // count a, b;
    // {
    //     count e, f;
    // }
    // count c, d;
    return 0;
}