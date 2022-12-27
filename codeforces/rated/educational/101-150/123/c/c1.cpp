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

//...............................

void suraj()
{
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        for (int &i : v)
                cin >> i;

        vector<int> f(n + 1, 0);

        // f[i] = max(f[i-1],maxsubarraysum of size i + i*x)

        vector<int> mxSubSum(n + 1, -1e9); // mxSubSum[i] = max subarray ssum of size i
        mxSubSum[0] = 0;
        vector<int> ps(n, 0);
        ps[0] = v[0];
        for (int i = 1; i < n; i++)
        {
                ps[i] = ps[i - 1] + v[i];
        }

        // ps[i] = sum till index i-1. ie the ith element
        for (int len = 1; len <= n; len++)
        {
                // int sum = 0;
                // here i=len of subarray
                for (int r = len - 1; r < n; r++)
                {
                        if (r - len >= 0)
                                mxSubSum[len] = max(mxSubSum[len], ps[r] - ps[r - len]);
                        else
                                mxSubSum[len] = max(mxSubSum[len], ps[r] - 0);
                }
        }
        vector<int> temp(n + 1, 0);
        temp[n] = mxSubSum[n];
        for (int i = n - 1; i >= 0; i--)
        {
                temp[i] = max(temp[i + 1], mxSubSum[i]);
        }
        // cout << "--" << endl;
        // for (int i = 0; i <= n; i++)
        //         cout << mxSubSum[i] << " ";
        // cout << endl;

        // for (int i = 0; i <= n; i++)
        //         cout << temp[i] << " ";
        // cout << endl;
        // cout << "--" << endl;

        for (int i = 0; i <= n; i++)
        {
                if (i == 0)
                {
                        f[i] = max(0, temp[i] + x * i);
                }
                else
                        f[i] = max(f[i - 1], temp[i] + x * i);
                cout << f[i] << " ";
        }
        cout << endl;
}

//................................

// int

// int

// int

// int
