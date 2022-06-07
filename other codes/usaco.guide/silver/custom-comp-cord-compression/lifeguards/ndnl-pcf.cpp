#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define endl "\n"
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);                  \
        cout.tie(0);
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
        freopen("lifeguards.in", "r", stdin);
        freopen("lifeguards.out", "w", stdout);
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

//...............................

void suraj()
{

        int n;
        cin >> n;
        //my method
        map<int, int> m;
        vector<pair<int, int>> vspecial;
        vector<int> vindex;
        vector<pair<int, int>> vqueries;
        for (int i = 0; i < n; i++)
        {
                int l, r;
                cin >> l >> r;
                m[l]++;
                m[r]--;
                vindex.pb(l);
                vindex.pb(r);
                vqueries.pb(make_pair(l, r));
        }
        sort(vindex.begin(), vindex.end());
        vindex.erase(unique(vindex.begin(), vindex.end()), vindex.end());
        for (int i : vindex)
                vspecial.push_back(make_pair(i, m[i]));
        for (int i = 1; i < int(vspecial.size()); i++)
        {
                vspecial[i].second += vspecial[i - 1].second;
        }
        // for (auto i : vspecial)
        //         cout << i.second << "  ";
        // cout << endl;
        // for (auto i : vspecial)
        //         cout << i.first << "  ";
        // cout << endl;
        // // this will exceed in timelimit as O(n^2)
        // // for (int i = 0; i < n; i++)
        // // {
        // //         auto query = vqueries[i];
        // //         auto index_l = lower_bound(vspecial.begin(), vspecial.end(), query.first) - vspecial.begin();
        // //         auto index_r = lower_bound(vspecial.begin(), vspecial.end(), query.second) - vspecial.begin();
        // //         cout << index_l << " " << index_r << endl;
        // //         for(int i)
        // // }
        vector<int> ps(vspecial.size());
        ps[0] = 0;
        for (int i = 1; i < vspecial.size(); i++)
        {
                if (vspecial[i - 1].second == 1)
                {
                        ps[i] = ps[i - 1] + vspecial[i].first - vspecial[i - 1].first;
                }
                else
                        ps[i] = ps[i - 1];
        }
        int total = 0;
        for (int i = 1; i < vspecial.size(); i++)
        {
                if (vspecial[i - 1].second != 0)
                {
                        total += (vspecial[i].first - vspecial[i - 1].first);
                }
        }
        int minSingle = 1e9;
        // for (int i : ps)
        //         cout << i << " ";
        // cout << endl;
        for (int i = 0; i < vqueries.size(); i++)
        {
                auto query = vqueries[i];
                auto index_l = lower_bound(vindex.begin(), vindex.end(), query.first) - vindex.begin();
                auto index_r = lower_bound(vindex.begin(), vindex.end(), query.second) - vindex.begin();
                minSingle = min(minSingle, ps[index_r] - ps[index_l]);
        }
        // cout << "total " << total << endl;
        cout << total - minSingle << endl;
        // nick wu's idea
        // sort(vqueries.begin(), vqueries.end());
        // for (int i = 0; i < n; i++)
        // {
        //         auto query = vqueries[i];
        // }
}

//................................
