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
int n;
vector<int> v;
//...............................

//...............................

void suraj()
{
        cin >> n;
        v = vector<int>(2 * n);
        for (int &i : v)
                cin >> i;
        sort(v.begin(), v.end());

        int ans = 1e9;
        int prev = -1, curr = -1, sum = 0;
        for (int i = 0; i < 2 * n; i++)
        {
                for (int j = 0; j < 2 * n; j++)
                {
                        // cout << "i = " << i << "     j = " << j << endl;
                        sum = 0;
                        if (i == j)
                                continue;
                        //i and j will go on the single person boats

                        for (int x = 0; x < 2 * n; x++)
                        {
                                // cout << "x = " << x << endl;
                                if (x == i || x == j)
                                        continue;
                                if (prev == -1)
                                        prev = x;
                                else
                                {
                                        sum += abs(v[x] - v[prev]);
                                        prev = -1;
                                }
                                // cout << "prev = " << prev << endl;
                        }
                        // cout << sum << endl;
                        ans = min(ans, sum);
                }
        }

        cout << ans << endl;
}

//................................
