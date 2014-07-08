# include <iostream>
using namespace std;
int trino(unsigned long int n)
{
 return (n*(n+1)/2);
}
int divisors(unsigned long int n)
{
 long int i;
 int div=2;
 for(i=2;i<=n/2;i++)
  {
   if(n%i==0)
    div++;
  }
 return div;
}
int main()
{
 unsigned long int a;
 unsigned long int tno,d;
 for(a=2;;a++)
  {
   tno=trino(a);
   d=divisors(tno);
   if(d>=500)
    {
     cout<<a<<" "<<tno<<" "<<d<<endl;
     break;
    }
  }
 return 0;
}
