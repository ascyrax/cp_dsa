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
        int q;
        cin >> q;
        map<int, int> actual;
        for (int i = 1; i <= 5 * 1e5; i++)
        {
                actual[i] = i;
        }
        vector<vector<int>> vq;
        for (int i = 0; i < q; i++)
        {
                int a, b, c;
                cin >> a;
                if (a == 1)
                {
                        cin >> b;
                        vq.pb({a, b});
                }
                else if (a == 2)
                {
                        cin >> b >> c;
                        vq.pb({a, b, c});
                }
        }
        deque<int> ans;
        for (int i = q - 1; i >= 0; i--)
        {
                if (vq[i][0] == 2)
                {
                        actual[vq[i][1]] = actual[vq[i][2]];
                }
                else if (vq[i][0] == 1)
                {
                        // if (actual.count(vq[i][1]) == 0)
                        //         ans.push_front(vq[i][1]);
                        // else
                        ans.push_front(actual[vq[i][1]]);
                }
                // cout << "ans: " << endl;
                // for (int i : ans)
                //         cout << i << " ";
                // cout << endl;
        }
        for (int i : ans)
                cout << i << " ";
        cout << endl;
}

//................................
