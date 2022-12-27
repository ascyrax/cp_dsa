#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout << "Case #" << i << ": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        int xa, ya;
        cin >> xa >> ya;
        int xb, yb;
        cin >> xb >> yb;
        int xf, yf;
        cin >> xf >> yf;
        int diff = abs(xa - xb) + abs(ya - yb);
        if (xa == xb || ya == yb)
        {
                if (xa == xb && xf == xb)
                {
                        if (yf < max(ya, yb) && yf > min(ya, yb))
                        {
                                cout << diff + 2 << endl;
                        }
                        else
                                cout << diff << endl;
                }
                else if (ya == yb && ya == yf)
                {
                        if (xf > min(xb, xa) && xf < max(xa, xb))
                        {
                                cout << diff + 2 << endl;
                        }
                        else
                                cout << diff << endl;
                }
                else
                        cout << diff << endl;
        }
        else
        {
                cout << diff << endl;
        }
}

//................................
