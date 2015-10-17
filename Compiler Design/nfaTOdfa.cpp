// Deterministic Finite Automata

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include <string>
# include <map>
# include <set>

using namespace std;

// Creates the dfa type of data structure.
// start symbol, no. of states, no. of inputs, table.
struct nfa
{
    string start;
    vector<string> states, inputs, final;
    map< string, map<string, set<string> > > table;
};

struct dfa
{
    string start;
    vector<string> states, inputs, final;
    map< string, map<string, string > > table;
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
    for(int i = 4; i < size; i++)
    {
        if(v[i] == "")
            break;
        map<string, set<string> > row;

        vector<string> rows;
        stringstream ss(v[i]);
        while (ss >> temp)
            rows.push_back(temp);

        print_vector(rows);

        for(int j=0; j<isize; j++)
        {
            set<string> nfa_state;

            istringstream line_stream(rows[j]);
            while(getline(line_stream, temp, ','))
                nfa_state.insert(temp);

            row[inp.inputs[j]] = nfa_state;
        }
        inp.table[inp.states[i-4]] = row;
    }
    return inp;
}


string join( const set<string>& st, const char* const sep)
{
    switch (st.size())
    {
        case 0:
            return "";
        case 1:
            return st[0];
        default:
            std::ostringstream os;
            std::copy(st.begin(), st.end()-1, std::ostream_iterator<std::string>(os, separator));
            os << *st.rbegin();
            return os.str();
    }
}


dfa conversion(nfa automata)
{
    dfa converted;
    converted.start = automata.start;
    converted.states = automata.states;
    converted.inputs = automata.inputs;
    converted.final = automata.final;

    for (it_type i = automata.table.begin(); i != automata.table.end(); i++)
    {
        for (it_type j = i->second.begin(); j != i->second.end(); j++)
        {
            map<string, string> temp;
            set<string> new_state;

            string state = join(j->second);
            temp[j->first] = state;
            converted[state][j->first] = set_union()
        }
        converted.table[i->first] =
    }

}


// Checks the validity of the user input
// int check_validity(dfa inp, string input)
// {
//     int size = input.size(), i = 0, flag = 1, size1 = 0;
//     string current = inp.start;
//     string output;
//     bool exists;
//     cout << "\n --------------- ------- ------------ " << endl;
//     cout << "| Current State | Input | Next State |" << endl;
//     cout << " --------------- ------- ------------ " << endl;

//     do
//     {
//         exists = inp.table[current].find(string(1, input[i])) == inp.table[current].end();
//         if(!exists)
//         {
//             cout << "|\t" << current << "\t|   "<< input[i] << "   |     ";
//             output = inp.table[current][string(1, input[i])];
//             if (output == "-1")
//             {
//                 cout << "\nInput symbol \"" << input[i] << "\" at state "
//                 << current << " is not recognized!!";
//                 flag = 0;
//                 break;
//             }
//             current = output;
//             cout << current << "     |\n";
//             i++;
//             if(i == size)
//                 cout << " --------------- ------- ------------ " << endl;

//             size1 = inp.final.size();
//             for (int k = 0; k < size1; ++k)
//             {
//                 if (current == inp.final[k])
//                     flag = 1;
//                 else
//                     flag = 0;
//             }
//         }
//         else
//         {
//             cout << " --------------- ------- ------------ " << endl;
//             cout << "\nInput symbol \"" << input[i] << "\" at state \""
//             << current << "\" is not recognized!!" << endl;
//             flag = 0;
//             break;
//         }
//     }
//     while(i != size);


//     return flag;
// }

int main()
{
    vector<string> data;    // stores file data
    string s;
    nfa inp;
    dfa automata;

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

    // Converts the nfa to dfa
    automata = conversion(inp);

    // take a string as input
    cout << "Enter the string to check: ";
    getline(cin, s);

    // Check the validity of the string & display the output.
    // if (check_validity(inp, s))
    //     cout << "\nString accepted!!\n";
    // else
    //     cout << "\nString not accepted!!\n";

    return 0;
}
