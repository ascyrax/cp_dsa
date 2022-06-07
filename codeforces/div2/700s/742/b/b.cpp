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
void func();
int main()
{
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        func();

        for (int i = 1; i <= t; i++)
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
vector<ll> psXor((int)3e5 + 1);
//...............................
void func()
{
        psXor[0] = 0;
        for (int i = 1; i <= (int)3e5; i++)
        {
                psXor[i] = psXor[i - 1] ^ (ll)i;
        }
}
//...............................

void suraj()
{

        ll mex, zor;
        cin >> mex >> zor;
        ll ans = mex;
        // if (mex == 2 || mex == 3 || (mex > 3 && mex % 2 == 1)) //2 3 5 7 9...
        // {
        //         if (psXor[mex - 1] != zor)
        //                 ans++;
        // }
        // else
        // {
        //         //if bitwise xor of all == zor
        //         //do nothing
        //         //else
        //         //ans++;
        //         if (psXor[mex - 1] != zor)
        //                 ans++;
        // }
        if (psXor[mex - 1] == zor)
                ans += 0;
        else
        {
                ll b = zor ^ psXor[mex - 1];
                if (b == mex)
                        ans += 2;
                else
                        ans++;
        }
        // else if ((psXor[mex - 1] == 0) && (zor == mex))
        //     ans += 2;
        // else if (psXor[mex - 1] != zor)
        //     ans++;
        cout << ans << endl;
}

//................................
