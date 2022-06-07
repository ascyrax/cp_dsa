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
vector<int> p, siz;
//...............................

int fparent(int node) //gives the root of the tree..i.e. the topmost parent
{
        if (p[node] != node)
        {
                p[node] = fparent(p[node]);
        }
        return p[node];
}

void funion(int b, int c)
{
        int pb = fparent(b);
        int pc = fparent(c);
        if (pb == pc)
                return;
        else
        {
                if (siz[pb] < siz[pc])
                {
                        siz[pb]++;
                        p[pb] = pc;
                }
                else if (siz[pc] <= siz[pb])
                {
                        p[pc] = pb;
                        siz[pc]++;
                }
        }
        return;
}

string fget(int b, int c)
{
        int pb = fparent(b);
        int pc = fparent(c);
        if (pb == pc)
                return "YES";
        else
                return "NO";
}
//...............................

void suraj()
{
        cin >> n >> m;

        p = vector<int>(n + 1);
        siz = vector<int>(n + 1, 1);

        // initialize the parents of each int to itself
        for (int i = 1; i <= n; i++)
        {
                p[i] = i;
        }

        for (int i = 0; i < m; i++)
        {
                string a;
                cin >> a;
                int b, c;
                cin >> b >> c;

                if (a == "union")
                {

                        funion(b, c);
                }
                else if (a == "get")
                {
                        cout << fget(b, c) << endl;
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
