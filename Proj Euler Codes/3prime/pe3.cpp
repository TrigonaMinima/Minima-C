# include <iostream>
using namespace std;
int main()
{
long int j,i=600851475143;
for(j=2;j<i/2;j++)
 {
  if(i%j==0)
   cout<<j<<endl;
 }
return 0;
}
