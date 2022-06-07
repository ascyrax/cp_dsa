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
        // ioss
        startTime = (double)clock();
        freopen("cowdance.in", "r", stdin);
        freopen("cowdance.out", "w", stdout);
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
int n, tmax;
vector<int> vTime;

//...............................
bool check(int k)
{
        // cout << "check" << endl;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < min(k, n); i++)
                pq.push(vTime[i]);
        int ptr = k;
        int last = pq.top(); // last element to pe popped out
        while (!pq.empty())
        {
                // priority_queue<int, vector<int>, greater<int>> copy = pq;
                // while (!copy.empty())
                // {
                //         cout << copy.top() << " ";
                //         copy.pop();
                // }
                // cout << endl;
                last = pq.top();
                pq.pop();
                if (k < n)
                        pq.push(last + vTime[k++]);
        }
        // cout << last << " " << tmax << endl;
        return last <= tmax;
}
//...............................

void suraj()
{
        cin >> n >> tmax;
        vTime = vector<int>(n, 0);
        for (int &i : vTime)
                cin >> i;
        //binary search will work since if k cows at a time on the stage is ok then all size>k will also qualify
        // sort(vTime.rbegin(), vTime.rend());
        int l = 0, r = n;
        // cout << "hi" << endl;
        while (l < r)
        {
                int mid = l + (r - l) / 2;
                // cout << l << " " << r << " " << mid << endl;
                if (check(mid))
                {
                        r = mid;
                }
                else
                {
                        l = mid + 1;
                }
        }
        cout << l << endl;
}

//................................
