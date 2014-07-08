# include <iostream>
using namespace std;
int main()
{
long a=0,b=1,c=0,d=0;
for(;d<4000000;)
 {
 d=a+b;
 a=b;
 b=d;
 cout<<d<<endl;
 if(d % 2==0)
  c+=d;
 }
cout<<"the sum is :"<<c;
}
