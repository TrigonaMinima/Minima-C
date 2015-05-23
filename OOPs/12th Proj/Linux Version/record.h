# include <iostream>
# include <stdlib.h>
# include <string.h>

class record
{
    int age;
    string name, occupation, address1, email, faxadd, phone1, phone2;
public:
    record();
    ~record();

};

record :: record()
{
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