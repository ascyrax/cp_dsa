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
        ll x;
        cin >> x;

        set<ll> arithNums;

        // for (int len = 1; len <= 17; len++)
        // {
        for (ll firstNo = 1; firstNo <= 9; firstNo++)
        {
                for (ll d = -9; d <= 9; d++)
                {
                        string val = to_string(firstNo);
                        while (stoll(val) <= 2e17)
                        {
                                if (stoll(val.substr(val.size() - 1, 1)) + d <= 9 && stoll(val.substr(val.size() - 1, 1)) + d >= 0)
                                {
                                        val += to_string(stoll(val.substr(val.size() - 1, 1)) + d);
                                        arithNums.insert(stoll(val));
                                }
                                else
                                {
                                        arithNums.insert(stoll(val));
                                        break;
                                }
                        }
                }
        }
        // }
        // cout << "arithNums.size() = " << arithNums.size() << endl;
        // // sort(arithNums.begin(), arithNums.end());
        // for (auto el : arithNums)
        //         cout << el << " ";
        // cout << endl;

        auto it = lower_bound(arithNums.begin(), arithNums.end(), x);
        cout << *it << endl;
}

//................................

// ll

// ll

// int

// int
