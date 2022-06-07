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
int count10s(int x)
{
        int cnt = 0;
        while (x > 0)
        {
                cnt++;
                x /= 10;
        }
        return cnt;
}
double simplified(int a)
{
        double x = a;
        while (x >= 10)
        {
                x /= 10;
        }
        return x;
}
//...............................

void suraj()
{
        int x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        // cout << "count10s(" << x1 << ") + " << p1 << " = " << count10s(x1) + p1 << endl;
        // cout << "count10s(" << x2 << ") + " << p2 << " = " << count10s(x2) + p2 << endl;
        if (count10s(x1) + p1 < count10s(x2) + p2)
        {
                cout << "<" << endl;
        }
        else if (count10s(x1) + p1 > count10s(x2) + p2)
        {
                cout << ">" << endl;
        }
        else
        {
                // cout << "simplified(" << x1 << ") = " << simplified(x1) << endl;
                // cout << "simplified(" << x2 << ") = " << simplified(x2) << endl;
                if (simplified(x1) > simplified(x2))
                {
                        cout << ">" << endl;
                }
                else if (simplified(x1) < simplified(x2))
                {
                        cout << "<" << endl;
                }
                else
                        cout << "=" << endl;
        }
}

//................................
