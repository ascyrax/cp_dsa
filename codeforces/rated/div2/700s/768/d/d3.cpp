// @author: ascyrax
// queue implementation should work but it doesnt. there should have been 3 ifs but i was using if else if else if. thats why maybe.
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
int n, k;
vector<int> v;
vector<int> vcopy;
//...............................
bool check(int x, int y)
{
        // O(n) check. we might need a O(logn) check using lower_bound.
        int good = 0, bad = 0;
        // for (int i = 0; i < n; i++)
        // {
        //         if (v[i] >= x && v[i] <= y)
        //         {
        //                 good++;
        //         }
        //         else
        //                 bad++;
        // }
        // return (good - bad >= k);

        // O(logn)
        auto locx = lower_bound(vcopy.begin(), vcopy.end(), x);
        auto locy = upper_bound(vcopy.begin(), vcopy.end(), y) - 1;
        good = locy - (locx - 1);
        bad = n - good;
        return (good - bad >= k);
}
//...............................

void suraj()
{
        cin >> n >> k;

        v = vector<int>(n);

        int x = 1e9, y = 0;

        for (int &i : v)
        {
                cin >> i;
                // vcopy.pb(i);
                x = min(x, i);
                y = max(y, i);
        }
        vcopy = v;
        sort(vcopy.begin(), vcopy.end());
        // good = nos between x and y inclusive
        // bad = nos outside the range x and y

        // for a particular (x,y), if (good-bad>=k) then that x,y is valid.

        // since every subarray needs to have atleast 1 more value of good than bad.
        // therefore, k subarrays => we need at least k more values of good than bad.

        // just count good and bad in the whole subaerray, it will tell the validity of x and y.

        pair<int, int> ans;
        int lenans = n;

        queue<pair<int, int>> q;
        q.push(make_pair(x - 1, y + 1));
        while (!q.empty())
        {
                pair<int, int> top = q.front();
                // cout << "top : ";
                // cout << top.first << " " << top.second << endl;
                q.pop();

                if (check(top.first + 1, top.second - 1))
                {
                        q.push(make_pair(top.first + 1, top.second - 1));
                        // top.first++;
                        // top.second--;
                }
                if (check(top.first + 1, top.second))
                {
                        q.push(make_pair(top.first + 1, top.second));
                        // top.first++;
                }
                if (check(top.first, top.second - 1))
                {
                        q.push(make_pair(top.first, top.second - 1));
                        // top.second--;
                }
                // else
                //         continue;
                if (top.second - top.first + 1 <= lenans)
                {
                        lenans = top.second - top.first + 1;
                        ans = top;
                }
        }
        x = ans.first;
        y = ans.second;

        cout << x << " " << y << endl;
        int l = 0, r = 0;
        int good = 0, bad = 0;
        int nsub = 0; // no of subarrays formed.
        for (r = 0; r < n; r++)
        {
                if (v[r] >= x && v[r] <= y)
                {
                        good++;
                        if (good > bad)
                        {
                                if (nsub + 1 == k)
                                {
                                        cout << l + 1 << " " << n << endl;
                                        break;
                                }
                                else
                                {
                                        cout << l + 1 << " " << r + 1 << endl;
                                        l = r + 1;
                                        nsub++;
                                        good = 0;
                                        bad = 0;
                                }
                        }
                }
                else
                        bad++;
        }

        // cout << "--------------------------------" << endl;
}

//................................

// int

// int

// int

// int
