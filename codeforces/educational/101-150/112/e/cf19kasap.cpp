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
        //ioss
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
//...............................
int n, m;
vector<pair<int, pair<int, int>>> v;
//...............................

//...............................

void suraj()
{
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
                int l, r, w;
                cin >> l >> r >> w;
                v.pb(make_pair(w, make_pair(l, r)));
        }
        sort(v.begin(), v.end());
        int pl = 0, pr = 0;
        for (pl = 0; pl < n; pl++)
        {
                //while union does not extend over 1 to m => pr++
                while ()
                {
                        st.insert()
                }
                //if union of segments btwn pl and pr ranges from 1 to m=> extract ur ans=(v[pr].first-v[pl].first);
        }
}

//................................
