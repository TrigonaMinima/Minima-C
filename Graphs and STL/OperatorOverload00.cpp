// unary plus

# include <iostream>
using namespace std;

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT} days;

inline days operator+ (days d)
{
	return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

int main()
{
	for(int i =0; i<9; i++)
		cout << +days(i)<< endl;
//	cout<< +SUN;
/*	if(+SUN == MON)
		cout<<"\nTrue"; */
	cout << "\n\n" << +5344;
	return 0;
}
