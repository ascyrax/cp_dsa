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
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
vector<int> a, b;
// vector<bool> visited;
queue<int> q;
vector<int> d, f;

//...............................
void print(int x)
{
        if (x == n)
                return;
        print(f[x]);
        cout << x << " ";
}
//...............................

void suraj()
{
        cin >> n;
        a = vector<int>(n + 1);
        b = vector<int>(n + 1);
        d = vector<int>(n + 1, 0);
        f = vector<int>(n + 1, -1);
        // visited = vector<bool>(n + 1, false);

        for (int i = 1; i <= n; i++)
        {
                cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
                cin >> b[i];
        }
        q.push(n);
        // visited[n] = true;
        // cout << "HI" << endl;
        int dis = n;
        while (!q.empty())
        {
                int x = q.front();
                q.pop();
                if (x <= 0)
                {
                        cout << d[x] << endl;
                        print(x);
                        // cout << "hello" << endl;
                        return;
                }
                int y = x + b[x];
                // cout << "x = " << x << " y = " << y << endl;
                for (int i = min(dis - 1, y - 1); i >= y - a[y]; i--)
                {
                        // if (!visited[i])
                        {
                                q.push(i);
                                // visited[i] = true;
                                d[i] = d[x] + 1;
                                f[i] = x;
                        }
                }
                dis = min(dis, y - a[y]);
        }
        cout << -1 << endl;
}

//................................
