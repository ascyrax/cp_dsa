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
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

bool yincreasing(pair<ll, ll> a, pair<ll, ll> b) //whether a belongs to the left of b or not
{
        if (a.second < b.second)
        {
                return true;
        }
        else if (a.second > b.second)
        {
                return false;
        }
        else
        {
                if (a.first < b.first)
                        return true;
                else
                        return false;
        }
}

bool xincreasing(pair<ll, ll> a, pair<ll, ll> b) //whether a belongs to the
{
        if (a.first < b.first)
                return true;
        else if (a.first == b.first)
        {
                if (a.second < b.second)
                        return true;
                else
                        return false;
        }
        else
                return false;
}
//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<pair<ll, ll>> vnorth, veast;
        vector<pair<string, pair<ll, ll>>> vqueries;
        for (int i = 0; i < n; i++)
        {
                string dir;
                cin >> dir;
                ll x, y;
                cin >> x >> y;
                if (dir == "N")
                {
                        vnorth.pb(make_pair(x, y));
                }
                else if (dir == "E")
                {
                        veast.pb(make_pair(x, y));
                }
                vqueries.pb(make_pair(dir, make_pair(x, y)));
        }
        sort(veast.begin(), veast.end(), yincreasing);
        sort(vnorth.begin(), vnorth.end(), xincreasing);

        vector<ll> refEast(veast.size());
        vector<ll> maxXEast(veast.size());
        vector<ll> refNorth(vnorth.size());
        vector<ll> maxYNorth(vnorth.size());

        for (int i = 0; i < veast.size(); i++)
        {
                for (int j = 0; j < vnorth.size(); j++)
                {
                        if (vnorth[j].second > veast[i].second || vnorth[j].first < veast[i].first)
                        {
                                continue;
                        }
                        else
                        {
                                if (veast[i].second - vnorth[j].second > vnorth[j].first - veast[i].first)
                                {
                                        if (maxYNorth[j] < veast[i].second)
                                        {
                                                continue;
                                        }
                                        else
                                        {
                                                refEast[i]++;
                                                // maxYNorth[j] = veast[i].second;
                                        }
                                }
                                else if (veast[i].second - vnorth[j].second == vnorth[j].first - veast[i].first)
                                {
                                        refEast[i] += 0;
                                }
                                else
                                {
                                        //refNorth[j]++; but this will get updated in the nest loop
                                        maxXEast[i] = vnorth[j].first;
                                        continue;
                                }
                        }
                }
        }
        for (int i : refEast)
                cout << i << " ";
        cout << endl;
        for (int i : refNorth)
                cout << i << " ";
        cout << endl;
        for (int i = 0; i < vnorth.size(); i++)
        {
                for (int j = 0; j < veast.size(); j++)
                {
                        if (veast[j].second < vnorth[i].second || veast[j].first > vnorth[i].first)
                        {
                                continue;
                        }
                        else
                        {
                                if (veast[j].second - vnorth[i].second < vnorth[i].first - veast[j].first)
                                {
                                        if (maxXEast[j] < vnorth[i].first)
                                        {
                                                continue;
                                        }
                                        else
                                        {
                                                refNorth[i]++;
                                                refNorth[i] += refEast[j];
                                        }
                                }
                                else if (veast[j].second - vnorth[i].second == vnorth[i].first - veast[j].first)
                                {
                                        refNorth[i] += 0;
                                }
                                else
                                {
                                        //refEast[j]++; but it has already been updated in the previous loop
                                        maxYNorth[i] = veast[j].second;
                                        continue;
                                }
                        }
                }
        }
        for (int i : refEast)
                cout << i << " ";
        cout << endl;
        for (int i : refNorth)
                cout << i << " ";
        cout << endl;
        for (int i = 0; i < veast.size(); i++)
        {
                for (int j = 0; j < vnorth.size(); j++)
                {
                        if (vnorth[j].second > veast[i].second || vnorth[j].first < veast[i].first)
                        {
                                continue;
                        }
                        else
                        {
                                if (veast[i].second - vnorth[j].second > vnorth[j].first - veast[i].first)
                                {
                                        // refEast[i]++;
                                        refEast[i] += refNorth[j];
                                }
                                else if (veast[i].second - vnorth[j].second == vnorth[j].first - veast[i].first)
                                {
                                        refEast[i] += 0;
                                }
                                else
                                {
                                        //refNorth[j]++; but this will get updated in the nest loop
                                }
                        }
                }
        }
        for (int i : refEast)
                cout << i << " ";
        cout << endl;
        for (int i : refNorth)
                cout << i << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
        {
                auto query = vqueries[i];
                int ptrE = 0, ptrN = 0;
                if (query.first == "E")
                {
                        cout << refEast[ptrE] << endl;
                        ptrE++;
                }
                else if (query.first == "N")
                {
                        cout << refNorth[ptrN] << endl;
                        ptrN++;
                }
        }
}

//................................
