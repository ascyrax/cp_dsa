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

        ioss

            // startTime=(double)clock();

            // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

            // cout << setprecision(15) << fixed;

            int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout<<"Case #"<<i<<": ";

                suraj();
        }

        return 0;
}

//...............................
// ll
//...............................

void suraj()
{
        ll n;
        cin >> n;

        multiset<ll, greater<ll>> s;
        ll sum = 0;
        map<ll, ll> cnt;
        multiset<ll> pieces;
        multiset<ll, greater<ll>> piecesRev;
        for (ll i = 0; i < n; i++)
        {
                ll a;
                cin >> a;
                pieces.insert(a);
                piecesRev.insert(a);
                cnt[a]++;
                sum += a;
                // s.insert(a);
        }

        if (n == 1)
        {
                cout << "YES" << endl;
                return;
        }
        // cout << "sum = " << sum << endl;
        s.insert(sum);

        while (s.size() > 0 && n > 0)
        {
                ll smallest = *pieces.begin();
                ll largest = *piecesRev.begin();
                // cout << "s.size() = " << s.size() << endl;
                ll ab = *s.begin(); // this is the largest element in the multiset s.
                s.erase(s.begin());
                // if(ab< largest element of pieces) print no. return;
                if (ab < largest)
                {
                        cout << "NO" << endl;
                        return;
                }
                // cout << "ab = " << ab << endl;
                ll a, b;
                if (ab & 1)
                {
                        a = ab / 2;
                        b = a + 1;
                }
                else
                {
                        a = ab / 2;
                        b = ab / 2;
                }
                if (a < smallest || b < smallest)
                {
                        cout << "NO" << endl;
                        return;
                }
                // if (a != 0)
                {
                        if (cnt[a] > 0)
                        {
                                cnt[a]--;
                                pieces.erase(pieces.find(a));
                                piecesRev.erase(piecesRev.find(a));
                                n--;
                        }
                        else
                        {
                                s.insert(a);
                        }
                }
                // if (b != 0)
                {
                        if (cnt[b] > 0)
                        {
                                cnt[b]--;
                                pieces.erase(pieces.find(b));
                                piecesRev.erase(piecesRev.find(b));
                                n--;
                        }
                        else
                        {
                                s.insert(b);
                        }
                }
        }
        cout << "YES" << endl;

        // while (s.size() >= 2)
        // {
        //         ll a = *s.begin();
        //         s.erase(s.begin());
        //         ll b = *s.begin();
        //         s.erase(s.begin());
        //         if (a == b || a == b - 1)
        //         {
        //                 s.insert(a + b);
        //         }
        //         else
        //         {
        //                 cout << "NO" << endl;
        //                 return;
        //         }
        // }
        // cout << "YES" << endl;
}

//................................

// ll

// ll

// int

// int
