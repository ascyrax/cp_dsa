
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
        // int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        // vector<vector<int>> factors(n);
        int ans = 0;

        int cnt = 0;

        if (n == 200000)
        {
                cout << "start: " << gct() << endl;
        }

        vector<int> m(1000009);
        for (int i = 0; i < n; i++)
        {
                cin >> v[i];
                for (int j = 1; j * j <= v[i]; j++)
                {
                        cnt++;
                        if (v[i] % j == 0)
                        {
                                // factors[i].pb(j);
                                m[j]++;
                                if (j != v[i] / j)
                                {
                                        // factors[i].pb(v[i] / j);
                                        m[v[i] / j]++;
                                }
                        }
                }
        }

        if (n == 200000)
        {
                cout << "end: " << gct() << endl;
                cout << "cnt : " << cnt << endl;
        }

        // for (int i = 0; i < n; i++)
        // {
        //         for (int divisor : factors[i])
        //         {
        //                 if (m[divisor] > 1)
        //                 {
        //                         ans = max(ans, divisor);
        //                 }
        //         }
        // }
        for (int i = 1000000; i >= 1; i--)
        {
                if (m[i] >= 2)
                {
                        cout << i << endl;
                        break;
                }
        }
}

//................................
//................................

// int

// int

// int

// int
