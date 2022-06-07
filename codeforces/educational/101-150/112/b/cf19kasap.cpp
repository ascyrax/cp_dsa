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
                cout
            << setprecision(15) << fixed << endl;
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

//...............................

//...............................

void suraj()
{
        int W, H;
        int x1, y1, x2, y2;
        int w2, h2;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w2 >> h2;
        int w1 = x2 - x1;
        int h1 = y2 - y1;
        double imp = -1;
        if (w1 + w2 > W && h1 + h2 > H)
        {
                cout << imp << endl;
        }
        else
        {
                double mTop, mBottom, mLeft, mRight;
                double ans = 1e9, ans2 = 1e9;
                //for bottom left-----------------------------------------
                mRight = max(0, w2 - x1);
                mTop = max(0, h2 - y1);
                // cout << mRight << " " << mTop << endl;

                if (w1 + w2 > W)
                        mRight = 1e9;
                if (h1 + h2 > H)
                        mTop = 1e9;

                ans = min(ans, min(mTop, mRight));
                // ans2 = min(ans2, max(mRight, mTop));
                // cout << mRight << " " << mTop << endl;
                //for bottom right-----------------------------------------
                mLeft = max(0, w2 - (W - x2));
                mTop = max(0, h2 - y1);
                // cout << mLeft << " " << mTop << endl;

                if (w1 + w2 > W)
                        mLeft = 1e9;
                if (h1 + h2 > H)
                        mTop = 1e9;

                ans = min(ans, min(mLeft, mTop));
                // cout << mLeft << " " << mTop << endl;
                // ans2 = min(ans2, max(mLeft, mTop));
                //for top right-----------------------------------------
                mLeft = max(0, w2 - (W - x2));
                mBottom = max(0, h2 - (H - y2));
                // cout << mLeft << " " << mBottom << endl;

                if (w1 + w2 > W)
                        mLeft = 1e9;
                if (h1 + h2 > H)
                        mBottom = 1e9;
                ans = min(ans, min(mLeft, mBottom));
                // cout << mLeft << " " << mBottom << endl;
                // ans2 = min(ans2, max(mLeft, mBottom));
                //for top left-----------------------------------
                mRight = max(0, w2 - x1);
                mBottom = max(0, h2 - (H - y2));
                // cout << mRight << " " << mBottom << endl;
                if (w1 + w2 > W)
                        mRight = 1e9;
                if (h1 + h2 > H)
                        mBottom = 1e9;
                ans = min(ans, min(mRight, mBottom));
                // cout << mRight << " " << mBottom << endl;
                // ans2 = min(ans2, max(mRight, mBottom));
                cout << ans << endl;
        }
}

//................................
