/*
* = overloaded
*/

# include <iostream>
# include <string.h>

using namespace std;

class String
{
    char *s;
public:
    String()
    {
        s = new char[20];
    }

    String(char *a)
    {
        s = new char[20];
        strcpy(s, a);
    }

    ~String()
    {
        delete [] s;
    }

    friend String add(String, String);

    String& operator=(String a)
    {
        strcpy(s, a.s);
        return *this;
    }

    void print()
    {
        cout << s << endl;
    }
};

String add(String a, String b)
{
    String temp;
    a.print();
    strcpy(temp.s, a.s);
    temp.print();
    // strcat(temp.s, b.s);
    return temp;
}

int main(int argc, char const *argv[])
{
    String a1("Shivam "), a2("Rana"), a3, a4;

    a1.print();
    a3 = a1;
    a3.print();

    a4 = add(a1, a2);
    a4.print();

    return 0;
}