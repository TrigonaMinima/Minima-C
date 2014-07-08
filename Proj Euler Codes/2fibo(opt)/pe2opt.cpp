# include <iostream>
using namespace std;
int main()
{
int a=1,b=1,c=0;
int d=0;
while(c<4000000)
 {
 d+=c;
 a=b+c;
 b=c+a;
 c=a+b;
 }
cout<<"the sum is :"<<d;
}
