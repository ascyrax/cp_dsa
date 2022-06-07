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

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n, k;
        cin >> n >> k;
        // map<int, int> m;
        vector<pair<int, int>> events;
        for (int i = 0; i < n; i++)
        {
                int l, r;
                cin >> l >> r;
                // m[l]++;
                // m[r]--;
                events.pb(make_pair(l, -1));
                events.pb(make_pair(r, 1));
        }
        sort(events.begin(), events.end());
        vector<pair<int, int>> ans;
        int left, right;
        int carry = 1;
        if (k == 1)
        {
                left = events[0].first;
                events[0].second = 1;
        }
        for (int i = 1; i < (int)events.size(); i++)
        {
                if (events[i].second == -1)
                {
                        carry++;
                }
                else
                        carry--;
                events[i].second = carry;
                if (events[i - 1].second < k && events[i].second == k)
                        left = events[i].first;
                if (events[i].second < k && events[i - 1].second == k)
                {
                        right = events[i].first;
                        ans.pb(make_pair(left, right));
                }
        }
        cout << (int)ans.size() << endl;
        for (auto el : ans)
                cout << el.first << " " << el.second << endl;
        // vector<pair<int, int>> v;
        // for (auto el : m)
        // {
        //         // cout << el.first << " " << el.second << endl;
        //         v.pb(make_pair(el.second, el.first));
        // }
        // int carry = 1; //v[0].first has got to be =1
        // vector<int> ref;
        // for (auto el : v)
        //         ref.pb(el.first);
        // // for (int i : ref)
        // //         cout << i << " ";
        // // cout << endl;
        // // for (auto el : v)
        // //         cout << el.first << " ";
        // // cout << endl;
        // // for (auto el : v)
        // //         cout << el.second << " ";
        // // cout << endl;
        // for (int i = 1; i < (int)v.size(); i++)
        // {
        //         if (v[i].first < 0)
        //         {
        //                 int temp = v[i].first;
        //                 v[i].first = carry;
        //                 carry += temp;
        //         }
        //         else if (v[i].first > 0)
        //         {
        //                 carry += v[i].first;
        //                 v[i].first = carry;
        //         }
        //         else if (v[i].first == 0)
        //         {
        //                 v[i].first = carry;
        //         }
        //         // cout << "carry = " << carry << endl;
        // }
        // // for (auto el : v)
        // //         cout << el.first << " ";
        // // cout << endl;
        // // for (auto el : v)
        // //         cout << el.second << " ";
        // // cout << endl;
        // vector<pair<int, int>> ans;
        // int left = 2e9, right = 2e9;
        // for (int i = 0; i < (int)v.size(); i++)
        // {
        //         pair<int, int> el = v[i];
        //         if (el.first >= k && el.first + ref[i] >= k)
        //         {
        //                 left = min(left, el.second);
        //         }
        //         else if (left != 2e9)
        //         {
        //                 right = el.second;
        //                 ans.pb(make_pair(left, right));
        //                 left = 2e9;
        //                 right = 2e9;
        //         }
        // }
        // cout << (int)ans.size() << endl;
        // for (auto el : ans)
        //         cout << el.first << " " << el.second << endl;
}

//................................
