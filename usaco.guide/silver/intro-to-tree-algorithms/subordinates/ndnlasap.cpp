#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define size(x) (int)(x).size()
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
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

vector<int> nSubordinates(int(2e5 + 1));
vector<vector<int>> v(int(2e5 + 1));

//...............................

void dfs(int current, int parent)
{
        nSubordinates[current]++;
        for (int child : v[current])
        {
                if (child == parent)
                        continue;
                else
                {
                        dfs(child, current); //cz current will be the parent of the child
                        nSubordinates[current] += nSubordinates[child];
                }
        }
}

void suraj()
{
        int n;
        cin >> n;
        nSubordinates.resize(n + 1);
        v.resize(n + 1);
        for (int i = 2; i <= n; i++)
        {
                int boss;
                cin >> boss;
                v[boss].pb(i);
        }
        //for each vertex find the no of subordinates of the vertices
        dfs(1, 0);
        for (int i = 1; i <= n; i++)
        {
                cout << nSubordinates[i] - 1 << " "; //cz we need to count only the people who are below the current one ie
                //we need to leave the person cz he is not considered as the boss of himself
        }
        cout << endl;
}

//................................
