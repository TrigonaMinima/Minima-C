# include <iostream>
using namespace std;

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT} days;

inline days operator+ (days d)
{
	return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

inline ostream& operator<< (ostream& out, days d)
{
	switch(d)
	{
		case SUN : out<<"SUN";
					break;
		case MON : out<<"MON";
					break;
		case TUE : out<<"TUE";
					break;
		case WED : out<<"WED";
					break;
		case THU : out<<"THU";
					break;
		case FRI : out<<"FRI";
					break;
		case SAT : out<<"SAT";
					break;
	}
	return out;
}

int main()
{
	cout << "After sunday comes - \n";
	for(int i =0; i<9; i++)
		cout << +days(i)<< endl ;
	cout << "\n\n" << +THU << '\t'<< "sdfs" << endl;
	return 0;
}
