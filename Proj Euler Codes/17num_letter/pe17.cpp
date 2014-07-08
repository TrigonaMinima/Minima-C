/*
 * number letter count.
 */
 
 
 # include <iostream>
 using namespace std;
 int
 main()
 {
 	int dig[9] = {3,3,5,4,4,3,5,5,4};
 	int ten[10] = {0,3,6,6,5,5,5,7,6,6};
	int ele[9] = {6,6,8,8,7,7,9,8,8};
 	int num, num1, j=999, sum=11+891*3;
 	cout<<sum<<endl;
 	while(j>0)
 	{
 		num = j;
 		while(1)
 		{
 			if(num >= 100)
 			{
 				num1 = num/100;
 				num%= 100;
 				sum+= dig[num1-1]+7;
 			}
 			else
 			{
 				if(num>10 && num<20)
 				{
 					sum+= ele[num-11];
 					break;
 				}
 				else
 				{
 					num1 = num/10;
 					num%= 10;
 					if(num != 0)
 						sum+= ten[num1]+dig[num-1];
 					else
 						sum+= ten[num1];
 					break;
 				}
 			}
 		}
		j--;
 	}
 	cout<<sum<<endl;
 	return 0;
 }
