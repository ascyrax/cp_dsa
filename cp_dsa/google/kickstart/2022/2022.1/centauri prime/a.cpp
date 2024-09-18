// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

#define endl "\n"

#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);

#define pb push_back

double startTime;

double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

int main()
{

        ioss

            // startTime=(double)clock();

            // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

            // cout << setprecision(15) << fixed;

            int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                cout << "Case #" << i << ": ";

                suraj();
        }

        return 0;
}

//...............................

string alice = "is ruled by Alice.";
string bob = "is ruled by Bob.";
string nobody = "is ruled by nobody.";
char vowels[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
bool isVowel(char c)
{
        for (auto el : vowels)
        {
                if (c == el)
                        return true;
        }
        return false;
}

//...............................

void suraj()
{
        string s;
        cin >> s;
        int lens = s.size();
        if (s[lens - 1] == 'y' || s[lens - 1] == 'Y')
        {
                cout << s << " " << nobody << endl;
        }
        else if (isVowel(s[lens - 1]))
        {
                cout << s << " " << alice << endl;
        }
        else
                cout << s << " " << bob << endl;
}

//................................

// int

// int

// int

// int
