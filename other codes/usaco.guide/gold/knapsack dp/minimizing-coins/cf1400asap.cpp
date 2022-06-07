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
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

const int mod = 1e9 + 7;

//...............................

void suraj()
{
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        // sort(v.begin(), v.end());
        if (x < v[0])
        {
                cout << -1 << endl;
                return;
        }
        vector<int> dp((1e6) + 1);
        for (int i : v)
                dp[i] = 1;
        for (int i = 1; i <= x; i++)
        {
                int temp = 1e7;
                for (int j = 0; j < n; j++)
                {
                        if (i - v[j] > 0 && dp[i - v[j]] > 0)
                        {
                                temp = min(temp, dp[i - v[j]] + 1);
                        }
                }
                if (temp != 1e7)
                        dp[i] = dp[i] > 0 ? min(dp[i], temp) : temp;
                // cout << dp[i] << endl;
        }
        if (dp[x] == 0)
                cout << -1 << endl;
        else
                cout << dp[x] << endl;
}

//................................
