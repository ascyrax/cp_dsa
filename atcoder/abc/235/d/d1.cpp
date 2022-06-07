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
vector<pair<string, int>> findVar(vector<pair<string, int>> vps)
{
        vector<pair<string, int>> variations;
        for (int i = 0; i < vps.size(); i++)
        {
                string sn = vps[i].first;
                int movesCnt = vps[i].second;

                int lensn = sn.size();

                string sn2 = sn + sn;

                for (int i = 0; i < lensn; i++)
                {
                        string temp = sn2.substr(i, lensn);
                        if (temp == sn)
                                variations.pb(make_pair(temp, movesCnt));
                        else
                                variations.pb(make_pair(temp, movesCnt + 1));
                }
        }
        return variations;
}
//...............................

void suraj()
{
        int a, n;
        cin >> a >> n;

        int nMoves = 0;

        vector<pair<string, int>> variationsBefore, variationsFound; //, variationsSelected;

        variationsBefore.pb(make_pair(to_string(n), 0));

        // 1 ----a---> n
        while (variationsBefore.size() > 0)
        {
                // cout << "variationsBefore : " << endl;
                // for (auto el : variationsBefore)
                //         cout << el.first << " " << el.second << " , ";
                // cout << endl;

                variationsFound = findVar(variationsBefore);

                // cout << "variationsFound : " << endl;
                // for (auto el : variationsFound)
                //         cout << el.first << " " << el.second << " , ";
                // cout << endl;

                variationsBefore.clear();

                for (auto el : variationsFound)
                {
                        if (stoi(el.first) % a == 0)
                        {
                                int rem = stoi(el.first) / a;
                                if (rem == 1)
                                {
                                        cout << el.second + 1 << endl;
                                        return;
                                }
                                variationsBefore.push_back(make_pair(to_string(rem), el.second + 1));
                        }
                }
        }
        cout << -1 << endl;
}

//................................
// int
// int
// int
// int
