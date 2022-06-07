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
const ll INF = ll(1e9);
const ll NEG_INF = ll(-1e9);
//const ll INF = 2147483647;
//const ll NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        ll n;
        vector<ll> strHeroes;
        ll m;
        cin >> n;
        strHeroes = vector<ll>(n, 0ll);
        for (ll &i : strHeroes)
                cin >> i;

        sort(strHeroes.begin(), strHeroes.end());

        vector<ll> pSum;
        for (ll i : strHeroes)
        {
                if ((ll)pSum.size() > 0)
                        pSum.pb(pSum.back() + i);
                else
                        pSum.pb(i);
        }
        cin >> m;
        for (ll i = 0; i < m; i++)
        {
                ll defDragon, strDragon;
                cin >> defDragon >> strDragon;
                if (pSum[n - 1] <= strDragon)
                {
                        // cout << "pSum[n-1] = " << pSum[n - 1] << endl;
                        auto it = lower_bound(strHeroes.begin(), strHeroes.end(), defDragon);
                        ll temp = 0;
                        if (it == strHeroes.end())
                        {
                                // cout << "if" << endl;
                                // temp = defDragon - *(--it);
                                // temp += (strDragon - (pSum[n - 1] - *it));
                                temp = strDragon + defDragon - pSum[n - 1];
                        }
                        else if (it == strHeroes.begin())
                        {

                                temp = max(0ll, defDragon - *it);
                                temp += (strDragon - (pSum[n - 1] - *it));
                        }
                        else
                        {
                                // cout << "else" << endl;
                                if (*it == defDragon)
                                {
                                        temp += 0;
                                }
                                else
                                {
                                        // ll diffR = *it - defDragon;
                                        // ll diffL = defDragon - *(it - 1);
                                        // if (diffR < diffL)
                                        // {
                                        //         temp = diffR;
                                        // }
                                        // else
                                        // {
                                        //         temp = diffL;
                                        //         it--;
                                        // }
                                        it--;
                                        temp += (defDragon - *it);
                                        // cout << temp << endl;
                                }
                                temp += (strDragon - (pSum[n - 1] - *it));
                        }
                        cout << temp << endl;
                }
                else if (pSum[n - 1] > strDragon)
                { //we need to efficiently choose who will kill the dragon
                        ll ans = 1e18;
                        ll sumDefendingHeroes = 0;
                        ll l = 0, r = n - 1;
                        while (true)
                        {
                                // cout << "l = " << l << " r = " << r << endl;
                                ll mid = l + (r - l) / 2;
                                sumDefendingHeroes = pSum[n - 1] - strHeroes[mid];
                                ans = min(ans, max(0ll, defDragon - strHeroes[mid]) + max(0ll, strDragon - sumDefendingHeroes));
                                if (sumDefendingHeroes > strDragon) //send a hero with more attack power to the dragon
                                {
                                        if (strHeroes[mid] >= defDragon)
                                        {
                                                ans = min(ans, 0ll + max(0ll, strDragon - sumDefendingHeroes));
                                                break;
                                        }
                                        else
                                        {
                                                l = mid;
                                                ans = min(ans, defDragon - strHeroes[mid] + max(0ll, strDragon - sumDefendingHeroes));
                                                // cout << "ans = " << ans << endl;
                                        }
                                }
                                else if (sumDefendingHeroes < strDragon)
                                {
                                        r = mid - 1;
                                        ans = min(ans, max(0ll, defDragon - strHeroes[mid]) + strDragon - sumDefendingHeroes);
                                        // cout << "ans = " << ans << endl;
                                }
                                else if (sumDefendingHeroes == strDragon)
                                {
                                        l = mid;
                                        ans = min(ans, max(0ll, defDragon - strHeroes[mid]) + 0ll);
                                        // cout << "ans = " << ans << endl;
                                        break;
                                }
                                if (r - l <= 1)
                                {
                                        // cout << "l = " << l << " r = " << r << endl;
                                        sumDefendingHeroes = pSum[n - 1] - strHeroes[l];
                                        ans = min(ans, max(0ll, defDragon - strHeroes[l]) + max(0ll, strDragon - sumDefendingHeroes));
                                        // cout << "ans = " << ans << endl;
                                        sumDefendingHeroes = pSum[n - 1] - strHeroes[r];
                                        ans = min(ans, max(0ll, defDragon - strHeroes[r]) + max(0ll, strDragon - sumDefendingHeroes));
                                        // cout << "ans = " << ans << endl;
                                        break;
                                }
                        }
                        // sumDefendingHeroes = pSum[n] - strHeroes[4 - 1];
                        // cout << "ans = " << max(0ll, defDragon - strHeroes[4 - 1]) + abs(strDragon - sumDefendingHeroes) << endl;
                        cout << ans << endl;
                }
                // cout << "================" << endl;
        }
}

//................................
