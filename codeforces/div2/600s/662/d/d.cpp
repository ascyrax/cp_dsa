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
int n;
vector<pair<int, int>> cnt;
map<int, int> m;
vector<int> v;
//...............................
bool check(int m)
{
        vector<int> flag(n, -1);
        for (auto el : cnt)
        {
                int val = el.second;
                int count = el.first;
                // first flag with value=-1
        }
}
//...............................

void suraj()
{

        cin >> n;
        v = vector<int>(n, 0);
        for (int &i : v)
        {
                cin >> i;
                m[i]++;
        }

        for (auto el : m)
        {
                cnt.pb(make_pair(el.second, el.first));
        }
        sort(cnt.rbegin(), cnt.rend());
        int l = 0, r = n - 2;
        while (l < r)
        {
                int m = l + (r - l) / 2;
                if (check(m))
                {
                        l = m;
                }
                else
                {
                        r = m - 1;
                }
        }
        cout << l << endl;
}

//................................
