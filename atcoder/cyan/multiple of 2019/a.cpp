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
// abcdefgh
// say if fgh%mod=5
// and if cdefgh%mod = 5 as well
// => cde000 % mod =0 .
// since mod=2019 here, therefore ( cde000%mod =0 )=> cde %mod=0.
//...............................

void suraj()
{
        string s;
        cin >> s;

        ll lens = s.size();

        vector<ll> suffixMod(lens + 1, -1);

        ll mod = 2019;
        ll pow_of_10 = 1;
        ll val = 0;

        vector<ll> cnt(2020, 0);
        ll ans = 0;
        cnt[0] = 1; // when suffix of length 0 is chosen.

        for (ll r = lens - 1; r >= 0; r--)
        {
                ll digit = s[r] - '0';
                // val of the suffix
                val = (val + (digit * pow_of_10) % mod) % mod; // e.g. (8*100000000000)%mod but this is also = (8%mod*(1e11)%mod)%mod;

                // cout << "val = " << val << endl;
                pow_of_10 = (pow_of_10 * 10) % mod;

                ans += cnt[val];

                cnt[val]++;
        }

        cout << ans << endl;
}

//................................

// ll

// int

// int

// int
