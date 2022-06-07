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

        // ioss

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

        string rev = s;
        reverse(rev.begin(), rev.end());

        // biggest prefixe of rev which is a subsequence in s.
        int ptrs = 0;
        vector<bool> flag(s.size(), false);

        for (int i = 0; i < rev.size() && ptrs < s.size(); i++)
        {
                for (ptrs = ptrs; ptrs < s.size(); ptrs++)
                {
                        if (s[ptrs] == rev[i])
                        {
                                ptrs++;
                                flag[i] = true;
                                break;
                        }
                }
        }
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
                if (flag[i])
                        cnt++;
        }

        cout << s.size() - cnt << endl;
}

//................................

// int

// int

// int

// int
