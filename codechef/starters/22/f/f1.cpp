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

//...............................
vector<int> v;
vector<int> ans;
int n;

int convertToInt(vector<int> v)
{
        int val = 0;
        for (int i : v)
        {
                val += pow(2, i);
        }
        return val;
}

int cnt = 0;

void search(int k)
{
        cnt++;
        if (k == 20)
                return;
        if (v.size() == 4)
        {
                ans.pb(convertToInt(v));
                return;
        }
        else
        {
                v.pb(k);
                search(k + 1);

                v.pop_back();
                search(k + 1);
        }
}

//...............................

int main()
{

        // ioss

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        // cout << setprecision(15) << fixed;

        search(0);

        int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout << "Case #" << i << ": ";

                suraj();
        }

        return 0;
}

void suraj()
{
        cin >> n;

        // print n  19bits( or less) nos with 0 or 2 or 4 or 6 or 8 or.... bits turned on.

        // ie xor of any two good nos is always good. So just print n good numbers;

        for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
