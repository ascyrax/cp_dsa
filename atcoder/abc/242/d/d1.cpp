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
        string s;
        cin >> s;

        ll q;
        cin >> q;
        for (ll i = 0; i < q; i++)
        {
                ll t, k;
                cin >> t >> k;
                ll treal = t, kreal = k;
                int cnt = 0;
                while (t > 0 && k > 1)
                {
                        // cout << "t = " << t << endl;
                        // cout << "k = " << k << endl;
                        if (k % 2 == 1)
                                cnt++;
                        k = (k + 1) / 2;
                        t--;
                }
                cout << "t = " << t << endl;
                cout << "k = " << k << endl;

                cnt %= 3;

                if (t == 0)
                {
                        char c = s[k - 1];
                        cout << "c = " << c << endl;
                        ll diff = treal - 0;
                        ll r = diff % 3;
                        r += cnt;
                        r %= 3;
                        if (r == 0)
                                cout << c << endl;
                        else if (r == 1)
                        {
                                if (c == 'A')
                                        cout << "B" << endl;
                                else if (c == 'B')
                                        cout << "C" << endl;
                                else
                                        cout << "A" << endl;
                        }
                        else if (r == 2)
                        {
                                if (c == 'A')
                                        cout << "C" << endl;
                                else if (c == 'B')
                                        cout << "A" << endl;
                                else
                                        cout << "B" << endl;
                        }

                        // cout << s[k - 1] << endl;
                }
                else if (k == 1)
                {
                        ll diff = t - 0;

                        ll r = diff % 3;
                        char c = s[0];
                        if (r == 0)
                                c = c;
                        // cout << c << endl;
                        else if (r == 1)
                        {
                                if (c == 'A')
                                        c = 'B';
                                // cout << "B" << endl;
                                else if (c == 'B')
                                        c = 'C';
                                // cout << "C" << endl;
                                else
                                        c = 'A';
                                // cout << "A" << endl;
                        }
                        else if (r == 2)
                        {
                                if (c == 'A')
                                        c = 'C';
                                // cout << "C" << endl;
                                else if (c == 'B')
                                        c = 'A';
                                // cout << "A" << endl;
                                else
                                        c = 'B';
                                // cout << "B" << endl;
                        }
                        // cout << r << endl;
                        diff = treal - t;
                        r = diff % 3;
                        if (r == 0)
                                cout << c << endl;
                        else if (r == 1)
                        {
                                if (c == 'A')
                                        cout << "B" << endl;
                                else if (c == 'B')
                                        cout << "C" << endl;
                                else
                                        cout << "A" << endl;
                        }
                        else if (r == 2)
                        {
                                if (c == 'A')
                                        cout << "C" << endl;
                                else if (c == 'B')
                                        cout << "A" << endl;
                                else
                                        cout << "B" << endl;
                        }
                }
                cout << "-----------------------" << endl;
        }
}

//................................

// ll

// ll

// int

// int
