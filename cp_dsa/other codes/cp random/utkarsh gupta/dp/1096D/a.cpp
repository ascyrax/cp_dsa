
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
ll dp[100001][4];
string hard = "hard";
// dp[i][j] = minimum amiguity when the first i characters of the string s is considered and lets call this as ps(i.e. prefix of s). Now if ps has a subsequence corresponding to the word "hard" of length j. viz length 0 =>"", length 1=> "h", length 2=>"ha", length 3=>"har".
//...............................

void suraj()
{
        ll n;
        cin >> n;
        string s;
        cin >> s;

        vector<ll> v(n);
        for (ll &i : v)
                cin >> i;

        for (int j = 0; j < 4; j++)
        {
                if (s[0] == 'h')
                        dp[0][0] = v[0];
        }

        for (ll i = 1; i < n; i++)
        {
                for (ll j = 0; j < 4; j++)
                {
                        dp[i][j] = 1e18;
                        if (s[i] != 'h' && s[i] != 'a' && s[i] != 'r' && s[i] != 'd')
                        {
                                dp[i][j] = dp[i - 1][j];
                        }
                        else
                        {
                                if (s[i] == 'h')
                                {
                                        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
                                        dp[i][0] = min(dp[i][0], dp[i - 1][0] + v[i]);
                                        dp[i][2] = dp[i - 1][2];
                                        dp[i][3] = dp[i - 1][3];
                                }
                                else if (s[i] == 'a')
                                {
                                        dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]);
                                        dp[i][1] = min(dp[i][1], dp[i - 1][1] + v[i]);
                                        dp[i][0] = dp[i - 1][0];
                                        dp[i][3] = dp[i - 1][3];
                                }
                                else if (s[i] == 'r')
                                {
                                        dp[i][3] = min(dp[i - 1][3], dp[i - 1][2]);
                                        dp[i][2] = min(dp[i][2], dp[i - 1][2] + v[i]);
                                        dp[i][0] = dp[i - 1][0];
                                        dp[i][1] = dp[i - 1][1];
                                }
                                else if (s[i] == 'd')
                                {
                                        dp[i][3] = dp[i - 1][3] + v[i];
                                        dp[i][0] = dp[i - 1][0];
                                        dp[i][1] = dp[i - 1][1];
                                        dp[i][2] = dp[i - 1][2];
                                }
                        }
                }
        }

        // cout << "dp" << endl;
        // for (int i = 0; i < n; i++)
        // {
        //         for (int j = 0; j < 4; j++)
        //                 cout << dp[i][j] << " ";
        //         cout << endl;
        // }

        ll ans = 1e18;
        for (ll i = 0; i < 4; i++)
                ans = min(ans, dp[n - 1][i]);
        cout << ans << endl;
}

//................................

// ll

// ll

// int

// int
