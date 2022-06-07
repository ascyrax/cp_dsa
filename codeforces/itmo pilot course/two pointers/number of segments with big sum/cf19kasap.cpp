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
        //int t;cin>>t;for(int i=1;i<=t;i++)
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
ll n, s;
vector<ll> v;
ll num = 0;
//...............................

//...............................

void suraj()
{
        cin >> n >> s;
        v = vector<ll>(n);
        for (ll &i : v)
                cin >> i;
        ll subSum = 0, l = 0, r = 0;
        for (r = 0; r < n; r++)
        {
                subSum += v[r];
                while (subSum - v[l] >= s && l < r)
                {
                        subSum -= v[l++];
                }
                if (subSum >= s)
                        num += (l + 1);
        }
        cout << num << endl;
}

//................................
