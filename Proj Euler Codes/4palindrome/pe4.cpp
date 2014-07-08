# include <iostream>
using namespace std;
int main()
{
int i,j,k,l=0;
for(i=100; i<=999; i++)
 {
  for(j=100; j<=999; j++)
   {
    k=i*j;
    if(k>l)
    {
    if(k/100000==k%10)
     { if(((k%100000)/10000)==(k%100)/10)
      { if((((k%100000)%10000)/1000)==((k%1000)/100))
        {l=k;
       cout<<"palindrome : "<<i<<"*"<<j<<" ="<<k<<endl;}
      }
     }
    }
   }
  }
  return 0;
 }
