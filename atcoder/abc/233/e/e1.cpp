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
int calcCarry(int val)
{
        return (val / 10) * 10;
}
//...............................

void suraj()
{
        string x;
        cin >> x;
        vector<ll> ps = {0};
        int lenx = x.size();
        for (int i = 0; i < lenx; i++)
        {
                ps.pb(ps.back() + (x[i] - '0'));
        }
        // cout << "ps : " << endl;
        // for (int i : ps)
        //         cout << i << " ";
        // cout << endl;
        vector<int> ans;
        // string ans = "";
        int carryPrev = 0;
        for (int i = lenx; i >= 0; i--)
        {
                if (ps[i] > 9)
                {
                        int carryNew = calcCarry(ps[i] + carryPrev);
                        // cout << "i = " << i << endl;
                        // cout << "ps[i] = " << ps[i] << endl;
                        // cout << "carryNew = " << carryNew << endl;
                        ans.pb(ps[i] + carryPrev - carryNew);
                        carryPrev = carryNew / 10;
                        // ans += to_string(ps[i] + carryPrev - carryNew);
                        // cout << "ans = " << ans << endl;
                }
                else
                {
                        int carryNew = calcCarry(ps[i] + carryPrev);
                        // cout << "i = " << i << endl;
                        // cout << "ps[i] = " << ps[i] << endl;
                        // cout << "carryNew = " << carryNew << endl;
                        ans.pb(ps[i] + carryPrev - carryNew);
                        carryPrev = carryNew / 10;
                }
        }
        int ptr = -1;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
                if (ans[i] != 0)
                {
                        ptr = i;
                        break;
                }
        }
        for (int i = ptr; i >= 0; i--)
                cout << ans[i];
        cout << endl;
}

//................................
// int
// int
// int
// int
