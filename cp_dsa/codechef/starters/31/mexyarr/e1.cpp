// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

double startTime;

double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

        ioss

            // startTime=(double)clock();

            // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

            // cout << setprecision(15) << fixed;

            int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> ans(n + 1, -3);
        int next = 0; // => next value of b can be 0 or 1.i.e. next or next+1.
        // mex at index i can be 0 to i+1.
        for (int i = 0; i < n; i++)
        {
                cin >> v[i];
        }

        map<int, int> last; // last[2] means the last index until which we cannot use 2 in array a.// its so becz b[i]=2 i.e. b requests for mex at index i to be 2.
        for (int i = 0; i <= n; i++)
        {
                last[i] = -1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
                if (v[i] > i + 1)
                {
                        cout << -1 << endl;
                        return;
                }
                else if (v[i] == -1)
                {
                        ;
                }
                else
                {
                        last[v[i]] = max(last[v[i]], i);
                }
        }
        // cout << "last" << endl;
        // for (auto el : last)
        // {
        //         cout << el.first << " " << el.second << endl;
        // }
        vector<pair<int, int>> temp;
        for (auto el : last)
                temp.pb(make_pair(el.second, el.first));
        sort(temp.begin(), temp.end());
        // cout << "temp" << endl;
        // for (auto el : temp)
        // {
        //         cout << el.first << " " << el.second << endl;
        // }
        queue<int> q;
        for (int i = 0; i <= n; i++)
        {
                if (temp[i].first == -1)
                {
                        q.push(temp[i].second);
                }
                else
                {
                        ans[temp[i].first + 1] = temp[i].second;
                }
        }

        for (int i = 0; i <= n; i++)
        {
                if (ans[i] == -3)
                {
                        ans[i] = q.front();
                        q.pop();
                }
        }

        ans.ppb();

        for (auto el : ans)
                cout << el << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
