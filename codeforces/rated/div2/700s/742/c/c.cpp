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
        int t;
        cin >> t;
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

//...............................

//...............................

void suraj()
{
        string n;
        cin >> n;
        string a, b;
        for (int i = (int)n.size() - 1; i >= 0; i--)
        {
                if (i % 2 == 0)
                        a = n[i] + a;
                else
                        b = n[i] + b;
        }

        // cout << a << " " << b << endl;

        ll cntA = stoi(a) + 1, cntB = 0;
        if ((int)b.size() > 0)
                cntB = stoi(b) + 1;
        else
                cntB = 1; //so that ans dont get =0

        ll ans = cntA * cntB;
        cout << ans - 2 << endl;
        // cout << "--------------------------" << endl;
}

//................................
