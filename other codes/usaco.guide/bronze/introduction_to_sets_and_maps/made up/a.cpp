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

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

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

//...............................

void suraj()
{

        // set of values present in a

        // map with these values as the key and the no of times it occurs in a as the value

        // map with values of vector b as the key and indices(1-indexed) containing these values
        // as the elements of the vector(which is the value for the key)

        // map with values of vector c and the no of occurence as the value

        ll n;
        cin >> n;
        vector<ll> va(n), vb(n), vc(n);
        for (ll &i : va)
                cin >> i;
        for (ll &i : vb)
                cin >> i;
        for (ll &i : vc)
                cin >> i;

        set<ll> valuesA;
        for (ll i : va)
                valuesA.insert(i);
        map<ll, ll> valCntA;
        for (ll i : va)
                valCntA[i]++;

        map<ll, vector<ll>> valIndicesB;
        for (ll i = 0; i < n; i++)
        {
                valIndicesB[vb[i]].pb(i + 1);
        }

        map<ll, ll> valCntC;
        for (ll i : vc)
                valCntC[i]++;
        ll cntIJ = 0;
        for (ll i : valuesA)
        {
                ll cntI = valCntA[i];
                ll goodIndicesInC = 0;
                for (ll j : valIndicesB[i])
                {
                        ll cntJ = valCntC[j];
                        goodIndicesInC += cntJ;
                }
                cntIJ += cntI * goodIndicesInC;
        }
        cout << cntIJ << endl;
}

//................................

// ll

// ll

// int

// int
