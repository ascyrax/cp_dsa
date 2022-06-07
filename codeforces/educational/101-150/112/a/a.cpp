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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
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

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................
ll n;
//...............................

//...............................

void suraj()
{
        cin >> n;
        if (n % 2 == 1)
                n++;
        if (n < 12)
        {
                if (n == 10)
                        cout << 25 << endl;
                else if (n == 8)
                        cout << 20 << endl;
                else if (n == 6)
                        cout << 15 << endl;
                else
                        cout << 15 << endl;
        }
        else
        {
                int rem = n % 6;
                if (rem == 2)
                {
                        cout << ll(20 + (n - 8) * 2.5) << endl;
                }
                else if (rem == 4)
                {
                        cout << ll(25 + (n - 10) * 2.5) << endl;
                }
                else if (rem == 0)
                {
                        cout << ll(n * 2.5) << endl;
                }
        }
}

//................................
