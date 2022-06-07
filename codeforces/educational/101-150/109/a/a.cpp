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

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int k;
//...............................

//...............................

void suraj()
{
        cin >> k;
        if (100 % k == 0)
        {
                cout << 100 / k << endl;
        }
        else
        {
                //convert 100/k into simpler form and print it
                int copy = 100;
                for (int i = 2; i <= 99; i++)
                {
                        while (copy % i == 0 && k % i == 0)
                        {
                                copy /= i;
                                k = k / i;
                        }
                }
                cout << copy << endl;
        }
}

//................................
