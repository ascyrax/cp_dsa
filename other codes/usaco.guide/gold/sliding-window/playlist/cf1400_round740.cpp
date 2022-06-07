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

void suraj()
{
        // int n;
        // cin >> n;
        // vector<int> v(n);
        // for (int &i : v)
        //         cin >> i;

        // int ans = 0;
        // // int flag = 0;
        // int r = 0;
        // set<int> s;

        // for (int i = 0; i < n; i++)
        // {
        //         for (int j = r; j < n; j++)
        //         {
        //                 if (!s.count(v[r]))
        //                 {
        //                         s.insert(v[j]);
        //                         r++;
        //                 }
        //                 else
        //                 {
        //                         ans = max(ans, (int)s.size());
        //                         s.erase(v[i]);
        //                         break;
        //                 }
        //                 if (r == n)
        //                         break;
        //         }
        //         ans = max(ans, (int)s.size());
        //         if (r == n)
        //                 break;
        // }
        // cout << ans << endl;
        int n;
        int k;
        cin >> n >> k;
        vector<int> nums(n);

        for (int &i : nums)
                cin >> i;

        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
                // s.insert(nums[i]);
                m[nums[i]]++;
                // ans.push_back(*(s.end()-1));
        }
        ans.push_back((--m.end())->first);
        for (auto a : m)
                cout << a.first << " " << a.second << endl;
        cout << "-------------------------" << endl;
        int len = (int)nums.size();
        for (int i = 0; i < len - k; i++)
        {
                // m[nums[i]]--;
                if (m[nums[i]] == 1)
                        m.erase(nums[i]);
                else
                        m[nums[i]]--;
                if (i + k < len)
                        m[nums[i + k]]++;
                for (auto a : m)
                        cout << a.first << " " << a.second << endl;
                cout << "-------------------------" << endl;

                ans.push_back((--m.end())->first);
        }
        for (int i : ans)
                cout << i << " ";
        cout << endl;
}

//................................

// 8 3
// 1 3 -1 -3 5 3 6 7

// 8 4
// -7 -8 7 5 7 1 6 0