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
double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        // ioss
        startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> cnt;
        multiset<int, greater<int>> ms;
        for (int i = 0; i < n; i++)
        {
                cin >> v[i];
                cnt[v[i]]++;
        }
        for (auto el : cnt)
                ms.insert(el.second);

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
                char ch;
                cin >> ch;
                int val;
                cin >> val;
                if (ch == '+')
                {
                        if (cnt.count(val) == 0)
                        {

                                cnt[val]++;
                                ms.insert(cnt[val]);
                        }
                        else
                        {
                                ms.erase(ms.find(cnt[val]));
                                cnt[val]++;
                                ms.insert(cnt[val]);
                        }
                }
                else if (ch == '-')
                {
                        ms.erase(ms.find(cnt[val]));
                        cnt[val]--;
                        ms.insert(cnt[val]);
                }
                vector<int> temp;
                for (auto el : ms)
                {
                        temp.pb(el);
                        if (temp.size() == 3)
                                break;
                }
                sort(temp.rbegin(), temp.rend());
                // cout << "temp = " << endl;
                // for (int i : temp)
                //         cout << i << " ";
                // cout << endl;
                if (temp.size() == 0)
                {
                        cout << "NO" << endl;
                }
                else if (temp[0] < 4)
                {
                        cout << "NO" << endl;
                }
                else
                {
                        // temp[0]>=4
                        int sum = 0;
                        for (int i : temp)
                        {
                                sum += i / 2;
                        }
                        if (sum >= 4)
                        {
                                cout << "YES" << endl;
                        }
                        else
                        {
                                cout << "NO" << endl;
                        }
                }
                // cout << "ch = " << ch << " val = " << val << endl;
        }
}

//................................
