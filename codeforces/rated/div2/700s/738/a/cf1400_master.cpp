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
        int t;
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        // vector<int> v2 = v;
        // sort(v2.begin(), v2.end());
        // int maxVal = v2[n - 1];
        // int ans = maxVal;
        // int prevAns = 1e9 + 9;
        // while (prevAns != ans)
        // {
        //         prevAns = ans;
        //         for (int i = 0; i < n; i++)
        //         {
        //                 ans = min(ans, v[i] & maxVal);
        //         }
        // }

        // cout << ans << endl;
        while (true)
        {
                vector<pair<int, int>> vp;
                for (int i = 0; i < n; i++)
                {
                        vp.pb(make_pair(v[i], i));
                }
                sort(vp.begin(), vp.end());
                int l = min(vp[0].second, vp[n - 1].second);
                int r = max(vp[0].second, vp[n - 1].second);
                vector<int> vCopy = v;
                for (int i = 0; i <= r - l; i++)
                {
                        vCopy[l + i] = v[l + i] & v[r - i];
                }
                // for (int i : v)
                //         cout << i << " ";
                // cout << endl;
                // for (int i : vCopy)
                //         cout << i << " ";
                // cout << endl;
                if (v == vCopy)
                {
                        // cout << "copy found";
                        break;
                }
                v = vCopy;
        }
        sort(v.rbegin(), v.rend());
        cout << v[0] << endl;
}

//................................
