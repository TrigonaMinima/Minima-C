# include <fstream.h>
# include <conio.h>
# include <stdio.h>
# include <process.h>
# include <string.h>

void welcome_screen()
{
    clrscr();
    cout << "******************* W E L C O M E  ***********************\n\n\n";
    cout << " D A T A  M A N A G E M E N T  S O F T W A R E\n\n\n";
    cout << " D O N E  B Y :\n";
    cout << " S H I V A M   R A N A\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << " ****press any key to continue***";
    getch();
    return;
}

class directory
{
    public:
    int record, age;
    long pn1, pn2;
    char name[20], occupation[25], address1[75], address2[75], emailadd[25];
    char faxadd[25], check(char *);
    void menu();
    void addition();
    void init();
    void delette();
    void view1();
    void modification();
    void view();
    void search();
    int  no_of_records();
} obj;

void  directory::menu()
{
    clrscr();
    char ch;
    cout << "*******MENU*********\n";
    cout << endl;
    cout << "1: ADDITION(a/A)\n";
    cout << "2: DELETION(d/D)\n";
    cout << "3: MODIFICATION(m/M)\n";
    cout << "4: VIEW(v/V)\n";
    cout << "5: SEARCH(s/S)\n";
    cout << "6: NO OF RECORDS(n/N)\n";
    cout << "7: EXIT(e/E)\n";
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
            cout << "\n\n\n\nDo you want to return to the menu(m/M) or exit(e/E) ??????? ";
            cin >> ch;
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
    fout.open("addbuk.txt", ios::binary | ios::app);
    init();
    fout.write((char*)&obj, sizeof(obj));
    fout.close();
    char l;
    cout << "Want to enter more ??(y/n)";
    cin >> l;
    if(l == 'y')
        goto start;
    char r;
    cout << "Do you want to return to the menu(m/M) or exit(e/E)? ";
    cin >> r;
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
    cout << " ***********ADDITION*********** ";
    cin.get(ch);
    cout << "\n ENTER NAME\t\t: ";
    cin.getline(name, 20);
    cout << "\n ENTER THE OCCUPATION\t: ";
    cin.getline(occupation, 20);
    cout << "\n ENTER HOUSE ADDRESS\t: ";
    cin.getline(address1, 50);
    cout << "\n ENTER HOUSE PHONE NUMBER\t: ";
    cin >> obj.pn1;
    cin.get(ch);
    cout << "\n ENTER OFFICE ADDRESS\t: ";
    cin.getline(address2, 50);
    cout << "\n ENTER OFFICE PHONE NUMBER\t: ";
    cin >> pn2;
    cin.get(ch);
    cout << "\n ENTER EMAIL ADDRESS\t: ";
    cin.getline(emailadd, 25);
    cout << "\n ENTER FAX NUMBER\t: ";
    gets(faxadd);
    return;
}

void  directory::delette()      //DELETION OF RECORDS
{
    start:
    clrscr();
    cout << "**********DELETION**********";
    int n;
    fstream fin;
    fstream fout;
    fin.open("addbuk.txt", ios::binary | ios::in);
    fout.open("new.txt", ios::binary | ios::out);
    if(fin.fail() || fin.bad())
    {
        cout << "\nFILE NOT FOUND!";
        getch();
        return;
    }
    else
    {
        n=no_of_records();
        if(n == 0)
        {
            cout << "\nFILE IS EMPTY!";
            getch();
            return;
        }
    }
    char dname[20];
    cout << "\nEnter the name of person whose record you want to delete: ";
    gets(dname);
    int dele = 0;
    char confirm = 'n';
    while(fin.read((char*)&obj, sizeof(obj)))
    {
        if(strcmp(name, dname))
        {
            fout.write((char*)&obj, sizeof(obj));
        }
        else
        {
            cout << "Record found as follows :\n";
            obj.view1();
            cout << endl;
            cout << "Are you sure you want to delete this record ???(y/n)\n";
            cin >> confirm;
            if(confirm == 'y')
                dele += 1;
            else
                fout.write((char*)&obj, sizeof(obj));
        }
    }
    if(!dele)
        cout << "Record not found!!" << endl;
    else
        cout << "Record deleted!!\n";
    fin.close();
    fout.close();
    remove("addbuk.txt");
    rename("new.txt", "addbuk.txt");
    char l;
    cout << "Want to delete more ??(y/n)";
    cin >> l;
    if(l == 'y')
        goto start;
    char r;
    cout << "Do you want to return to the menu(m/M) or exit(e/E)? ";
    cin >> r;
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
    cout << "\n";
    cout << " NAME                   : " << name << "\n";
    cout << " OCCUPATION             : " << occupation << "\n";
    cout << " HOUSE ADDRESS          : " << address1 << "\n";
    cout << " HOUSE PHONE NUMBER     : " << pn1 << "\n";
    cout << " OFFICE ADDRESS         : " << address2 << "\n";
    cout << " OFFICE PHONE NUMBER    : " << pn2 << "\n";
    cout << " EMAIL ADDRESS          : " << emailadd << "\n";
    cout << " FAX NUMBER             : " << faxadd << "\n";
    getch();
}

