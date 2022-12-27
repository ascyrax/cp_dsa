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
        ioss
                cout
            << setprecision(15) << fixed << endl;
        int t;
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

void suraj()
{
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t;
        for (int i = 0; i < n; i++)
                t += "?";
        if (s == t)
        {
                for (int i = 0; i < n; i++)
                {
                        if (i % 2 == 0)
                                cout << "B";
                        else
                                cout << "R";
                }
                cout << endl;
                return;
        }
        for (int i = 0; i < n; i++)
        {
                // if (i + 1 < n)
                // {
                //         if (s[i] == '?' && s[i + 1] != '?')
                //         {

                //         }
                // }
                if (i > 0 && s[i] == '?' && s[i - 1] != '?')
                {
                        if (s[i - 1] == 'B')
                        {
                                s[i] = 'R';
                        }
                        else if (s[i - 1] == 'R')
                        {
                                s[i] = 'B';
                        }
                }
        }
        for (int i = n - 1; i >= 0; i--)
        {
                if (i < n - 1 && s[i] == '?') //s[i+1] will obviously be != '?'
                {
                        if (s[i + 1] == 'B')
                        {
                                s[i] = 'R';
                        }
                        else if (s[i + 1] == 'R')
                        {
                                s[i] = 'B';
                        }
                }
        }
        cout << s << endl;
}

//................................
