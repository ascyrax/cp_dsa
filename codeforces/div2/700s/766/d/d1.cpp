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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
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

        vector<int> v(n);
        vector<bool> flag(1e6 + 1);
        int mx = 0;

        map<int, vector<int>> m;

        for (int &i : v)
        {
                cin >> i;
                for (int j = 1; j <= 1e6; j++)
                {
                        if (i % j == 0)
                                m[j].pb(i);
                }
                flag[i] = true;
                mx = max(mx, i);
        }

        int cnt = 0;

        // for (int i = 1; i <= mx; i++)
        // {
        //         if (flag[i])
        //                 continue;
        //         int temp = -1;
        //         for (int j = 0; j < n; j++)
        //         {
        //                 if (v[j] % i == 0)
        //                 {
        //                         if (temp == -1)
        //                                 temp = v[j];
        //                         else
        //                                 temp = __gcd(v[j], temp);
        //                 }
        //         }
        //         if (temp == i)
        //         {
        //                 cnt++;
        //                 flag[i] = true;
        //         }
        // }

        for (int i = 1; i <= 1e6; i++)
        {
                int gcd = -1;
                if (m[i].size() == 0)
                        continue;
                // cout << "i = " << i << endl;
                // cout << "m[i] : " << endl;

                for (auto el : m[i])
                {
                        // cout << el << " ";
                        if (gcd == -1)
                                gcd = el;
                        else
                                gcd = __gcd(gcd, el);
                }
                // cout << endl;
                if (gcd == i && flag[i] == false)
                {
                        // cout << "gcd = i for i = " << i << endl;
                        cnt++;
                }
        }
        cout << cnt << endl;
}

//................................
// int
// int
// int
// int
