# include <iostream>
using namespace std;
int main()
{
 int a,b,c;
 c=1000;
 for(a=1;a<500; a++)
  {
   for(b=a; b<500; b++)
    {
     if((a*a+b*b== (c-a-b)*(c-a-b))&&(a<b<c))
      {
       cout<<a<<" "<<b<<" "<<(c-a-b)<<endl;
       cout<<a*b*(c-a-b);
      }
    }
  }
return 0;
}
    
       
