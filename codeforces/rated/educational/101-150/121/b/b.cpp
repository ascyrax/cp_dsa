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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
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

//...............................

//...............................

void suraj()
{
        string s;
        cin >> s;

        int lens = s.size(); //>=2

        int smaller = 0, same = 0;

        for (int i = 1; i < lens; i++)
        {
                int a = s[i - 1] - '0';
                int b = s[i] - '0';
                if (a + b <= 9)
                {
                        smaller++;
                }
                else
                        same++;
        }

        if (smaller == lens - 1)
        {
                // check the cases a+b<=9
                int ta = -1, tb = -1;
                // check only the cases for a+b>=10
                int a, b;
                for (int i = 1; i < lens; i++)
                {
                        a = s[i - 1] - '0';
                        b = s[i] - '0';
                        if (a + b >= a)
                        {
                                ta = i - 1;
                                tb = i;
                                break;
                        }
                }
                for (int i = 0; i < ta; i++)
                        cout << s[i];
                cout << a + b;
                for (int i = tb + 1; i < lens; i++)
                        cout << s[i];
                cout << endl;
        }
        else
        {
                int ta = -1, tb = -1;
                // check only the cases for a+b>=10
                int a, b;
                for (int i = lens - 1; i >= 1; i--)
                {
                        a = s[i - 1] - '0';
                        b = s[i] - '0';
                        if (a + b >= 10)
                        {
                                ta = i - 1;
                                tb = i;
                                break;
                        }
                }
                for (int i = 0; i < ta; i++)
                        cout << s[i];
                cout << a + b;
                for (int i = tb + 1; i < lens; i++)
                        cout << s[i];
                cout << endl;
        }
}

//................................
// int
// int
// int
// int
