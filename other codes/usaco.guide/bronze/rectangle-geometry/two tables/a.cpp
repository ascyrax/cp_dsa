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

        // ioss

        // startTime=(double)clock();

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        cout << setprecision(15) << fixed;

        int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................
ll w, h;
ll xa, ya, xb, yb;
ll w2, h2;

//...............................

void suraj()
{

        cin >> w >> h;

        cin >> xa >> ya >> xb >> yb;

        cin >> w2 >> h2;

        ll w1 = xb - xa;
        ll h1 = yb - ya;

        if (w1 + w2 > w && h1 + h2 > h)
        {
                cout << -1 << endl;
                return;
        }

        ll ans = 1e16;
        ll mr, ml, mt, mb;
        // if table b is placed in lower left
        mr = max(w2 - xa, 0ll);
        mt = max(h2 - ya, 0ll);
        // cout << mr << " " << mt << endl;
        if (w2 + w1 > w)
                mr = 1e9;
        if (h2 + h1 > h)
                mt = 1e9;
        // cout << mr << " " << mt << endl;
        ans = min(ans, min(mr, mt));

        // lower right
        ml = max(0ll, xb - (w - w2));
        mt = max(0ll, h2 - ya);
        // cout << ml << " " << mt << endl;
        if (w2 + w1 > w)
                ml = 1e9;
        if (h2 + h1 > h)
                mt = 1e9;
        // cout << ml << " " << mt << endl;
        ans = min(min(ml, mt), ans);

        // top right
        ml = max(0ll, xb - (w - w2));
        mb = max(0ll, yb - (h - h2));
        // cout << ml << " " << mb << endl;
        if (w2 + w1 > w)
                ml = 1e9;
        if (h2 + h1 > h)
                mb = 1e9;
        // cout << ml << " " << mb << endl;
        ans = min(ans, min(ml, mb));

        // top left
        mr = max(w2 - xa, 0ll);
        mb = max(0ll, yb - (h - h2));
        // cout << mr << " " << mb << endl;
        if (w2 + w1 > w)
                mr = 1e9;
        if (h2 + h1 > h)
                mb = 1e9;
        // cout << mr << " " << mb << endl;
        ans = min(ans, min(mr, mb));

        if (ans >= 1e9)
                cout << -1 << endl;
        else
                cout << double(ans) << endl;
}

//................................

// ll

// ll

// ll

// ll
