# include <fstream.h>
# include <conio.h>
# include <stdio.h>
# include <process.h>
# include <string.h>
void welcome_screen()
  {
  clrscr();
  cout<<"******************* W E L C O M E  *********************** \n\n\n";
  cout<<" D A T A  M A N A G E M E N T  S O F T W A R E  \n\n\n";
  cout<<" D O N E  B Y :  \n";
  cout<<" S H I V A M   R A N A \n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout<<" ****press any key to continue***";
  getch();
  return;
  }
class directory
  {
  public:
  int record,age;
  long pn1,pn2;
  char name[20],occupation[25],address1[75],address2[75],emailadd[25];
  char faxadd[25],check(char *);
  void menu();
  void addition();
  void init();
  void delette();
  void view1();
  void modification();
  void view();
  void search();
  int  no_of_records();
  }obj;
void  directory::menu()
  {
  clrscr();
  char ch;
  cout<<"*******MENU*********\n";
  cout<<endl;
  cout<<" 1: ADDITION(a/A)     \n";
  cout<<" 2: DELETION(d/D)     \n";
  cout<<" 3: MODIFICATION(m/M) \n";
  cout<<" 4: VIEW(v/V)         \n";
  cout<<" 5: SEARCH(s/S)       \n";
  cout<<" 6: NO OF RECORDS(n/N)\n";
  cout<<" 7: EXIT(e/E)         \n";
  ch=getch();
  switch(ch)
	{
	case 'a':
	case 'A':
				obj.addition();
				break;
	case 'd' :
	case 'D' :
				obj.delette();
				break;
	case 'm':
	case 'M':
			  obj.modification();
			  break;
	case 'v':
	case 'V':
			  obj.view();
			  break;
	case 's':
	case 'S':
			  obj.search();
			  break;
	case 'n':
	case 'N':
			  obj.no_of_records();
			  char ch;
			  cout<<"\n\n\n\ndo you want to return to the menu(m/M) or exit(e/E) ??????? ";
			  cin>>ch;
			  switch(ch)
				{
				case 'm':
				case 'M':
						  menu();
						  break;
				case 'e':
				case 'E':
						  exit(0);
				}
			  break;
	case 'e':
	case 'E':
			  exit(0);
	}
  }
void directory::addition()  //ADDING  INFORMATION
  {
  start:
  ofstream fout;
  fout.open("addbuk.txt",ios::binary|ios::app);
  init();
  fout.write((char*)&obj,sizeof(obj));
  fout.close();
  char l;
  cout<<"want to enter more ??(y/n)" ;
  cin>>l;
  if(l=='y')
	goto start;
  char r;
  cout<<"do you want to return to the menu(m/M) or exit(e/E) ??????? ";
  cin>>r;
  switch(r)
	{
	 case 'm':
	 case 'M':
				menu();
				break;
	 case 'e':
	 case 'E':
				exit(0);
	 }
  }
void directory::init()  // ENTERING THE DETAILS
  {
  clrscr();
  char ch;
  cout<<" ***********ADDITION*********** ";
  cin.get(ch);
  cout<<" \n ENTER NAME                : ";
  cin.getline(name,20);
  cout<<" \n ENTER THE OCCUPATION      : ";
  cin.getline(occupation,20);
  cout<<" \n ENTER HOUSE ADDRESS       : ";
  cin.getline(address1,50);
  cout<<" \n ENTER HOUSE PHONE NUMBER  : ";
  cin>>obj.pn1;
  cin.get(ch);
  cout<<" \n ENTER OFFICE ADDRESS      : ";
  cin.getline(address2,50);
  cout<<" \n ENTER OFFICE PHONE NUMBER : ";
  cin>>pn2;
  cin.get(ch);
  cout<<" \n ENTER EMAIL ADDRESS       : ";
  cin.getline(emailadd,25);
  cout<<" \n ENTER FAX NUMBER          : ";
  gets(faxadd);
  return;
  }
