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

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        sort(v.rbegin(), v.rend());
        map<int, int> cnt;
        int mx = v[0], cntMx = 1;
        for (int i : v)
        {
                cnt[i]++;
                if (cnt[i] > cntMx)
                {
                        cntMx = cnt[i];
                        mx = i;
                }
        }
        int a = 0, b = 0;
        for (auto el : cnt)
        {
                // cout << " el : " << endl
                //      << el.first << " " << el.second << endl;
                if (el.first == mx)
                        continue;
                else if (el.second >= cnt[mx] - 1)
                {
                        a++;
                }
                else
                {
                        b += el.second;
                }
                // cout << "a = " << a << " b = " << b << endl;
        }
        b /= (cnt[mx] - 1);
        // cout << "mx: " << mx << " cntMx = " << cnt[mx] << endl;
        // cout << "a = " << a << "b = " << b << endl;
        cout << a + b << endl;
}

//................................
