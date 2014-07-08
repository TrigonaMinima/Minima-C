# include <iostream>
# include <math.h>
using namespace std;
int main()
{
 int r=0;
 long int a,b,c,d=5;
 for(c=5;c<2000000; c++ )
 {
  for(a=2;a<=(sqrt(c));a++)
   {
    if(c%a!=0)
     r=1;
    else
     {
      r=0;
      break;
     }
   }
  if(r==1)
   d+=c;
 }
 cout<<d<<endl;
 return 0;
}  
    
