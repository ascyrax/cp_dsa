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
int n, k;
vector<int> v;
bool check(int x, int y)
{
        int l = 0, r = 0; // two pointers
        int bad = 0, good = 0;
        int nSubs = 0; // no of subarrays
        for (r = 0; r < n; r++)
        {
                // cout << "l = " << l << " , r = " << r << endl;
                if (v[r] >= x && v[r] <= y)
                {
                        // cout << "if a" << endl;
                        good++;
                        if (good > bad)
                        {
                                // cout << "good > bad" << endl;
                                if (nSubs + 1 < k)
                                {
                                        // cout << "if b" << endl;
                                        nSubs++;
                                        l = r + 1;
                                        good = 0;
                                        bad = 0;
                                }
                                else if (nSubs + 1 == k)
                                {
                                        // check if the last few elements from r=r to r=n-1 keeps this subarray as subarray or not.
                                        ;
                                }
                        }
                }
                else
                {
                        bad++;
                }
        }
        if (nSubs == k - 1 && good > bad)
                return true;
        else
                return false;
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
                x = min(x, i);
                y = max(y, i);
        }

        int flag = 0;

        while (x < y)
        {
                int mid = x + (y - x) / 2;
                // cout << x << " " << mid << " " << y << endl;
                if (check(x, mid))
                {
                        y = mid;
                        // cout << "if" << endl;
                }
                else
                {
                        // cout << "else" << endl;
                        if (flag == 0 && x + 1 == y)
                        {
                                flag = 1;
                                x = mid;
                        }
                        else if (flag == 1 && x + 1 == y)
                                break;
                        x = mid;
                }
        }

        if (x == y - 1)
        {
                if (check(y, y))
                {
                        x = y;
                }
                else if (check(x, x))
                {
                        y = x;
                }
        }

        cout << x << " " << y << endl;
        // find k subarray;

        int l = 0, r = 0; // two pointers
        int bad = 0, good = 0;
        int nSubs = 0; // no of subarrays
        for (r = 0; r < n; r++)
        {
                if (v[r] >= x && v[r] <= y)
                {
                        good++;
                        if (good > bad)
                        {
                                if (nSubs + 1 < k)
                                {
                                        nSubs++;
                                        cout << l + 1 << " " << r + 1 << endl;
                                        l = r + 1;
                                        good = 0;
                                        bad = 0;
                                }
                                else if (nSubs + 1 == k)
                                {
                                        // check if the last few elements from r=r to r=n-1 keeps this subarray as subarray or not.
                                        ;
                                }
                        }
                }
                else
                {
                        bad++;
                }
        }
        if (nSubs == k - 1 && good > bad)
                cout << l + 1 << " " << r << endl;
}

//................................

// int

// int

// int

// int
