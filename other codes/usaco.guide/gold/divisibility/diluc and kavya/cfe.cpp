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
pair<int, int> simplify(int cntd, int cntk)
{
        // for (int i = 2; i <= min(cntd, cntk); i++)
        // {
        //         while (cntd % i == 0 && cntk % i == 0)
        //         {
        //                 cntd /= i;
        //                 cntk /= i;
        //         }
        // }

        while (1)
        {
                int gcd = __gcd(cntd, cntk);
                if (gcd > 1)
                {
                        cntd /= gcd;
                        cntk /= gcd;
                }
                else
                        break;
        }

        return make_pair(cntd, cntk);
}
//...............................

void suraj()
{
        int n;
        cin >> n;
        string s;
        cin >> s;

        int totd = 0, totk = 0;

        map<pair<int, int>, int> cnt;

        for (int i = 0; i < n; i++)
        {
                if (s[i] == 'D')
                        totd++;
                else
                        totk++;

                // cout << totd << " " << totk << endl;

                if (totd == i + 1 || totk == i + 1) // ie all Ds or all Ks
                {
                        cout << i + 1 << " ";
                        continue;
                }

                pair<int, int> temp = simplify(totd, totk);

                cnt[temp]++;

                // cout << "hi " << cntd << " " << cntk << endl;

                cout << cnt[temp] << " ";
        }
        cout << endl;
}

//................................

// int

// int

// int

// int
