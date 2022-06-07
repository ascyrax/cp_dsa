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
        freopen("rentals.in", "r", stdin);
        freopen("rentals.out", "w", stdout);
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
        ll n, m, r;
        cin >> n >> m >> r;

        vector<ll> vcows;
        for (ll i = 0; i < n; i++)
        {
                ll c;
                cin >> c;
                vcows.pb(c);
        }
        sort(vcows.rbegin(), vcows.rend());
        vector<ll> pscows(n);
        pscows[0] = vcows[0];
        for (ll i = 1; i < n; i++)
        {
                pscows[i] = pscows[i - 1] + vcows[i];
        }

        ll sumq = 0;
        vector<pair<ll, ll>> vpmilk;
        for (ll i = 0; i < m; i++)
        {
                ll q, p;
                cin >> q >> p;
                sumq += q;
                vpmilk.pb(make_pair(p, q));
        }
        sort(vpmilk.rbegin(), vpmilk.rend());
        vector<ll> psmilk(m), psmilkCost(m);
        psmilk[0] = vpmilk[0].second;
        for (int i = 1; i < m; i++)
        {
                psmilk[i] = psmilk[i - 1] + vpmilk[i].second;
        }
        psmilkCost[0] = vpmilk[0].first * vpmilk[0].second;
        for (ll i = 1; i < m; i++)
        {
                psmilkCost[i] = psmilkCost[i - 1] + vpmilk[i].first * vpmilk[i].second;
        }

        vector<ll> vrent;
        for (ll i = 0; i < r; i++)
        {
                ll rent;
                cin >> rent;
                vrent.pb(rent);
        }
        sort(vrent.rbegin(), vrent.rend());
        vector<ll> psrent(r);
        psrent[0] = vrent[0];
        for (ll i = 1; i < r; i++)
        {
                psrent[i] = psrent[i - 1] + vrent[i];
        }

        ll rented = 0, milked = n;
        ll ans = 0;
        // cout << "vcows" << endl;
        // for (int i : vcows)
        //         cout << i << "  ";
        // cout << endl;
        // cout << "pscows" << endl;
        // for (int i : pscows)
        //         cout << i << "  ";
        // cout << endl;
        // cout << "vpmilk" << endl;
        // for (auto i : vpmilk)
        //         cout << i.first << "  ";
        // cout << endl;
        // for (auto i : vpmilk)
        //         cout << i.second << "  ";
        // cout << endl;
        // cout << "psmilk" << endl;
        // for (int i : psmilk)
        //         cout << i << "  ";
        // cout << endl;
        // cout << "psmilkCost" << endl;
        // for (int i : psmilkCost)
        //         cout << i << "  ";
        // cout << endl;
        // cout << "vrent" << endl;
        // for (int i : vrent)
        //         cout << i << "  ";
        // cout << endl;
        // cout << "psrent" << endl;
        // for (int i : psrent)
        //         cout << i << "  ";
        // cout << endl;

        for (rented = 0, milked = n; rented <= n; rented++, milked--)
        {
                // cout << "rented = " << rented << " milked = " << milked << endl;
                ll totalRented = 0, totalMilked = 0;
                if (rented > r)
                        break;

                ll milkInGallons = 0;
                if (milked > 0)
                        milkInGallons = pscows[milked - 1];

                if (milkInGallons > sumq)
                        continue;
                //total add rented cows
                // total += psrent[rented - 1];
                if (rented > 0)
                        totalRented += psrent[rented - 1];
                //total me add milked portion too
                auto it = upper_bound(psmilk.begin(), psmilk.end(), milkInGallons) - psmilk.begin();
                it--;
                if (it >= 0)
                {
                        milkInGallons -= psmilk[it];
                        totalMilked += psmilkCost[it];
                }
                else
                {
                        milkInGallons = milkInGallons; //no change
                }
                totalMilked += ((milkInGallons)*vpmilk[it + 1].first);
                ans = max(ans, totalRented + totalMilked);
                // cout << "totalMilked = " << totalMilked << endl;
                // cout << "totalRented = " << totalRented << endl;
                // cout << "ans = " << ans << endl;
        }
        cout << ans << endl;
}

//................................
