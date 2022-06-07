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
        string s;
        cin >> s;
        set<char> sa;
        for (char c : s)
                sa.insert(c);
        int uniqLen = sa.size();
        int l = 0, r = 0;
        set<char> sb;
        map<char, int> m;
        int ans = n;
        // cout << "uniqLen: " << uniqLen << endl;
        for (int r = 0; r < n; r++)
        {
                m[s[r]]++;
                sb.insert(s[r]);
                if (sb.size() < uniqLen)
                        continue;
                while (1)
                {
                        if (m[s[l]] > 1)
                        {
                                m[s[l]]--;
                                l++;
                        }
                        else
                                break;
                }
                ans = min(ans, r - l + 1);
        }
        cout << ans << endl;
}

//................................
// int
// int
// int
// int
