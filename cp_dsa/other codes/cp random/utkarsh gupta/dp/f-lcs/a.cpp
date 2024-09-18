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
string s, t;
int lens, lent;
int dp[3001][3001], parent[3001][3001];
//...............................

void suraj()
{
        cin >> s >> t;
        lens = s.size();
        lent = t.size();

        // dp[i][j] = first i chars from s and first j chars from t, what is the lcs that they lead to.
        // base cases
        // i=0
        // for (int j = 0; j < lent; j++)
        // {
        //         dp[0][j] = (s[0] == t[j]) ? 1 : 0;
        //         if (s[0] == t[j])
        //                 parent[0][j] = 3;
        //         else
        //                 parent[0][j] = 2;
        // }
        // // j=0
        // for (int i = 0; i < lens; i++)
        // {
        //         dp[i][0] = (s[i] == t[0]) ? 1 : 0;
        //         if (s[i] == t[0])
        //                 parent[i][0] = 3;
        //         else
        //                 parent[i][0] = 1;
        // }
        // i=0 and j=0
        if (s[0] == t[0])
        {
                parent[0][0] = 3;
                dp[0][0] = 1;
        }
        // else
        // {
        //         parent[0][0] = 1;
        //         dp[0][0] = 0;
        // }

        // cout << "parent" << endl;
        // for (int i = 0; i < lens; i++)
        // {
        //         for (int j = 0; j < lent; j++)
        //         {
        //                 cout << parent[i][j] << " ";
        //         }
        //         cout << endl;
        // }
        for (int i = 0; i < lens; i++)
        {
                for (int j = 0; j < lent; j++)
                {
                        if (i - 1 >= 0) //&& dp[i - 1][j] > dp[i][j])
                        {
                                parent[i][j] = 1;
                                dp[i][j] = dp[i - 1][j];
                        }
                        if (j - 1 >= 0 && dp[i][j - 1] > dp[i][j])
                        {
                                parent[i][j] = 2;
                                dp[i][j] = dp[i][j - 1];
                        }
                        if (s[i] == t[j])
                                if (i - 1 >= 0 && j - 1 >= 0)
                                {
                                        if (dp[i - 1][j - 1] + 1 > dp[i][j])
                                        {
                                                parent[i][j] = 3;
                                                dp[i][j] = dp[i - 1][j - 1] + 1;
                                        }
                                }
                                else
                                {
                                        dp[i][j] = 1;
                                        parent[i][j] = 3;
                                }
                }
        }

        // cout << "dp" << endl;
        // for (int i = 0; i < lens; i++)
        // {
        //         for (int j = 0; j < lent; j++)
        //         {
        //                 cout << dp[i][j] << " ";
        //         }
        //         cout << endl;
        // }

        // cout << "parent" << endl;
        // for (int i = 0; i < lens; i++)
        // {
        //         for (int j = 0; j < lent; j++)
        //         {
        //                 cout << parent[i][j] << " ";
        //         }
        //         cout << endl;
        // }

        // cout << "dp[0][0] = " << dp[0][0] << endl;
        // cout << dp[0][1] << endl;

        // cout << dp[lens - 1][lent - 1] << endl;

        vector<char> ans;
        int i = lens - 1, j = lent - 1;
        while (1)
        {
                // cout << "i = " << i << " , j = " << j << endl;
                // cout << "parent[i][j] = " << parent[i][j] << endl;
                if (parent[i][j] == 3)
                {
                        // cout << "if" << endl;
                        ans.pb(s[i]);
                        i--;
                        j--;
                }
                else if (parent[i][j] == 2)
                {
                        // cout << "else if" << endl;
                        j--;
                }
                else if (parent[i][j] == 1 || dp[i][j] == 0)
                {
                        // cout << "else" << endl;
                        i--;
                }
                if (i < 0 || j < 0)
                        break;
        }
        reverse(ans.begin(), ans.end());
        for (auto el : ans)
                cout << el;
        cout << endl;
}

//................................

// int

// int

// int

// int
