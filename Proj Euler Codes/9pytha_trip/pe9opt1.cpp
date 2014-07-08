# include <iostream>
using namespace std;
int main()
{
 int a,b,c;
 cout<<"enter sum of triplet..";
 cin>>c;
 for(a=3;a<((c-3)/3); a++)     // a>=3
  {
   for(b=a; b<((c-a)/2); b++)
    {
     if((a*a+b*b== (c-a-b)*(c-a-b))&&(a<b<c))
      {
       cout<<a<<" "<<b<<" "<<(c-a-b)<<endl;
       cout<<a*b*(c-a-b);
      }
     else
     {
      cout<<"fuck off\t"<<endl;
     }
    }
  }
return 0;
}
    
       
