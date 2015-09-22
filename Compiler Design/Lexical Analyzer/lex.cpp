# include <iostream>
# include <sstream>
# include <fstream>
# include <string>

using namespace std;

# define EMPTY -99
# define STATE 4
# define INPUT 3
# define initial 0

# define INPUT_FILE ("lex_input.txt")

// Automata of the lexemes.
const int automata[STATE][INPUT] =
    {
        {1, 2, 3},
        {1, 1, 3},
        {3, 2, 2},
        {3, 3, 3}
    };

// List of final states.
const int final[STATE] = {1, 2};


// This method prints the DFA of lexemes.
void print_lexeme_dfa()
{
    cout << "Lexeme Automata: \n";
    cout << " --------- --------- --------- ---------\n";
    cout << "|  State  |[A-Za-z_]|  [0-9]  |   Spl   |\n";
    cout << " --------- --------- --------- ---------\n";

    for(int i=0; i < STATE; i++)
    {
        cout << "|    q" << i << "   |";
        for(int j=0; j < INPUT; j++)
            cout << "    q" << automata[i][j] << "   |";
        cout << endl;
    }
    cout << " --------- --------- --------- ---------\n\n";
}

// checks in which range does the character lies.
int range(char a)
{
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == '_')
        return 0;
    else if(a >= '0' && a <= '9')
        return 1;
    else
        return -1;
}

// gives the status of a token.
int check(const char * line)
{
    int state = initial, flag = 0, c;

    for (int i = 0; line[i] != '\0'; i++)
    {
        c = range(line[i]);
        if(c == 0)
            state = automata[state][0];
        else if(c == 1)
            state = automata[state][1];
        else
            return -1;
    }
    return state;
}


// Determines if the lexeme is valid or not.
void determine(ifstream &input)
{
    int status;
    string line;
    const char *inval;

    while(getline(input, line))
    {
        inval = line.c_str();
        cout << inval;

        status = check(inval);

        switch(status)
        {
            case -1:
                cout << "\t\tInvalid\t\tRejected --\n";
                break;

            case 1:
                cout << "\t\tIdentifier\tAccepted ++\n";
                break;

            case 2:
                cout << "\t\tNumeric\t\tAccepted ++\n";
                break;

            default:
                cout << "\t\tInvalid\t\tRejected --\n";
                break;
        }
    }
}


int main()
{
    // Prints the lexeme DFA
    print_lexeme_dfa();

    // Determines if the lexeme is valid or not.
    ifstream input(INPUT_FILE);
    determine(input);

    return 0;
}