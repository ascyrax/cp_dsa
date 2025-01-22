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

                cout << "Case #" << i << ": ";

                suraj();
        }

        return 0;
}

//...............................

//...............................

void suraj()
{
        string i, p;
        cin >> i >> p;

        int leni = i.size();
        int lenp = p.size();

        if (lenp < leni || (lenp == leni && i != p))
                cout << "IMPOSSIBLE" << endl;
        else
        {
                int ptri = 0, ptrp = 0;
                for (; ptri < leni && ptrp < lenp; ptri++, ptrp++)
                {
                        while (i[ptri] != p[ptrp])
                        {
                                ptrp++;
                                if (ptrp == lenp)
                                        break;
                        }
                }
                if (ptri < leni)
                {
                        cout << "IMPOSSIBLE" << endl;
                }
                else
                {
                        cout << lenp - leni << endl;
                }
        }
}

//................................

// int

// int

// int

// int
