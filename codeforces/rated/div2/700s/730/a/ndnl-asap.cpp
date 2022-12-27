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
        for (int i = 1; i <= t; i++) //{cout<<"Case #"<<i<<": ";
                suraj();
        //}
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        ll a, b;
        cin >> a >> b;
        ll diff = abs(a - b);
        if (diff == 0)
        {
                cout << "0 0" << endl;
                return;
        }
        else if (diff == 1)
        {
                cout << "1 0" << endl;
        }
        else
        {
                ll max_excitement = diff;
                cout << max_excitement << " ";
                ll rem = a % max_excitement;
                cout << min(rem, max_excitement - rem);
                cout << endl;
        }
}

//................................
