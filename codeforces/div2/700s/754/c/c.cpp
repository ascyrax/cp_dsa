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

//...............................

void suraj()
{
        int n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0, r = 1;

        // m[s[0]]++;
        // m[s[1]]++;
        int ans = 1e6;
        // while (1)
        // {
        //         m[s[r]]++;
        //         if (m['a'] > m['b'] && m['a'] > m['c'])
        //         {
        //                 ans = min(ans, r - l + 1);
        //         }
        // }
        // cout << ans << endl;
        map<char, int> cnt;
        vector<int> psa(n + 1), psb(n + 1), psc(n + 1);
        for (int i = 0; i < n; i++)
        {
                cnt[s[i]]++;
                psa[i + 1] = cnt['a'];
                psb[i + 1] = cnt['b'];
                psc[i + 1] = cnt['c'];
        }
        for (int len = 2; len <= 7; len++)
        {
                // for (int i = 0; i <= n - len; i++)
                // {
                //         map<char, int> m;
                //         for (int j = i; j <= i + len - 1; j++)
                //         {
                //                 // cout << "len = " << len << " i = " << i << " j= " << j << endl;
                //                 m[s[j]]++;
                //         }
                //         // cout << m['a'] << " " << m['b'] << " " << m['c'] << endl;
                //         if (m['a'] > m['b'] && m['a'] > m['c'])
                //         {
                //                 ans = min(ans, len);
                //         }
                // }
                for (int i = 0; i <= n - 1 - (len - 1); i++)
                {
                        int cnta = psa[i + len] - psa[i];
                        int cntb = psb[i + len] - psb[i];
                        int cntc = psc[i + len] - psc[i];
                        if (cnta > cntb && cnta > cntc)
                        {
                                ans = min(ans, len);
                        }
                }
        }
        if (ans == 1e6)
                cout << -1 << endl;
        else
                cout << ans << endl;
}

//................................
