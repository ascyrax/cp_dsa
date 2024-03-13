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

//...............................

void suraj()
{
        int n, x;
        cin >> n >> x;

        string s;
        cin >> s;

        int lens = n;

        int l = 0, r = 0;
        int cnt = 0;

        string t = "";

        int ans = 0;

        for (r = 0; r < n; r++)
        {
                if (s[r] == '1')
                {
                        while (cnt > 0)
                        {
                                t.pb('0');
                                cnt--;
                        }
                        t.pb('1');
                        l = r;
                }
                else if (s[r] == '0')
                {
                        cnt++;
                        if (cnt == x)
                        {
                                ans++;
                                cnt = 0;
                        }
                }
        }
        while (cnt > 0)
        {
                t.pb('0');
                cnt--;
        }
        // cout << t << endl;
        int lent = t.size();
        l = 0, r = 0;
        cnt = 0;
        int mx = 1;
        for (r = 0; r < lent; r++)
        {
                if (t[r] == '0')
                {
                        mx = max(mx, r - l + 1);
                }
                else if (t[r] == '1')
                {
                        if (cnt == 0)
                        {
                                cnt++;
                                mx = max(mx, r - l + 1);
                        }
                        else
                        {
                                mx = max(mx, (r - 1) - l + 1);
                                while (cnt > 0)
                                {
                                        if (t[l] == '1')
                                                cnt--;
                                        l++;
                                }
                                r--;
                        }
                }
        }
        // cout << "mx = " << mx << endl;
        if (mx >= x)
                ans++;
        cout << ans << endl;
}

//................................

// int

// int

// int

// int
