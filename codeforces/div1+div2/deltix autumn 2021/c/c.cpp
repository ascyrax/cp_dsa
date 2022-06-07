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
        int n, e;
        cin >> n >> e;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        int ans = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
                if (v[i] == 1 && visited[i] == false)
                {
                        cout << "i = " << i << endl;
                        int cnt = 1;
                        // go left
                        int j = i;
                        int prod = v[i];
                        while (1)
                        {
                                j = j - e;
                                if (j >= 0 && visited[j] == false)
                                {
                                        if (v[j] != 1)
                                        {
                                                cnt++;
                                                break;
                                        }
                                        else if (v[j] == 1)
                                        {
                                                cnt++;
                                        }
                                        visited[j] = true;
                                        prod *= v[j];
                                }
                                else
                                        break;
                        }
                        // go right
                        j = i;
                        while (1)
                        {
                                j = j + e;
                                if (j < n && visited[j] == false)
                                {
                                        if (v[j] == 1)
                                        {
                                                cnt++;
                                        }
                                        else
                                        {
                                                cnt++;
                                                break;
                                        }
                                        visited[j] = true;
                                        prod *= v[j];
                                }
                                else
                                        break;
                        }
                        cout << "cnt before decrementing = " << cnt << endl;
                        cnt--;
                        ans += ((cnt * (cnt + 1)) / 2);
                        cout << "ans = " << ans << endl;
                }
        }
        cout << ans << endl;
        cout << "-------------------------" << endl;
}

//................................
