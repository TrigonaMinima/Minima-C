/*
* Template sort function
*/

# include <iostream>
# include <stdlib.h>

using namespace std;

template <class T>
class sort
{
    T *arr;
    int size;
public:
    sort(int s)
    {
        size = s;
        arr = new T[size];
        for (int i = 0; i < size; ++i)
            arr[i] = rand() % 100;
    }

    ~sort()
    {
        delete [] arr;
    }

    void sorting()
    {
        T temp;
        for(int i = 0; i < size; i++)
        {
            for(int j = 1; j < size-i; j++)
            {
                if(arr[j] < arr[j-1])
                {
                    temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
        print();
    }

    void print()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    sort<int>a(10);
    sort<float>b(10);

    a.print();
    b.print();

    a.sorting();
    b.sorting();

    return 0;
}