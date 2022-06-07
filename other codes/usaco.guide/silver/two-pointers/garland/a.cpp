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
        string s;
        cin >> s;

        int lens = n;

        vector<vector<int>> data(26, vector<int>(n, 0));

        for (int i = 0; i <= 25; i++)
        {
                for (int len = 1; len <= lens; len++) // cnt of unwanted characters
                {
                        int l = 0, r = 0;
                        int cnt = 0; // cnt of characters of the string s which are not equal to char(i-'a');
                        int mx = 0;
                        for (r = 0; r < lens; r++)
                        {
                                if (s[r] - 'a' != i)
                                        cnt++;
                                // cnt more than len is not allowed
                                while (cnt > len)
                                {
                                        if (s[l] - 'a' != i)
                                                cnt--;
                                        l++;
                                }
                                // if (r - l + 1 > mx)
                                //         cout << "r = " << r << " , l = " << l << " , r-l+1 = " << r - l + 1 << endl;
                                mx = max(mx, r - l + 1);
                        }
                        data[i][len - 1] = mx;
                }
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
                int m;
                cin >> m;
                char c;
                cin >> c;

                cout << data[c - 'a'][m - 1] << endl;
        }
}

//................................

// int

// int

// int

// int