void directory::modification() //TO MODIFY ANY DATA IN  THE RECORD IF NECESSARY
{
 start:
 clrscr();
 cout << "*********MODIFICATION**********";
 fstream fin, fout;
 fin.open("addbuk.txt", ios::binary |ios::in);
 fout.open("new.txt", ios::binary |ios::out);
 if(fin.fail() || fin.bad())
  {
  cout << "\nFILE NOT FOUND!";
  fin.close();
  exit(-1);
  }
 int n = no_of_records();
 if(n == 0)
  {
  cout << "\nFILE IS EMPTY! ";
  getch();
  return;
  }
    char dname[50], confirm='n';
    cout << "\nEnter the name of the person whose record you want to modify: ";
    gets(dname);
    long pos;
    int dele = 0;
    char d, e, f, g, h, i, j, k, ch;
    while(fin.read((char*)&obj, sizeof(obj)))
    {
        pos=fin.tellg();
        if(strcmp(name, dname))
        {
            fout.write((char*)&obj, sizeof(obj));
        }
        else
        {
            dele++;
            cout << "The record is as follows :\n";
            view1();
            cout << endl;
            cout << "Are you sure you want to modify this record ???(y/n)\n";
            cin >> confirm;
            if(confirm == 'y')
            {
                cout << "Now modify-\n\n";
                d=check("NAME");
                if(d == 'y' || d == 'Y')
                {
                    cout << "\nYour name is\t\t: ";
                    puts(name);
                    cout << "\nEnter your new name: ";
                    gets(name);
                }
                e=check("OCCUPATION");
                if(e == 'y' || e == 'Y')
                {
                    cout << "\nYour previous occupation is\t: ";
                    puts(occupation);
                    cout << "\nEnter your new occupation name: ";
                    gets(occupation);
                }
                f=check("HOME ADDRESS");
                if(f == 'y' || f == 'Y')
                {
                    cout << "\nYour previous home address is : ";
                    cout << address1;
                    cout << "\nEnter new home address\t: ";
                    gets(address1);
                }
                g=check("HOUSE PHONE NUMBER ");
                if((g == 'y') || (g == 'Y'))
                {
                    cout << "\nThe previous phone no. is : ";
                    cout << pn1;
                    cout << "\nEnter new phone no.\t: ";
                    cin >> pn1;
                    cin.get(ch);
                }
                h=check("OFFICE ADDRESS");
                if(h == 'y' || h == 'Y')
                {
                    cout << "\nYour previous office address is : ";
                    cout << address2;
                    cout << "\nEnter new office address        : ";
                    cin.getline(address2, 75, '\n');
                }
                i=check("OFFICE PHONE NUMBER ");
                if(i == 'y' || i == 'Y')
                {
                    cout << "\nThe previous phone no. is : ";
                    cout << pn2;
                    cout << "\nEnter new phone number    : ";
                    cin >> pn2;
                    cin.get(ch);
                }
                j=check("EMAIL ADDRESS");
                if(j == 'y' || j == 'Y')
                {
                    cout << "\nYour previous email address is : ";
                    cout << emailadd;
                    cout << "\nEnter new email address :";
                    gets(emailadd);
                }
                k=check("FAX NUMBER");
                if(k == 'y' || k == 'Y')
                {
                    cout << "\nYour previous fax no. is : ";
                    cout << faxadd;
                    cout << "\nEnter new fax addresst\t:";
                    gets(faxadd);
                }
                fout.seekp(pos);
                fout.write((char*)&obj, sizeof(obj));
            }
            else
            {
                dele += 2;
                fout.write((char*)&obj, sizeof(obj));
            }
        }
    }
    if(!dele)
        cout << "\nRecord not found!";
    else if(dele == 1)
        cout << "\nRecord modified!\n";
    else
        cout << "Record not modified!\n";
    fin.tellg();
    fin.close();
    fout.close();
    remove("addbuk.txt");
    rename("new.txt", "addbuk.txt");
    char r, a;
    cout << "Do you want to modify some other record (y/n) ?";
    cin >> a;
    if(a == 'y')
        goto start;
    cout << "Do you want to return to the menu(m/M) or exit(e/E)? ";
    cin >> r;
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
    cout << "\n MODIFY \t " << s << "\t" << "Y/N";
    char ch;
    ch = getch();
    if(ch == 'y' || ch == 'Y')
        return 'y';
    else
        return 'n';
}

 void directory::view()
{
    int n, j, s = 0;
    ifstream fin;
    fin.open("addbuk.txt");
    if(fin.fail() || fin.bad())
    {
        cout << "\nFILE NOT FOUND!";
        getch();
        return;
    }
    clrscr();
    n=no_of_records();
    for(j = 0; j < n; j++)
    {
        cout << "\n **********RECORD " << (s + 1) << " **********" << endl;
        fin.read((char*)&obj, sizeof(obj));
        cout << "\nNAME\t\t:" << name << "\n";
        cout << "\nOCCUPATION\t\t:" << occupation << "\n";
        cout << "\nHOUSE ADDRESS\t\t:" << address1 << "\n";
        cout << "\nHOUSE PHONE NUMBER\t:" << pn1 << "\n";
        cout << "\nOFFICE ADDRESS\t\t:" << address2 << "\n";
        cout << "\nOFFICE PHONE NUMBER\t:" << pn2 << "\n";
        cout << "\nINTERNET ADDRESS\t\t:" << emailadd << "\n";
        cout << "\nFAX NUMBER\t\t:" << faxadd << "\n";
        s += 1;
    }
    fin.close();
    getch();
    char ch;
    cout << "Do you want to return to the menu(m/M) or exit(e/E)? ";
    cin >> ch;
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
        cout << "\nFILE NOT FOUND ";
        getch();
        return;
    }
    int n=no_of_records();
    if(n == 0)
    {
        cout << "\nFILE IS EMPTY ! ";
        getch();
        return;
    }
    clrscr();
    cout << "**********SEARCHING********** ";
    cout << "\nENTER PHONE NUMBER TO BE SEARCHED : ";
    long pn;
    cin >> pn;
    for(int i=0; i<n; i++)
    {
        fin.read((char*)&obj, sizeof(obj));
        if(pn == pn1)
        {
            cout << "Record found as follows :\n";
            view1();
        }
    }
    char ch, l;
    cout << "\nWant to search more ??(y/n)";
    cin >> l;
    if(l == 'y')
        goto start;
    cout << "\nDo you want to return to the menu(m/M) or exit(e/E) ??????? ";
    cin >> ch;
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
    fin.seekg(0, ios::end);
    float n;
    n=fin.tellg() / sizeof(obj);
    cout << "\n **********NUMBER OF RECORDS**********" << endl;
    cout << n;
    return n;
}

int main()
{
    welcome_screen();
    obj.menu();
    return(0);
}
