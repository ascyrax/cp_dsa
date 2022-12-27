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

        string s;
        cin >> s;
        int n = s.size();

        int cntN = 0;
        for (int i = 0; i < n - 1; i++)
        {
                if (s[i] == 'N')
                        cntN++;
        }

        if (s[n - 1] == 'N')
        {
                if (cntN > 0)
                {
                        cout << "YES" << endl;
                        return;
                }
                else
                {
                        cout << "NO" << endl;
                        return;
                }
        }
        else if (s[n - 1] == 'E')
        {
                if (cntN == 0 || cntN > 1)
                {
                        cout << "YES" << endl;
                        return;
                }
                else
                {
                        cout << "NO" << endl;
                        return;
                }
        }
}

//................................
