#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    string s;
    for (int i = 0; i < t; i++)
    {
        cout << "case #" << i << ":\n";
        getline(cin, s);
        int l = s.size();
        for (int j = 0; j < l; j++)
        {
            if (isupper(s[j]))
            {
                s[j] = (s[j] - 'A' + 13) % 26 + 'A';
            }
            else if (islower(s[j]))
            {
                s[j] = (s[j] - 'a' + 13) % 26 + 'a';
            }
        }
        cout << s << endl;
    }
}