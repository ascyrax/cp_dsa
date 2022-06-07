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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;

        vector<int> cnt(n);
        int l = 0, r = 0;
        int gcd = v[l];
        int prevl = l;
        // rbnd means the right boundary
        for (int rbnd = 0; rbnd <= n - 1; rbnd++) // rbnd = i corresponds to a subarray of length of i+1.
        {
                // right boundary will be rbnd+1
                // left will be 1 always......
                prevl = l;
                cout << "rbnd : " << rbnd << endl;
                gcd = v[l];
                for (r = l; r <= rbnd; r++)
                {
                        gcd = __gcd(gcd, v[r]);
                        cout << "l : " << l << " , r: " << r << " , gcd : " << gcd << endl;
                        if (gcd == r - l + 1)
                        {
                                cout << "if" << endl;
                                cout << "l : " << l << " , r: " << r << " , gcd : " << gcd << endl;
                                cout << "hello" << endl;
                                cnt[rbnd]++;
                                l = r + 1;
                                gcd = v[l];
                        }
                }
        }
        for (int el : cnt)
                cout << el << " ";
        cout << endl;
        for (int i = 1; i < n; i++)
        {
                cnt[i] += cnt[i - 1];
        }
        for (int el : cnt)
                cout << el << " ";
        cout << endl;
}

//................................

// int

// int

// int

// int
