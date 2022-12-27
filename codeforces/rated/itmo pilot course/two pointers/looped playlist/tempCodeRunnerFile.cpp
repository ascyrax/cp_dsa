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
        ll n;
        cin >> n;
        ll p;
        cin >> p;

        ll total = 0;

        vector<ll> v(n);
        for (ll &i : v)
        {
                cin >> i;
                total += i;
        }

        ll index = 0, nSongs = 0;
        if (p % total == 0)
        {
                cout << 1 << " ";
                cout << (p / total) * n << endl;
                return;
        }

        nSongs = p / total;

        p -= total * nSongs;
        nSongs *= n;

        // smallest substring adding to p

        ll l = 0, r = 0;

        ll len = n, currSum = 0;

        for (ll i = 0; i < n; i++)
        {
                currSum = 0, l = i;
                // cout << "i = " << i << endl;
                for (r = i; r < i + n; r++)
                {
                        // cout << "r = " << r << endl;
                        currSum += v[r % n];
                        while (currSum >= p)
                        {
                                if (r - l + 1 <= len)
                                {
                                        len = min(len, r - l + 1);
                                        index = l % n;
                                }
                                l++;
                                currSum -= v[l % n];
                        }
                }
        }

        cout << index + 1 << " " << nSongs + len << endl;
}

//................................

// ll

// ll

// int

// int
