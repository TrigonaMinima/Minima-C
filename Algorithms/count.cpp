/*
* Count Sort (Bucket is very similar)
*/

# include <iostream>

using namespace std;

void count_sort(int *arr, int size, int start, int end)
{
    // Creates a bucket of the size (end - start + 1) to hold the count
    // of the occurrence of the array elements in the range. King of like
    // the frequency.
    int *bucket = new int[end - start + 1];
    for(int i = 0; i < (end - start + 1); i++)
        bucket[i] = 0;

    for (int i = 0; i < size; ++i)
        bucket[arr[i] - start] += 1;

    // prints the sorted array.
    for (int i = 0; i < (end - start + 1); ++i)
    {
        for(int j = 0; j < bucket[i]; j++)
            cout << (i + start) << " ";
    }
}

int main(int argc, char const *argv[])
{
    int *arr, s, start, end;

    cout << "Enter the size of array: ";
    cin >> s;
    arr = new int[s];
    cout << "Enter the ranges (start, end): ";
    cin >> start >> end;

    cout << "Enter the elements-\n";
    for (int i = 0; i < s; ++i)
        cin >> arr[i];

    count_sort(arr, s, start, end);
    return 0;
}