void  directory::delette()      //DElETION OF RECORDS
  {
  start:
  clrscr();
  cout<<"**********DELETION**********";
  int n;
  fstream fin;
  fstream fout;
  fin.open("addbuk.txt",ios::binary|ios::in);
  fout.open("new.txt",ios::binary|ios::out);
  if(fin.fail() || fin.bad())
	{
	cout<<"\n FILE NOT FOUND ! ";
	getch();
	return;
	}
  else
	{
	n=no_of_records();
	if(n==0)
	 {
	 cout<<"\n FILE IS EMPTY ! ";
	 getch();
	 return;
	 }
	}
  char dname[20];
  cout<<" \nEnter the name of person whose record you want to delete ";
  gets(dname);
  int dele=0;
  char confirm='n';
  while(fin.read((char*)&obj,sizeof(obj)))
	{
	if(strcmp(name,dname))
	 {
	 fout.write((char*)&obj,sizeof(obj));
	 }
	else
	 {
	 cout<<"Record found as follows :\n";
	 obj.view1();
	 cout<<endl;
	 cout<<"are you sure you want to delete this record ???(y/n)\n";
	 cin>>confirm;
	 if(confirm=='y')
	  {
	  dele+=1;
	  }
	 else
	  {
	  fout.write((char*)&obj,sizeof(obj));
	  }
	 }
	}
  if(!dele)
	{
	cout<<"record not found !!..."<<endl;
	}
  else
	{
	cout<<"Record deleted\n";
	}
  fin.close();
  fout.close();
  remove("addbuk.txt");
  rename("new.txt","addbuk.txt");
  char l;
  cout<<"want to delete more ??(y/n)" ;
  cin>>l;
  if(l=='y')
  goto start;
  char r;
  cout<<"do you want to return to the menu(m/M) or exit(e/E) ??????? ";
  cin>>r;
  switch(r)
	{
	case 'm':
	case 'M':
			  menu();
			  break;
	case 'e':
	case 'E':
			  exit(0);
	}
 }
void directory::view1() //TO DISPLAY A RECORD
 {
 cout<<"\n";
 cout<<" NAME                   : "<<name<<"\n";
 cout<<" OCCUPATION             : "<<occupation<<"\n";
 cout<<" HOUSE ADDRESS          : "<<address1<<"\n";
 cout<<" HOUSE PHONE NUMBER     : "<<pn1<<"\n";
 cout<<" OFFICE ADDRESS         : "<<address2<<"\n";
 cout<<" OFFICE PHONE NUMBER    : "<<pn2<<"\n";
 cout<<" EMAIL ADDRESS          : "<<emailadd<<"\n";
 cout<<" FAX NUMBER             : "<<faxadd<<"\n";
 getch();

 }
void directory::modification() //TO MODIFY ANY DATA IN  THE RECORD IF NECESSARY
 {
 start:
 clrscr();
 cout<<"*********MODIFICATION**********";
 fstream fin,fout;
 fin.open("addbuk.txt", ios::binary |ios::in);
 fout.open("new.txt", ios::binary |ios::out);
 if(fin.fail() || fin.bad())
  {
  cout<<"\n FILE NOT FOUND !";
  fin.close();
  exit(-1);
  }
 int n=no_of_records();
 if(n==0)
  {
  cout<<"\n FILE IS EMPTY ! ";
  getch();
  return;
  }
 char dname[50],confirm='n';
 cout<<" \nEnter the name of the person whose record you want to modify.....\n";
 gets(dname);
 long pos;
 int dele=0;
 char d,e,f,g,h,i,j,k,ch;
 while(fin.read((char*)&obj,sizeof(obj)))
  {
  pos=fin.tellg();
  if(strcmp(name,dname))
	{
	fout.write((char*)&obj,sizeof(obj));
	}
  else
	{
	dele++;
	cout<<"The record is as follows :\n";
	view1();
	cout<<endl;
	cout<<"are you sure you want to modify this record ???(y/n)\n";
	cin>>confirm;
	if(confirm=='y')
	 {
	 cout<<"Now modify :\n\n";
	 d=check("NAME");
	 if(d=='y' || d=='Y')
	  {
	  cout<<" \nYour name is       : ";
	  puts(name);
	  cout<<"\nEnter your new name : ";
	  gets(name);
	  }
	 e=check("OCCUPATION");
	 if(e=='y' || e=='Y')
	  {
	  cout<<" \nYour previous occupation is   : ";
	  puts(occupation);
	  cout<<"\nEnter your new occupation name : ";
	  gets(occupation);
	  }
	 f=check("HOME ADDRESS");
	 if(f=='y' || f=='Y')
	  {
	  cout<<"\nYour previous home address is : ";
	  cout<<address1;
	  cout<<"\nEnter new home address        : ";
	  gets(address1);
	  }
	 g=check("HOUSE PHONE NUMBER ");
	 if((g=='y') || (g=='Y'))
	  {
	  cout<<"\nThe previous phone no. is : ";
	  cout<<pn1;
	  cout<<"\nEnter new phone no.       : ";
	  cin>>pn1;
	  cin.get(ch);
	  }
	 h=check("OFFICE ADDRESS");
	 if(h=='y' || h=='Y')
	  {
	  cout<<"\nYour previous office address is : ";
	  cout<<address2;
	  cout<<"\nEnter new office address        : ";
	  cin.getline(address2,75,'\n');
	  }
	 i=check("OFFICE PHONE NUMBER ");
	 if(i=='y' || i=='Y')
	  {
	  cout<<"\nThe previous phone no. is : ";
	  cout<<pn2;
	  cout<<"\nEnter new phone number    : ";
	  cin>>pn2;
	  cin.get(ch);
	  }
	 j=check("EMAIL ADDRESS");
	 if(j=='y' || j=='Y')
	  {
	  cout<<" \nYour previous email address is : ";
	  cout<<emailadd;
	  cout<<"\n Enter new email address :";
	  gets(emailadd);
	  }
	 k=check("FAX NUMBER");
	 if(k=='y' || k=='Y')
	  {
	  cout<<"\nYour previous fax no. is : ";
	  cout<<faxadd;
	  cout<<"\nEnter new fax address    :";
	  gets(faxadd);
	  }
	 fout.seekp(pos);
	 fout.write((char*)&obj,sizeof(obj));
	 }
	else
	 {
	 dele+=2;
	 fout.write((char*)&obj,sizeof(obj));
	 }
	}
  }
  if(!dele)
	{
	cout<<" \nrecord not found  !!!....";
	}
  else if(dele==1)
	{
	cout<<"\nrecord modified\n";
	}
  else
	{
	cout<<"record not modified \n";
	}
  fin.tellg();
  fin.close();
  fout.close();
  remove("addbuk.txt");
  rename("new.txt","addbuk.txt");
  char r,a;
  cout<<"do you want to modify some other record ????(y/n)";
  cin>>a;
  if(a=='y')
	{
	goto start;
	}
  cout<<"do you want to return to the menu(m/M) or exit(e/E) ??????? ";
  cin>>r;
  switch(r)
	{
	case 'm':
	case 'M':
			  menu();
			  break;
	case 'e':
	case 'E':
			  exit(0);
	}
 }
