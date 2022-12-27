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
        string s;
        cin >> s;
        int r, b, g, R, B, G;
        for (int i = 0; i < s.size(); i++)
        {
                if (s[i] == 'r')
                        r = i;
                if (s[i] == 'g')
                        g = i;
                if (s[i] == 'b')
                        b = i;
                if (s[i] == 'R')
                        R = i;
                if (s[i] == 'G')
                        G = i;
                if (s[i] == 'B')
                        B = i;
        }
        if (b < B && g < G && r < R)
                cout << "YES" << endl;
        else
                cout << "NO" << endl;
}

//................................

// int

// int

// int

// int
