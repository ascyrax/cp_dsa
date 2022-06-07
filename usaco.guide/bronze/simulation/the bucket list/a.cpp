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

        freopen("blist.in", "r", stdin);
        freopen("blist.out", "w", stdout);

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
        int n;
        cin >> n;

        int ans = 0;

        int cnt = 0;

        map<int, int> m;

        vector<int> events;

        for (int i = 0; i < n; i++)
        {
                int s, t, b;
                cin >> s >> t >> b;
                m[s] += b;
                m[t] -= b;
                events.pb(s);
                events.pb(t);
        }

        sort(events.begin(), events.end());

        for (int i = 0; i < 2 * n; i++)
        {
                cnt += m[events[i]];
                ans = max(ans, cnt);
        }
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
