# include <iostream>
using namespace std;

template <class T>
T output(const T arr[], int size, T sub = 0)
{
	for(int i = 0; i<size; i++)
	{
		sub-= arr[i];
		cout<<arr[i]<<" ";
	}
	return sub;
}

int main()
{
	int a[] = {1,2,3,4,54,5,5,6,7,8,9,0,-0,-3};
	cout << "\n" << output(a, 14);
	return 0;
}
