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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................
bool isSubSequence(string t, string s, int lent, int lens)
{
        int j = 0;
        int prev = -1;
        for (int i = 0; i < lens && j < lent; i++)
                if (t[j] == s[i])
                {
                        if (prev == i - 1)
                        {
                                continue;
                        }
                        j++;
                        prev = i;
                }
        return (j == lent);
}
void suraj()
{
        string s, t;
        cin >> s >> t;
        int lens = int(s.size());
        int lent = int(t.size());
        if (lent > lens)
                cout << "no" << endl;
        else if (lent == lens)
        {
                if (s == t)
                        cout << "yes" << endl;
                else
                        cout << "no" << endl;
        }
        else if (lent < lens)
        {
                // if ((lens - lent) % 2 == 0)
                // { //first char was not rep by backspace
                //         int nback = (lens - lent) / 2;
                // }
                // else if ((lens - lent) % 2 == 1)
                // { //first char of s was repl by backspace
                //         int nback = (lens - lent) / 2 + 1;
                // }

                isSubSequence(t, s, lent, lens) ? cout << "Yes "
                                                : cout << "No";
                cout << endl;
        }
}

//................................
