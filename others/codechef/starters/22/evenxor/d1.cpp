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

        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

        // cout << setprecision(15) << fixed;

        int t = 1;

        cin >> t;

        for (int i = 1; i <= t; i++)
        {

                // cout << "Case #" << i << ": ";

                suraj();
        }

        return 0;
}
//...............................
vector<int> v;
vector<int> ans;
vector<bool> flag;
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

void permute()
{
        cnt++;
        // if (cnt == 1e5)
        //         cout << "cnt = " << cnt << endl;
        // if (cnt == 1e6)
        //         cout << "cnt = " << cnt << endl;
        // if (cnt == 1e7)
        //         cout << "cnt = " << cnt << endl;
        if (v.size() == 4)
        {
                ans.pb(convertToInt(v));
                return;
        }
        for (int i = 0; i <= 19; i++)
        {
                if (flag[i] == true)
                        continue;

                v.pb(i);
                flag[i] = true;

                permute();

                if (ans.size() == n)
                        return;

                v.pop_back();
                flag[i] = false;
        }
}
//...............................

void suraj()
{
        cin >> n;

        ans.clear();
        v.clear();

        flag = vector<bool>(20, false);

        // print n combinations of a 19bit no with 4 or 6 or 8 or.... bits turned on.

        permute();

        // cout << "cnt = " << cnt << endl;

        for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
