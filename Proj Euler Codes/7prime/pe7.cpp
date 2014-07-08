# include <iostream>
# include <math.h>
using namespace std;
int main()
{
 int r=0;
 long int a,b,c,d=2;
 for(c=5;d<10002; c++ )
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
   d+=1;
 if(d==10001)
 { 
  cout<<c<<endl;
  break;
 }
}
 return 0;
}  
    
