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

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
ll nDays, totGadgets, reqGadgets, nBurles;
vector<pair<ll, ll>> daywiseDvB, daywisePvB, gadgetsD, gadgetsP;
vector<ll> psMinDvB, psMinPvB;
vector<pair<ll, ll>> ans;
map<ll, ll> mD, mP;
//...............................
bool check(int m)
{
        ll reqGadgetsCopy = reqGadgets;
        ll nBurlesCopy = nBurles;
        ll dvb = psMinDvB[m];
        ll pvb = psMinPvB[m];
        ll ptrD = 0, ptrP = 0;
        while (true)
        {
                cout << "ptrD = " << ptrD << " ptrP = " << ptrP << endl;

                if (ptrD == gadgetsD.size() && ptrP == gadgetsP.size())
                {
                        break;
                }
                else if (ptrD == gadgetsD.size())
                {
                        if (nBurlesCopy - gadgetsP[ptrP].first * pvb >= 0)
                        {
                                // ans.pb(make_pair(gadgetsP[ptrP].second, lower_bound(psMinPvB.begin(), psMinPvB.end(), gadgetsP[ptrP].first) - psMinPvB.begin()));
                                ans.pb(make_pair(gadgetsP[ptrP].second, mP[gadgetsP[ptrP].first]));
                                nBurlesCopy -= gadgetsP[ptrP].first * pvb;
                                ptrP++;
                                reqGadgetsCopy--;
                        }
                        else
                                break;
                }
                else if (ptrP == gadgetsP.size())
                {
                        if (nBurlesCopy - gadgetsD[ptrD].first * dvb >= 0)
                        {
                                ans.pb(make_pair(gadgetsD[ptrD].second, lower_bound(psMinDvB.begin(), psMinDvB.end(), gadgetsD[ptrD].first) - psMinDvB.begin()));
                                nBurlesCopy -= gadgetsD[ptrD].first * dvb;
                                ptrD++;
                                reqGadgetsCopy--;
                        }
                        else
                                break;
                }
                else
                {
                        if (gadgetsD[ptrD].first * dvb < gadgetsP[ptrP].first * pvb)
                        {
                                if (nBurlesCopy - gadgetsD[ptrD].first * dvb >= 0)
                                {
                                        ans.pb(make_pair(gadgetsD[ptrD].second, lower_bound(psMinDvB.begin(), psMinDvB.end(), gadgetsD[ptrD].first) - psMinDvB.begin()));

                                        nBurlesCopy -= gadgetsD[ptrD].first * dvb;
                                        ptrD++;
                                        reqGadgetsCopy--;
                                }
                                else
                                        break;
                        }
                        else
                        {
                                if (nBurlesCopy - gadgetsP[ptrP].first * pvb >= 0)
                                {
                                        ans.pb(make_pair(gadgetsP[ptrP].second, lower_bound(psMinPvB.begin(), psMinPvB.end(), gadgetsP[ptrP].first) - psMinPvB.begin()));

                                        nBurlesCopy -= gadgetsP[ptrP].first * pvb;
                                        ptrP++;
                                        reqGadgetsCopy--;
                                }
                                else
                                        break;
                        }
                }
        }
        if (reqGadgetsCopy == 0)
                return true;
        else
                return false;
}
//...............................

void suraj()
{
        cin >> nDays >> totGadgets >> reqGadgets >> nBurles;

        for (int i = 0; i < nDays; i++)
        {
                ll xx;
                cin >> xx;
                daywiseDvB.pb(make_pair(xx, i));
        }
        for (auto el : daywiseDvB)
        {
                if (psMinDvB.size() > 0)
                {
                        if (el.first < psMinDvB.back())
                        {
                                mD[el.first] = el.second;
                        }
                        psMinDvB.pb(min(psMinDvB.back(), el.first));
                }
                else
                {
                        psMinDvB.pb(el.first);
                        mD[el.first] = el.second;
                }
        }
        // for (int i : psMinDvB)
        //         cout << i << " ";
        // cout << endl;
        for (int i = 0; i < nDays; i++)
        {
                ll x;
                cin >> x;
                daywisePvB.pb(make_pair(x, i));
        }
        for (auto el : daywisePvB)
        {
                if (psMinPvB.size() > 0)
                {
                        if (el.first < psMinPvB.back())
                        {
                                mP[el.first] = el.second;
                        }
                        psMinPvB.pb(min(psMinPvB.back(), el.first));
                }
                else
                {
                        psMinPvB.pb(el.first);
                        mP[el.first] = el.second;
                }
        }
        // for (int i : psMinPvB)
        //         cout << i << " ";
        // cout << endl;
        for (int i = 0; i < totGadgets; i++)
        {
                ll type, d = -1, p = -1;
                cin >> type;
                if (type == 1)
                {
                        cin >> d;
                        gadgetsD.pb(make_pair(d, i));
                }
                else
                {
                        cin >> p;
                        gadgetsP.pb(make_pair(p, i));
                }
        }
        sort(gadgetsD.begin(), gadgetsD.end());
        sort(gadgetsP.begin(), gadgetsP.end());
        int l = 0, r = nDays - 1;
        int m = l + (r - l) / 2;
        while (l < r)
        {
                cout << "l = " << l << " r = " << r << endl;
                m = l + (r - l) / 2;
                if (check(m)) //check whether reqGadgets can be bought in the first m days or not
                {
                        r = m;
                }
                else
                        l = m + 1;
        }
        cout << l + 1 << endl;
        for (auto el : ans)
                cout << el.first + 1 << " " << el.second + 1 << endl;
}

//................................
