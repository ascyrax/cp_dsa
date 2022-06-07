#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> mc(n);
        int cnt0 = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
                cin >> mc[i];
                if (mc[i] == 0)
                {
                        cnt0++;
                }
                else
                {
                        v.pb(mc[i]);
                }
        }
        vector<int> pc(m);
        for (int i = 0; i < m; i++)
        {
                cin >> pc[i];
                if (pc[i] == 0)
                {
                        cnt0++;
                }
                else
                        v.pb(pc[i]);
        }
        sort(v.rbegin(), v.rend());
        if (v[0] <= k + cnt0)
        {
                for (int i = 0; i < cnt0; i++)
                        cout << 0 << " ";
                for (int i : v)
                        cout << i << " ";
                cout << endl;
        }
        else
        {
                cout << -1 << endl;
        }
}

//................................
