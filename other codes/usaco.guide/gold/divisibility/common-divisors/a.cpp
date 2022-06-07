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
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................
vector<int> funcFactors(int n)
{
        vector<int> vfactors;
        for (int i = 2; i * i <= n; i++)
        {
                if (n % i == 0)
                {
                        vfactors.pb(i);
                        vfactors.pb(n / i);
                }
        }
        vfactors.pb(n);
        // for (int i : vfactors)
        //         cout << i << " ";
        // cout << endl;
        return vfactors;
}
void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        vector<vector<int>> factors(n);
        // map<int, int> m;
        int ans = 0;

        vector<int> m(1000009);
        for (int i = 0; i < n; i++)
        {
                cin >> v[i];
                // factors[i] = (funcFactors(v[i]));
                for (int j = 1; j * j <= v[i]; j++)
                {
                        if (v[i] % j == 0)
                        {
                                factors[i].pb(j);
                                m[j]++;
                                if (j != v[i] / j)
                                {
                                        factors[i].pb(v[i] / j);
                                        m[v[i] / j]++;
                                }
                        }
                }
        }

        // for (auto i : m)
        //         cout << i.first << " " << i.second << endl;
        for (int i = 0; i < n; i++)
        {
                for (int divisor : factors[i])
                {
                        if (m[divisor] > 1)
                        {
                                // cout << "if" << endl;
                                ans = max(ans, divisor);
                        }
                }
                // cout << "ans " << ans << endl;
        }
        cout << ans << endl;
        // for (int i = 0; i <= 1e8; i++)
        // {
        //         if (i == 1e6)
        //         {
        //                 cout << "i " << i << endl;
        //                 cout << gct() << endl;
        //         }
        //         else if (i == 1e7)
        //         {
        //                 cout << "i " << i << endl;
        //                 cout << gct() << endl;
        //         }
        //         else if (i == 1e8)
        //         {
        //                 cout << "i " << i << endl;
        //                 cout << gct() << endl;
        //         }
        // }
}

//................................
