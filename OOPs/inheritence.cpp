/*
* Inheritance
*/


# include <iostream>

using namespace std;

class vehicle
{
    string name;
    int wheels;
public:
    vehicle(string n, int w)
    {
        name = n;
        wheels = w;
    }

    string getname()
    {
        return name;
    }

    int getwheels()
    {
        return wheels;
    }

    void print()
    {
        cout << name << "with " << wheels << " wheels.\n";
    }
};

class lmv : public vehicle
{
    float speed;
    int load;
public:
    lmv(string n, int w, float v, int l) : vehicle(n, w)
    {
        speed = v;
        load = l;
    }

    void print()
    {
        cout << "\n\nLMV with-\n" << "Speed - " << speed << "\nLoad Capacity - " << load;
        cout << "\nName - " << getname() << "\nWheels - " << getwheels();
    }
};

class hmv : public vehicle
{
    float speed;
    int load;
    int permit;
public:
    hmv(string n, int w, float v, int l, int p) : vehicle(n, w)
    {
        speed = v;
        load = l;
        permit = p;
    }

    void print()
    {
        cout << "\n\nHMV with-\n" << "Speed - " << speed << "\nLoad Capacity - " << load << "\nPermit - " << permit;
        cout << "\nName - " << getname() << "\nWheels - " << getwheels();
    }
};

int main()
{
    lmv a("Cycle", 2, 30, 10);
    hmv b("Truck", 8, 120, 1000, 12);

    a.print();
    b.print();
    return 0;
}