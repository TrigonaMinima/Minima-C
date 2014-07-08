# include <iostream>

using namespace std;


int
div(int a, int *num1, int *num2)
{
	int l=2;
	while(l<a)
	{
		while(*num1 % l == 0 && * num2 % l == 0)
		{
			(*num1)/= l;
			(*num2)/= l;
		}
		l++;
	}
	return 0;
}



int
main()
{
	int i, j, a, b, c, d, e, f, l, m=1, n=1;
	for(i=11; i<100; i++)
	{
		for(j=i+1; j<100; j++)
		{
			a = i/10;
			b = i%10;
			c = j/10;
			d = j%10;
			e=i;
			f=j;
			if(a==c && a!=0)
			{
				div(j, &e, &f);
				div(10, &b, &d);
				if(b==e && d==f)
				{
					cout<<"["<<e<<"/"<<f<<"  --- "<<i<<"/"<<j<<"]"<<endl;
					m*= e;
					n*= f;
				}
			}
			if(a==d && a!=0)
			{
				div(j, &e, &f);
				div(10, &b, &c);
				if(b==e && c==f)
				{
					cout<<"["<<e<<"/"<<f<<"  --- "<<i<<"/"<<j<<"]"<<endl;
					m*= e;
					n*= f;
				}
			}
			if(b==c && b!=0)
			{
				div(j, &e, &f);
				div(10, &a, &d);
				if(a==e && d==f)
				{
					cout<<"["<<e<<"/"<<f<<"  --- "<<i<<"/"<<j<<"]"<<endl;
					m*= e;
					n*= f;
				}
			}
			if(b==d && b!=0)
			{
				div(j, &e, &f);
				div(10, &a, &c);
				if(a==e && c==f)
				{
					cout<<"["<<e<<"/"<<f<<"  --- "<<i<<"/"<<j<<"]"<<endl;
					m*= e;
					n*= f;
				}
			}
		}
	}
	div(10, &m, &n);
	cout<<"["<<m<<"/"<<n<<"]"<<endl;
	return 0;
}
