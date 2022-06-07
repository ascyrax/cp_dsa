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

map<int, int> parent;
map<int, int> dg;
//...............................
int findParent(int node)
{
        if (parent[node] == node)
        {
                return node;
        }
        else
        {
                return findParent(parent[node]);
        }
}
//...............................

void suraj()
{
        int n;
        cin >> n;

        vector<int> v(n);
        for (int &i : v)
                cin >> i;

        int l = 0, r = n - 1;

        for (int el : v)
                parent[el] = el;

        ll nEdges = 0;

        while (l < r)
        {
                // cout << "l = " << l << " , r = " << r << endl;
                if (l == r)
                {
                        break;
                }
                if (v[l] == v[r])
                {
                        l++;
                        r--;
                        continue;
                }
                else
                {
                        // cout << "else" << endl;
                        int mx = max(v[l], v[r]);
                        int mn = min(v[l], v[r]);

                        // cout << "mx = " << mx << " , mn = " << mn << endl;

                        int mxParent = findParent(mx);
                        int mnParent = findParent(mn);

                        // cout << "mxParent = " << mxParent << " , mnParent = " << mnParent << endl;

                        if (mxParent > mnParent)
                        {
                                // parent[mn] = mxParent;
                                parent[mnParent] = mxParent;
                                // if (dg.count(mnParent) == 0)
                                nEdges++;
                                // dg[mnParent] = mxParent;
                        }
                        else if (mnParent < mxParent)
                        {
                                // parent[mx] = mnParent;
                                parent[mxParent] = mnParent;
                                // if (dg.count(mxParent) == 0)
                                nEdges++;
                                // dg[mxParent] = mnParent;
                        }
                        else if (mxParent == mnParent)
                        {
                                // do nothing
                        }
                        l++;
                        r--;
                }
                // cout << "nEdges = " << nEdges << endl;
        }

        cout << nEdges << endl;
}

//................................
// int
// int
// int
// int
