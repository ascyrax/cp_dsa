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

int main()
{

        // ioss

        // startTime=(double)clock();

        freopen("rental.in", "r", stdin);
        freopen("rental.out", "w", stdout);

        // cout << setprecision(15) << fixed;

        int t = 1;

        // cin>>t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................
bool custom(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
        if (a.second > b.second)
                return true;
        else if (a.second == b.second)
        {
                if (a.first > b.first)
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
        ll n, m, r;
        cin >> n >> m >> r;

        vector<ll> milk(n);
        vector<pair<ll, ll>> pq;
        vector<ll> rent;

        for (ll &i : milk)
                cin >> i;

        for (ll i = 0; i < m; i++)
        {
                ll p, q;
                cin >> p >> q;

                pq.pb(make_pair(p, q));
        }

        for (ll i = 0; i < r; i++)
        {
                ll a;
                cin >> a;
                rent.pb(a);
        }

        sort(milk.rbegin(), milk.rend());
        sort(pq.begin(), pq.end(), custom);
        sort(rent.rbegin(), rent.rend());

        vector<ll> psmilk;
        vector<ll> psgallons, psmoney;
        vector<ll> psrent;

        psmilk.pb(milk[0]);
        psgallons.pb(pq[0].first);
        psmoney.pb(pq[0].second * pq[0].first);
        psrent.pb(rent[0]);

        for (ll i = 1; i < n; i++)
                psmilk.pb(psmilk.back() + milk[i]);

        for (ll i = 1; i < m; i++)
        {
                psgallons.pb(psgallons.back() + pq[i].first);
                psmoney.pb(psmoney.back() + pq[i].second * pq[i].first);
        }

        for (ll i = 1; i < r; i++)
                psrent.pb(psrent.back() + rent[i]);
        // cout << "--------------------" << endl;
        // cout << "milk: " << endl;
        // for (auto el : milk)
        //         cout << el << " ";
        // cout << endl;
        // cout << "pq:" << endl;
        // for (auto el : pq)
        //         cout << el.first << " " << el.second << endl;
        // cout << "rent: " << endl;
        // for (auto el : rent)
        //         cout << el << " ";
        // cout << endl;
        // cout << "psmilk: " << endl;
        // for (auto el : psmilk)
        //         cout << el << " ";
        // cout << endl;
        // cout << "psgallons: " << endl;
        // for (auto el : psgallons)
        //         cout << el << " ";
        // cout << endl;
        // cout << "psmoney: " << endl;
        // for (auto el : psmoney)
        //         cout << el << " ";
        // cout << endl;
        // cout << "psrent: " << endl;
        // for (auto el : psrent)
        //         cout << el << " ";
        // cout << endl;
        // cout << "--------------------" << endl;

        // if a gets rented then n-a will sell its milk

        // rented -> 0 to r
        // milk sold -> 0 to (totalMilk corresponding cows)

        ll ans = 0;

        for (ll rented = r, milked = n - r; rented >= 0; rented--, milked++)
        {
                // the cows with the largest milk production will be milked always
                // cout << "rented : " << rented << " , milked : " << milked << endl;
                ll moneyByRent;
                if (rented - 1 >= 0)
                        moneyByRent = psrent[rented - 1];
                else
                        moneyByRent = 0;
                ll moneyByMilking = 0;

                ll milkCnt;
                if (milked - 1 >= 0)
                        milkCnt = psmilk[milked - 1];
                else
                        milkCnt = 0;

                if (milkCnt > psgallons[m - 1])
                        break;

                auto loc = lower_bound(psgallons.begin(), psgallons.end(), milkCnt) - psgallons.begin();

                if (psgallons[loc] == milkCnt)
                {
                        moneyByMilking = psmoney[loc];
                }
                else
                {
                        if (loc - 1 >= 0)
                        {
                                moneyByMilking = psmoney[loc - 1];
                                ll temp = milkCnt - psgallons[loc - 1];
                                moneyByMilking += pq[loc].second * temp;
                        }
                        else
                        {
                                moneyByMilking = 0;
                                ll temp = milkCnt - 0;
                                moneyByMilking += pq[loc].second * temp;
                        }
                }
                // cout << "moneyByMilking: " << moneyByMilking << endl;
                // cout << "moneyByRent: " << moneyByRent << endl;
                // cout << "money made : " << moneyByMilking + moneyByRent << endl;

                ans = max(ans, moneyByMilking + moneyByRent);
        }

        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
