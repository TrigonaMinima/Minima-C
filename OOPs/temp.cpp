/*
* Template sort function
*/

# include <iostream>
# include <stdlib.h>

using namespace std;


template <class T>
void sort(T* arr, int size)
{
    int temp;
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
}


int main()
{
    int *arr = new int[20];
    float *arrf = new float[20];
    for(int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 100;
        arrf[i] = float(rand() % 1000);
    }
    for(int i = 0; i < 20; i++)
        cout << arr[i] << " ";
    cout << endl;
    sort(arr, 20);
    sort(arrf, 20);
    for(int i = 0; i < 20; i++)
        cout << arr[i] << " ";
    cout << endl;
    for(int i = 0; i < 20; i++)
        cout << arrf[i] << " ";
    return 0;
}