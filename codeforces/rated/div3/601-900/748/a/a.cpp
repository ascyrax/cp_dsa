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
        //cout << setprecision(15) << fixed;
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
        ll a, b, c;
        cin >> a >> b >> c;
        vector<ll> v = {a, b, c};
        sort(v.rbegin(), v.rend());
        if (a == b && b == c)
        {
                cout << 1 << " " << 1 << " " << 1 << endl;
                return;
        }
        else if (a != b && b != c && a != c)
        {
                if (v[0] == a)
                        cout << 0 << " ";
                else
                        cout << v[0] - a + 1 << " ";
                // cout << (v[0] - a) << " " << v[0] - b << " " << v[0] - c << endl;
                if (v[0] == b)
                        cout << 0 << " ";
                else
                        cout << v[0] - b + 1 << " ";
                if (v[0] == c)
                        cout << 0 << " ";
                else
                        cout << v[0] - c + 1 << " ";
                cout << endl;
                return;
        }
        else
        {
                if (v[0] == v[1])
                {
                        if (v[0] == a)
                                cout << 1 << " ";
                        else
                                cout << v[0] - a + 1 << " ";
                        // cout << (v[0] - a) << " " << v[0] - b << " " << v[0] - c << endl;
                        if (v[0] == b)
                                cout << 1 << " ";
                        else
                                cout << v[0] - b + 1 << " ";
                        if (v[0] == c)
                                cout << 1 << " ";
                        else
                                cout << v[0] - c + 1 << " ";
                        cout << endl;
                        return;
                }
                else if (v[1] == v[2])
                {
                        if (v[0] == a)
                                cout << 0 << " ";
                        else
                                cout << v[0] - a + 1 << " ";
                        // cout << (v[0] - a) << " " << v[0] - b << " " << v[0] - c << endl;
                        if (v[0] == b)
                                cout << 0 << " ";
                        else
                                cout << v[0] - b + 1 << " ";
                        if (v[0] == c)
                                cout << 0 << " ";
                        else
                                cout << v[0] - c + 1 << " ";
                        cout << endl;
                        return;
                }
        }
}

//................................
