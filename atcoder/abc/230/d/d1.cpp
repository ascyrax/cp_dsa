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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

//...............................

//...............................

void suraj()
{
        int n, d;
        cin >> n >> d;
        vector<pair<pair<int, int>, int>> vprl, vplr;
        for (int i = 0; i < n; i++)
        {
                int l, r;
                cin >> l >> r;
                vprl.pb(make_pair(make_pair(r, l), i));
                vplr.pb(make_pair(make_pair(l, r), i));
        }
        sort(vprl.begin(), vprl.end());
        sort(vplr.begin(), vplr.end());

        vector<bool> destroyed(n, false);
        int cnt = 0;
        int ptrlr = 0;
        for (int i = 0; i < n; i++)
        {
                // cout << "i = " << i << endl;
                auto el = vprl[i];

                if (destroyed[el.second] == true)
                        continue;

                cnt++;
                destroyed[el.second] = true;

                int range = el.first.first + d - 1;
                for (int j = ptrlr; j < n; j++)
                {
                        // cout << "j = " << j << endl;
                        // cout << "hi" << endl;
                        // cout << vplr[j].second << endl;
                        if (vplr[j].first.first <= range)
                        {
                                // cout << "if" << endl;
                                destroyed[vplr[j].second] = true;
                                ptrlr = j;
                        }
                        else
                        {
                                // cout << "else" << endl;
                                break;
                        }
                }
                // cout << "iteration ended" << endl;
        }
        cout << cnt << endl;
}

//................................
// int
// int
// int
// int
