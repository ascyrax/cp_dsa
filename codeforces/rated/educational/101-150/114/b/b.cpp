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
        int a, b, c, m;
        vector<int> vTemp(3);
        cin >> vTemp[0] >> vTemp[1] >> vTemp[2] >> m;
        sort(vTemp.begin(), vTemp.end());
        a = vTemp[0];
        b = vTemp[1];
        c = vTemp[2];
        int mMax = a - 1 + b - 1 + c - 1;
        int mMin = 1e9;
        if (a + b < c - 1)
        {
                mMin = (c - 1 - (a + b));
        }
        else if (a + b > c + 1)
        {
                mMin = 0;
        }
        else
                mMin = 0;
        if (m >= mMin && m <= mMax)
                cout << "YES" << endl;
        else
                cout << "NO" << endl;
}

//................................
