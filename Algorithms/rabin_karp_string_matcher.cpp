/*
* Rabin-Karp String Matching Algorithm
* Uses the number-theoretic notations. The text can be converted to an array of
* integer values and then this algorithm can be applied upon it.
*
*
*
*/

# include <iostream>

using namespace std;

int* rabin_karp(string text, string pat)
{
    int ts = text.size();
    int ps = pat.size();
    int flag = 0, k = 0;
    for (int i = 0; i < (ts - ps + 1); ++i)
    {
        flag = 0;
        for (int j = 0; j < ps; ++j)
        {
            if (pat[j] == text[i+j])
                flag += 1;
        }
        if (flag == ps)
        {
            k++;
            cout << "Pattern occurs with shift: " << i << endl;
            for (int j = 0; j < ps; ++j)
            {
                cout << text[j + i];
            }
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string text, pat;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pat);

    nsm(text, pat);

    return 0;
}