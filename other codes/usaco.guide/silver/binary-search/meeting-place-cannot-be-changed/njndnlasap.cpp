// doubts

// lmax,lmin waala implementation me float me loop keeps running while in double i get the ans (for testcase 3)

// vp waala implementation galat hai
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define size(x) (int)(x).size()
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
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
        long long n;
        cin >> n;
        vector<int> x(n);
        int xmin = 1e9, xmax = 0;
        for (int &i : x)
        {
                cin >> i;
                xmin = min(xmin, i);
                xmax = max(xmax, i);
        }
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        double tmin = 0, tmax = xmax - xmin, tmid = tmin + (tmax - tmin) / 2;

        int loop = 0;
        while (abs(tmax - tmin) > 1e-6)
        {
                // loop++;
                // if (loop == 100)
                //         break;
                tmid = tmin + (tmax - tmin) / 2;
                // tmid = (tmax + tmin) / 2;
                cout << fixed << setprecision(36) << tmin << " " << fixed << setprecision(36) << tmid << "  " << fixed << setprecision(36) << tmax << endl;
                vector<pair<int, int>> vp;
                // double lmax = -1e36;
                // double rmin = 1e36;
                for (int i = 0; i < n; i++)
                {
                        vp.pb(make_pair(max(double(xmin), x[i] - v[i] * tmid), 1));
                        // lmax = max(lmax, x[i] - v[i] * tmid);
                        // rmin = min(rmin, x[i] + v[i] * tmid);
                        vp.pb(make_pair(min(double(xmax + 1), x[i] + v[i] * tmid + 1), -1));
                }
                // cout << fixed << setprecision(36) << lmax << " " << fixed << setprecision(36) << rmin << endl;
                // if (lmax <= rmin)
                // {
                //         cout << "if" << endl;
                //         //tmid is valid
                //         tmax = tmid;
                // }
                // else
                // {
                //         cout << "else" << endl;
                //         cout << tmin << " " << tmid << " " << tmax << endl;
                //         tmin = tmid + 1;
                //         cout << tmin << " " << tmid << " " << tmax << endl;
                //         cout << (tmin + 3) << endl;
                //         cout << "else finished" << endl;
                // }

                sort(vp.begin(), vp.end());

                // //iterate over vp and if we find any point where vp[i].second == n
                // //it means tmid is a valid time and we should search for a shorter duration than tmid ka validity
                // cout << "vp" << endl;
                // for (auto i : vp)
                //         cout << i.second << "   ";
                // cout << endl;
                // for (auto i : vp)
                //         cout << i.first << "   ";
                // cout << endl;
                int cnt = 0;
                for (auto i : vp)
                {
                        cnt += i.second;
                        if (cnt == n)
                                break;
                }
                if (cnt == n)
                {
                        tmax = tmid;
                }
                // //else check for a bigger tmid
                else
                {
                        tmin = tmid;
                }
        }
        cout << fixed << setprecision(20) << tmid << endl;
}

//................................
