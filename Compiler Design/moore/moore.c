// Moore Machine

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include <string>
# include <map>

using namespace std;

// Creates the moore type of data structure.
// start symbol, no. of states, no. of inputs, table.
struct moore
{
    string start;
    vector<string> states, inputs;
    map<string, string> state_outputs;
    map< string, map<string, map<string, string> > > table;
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
moore gen_table(vector<string> v)
{
    moore inp;
    int size = v.size(), isize, i = 0;

    // Start symbol
    inp.start = v[0];
    // cout << inp.start << endl;

    // All states extracted.
    stringstream ss1(v[1]);
    string temp;
    while (ss1 >> temp)
        inp.states.push_back(temp);
    // print_vector(inp.states);

    // All states' outputs extracted.
    stringstream ss2(v[2]);
    while (ss2 >> temp)
    {
        inp.state_outputs[inp.states[i]] = temp;
        // inp.states.push_back(temp);
        i++;
    }
    // print_vector(inp.states);

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
        map<string, map<string, string> > row;
        vector<string> rows;
        stringstream ss(v[i]);
        while (ss >> temp)
            rows.push_back(temp);

        print_vector(rows);

        for(int j=0; j<isize; j++)
        {
            map<string, string> element;

            element["out"] = rows[isize];
            element["state"] = rows[j];

            row[inp.inputs[j]] = element;
        }
        inp.table[inp.states[i-4]] = row;
    }
    return inp;
}

// Checks the validity of the user input
void check_validity(moore inp, string input)
{
    int size = input.size(), i=0;
    string current = inp.start;
    string output;
    bool exists;
    cout << "\n --------------- ------- ------------ -------- " << endl;
    cout << "| Current State | Input | Next State | Output |" << endl;
    cout << " --------------- ------- ------------ -------- " << endl;

    do
    {
        exists = inp.table[current].find(string(1, input[i])) == inp.table[current].end();
        if(!exists)
        {
            cout << "|\t" << current << "\t|   "<< input[i] << "   |      ";
            current = inp.table[current][string(1, input[i])]["state"];
            output = inp.state_outputs[current];
            cout << current << "    |    " << output << "   |\n";
            i++;
            if(i == size)
                cout << " --------------- ------- ------------ -------- " << endl;
        }
        else
        {
            cout << " --------------- ------- ------------ -------- " << endl;
            cout << "\nInput symbol \"" << input[i] << "\" at state \""
            << current << "\" is not recognized!!" << endl;
            break;
        }
    }
    while(i != size);
}

int main()
{
    vector<string> data;    // stores file data
    string s;
    moore inp;

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
    check_validity(inp, s);

    return 0;
}
