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
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int cntABC = 0;
        for (int i = 0; i < n - 2; i++)
        {
                if (s.substr(i, 3) == "abc")
                        cntABC++;
        }
        for (int i = 0; i < q; i++)
        {
                int pos;
                string c;
                cin >> pos >> c;
                pos--;
                if (s[pos] == c[0])
                {
                        cntABC += 0;
                }
                else
                {
                        for (int j = max(0, pos - 2); j <= min(n - 2, pos); j++)
                        {
                                if (s.substr(j, 3) == "abc")
                                {
                                        cntABC--;
                                }
                        }
                        s[pos] = c[0];
                        for (int j = max(0, pos - 2); j <= min(n - 2, pos); j++)
                        {
                                if (s.substr(j, 3) == "abc")
                                {
                                        cntABC++;
                                }
                        }
                }
                cout << cntABC << endl;
        }
}

//................................