char  directory::check(char *s)
 {
  cout<<"\n MODIFY \t "<<s<<"\t"<<"Y/N";
  char ch;
  ch=getch();
  if((ch=='y')||(ch=='Y'))
  return 'y';
  else
  return 'n';
 }
 void directory::view()
 {
 int n,j,s=0;
 ifstream fin;
 fin.open("addbuk.txt");
 if(fin.fail() || fin.bad())
  {
  cout<<"\n FILE NOT FOUND !!!... ";
  getch();
  return;
  }
 clrscr();
 n=no_of_records();
 for(j=0; j<n; j++)
  {
  cout<<"\n **********RECORD "<<(s+1)<<" **********"<<endl;
  fin.read((char*)&obj,sizeof(obj));
  cout<<"\n NAME                   :" <<name       <<"\n";
  cout<<"\n OCCUPATION             :" <<occupation <<"\n";
  cout<<"\n HOUSE ADDRESS          :" <<address1   <<"\n";
  cout<<"\n HOUSE PHONE NUMBER     :" <<pn1        <<"\n";
  cout<<"\n OFFICE ADDRESS         :" <<address2   <<"\n";
  cout<<"\n OFFICE PHONE NUMBER    :" <<pn2        <<"\n";
  cout<<"\n INTERNET ADDRESS       :" <<emailadd   <<"\n";
  cout<<"\n FAX NUMBER             :" <<faxadd     <<"\n";
  s+=1;
  }
 fin.close();
 getch();
 char ch;
 cout<<"do you want to return to the menu(m/M) or exit(e/E) ??????? ";
 cin>>ch;
 switch(ch)
  {
  case 'm':
  case 'M':
			 menu();
			 break;
  case 'e':
  case 'E':
			 exit(0);
  }
 }
void directory::search()   //SEARCHING FOR A PARTICULAR NUMBER
 {
 start:
 ifstream fin;
 fin.open("addbuk.txt");
 if(fin.fail())
  {
  cout<<" \n FILE NOT FOUND ";
  getch();
  return;
  }
  int n=no_of_records();
 if(n==0)
  {
  cout<<"\n FILE IS EMPTY ! ";
  getch();
  return;
  }
 clrscr();
 cout<<"**********SEARCHING********** ";
 cout<<" \n ENTER PHONE NUMBER TO BE SEARCHED : ";
 long pn;
 cin>>pn;
 for(int i=0 ;i<n ;i++)
  {
  fin.read((char*)&obj,sizeof(obj));
  if(pn==pn1)
	{
	cout<<"record found as follows :\n";
	view1();
	}
  }
 char ch,l;
 cout<<"\nwant to search more ??(y/n)" ;
 cin>>l;
 if(l=='y')
  goto start;
 cout<<"\ndo you want to return to the menu(m/M) or exit(e/E) ??????? ";
 cin>>ch;
 switch(ch)
  {
  case 'm':
  case 'M':
			 menu();
			 break;
  case 'e':
  case 'E':
			 exit(0);
  }
 }
int directory::no_of_records()      //FIND NO. OF RECORDS
  {
  ifstream fin;
  fin.open("addbuk.txt");
  fin.seekg(0,ios::end);
  float n;
  n=fin.tellg()/sizeof(obj);
  cout<<" \n **********NUMBER OF RECORDS**********"<<endl;
  cout<<n;
  return n;
  }
int main()
 {
 welcome_screen();
 obj.menu();
 return (0);
 }
