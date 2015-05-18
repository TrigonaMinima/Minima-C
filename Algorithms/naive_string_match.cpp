/*
* Naive String Matching
* Works by matching the pattern for each element in the text.
* Worst case time complexity is - O((ts-ps)*ps)
* ts: text size; ps: pattern size
*/

# include <iostream>
# include <string>

using namespace std;

int* nsm(string text, string pat)
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