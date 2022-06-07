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
        int n, k;
        cin >> n >> k;
        vector<int> b(n);
        for (int &i : b)
                cin >> i;
        vector<int> basket;
        sort(b.rbegin(), b.rend());
        vector<int> baskets;
        if (n == 1)
        {
                cout << (b[0] / 4) * 2 << endl;
        }
        else if (n == 2)
        {
                cout << (b[0] / 2 + b[1] / 2) << endl;
        }
        else if (n == 3)
        {
                cout << b[2] + b[0] / 2 << endl;
        }
        else
        {
                for (int i = 0; i < 2; i++)
                        baskets.pb(b[i] / 2);
                for (int i = 2; i < 4; i++)
                        baskets.pb(b[i]);
                sort(baskets.rbegin(), baskets.rend());
                cout << baskets[2] + baskets[3] << endl;
        }
}

//................................
