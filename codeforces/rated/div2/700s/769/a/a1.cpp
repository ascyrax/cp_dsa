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

        cin >> t;

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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
                if (s[i] == '0')
                        cnt0++;
                else
                        cnt1++;
        }

        if (n == 1)
        {
                cout << "YES" << endl;
        }
        else if (n == 2)
        {
                if (cnt0 == cnt1)
                        cout << "yes" << endl;
                else
                        cout << "no" << endl;
        }
        else
        {
                cout << "no" << endl;
        }
}

//................................

// int

// int

// int

// int
