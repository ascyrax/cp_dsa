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
        string a, s;
        cin >> a >> s;
        int diff = s.size() - a.size();
        if (diff > 0)
        {
                for (int i = 0; i < diff; i++)
                {
                        a = "0" + a;
                }
        }
        string b = "";
        while (1)
        {
                ll ta, ts, tb;
                int lena = a.size();
                int lens = s.size();

                if (lena == 0 && lens == 0)
                {
                        break;
                }
                else if (lena == 0)
                {
                        b = s + b;
                        break;
                }
                else if (lens == 0)
                {
                        if (stoll(a) != 0ll)
                        {
                                cout << -1 << endl;
                                return;
                        }
                        else
                        {
                                break;
                        }
                }
                ta = stoll(a.substr(lena - 1, 1));
                ts = stoll(s.substr(lens - 1, 1));
                if (ts < ta)
                {
                        if (s[lens - 2] == '1')
                        {
                                ts = stoll(s.substr(lens - 2, 2));
                                tb = ts - ta;
                        }
                        else
                        {
                                cout << -1 << endl;
                                return;
                        }
                }
                else
                { // if ts>=ta
                        tb = ts - ta;
                }
                b = to_string(tb) + b;
                a = a.substr(0, lena - 1);
                if (ts >= 10)
                {
                        s = s.substr(0, lens - 2);
                }
                else
                        s = s.substr(0, lens - 1);
        }
        cout << stoll(b) << endl;
}

//................................
