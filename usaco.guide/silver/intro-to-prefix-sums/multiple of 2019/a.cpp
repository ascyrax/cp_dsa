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
        string s;
        cin >> s;
        map<int, int> m;
        ll sum = 0;
        vector<int> ps(s.size());
        ps[0] = s[0] - '0';
        ll ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
                if (i > 0)
                        ps[i] = ps[i - 1] * 10 + (s[i] - '0');
                ps[i] = ps[i] % 2019;
                m[ps[i]]++;
                if (ps[i] == 0)
                {
                        cout << "if" << endl;
                        ans += m[ps[i]];
                }
                else
                {
                        cout << "else" << endl;
                        cout << ps[i] << endl;
                        ans += max(0, m[ps[i]] - 1);
                }
        }
        for (int i : ps)
                cout << i << " ";
        cout << endl;
        cout << ans << endl;
}

//................................
// int
// int
// int
// int
