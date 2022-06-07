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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        freopen("outofplace.in", "r", stdin);
        freopen("outofplace.out", "w", stdout);
        // cout << setprecision(15) << fixed;
        // int t;
        // cin >> t;
        // for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> a(n), b;
        for (int &i : a)
                cin >> i;
        b = a;
        sort(b.begin(), b.end());
        int flag = 0, l = -1, r = -1;
        for (int i = 0; i < n; i++)
        {
                if (flag == 0)
                {
                        if (a[i] != b[i])
                        {
                                l = i;
                                flag = 1;
                        }
                }
                else if (flag == 1)
                {
                        if (a[i] != b[i])
                        {
                                r = i;
                        }
                }
        }
        int nSwaps = r - l;
        for (int i = l + 1; i <= r; i++)
        {
                if (a[i] == a[i - 1])
                {
                        nSwaps--;
                }
        }
        cout << nSwaps << endl;
}

//................................
// int
// int
// int
// int
