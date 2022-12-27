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
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string ans = s;
        int sum = 0, maxDiff = 0;
        ;
        for (int i = 0; i < n; i++)
        {
                int l = s[i] - 'a';
                int r = 'z' - s[i];
                maxDiff += max(l, r);
        }
        if (k <= maxDiff)
        {
                // cout << k << endl;
                int ptr = 0;
                while (k)
                {
                        int l = s[ptr] - 'a';
                        int r = 'z' - s[ptr];
                        // cout << "l = " << l << " r = " << r << endl;
                        if (l > r)
                        {
                                if (l > k)
                                {
                                        ans[ptr] = ans[ptr] - k;
                                        k = 0;
                                }
                                else
                                {
                                        ans[ptr] = 'a';
                                        k -= l;
                                }
                        }
                        else
                        {
                                if (r > k)
                                {
                                        // cout << ans[ptr] << endl;
                                        ans[ptr] = ans[ptr] + k;
                                        // cout << ans[ptr] << endl;
                                        k = 0;
                                }
                                else
                                {
                                        ans[ptr] = 'z';
                                        k -= r;
                                }
                        }
                        ptr++;
                }
                cout << ans << endl;
        }
        else
        {
                cout << "-1" << endl;
        }
}

//................................
