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

//...............................
int k;
// vector<pair<int, int>> needed[n];
vector<pair<int, int>> calcFactors(int n)
{
        // vector<pair<int, int>> temp;
        vector<pair<int, int>> vp;
        int ncopy = n;
        for (int i = 2; i * i <= ncopy; i++)
        {
                int cnt = 0;
                while (n % i == 0)
                {
                        n = n / i;
                        cnt++;
                }
                if (cnt % k == 0)
                {
                        // vp.pb(make_pair(i, 0));
                        continue;
                }
                else
                {
                        vp.pb(make_pair(i, cnt % k));
                        // temp.pb(make_pair(i, k - cnt % k));
                }
        }
        if (n > 1)
        {
                vp.pb(make_pair(n, 1));
        }
        // needed.pb(temp);
        return vp;
}
vector<pair<int, int>> calcNeeded(vector<pair<int, int>> vp)
{
        vector<pair<int, int>> ans;
        for (int i = 0; i < int(vp.size()); i++)
        {
                ans.pb(make_pair(vp[i].first, k - vp[i].second));
        }
        return ans;
}
void suraj()
{
        int n;
        cin >> n;

        cin >> k;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;

        // vector<pair<int, int>> vp;
        // for (int i = 0; i < n; i++)
        // {
        //         vp.pb(make_pair(v[i], i));
        // }
        // sort(vp.begin(), vp.end());
        vector<pair<int, int>> factors[n], needed[n];
        map<vector<pair<int, int>>, int> m;
        for (int i = 0; i < n; i++)
        {
                // cout << "i " << i << endl;
                factors[i] = calcFactors(v[i]);
                // cout << "factors " << endl;
                // for (int j = 0; j < factors[i].size(); j++)
                // {
                //         // cout << j << endl;
                //         cout << factors[i][j].first << " " << factors[i][j].second << endl;
                // }
                needed[i] = calcNeeded(factors[i]);
                // cout << "needed " << endl;
                // for (int j = 0; j < needed[i].size(); j++)
                // {
                //         // cout << j << endl;
                //         cout << needed[i][j].first << " " << needed[i][j].second << endl;
                // }
                m[factors[i]]++;
        }
        // for (auto el : m)
        // {

        //         cout << typeid(el).name() << " " << el.second << endl;
        // }
        // for (int i = 0; i < n; i++)
        // {
        //         for (int j = 0; j < factors[i].size(); j++)
        //                 cout << factors[i][j].first << " " << factors[i][j].second << endl;
        // }
        // cout << endl;

        ll ans = 0;
        ll count = 0;
        for (int i = 0; i < n; i++)
        {
                if (needed[i].size() == 0)
                {
                        // cout << "if" << endl;
                        count++;
                        continue;
                }
                else
                {
                        // cout << "else" << endl;
                        if (factors[i] == needed[i])
                        {
                                ans += m[needed[i]] - 1;
                        }
                        else
                        {
                                ans += m[needed[i]];
                        }
                        // cout << m[needed[i]] << endl;
                        // cout << ans << endl;
                }
        }
        // cout << "ans " << ans << endl;
        ans /= 2;
        ans += (count * (count - 1) / 2);
        cout << ans << endl;
}

//................................
