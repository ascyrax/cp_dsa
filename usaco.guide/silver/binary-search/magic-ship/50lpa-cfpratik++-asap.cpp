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
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................

void suraj()
{
        ll xa, ya;
        cin >> xa >> ya;
        ll xb, yb;
        cin >> xb >> yb;
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> vx(n), vy(n);
        for (int i = 0; i < n; i++)
        {
                if (s[i] == 'U')
                {
                        vx[i] = 0;
                        vy[i] = 1;
                }
                else if (s[i] == 'D')
                {
                        vx[i] = 0;
                        vy[i] = -1;
                }
                else if (s[i] == 'R')
                {
                        vx[i] = 1;
                        vy[i] = 0;
                }
                else if (s[i] == 'L')
                {
                        vx[i] = -1;
                        vy[i] = 0;
                }
        }
        // for (ll i : vx)
        //         cout << i << " ";
        // cout << endl;
        // for (ll i : vy)
        //         cout << i << " ";
        // cout << endl;
        vector<ll> psx(n + 1), psy(n + 1);
        for (int i = 1; i <= n; i++)
        {
                psx[i] = vx[i - 1] + psx[i - 1];
                psy[i] = vy[i - 1] + psy[i - 1];
        }
        // for (ll i : psx)
        //         cout << i << " ";
        // cout << endl;
        // for (ll i : psy)
        //         cout << i << "  ";
        // cout << endl;
        ll oneloopx = psx[n] - psx[0];
        ll oneloopy = psy[n] - psy[0];
        // cout << oneloopx << " " << oneloopy << endl;
        ll dmin = 0, dmax = 1e15;
        ll dmid = dmin + (dmax - dmin) / 2;
        while (dmin < dmax)
        {

                dmid = dmin + (dmax - dmin) / 2;
                // cout << dmin << " " << dmid << " " << dmax << endl;
                //where will wind take the ship in dmid dais(say x3,y3)
                ll quo = dmid / n;
                ll rem = dmid % n;
                ll remx = psx[rem] - psx[0];
                ll remy = psy[rem] - psy[0];
                ll xwind = xa + quo * oneloopx + remx;
                ll ywind = ya + quo * oneloopy + remy;
                //can ship reach x2,y2 in dmid movements from x3,y3
                // cout << xwind << " " << ywind << endl;
                ll diffx = abs(xb - xwind);
                ll ndaysx = diffx;
                ll diffy = abs(yb - ywind);
                ll ndaysy = diffy;
                //if(true) dmax=dmid
                // cout << ndaysx << " " << ndaysy << endl;
                ndaysx = max(0ll, ndaysx);
                ndaysy = max(0ll, ndaysy);
                if (ndaysx + ndaysy <= dmid)
                {
                        dmax = dmid;
                }
                //else dmin=dmid+1
                else
                {
                        dmin = dmid + 1;
                }
                // cout << dmin << " " << dmid << " " << dmax << endl;
                // cout << "--------------------------------" << endl;
        }
        if (dmin == 1e15)
                cout << -1 << endl;
        else
                cout << dmin << endl;
}

//................................
