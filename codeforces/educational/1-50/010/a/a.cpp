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
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
        ll h1, h2;
        cin >> h1 >> h2;
        ll a, b;
        cin >> a >> b;
        ll days = 0;
        if (12 * a - 12 * b > 0) // cat can go up in total
        {
                if (h1 + 8 * a >= h2)
                {
                        days = 0;
                }
                else
                {
                        h1 = h1 + 8 * a - 12 * b;
                        days++;
                        // cout << "h1 = " << h1 << " days = " << days << endl;
                        while (h1 < h2 - 12 * a)
                        {
                                // cout << "h1 = " << h1 << " days = " << days << endl;
                                h1 += (12 * a - 12 * b);
                                days++;
                        }
                        // days++;
                }
        }
        else //cat will go down in total
        {
                // cout << "else " << endl;
                if (h1 + a * 8 >= h2)
                {
                        // cout << "if " << endl;
                        days = 0;
                }
                else
                {
                        // cout << "else" << endl;
                        days = -1;
                }
        }

        cout << days << endl;
}

//................................
