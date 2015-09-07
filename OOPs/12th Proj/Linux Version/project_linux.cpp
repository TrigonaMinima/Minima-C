# include <iostream>
# include <stdlib.h>
# include <string.h>
// # include <stdio.h>

# include <record.h>
# include <directory.h>

using namespace std;

void welcome_screen()
{
    system("clear");
    cout << "*********************** WELCOME ***********************\n\n";
    cout << "DATA MANAGEMENT SOFTWARE\n";
    cout << " Made by:";
    cout << " SHIVAM RANA\n\n\n\n\n\n\n\n";
    select_directory_type();
}

int select_directory_type()
{
    int ch;
    cout << "Menu-\n\n";
    cout << "1. Student-Course Management\n";
    cout << "2. Teacher-Course Management\n\n";
    cout << "Enter your choice: ";
    cin >> ch;
    return ch;
}

int main()
{
    directory dir;
    welcome_screen();

    // dir.menu();
    return(0);
}
