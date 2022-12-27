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
ll mod = 1e9 + 7;
map<ll, bool> flag;
ll find(ll val)
{
        ll pow = 0;
        ll exp = 1;
        while (exp < val)
        {
                pow++;
                exp *= 2;
        }
        if (exp == val)
                return pow;
        else
                return pow - 1;
}
bool ascy = false;
bool search(ll val)
{
        // cout << "search - val : " << val << endl;
        if (val == 0)
        {
                // cout << "if" << endl;
                ascy = ascy || false;
        }
        else if (flag[val])
        {
                // cout << "else if" << endl;
                ascy = ascy || true;
        }
        else
        {
                // cout << "else" << endl;
                if (val % 4 == 0 && (val - 1) % 2 == 0)
                {
                        // cout << "a" << endl;
                        ascy = ascy || (search(val / 4) || search((val - 1) / 2));
                }
                else if (val % 4 == 0)
                {
                        // cout << "b" << endl;
                        ascy = ascy || search(val / 4);
                }
                else if ((val - 1) % 2 == 0)
                {
                        // cout << "c" << endl;
                        // cout << (val - 1) << " " << ((val - 1) / 2) << endl;
                        ascy = ascy || search((val - 1) / 2);
                        // cout << "hello" << endl;
                }
                else // cannot be reached by any other value.
                {
                        // cout << "d" << endl;
                        ascy = ascy || false;
                }
        }
        return ascy;
}
// bool search(ll val)
// {
//         if (val % 4 != 0 && (val - 1) % 2 != 0)
//         {
//                 return false;
//         }
//         else
//         {
//                 if (search(val))
//                         return true;
//                 else
//                         return false;
//         }
// }
//...............................

void suraj()
{
        ll n, p;
        cin >> n >> p;

        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;

        sort(v.begin(), v.end());

        vector<ll> dp(p + 1);
        // dp[i] = no of llegers that lie between pow(2,i) and pow(2,i+1), lhs inclusive i.e.
        // [pow(2,i),pow(2,i+1))

        // ans = sigma(dp[i]) from i=0 to i=p-1;
        for (ll i = 0; i < n; i++)
        {
                // cout << "i :" << i << endl;
                // cout << "v[i] : " << v[i] << endl;
                // if this can be reached by any no already present, then we dont need to recount this val.
                if (flag[v[i]] || search(v[i]))
                {
                        flag[v[i]] = true;
                        ascy = false;
                        continue;
                }
                ascy = false;

                flag[v[i]] = true;
                ll temp = find(v[i]);
                if (temp < p)
                        dp[temp]++;
                // cout << "temp: " << temp << endl;
                // cout << "dp[temp]: " << dp[temp] << endl;
        }

        if (p >= 2)
                dp[1] += dp[0];

        for (ll i = 2; i < p; i++)
        {
                dp[i] += (dp[i - 1] + dp[i - 2]);
                dp[i] = dp[i] % mod;
        }

        ll ans = 0;
        for (ll i = 0; i < p; i++)
        {
                // cout << "dp[" << i << "] : " << dp[i] << endl;
                ans += dp[i];
                ans %= mod;
        }

        cout << ans << endl;
}

//................................

// ll

// int

// int

// int