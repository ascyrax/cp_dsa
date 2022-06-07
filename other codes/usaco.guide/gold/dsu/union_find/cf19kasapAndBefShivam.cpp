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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
                cout
            << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................
int n, q;
vector<int> parentOf;
vector<int> depth;
//...............................
int findParent(int node)
{
        if (parentOf[node] == node)
        {
                return node;
        }
        else
                return findParent(parentOf[node]);
}

void join(int b, int c)
{
        if (depth[findParent(b)] > depth[findParent(c)])
        {
                parentOf[findParent(c)] = findParent(b);
        }
        else if (depth[findParent(b)] < depth[findParent(c)])
        {
                parentOf[findParent(b)] = findParent(c);
        }
        else if (depth[findParent(b)] == depth[findParent(c)])
        {
                parentOf[findParent(b)] = findParent(c);
                depth[findParent(c)]++;
        }
}

bool isEdge(int b, int c)
{
        if (findParent(b) == findParent(c))
                return true;
        else
                return false;
}
//...............................

void suraj()
{
        cin >> n >> q;
        parentOf = vector<int>(n, 0);
        depth = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
                parentOf[i] = i;
        for (int i = 0; i < q; i++)
        {
                int a, b, c;
                cin >> a >> b >> c;
                if (a == 0)
                {
                        join(b, c);
                        // since q~1e5 , join should not be O(n) and above.
                }
                else if (a == 1)
                {
                        if (isEdge(b, c))
                        // since q~1e5 , isEdge should not be O(n) and above.
                        {
                                cout << 1 << endl;
                        }
                        else
                                cout << 0 << endl;
                }
        }
}

//................................
