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
        // int s, n;
        // cin >> s >> n;
        // vector<int> v(n, 1);
        // int diff = s - n;
        // // vector<int> vs;
        // // while (diff > 0)
        // // {
        // //         int rem = diff % 10;
        // //         diff /= 10;
        // //         vs.pb(rem);
        // // }
        // // reverse(vs.begin(), vs.end());
        // v[0] += diff;
        // for (int i : v)
        //         cout << i << " ";
        // cout << endl;
        string s;
        cin >> s;
        int n;
        cin >> n;
        int lens = int(s.size());
        int left = 0;
        int copy = stoi(s);
        vector<int> ans;
        while (true)
        {
                int current = stoi("" + s[0]);
                for (int i = 0; i < lens - (left + 1); i++)
                        current *= 10;
                if (copy - current >= n - 1)
                {
                        copy -= current;
                        ans.pb(current);
                }
                else
                {
                        ans.pb(1);
                        copy--;
                }
                // if (stoi(s) -))
        }
        for (int i : ans)
                cout << i << " ";
        cout << endl;
}

//................................
