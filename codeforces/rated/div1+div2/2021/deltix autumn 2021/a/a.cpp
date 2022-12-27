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
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................
ll count(ll n)
{
        int temp = 0;
        while (n > 0)
        {
                if (n % 2 == 0)
                {
                        temp++;
                        n /= 2;
                }
                else
                        break;
        }
        return temp;
}
//...............................

void suraj()
{
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;
        if (n == 1)
        {
                cout << v[0] << endl;
                return;
        }
        sort(v.begin(), v.end());
        ll sum = 0;
        // for (ll i = 0; i < n - 1; i++)
        // {
        //         ll n2 = count(v[i]);
        //         v[i] = v[i] / ll(pow(2, n2));
        //         v[n - 1] = v[n - 1] * ll(pow(2, n2));
        // }

        // int n2 = count(v[n - 1]);
        // if ((v[n - 1] / ll(pow(2, n2)) + v[n - 2] * ll(pow(2, n2))) > (v[n - 2] + v[n - 1]))
        // {
        //         v[n - 1] = v[n - 1] / ll(pow(2, n2));
        //         v[n - 2] = v[n - 2] * ll(pow(2, n2));
        // }
        // for (ll i : v)
        //         sum += i;
        // cout << sum << endl;
        ll n2Sum = 0;
        for (int i = 0; i < n; i++)
        {
                ll n2 = count(v[i]);
                // cout << "n2 = " << n2 << endl;
                v[i] = v[i] / ll(pow(2, n2));
                n2Sum += n2;
        }
        for (int i : v)
                // cout << i << " ";
                // cout << endl;
                sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++)
        {
                sum += v[i];
        }
        // cout << "sum = " << sum << endl;
        // cout << "n2Sum = " << n2Sum << endl;
        v[n - 1] *= ll(pow(2, n2Sum));
        // cout << "v[n-1]=" << v[n - 1] << endl;
        sum += v[n - 1];
        cout << sum << endl;
}

//................................
