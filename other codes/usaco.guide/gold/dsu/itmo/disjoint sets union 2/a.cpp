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

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, m;
vector<int> p, siz, vMin, vMax, vCnt;
//...............................

vector<int> fparent(int node) //gives the root of the tree..i.e. the topmost parent
{
        if (p[node] != node)
        {
                p[node] = fparent(p[node])[0];
                vMin[node] = min(vMin[node], vMin[p[node]]);
                vMax[node] = max(vMax[node], vMax[p[node]]);
                vCnt[node] = vCnt[p[node]];
        }
        vector<int> arr = {p[node], vMin[node], vMax[node], vCnt[node]};
        return arr;
}

void funion(int b, int c)
{
        vector<int> vb = fparent(b), vc = fparent(c);
        int pb = fparent(b)[0];
        int pc = fparent(c)[0];
        if (pb == pc)
                return;
        else
        {
                if (siz[pb] < siz[pc])
                {
                        siz[pb]++;
                        p[pb] = pc;
                        // vMin[pb] = min(vMin[pb], vMin[pc]);
                        vMin[pc] = min(vMin[pb], vMin[pc]);
                        // vMax[pb] = max(vMax[pb], vMax[pc]);
                        vMax[pc] = max(vMax[pb], vMax[pc]);
                        int sum = vCnt[pb] + vCnt[pc];
                        // vCnt[pb] = sum;
                        vCnt[pc] = sum;
                }
                else if (siz[pc] <= siz[pb])
                {
                        siz[pc]++;
                        p[pc] = pb;
                        vMin[pb] = min(vMin[pb], vMin[pc]);
                        // vMin[pc] = min(vMin[pb], vMin[pc]);
                        vMax[pb] = max(vMax[pb], vMax[pc]);
                        // vMax[pc] = max(vMax[pb], vMax[pc]);
                        int sum = vCnt[pb] + vCnt[pc];
                        vCnt[pb] = sum;
                        // vCnt[pc] = sum;
                }
        }
        return;
}

vector<int> fget(int b)
{
        vector<int> ans = fparent(b);
        return ans;
}
//...............................

void suraj()
{
        cin >> n >> m;

        p = vector<int>(n + 1);
        siz = vector<int>(n + 1, 1);
        vMin = vector<int>(n + 1, n);
        vMax = vector<int>(n + 1, 0);
        vCnt = vector<int>(n + 1, 1);

        // initialize the parents of each int to itself
        for (int i = 1; i <= n; i++)
        {
                p[i] = i;
        }

        for (int i = 0; i < m; i++)
        {
                string a;
                cin >> a;

                if (a == "union")
                {
                        int b, c;
                        cin >> b >> c;
                        funion(b, c);
                }
                else if (a == "get")
                {
                        int b;
                        cin >> b;
                        vector<int> ans = fget(b);
                        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
                }
                // for (int i = 1; i <= n; i++)
                //         cout << p[i] << " ";
                // cout << endl;
                // for (int i = 1; i <= n; i++)
                //         cout << siz[i] << " ";
                // cout << endl;
        }
}

//................................
