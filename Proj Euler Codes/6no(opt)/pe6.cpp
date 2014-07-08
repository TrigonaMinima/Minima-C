# include <iostream>
using namespace std;
int main()
{
 int a,c=0,d=0;
 for(a=1;a<=100;a++)
 {
  c+=a;
  d+=(a*a); 
 }
 cout<<(d-(c*c));
}
