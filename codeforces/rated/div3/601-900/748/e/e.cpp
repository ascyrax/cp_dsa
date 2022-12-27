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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        sort(v.begin(), v.end());
        int flag = 1;
        for (int i = 1; i < n; i++)
        {
                if (v[i] != v[0])
                {
                        flag = -1;
                        break;
                }
        }
        if (flag == 1)
        {
                cout << -1 << endl;
                return;
        }
        int smallest = v[0];
        vector<int> diff;
        for (int i = 1; i < n; i++)
        {
                if (v[i] != v[0])
                {
                        diff.pb(v[i] - v[0]);
                }
        }
        for (int i : diff)
                cout << i << " ";
        cout << endl;
        ll lcm = 1;
        for (int i = 1; i <= 1e6; i++)
        {
                int flag = 1;
                int divCnt = 0;
                for (int j = 0; j < (int)diff.size(); j++)
                {
                        if (diff[j] % i == 0)
                        {
                                flag = 1;
                                divCnt++;
                        }
                        // else
                        // {
                        //         flag = -1;
                        //         // break;
                        // }
                }
                // if (flag == 1)
                // lcm = max(lcm, (ll)i);
                if (divCnt >= n / 2)
                {
                        lcm = max(lcm, (ll)i);
                }
        }
        cout << lcm << endl;
}

//................................
