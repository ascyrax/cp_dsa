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

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................

//...............................

void suraj()
{
        string s;
        cin >> s;

        int lens = s.size();
        map<char, int> cnt;
        for (int i = 0; i < lens; i++)
        {
                cnt[s[i]]++;
        }
        int i = 0;
        for (i = 0; i < lens; i++)
        {
                if (cnt[s[i]] >= 2)
                {
                        cnt[s[i]]--;
                }
                else
                        break;
        }
        cout << s.substr(i) << endl;
}

//................................

// int

// int

// int

// int
