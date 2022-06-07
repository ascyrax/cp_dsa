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
void suraj(), suraj2();

int main()
{
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //ioss
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
                suraj2();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................
int n;
vector<vector<int>> ans, ans2;
vector<int> subset;
//...............................
void search(int k)
{

        if (k == n + 1)
        {
                // process subset
                ans.pb(subset);
        }
        else
        {
                search(k + 1);
                subset.pb(k);
                search(k + 1);
                subset.pop_back();
        }
        return;
}

//...............................

void suraj()
{
        n = 5;
        search(1);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
                for (auto j : i)
                        cout << j << " ";
                cout << endl;
        }
        cout << "....................." << endl;
}
void suraj2()
{
        n = 5;

        for (int i = 0; i <= (int)pow(2, n) - 1; i++)
        {
                vector<int> subset2;
                for (int j = 1; j <= n; j++)
                {
                        if (i & (1 << (j - 1)))
                                subset2.pb(j);
                }
                ans2.pb(subset2);
        }
        sort(ans2.begin(), ans2.end());
        for (auto i : ans2)
        {
                for (auto j : i)
                        cout << j << " ";
                cout << endl;
        }
}

//................................
