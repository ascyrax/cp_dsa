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
        cout << setprecision(8) << fixed << endl;
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
        int x1, x2, y1, y2, r1, r2;
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        // cout<<dist<<endl;
        //cout<<abs(r1-r2)<<endl;
        cout << r1 << " " << r2 << " " << dist << endl;
        if (dist >= r1 + r2)
        {
                double ans = 0.0;
                cout << ans << endl;
        }
        else if (dist < r1 + r2 && dist > abs(r1 - r2))
        {
                //cout<<"fuck"<<endl;
                double theta1 = acos((r1 * r1 + dist * dist - r2 * r2) / (2 * r1 * dist));
                double abcd = (r1 * dist * sin(theta1));
                double p = abcd - (r1 * r1 * theta1);
                double theta2 = acos((r2 * r2 + dist * dist - r1 * r1) / (2 * r2 * dist));
                double q = abcd - (r2 * r2 * theta2);
                double ans = abcd - p - q;
                cout << "theta1 = " << theta1 << " theta2 = " << theta2 << endl;
                cout << "abcd = " << abcd << endl;
                cout << "p = " << p << endl;
                cout << "q = " << q << endl;
                cout << "ans = " << ans << endl;
                cout << ans << endl;
        }
        else
        {
                //cout<<"hi"<<endl;
                int r = min(r1, r2);
                double area = r * r * 3.14159265358979323846264338;
                cout << area << endl;
        }
}

//................................
