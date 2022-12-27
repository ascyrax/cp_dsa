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
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> va(n), vb(n);
        for (int &i : va)
                cin >> i;
        for (int &i : vb)
                cin >> i;
        int diff = 0;
        int dpos = 0, dneg = 0;
        vector<pair<int, int>> dec, inc;
        for (int i = 0; i < n; i++)
        {
                if (vb[i] - va[i] > 0)
                        dpos += (vb[i] - va[i]);
                if (vb[i] - va[i] < 0)
                        dneg += (vb[i] - va[i]);
                diff += (vb[i] - va[i]);
                if (vb[i] < va[i])
                        dec.pb(make_pair(i + 1, abs(vb[i] - va[i])));
                else if (vb[i] > va[i])
                        inc.pb(make_pair(i + 1, abs(vb[i] - va[i])));
        }
        if (diff != 0)
                cout << -1 << endl;
        else
        {
                int pinc = 0;
                int pdec = 0;
                cout << dpos << endl;
                while (pinc < int(inc.size()))
                {
                        cout << dec[pdec].first << " " << inc[pinc].first << endl;
                        inc[pinc].second--;
                        dec[pdec].second--;
                        if (inc[pinc].second == 0)
                                pinc++;
                        if (dec[pdec].second == 0)
                                pdec++;
                }
        }
}

//................................
