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

        int a = 0, b = 0;
        int ab = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
                string s;
                cin >> s;
                if (s[s.size() - 1] == 'A' && s[0] == 'B')
                        ab++;
                else if (s[s.size() - 1] == 'A')
                        a++;
                else if (s[0] == 'B')
                        b++;

                for (int i = 0; i < s.size() - 1; i++)
                {
                        if (s.substr(i, 2) == "AB")
                                cnt++;
                }
        }
        // cout << "n = " << n << endl;
        // cout << "a = " << a << endl;
        // cout << "b = " << b << endl;
        // cout << "cnt = " << cnt << endl;

        if (ab > 0)
        {
                cnt += ab - 1;
                if (a > 0)
                {
                        cnt++;
                        a--;
                }
                if (b > 0)
                {
                        cnt++;
                        b--;
                }
                cnt += min(a, b);
        }
        else
        {
                cnt += min(a, b);
        }
        cout << cnt << endl;
}

//................................
// int
// int
// int
// int
