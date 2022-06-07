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
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}
int n;
vector<int> v;

//...............................
bool findX(int mr)
{
        int l = v[0], r = v[n - 1];
        while (l < r)
        {
                int m = l + (r - l) / 2;

                if ()
        }
        return l;
}
//...............................
bool check(int mr)
{
        int x = findX(mr); // using binary search again
}
//...............................

void suraj()
{
        cin >> n;

        v = vector<int>(n);

        for (int &i : v)
                cin >> i;

        sort(v.begin(), v.end());

        int lr = 0, rr = 1e9;

        while (lr < rr)
        {
                int mr = lr + (rr - lr) / 2;

                if (check(mr))
                        rr = mr;
                else
                        lr = mr + 1;
        }

        cout << lr << endl;
}

//................................
// int
// int
// int
// int
