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
        ioss
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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
        ll n;
        cin >> n;
        ll cnt = 0;
        ll ans = 20;
        // to make n divisible by 100 asap
        ll n2 = n;

        ll zeroCnt = 0, delCnt = 0;
        while (n2)
        {
                if (n2 % 10 == 0)
                {
                        n2 /= 10;
                        zeroCnt++;
                }
                else
                {
                        delCnt++;
                        n2 /= 10;
                }
                if (zeroCnt == 2)
                        break;
        }
        if (zeroCnt == 2)
                ans = min(ans, delCnt);

        // to make n divisible by 25 asap ---->> 25 and 75 only
        delCnt = 0;
        ll flag5 = -1;
        n2 = n;
        while (n2)
        {
                if (n2 % 10 == 5)
                {
                        if (flag5 == 1)
                        {
                                delCnt++;
                                n2 /= 10;
                        }
                        else
                        {
                                n2 /= 10;
                                flag5 = 1;
                        }
                }
                else
                {
                        if (flag5 == 1)
                        {
                                if (n2 % 10 == 2 || n2 % 10 == 7)
                                {
                                        ans = min(ans, delCnt);
                                        break;
                                }
                                else
                                {
                                        delCnt++;
                                        n2 /= 10;
                                }
                        }
                        else
                        {
                                n2 /= 10;
                                delCnt++;
                        }
                }
        }
        // to make n divisible by 25 asap ----->> 50
        delCnt = 0;
        ll flag0 = -1;
        n2 = n;
        while (n2)
        {
                if (n2 % 10 == 0)
                {
                        if (flag0 == 1)
                        {
                                n2 /= 10;
                                delCnt++;
                        }
                        else
                        {
                                flag0 = 1;
                                n2 /= 10;
                        }
                }
                else
                {
                        if (flag0 == 1)
                        {
                                if (n2 % 10 == 5)
                                {
                                        ans = min(ans, delCnt);
                                        break;
                                }
                                else
                                {
                                        delCnt++;
                                        n2 /= 10;
                                }
                        }
                        else
                        {
                                n2 /= 10;
                                delCnt++;
                        }
                }
        }
        cout << ans << endl;
}
