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
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        sort(v.rbegin(), v.rend());
        int mx = v[0];
        int ans = mx;

        for (int a = 0; a <= 5; a++)
        {
                for (int b = 0; b <= 5; b++)
                {

                        if ((mx - a * 1 - b * 2) % 3 != 0)
                                continue;
                        int c = (mx - a * 1 - b * 2) / 3;
                        for (int i = 0; i < n; i++)
                        {
                                if (check(v[i], a, b, c))
                                {
                                        ans = min(ans, a + b + c);
                                }
                        }
                }
        }

        // if (v[ptr] % 3 == 0)
        // {
        //         cout << "if" << endl;
        //         if (cnt1 > 0 && cnt2 > 0)
        //         {
        //                 cout << cnt3mx + 1 << endl;
        //         }
        //         else
        //                 cout << cnt3mx << endl;
        // }
        // else
        // {
        //         cout << "else" << endl;
        //         if (cnt1 > 0 && cnt2 > 0)
        //                 cout << (cnt3mx + 1) + 1 << endl;
        //         else
        //                 cout << (cnt3mx) + 1 << endl;
        // }
}

//................................
