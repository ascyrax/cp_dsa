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
        // int t;cin>>t;for(int i=1;i<=t;i++)
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

        ll lens = s.size();

        ll x;
        x = stoll(s);

        if (lens == 1)
        {
                cout << s << endl;
                return;
        }

        // for (ll i = 1; i < lens; i++)
        // {
        ll diff = (s[1] - '0') - (s[0] - '0');
        ll lastElement = (s[0] - '0') + (lens - 1) * diff;

        // cout << "diff = " << diff << endl;
        // cout << "lastElement = " << lastElement << endl;

        if (diff == 0)
        {
                ll sign = 0;
                for (ll i = 0; i < lens; i++)
                {
                        if ((s[i] - '0') > (s[0] - '0'))
                        {
                                sign = 1;
                                break;
                        }
                        else if ((s[i] - '0') < (s[0] - '0'))
                        {
                                sign = -1;
                                break;
                        }
                        else
                                continue;
                }
                if (sign == 0)
                {
                        cout << s << endl;
                        return;
                }
                else if (sign < 0)
                {
                        // => s[0]s[1]s[2]s[3]...... is smaller than s[0]s[0]s[0]s[0]........
                        for (ll i = 0; i < lens; i++)
                                cout << s[0];
                        cout << endl;
                }
                else
                {
                        // check for diff =1
                        diff = 1;
                        lastElement = (s[0] - '0') + (lens - 1) * diff;
                        if (lastElement <= 9)
                        {
                                for (ll i = 0; i < lens; i++)
                                {
                                        cout << (s[0] - '0') + i * diff;
                                }
                                cout << endl;
                        }
                        else
                        {
                                for (ll i = 0; i < lens; i++)
                                {
                                        cout << (s[0] - '0' + '1');
                                }
                                cout << endl;
                        }
                }
        }
        else if (diff < 0)
        {
                while (lastElement < 0)
                {
                        diff++;
                        lastElement = (s[0] - '0') + (lens - 1) * diff;
                }
                for (ll i = 0; i < lens; i++)
                {
                        cout << (s[i] - '0') + (i)*diff;
                }
                cout << endl;
        }
        else if (diff > 0)
        {
                while (lastElement > 9)
                {
                        ll a = s[0] - '0';
                        a++;
                        s[0] = (to_string(a))[0];

                        // diff = (s[1] - '0') - (s[0] - '0');
                        diff = -9;
                        lastElement = (s[0] - '0') + (lens - 1) * diff;
                        break;
                }

                while (lastElement < 0)
                {
                        diff++;
                        lastElement = (s[0] - '0') + (lens - 1) * diff;
                }
                for (ll i = 0; i < lens; i++)
                {
                        cout << (s[0] - '0') + (i)*diff;
                }
                cout << endl;
        }
        // }
}

//................................
// ll
// int
// int
// int
