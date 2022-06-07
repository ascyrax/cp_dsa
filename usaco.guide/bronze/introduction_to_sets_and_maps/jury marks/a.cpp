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

        // cin>>t;

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
        int k, n;
        cin >> k >> n;

        vector<int> jury(k);
        for (int &i : jury)
                cin >> i;

        vector<int> ps(k);
        ps[0] = jury[0];
        for (int i = 1; i < k; i++)
                ps[i] = ps[i - 1] + jury[i];

        set<int> ans;

        vector<int> memory;

        for (int i = 0; i < n; i++)
        {
                int b;
                cin >> b;
                memory.pb(b);
        }

        int mn = -4e6; // min ScorePossible
        int mx = 4e6;  // max ScorePossible

        for (int i = mn; i <= mx; i++)
        {
        }
}

//................................

// int

// int

// int

// int
