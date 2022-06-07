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

//...............................

//...............................

void suraj()
{
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &i : a)
                cin >> i;
        for (int &i : b)
                cin >> i;
        int flag = -1;
        for (int i = 0; i <= pow(2, 9) - 1; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        flag = -1;
                        for (int k = 0; k < m; k++)
                        {
                                if ((a[j] & b[k] | i) == i)
                                {
                                        flag = 1;
                                        break;
                                }
                        }
                        if (flag == -1)
                                break;
                }
                if (flag == 1)
                {
                        cout << i << endl;
                        return;
                }
        }
}

//................................
