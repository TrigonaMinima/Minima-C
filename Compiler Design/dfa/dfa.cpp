// Deterministic Finite Automata

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include <string>
# include <map>

using namespace std;

// Creates the dfa type of data structure.
// start symbol, no. of states, no. of inputs, table.
struct dfa
{
    string start;
    vector<string> states, inputs, final;
    map< string, map<string, string> > table;
};

// Prints the vector.
void print_vector(vector<string> v)
{
    int size = v.size(), i=0;
    while(i != size)
    {
        cout << v[i] << " ";
        i++;
    }
   cout << endl;
}

// Genrates the transition table kind of dictionary.
dfa gen_table(vector<string> v)
{
    dfa inp;
    int size = v.size(), isize;

    // Start symbol
    inp.start = v[0];
    // cout << inp.start << endl;

    // All states extracted.
    stringstream ss1(v[1]);
    string temp;
    while (ss1 >> temp)
        inp.states.push_back(temp);
    // print_vector(inp.states);

    // All final states extracted.
    stringstream ss2(v[2]);
    while (ss2 >> temp)
        inp.final.push_back(temp);
    // print_vector(inp.inputs);

    // All inputs extracted.
    stringstream ss3(v[3]);
    while (ss3 >> temp)
        inp.inputs.push_back(temp);
    isize = inp.inputs.size();
    // print_vector(inp.inputs);

    // Creates the table.
    for(int i=4; i<size; i++)
    {
        if(v[i] == "")
            break;
        map<string, string> row;
        vector<string> rows;
        stringstream ss(v[i]);
        while (ss >> temp)
            rows.push_back(temp);

        print_vector(rows);

        for(int j=0; j<isize; j++)
            row[inp.inputs[j]] = rows[j];
        inp.table[inp.states[i-4]] = row;
    }
    return inp;
}

// Checks the validity of the user input
int check_validity(dfa inp, string input)
{
    int size = input.size(), i = 0, flag = 1, size1 = 0;
    string current = inp.start;
    string output;
    bool exists;
    cout << "\n --------------- ------- ------------ " << endl;
    cout << "| Current State | Input | Next State |" << endl;
    cout << " --------------- ------- ------------ " << endl;

    do
    {
        exists = inp.table[current].find(string(1, input[i])) == inp.table[current].end();
        if(!exists)
        {
            cout << "|\t" << current << "\t|   "<< input[i] << "   |     ";
            output = inp.table[current][string(1, input[i])];
            if (output == "-1")
            {
                cout << "\nInput symbol \"" << input[i] << "\" at state "
                << current << " is not recognized!!";
                flag = 0;
                break;
            }
            current = output;
            cout << current << "     |\n";
            i++;
            if(i == size)
                cout << " --------------- ------- ------------ " << endl;

            size1 = inp.final.size();
            for (int k = 0; k < size1; ++k)
            {
                if (current == inp.final[k])
                    flag = 1;
                else
                    flag = 0;
            }
        }
        else
        {
            cout << " --------------- ------- ------------ " << endl;
            cout << "\nInput symbol \"" << input[i] << "\" at state \""
            << current << "\" is not recognized!!" << endl;
            flag = 0;
            break;
        }
    }
    while(i != size);


    return flag;
}

int main()
{
    vector<string> data;    // stores file data
    string s;
    dfa inp;

    // read input file
    ifstream f("input.txt");
    while(f)
    {
        getline(f, s);
        data.push_back(s);
    }
    f.close();

    // create an in-memory dict/table
    inp = gen_table(data);

    // take a string as input
    cout << "Enter the string to check: ";
    getline(cin, s);

    // Check the validity of the string & display the output.
    if (check_validity(inp, s))
        cout << "\nString accepted!!\n";
    else
        cout << "\nString not accepted!!\n";

    return 0;
}
