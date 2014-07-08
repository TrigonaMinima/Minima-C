# include <iostream>
using namespace std;
int sumdiv(int n, int tar)
{
 float sum;
 float p=tar/n;
 sum=n*((p*(p+1))/2);
 return sum;
}
int main()
{
 int tar;
 cout<<"input range ";
 cin>>tar;
 float sum=sumdiv(3,tar)+sumdiv(5,tar)-sumdiv(15,tar);
 cout<<"sum is : "<<sum;
 return 0;
}
