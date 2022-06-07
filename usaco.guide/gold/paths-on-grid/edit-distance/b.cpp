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
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        string a, b;
        cin >> a >> b;
        int lena = a.size();
        int lenb = b.size();
        vector<vector<int>> dp(lena + 1, vector<int>(lenb + 1, max(lena, lenb)));
        //dp[i][j]=lcs if first i char of string a and the first j char of string b is considered
        // for (int i = 0; i <= lena; i++)
        // {
        //         for (int j = 0; j <= lenb; j++)
        //         {
        //                 if (i == 0 || j == 0)
        //                         dp[i][j] = 0;
        //         }
        // }
        dp[0][0] = 0;
        for (int i = 0; i <= lena; i++)
        {
                for (int j = 0; j <= lenb; j++)
                {
                        // if both ith char of string a and jth car of string b are same
                        if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1] == b[j - 1])
                                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                        else
                        { //add
                                if (i < j)
                                {
                                        if (j - 1 >= 0)
                                        {
                                                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // if one char was added to string a
                                                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // if one char was removed from string b
                                        }
                                }
                                else if (j < i)
                                {
                                        if (i - 1 >= 0)
                                        {
                                                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // if one char was added to string b
                                                //delete
                                                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // if one char was removed from string a
                                        }
                                }
                                // replace
                                else if (i == j && i - 1 >= 0 && j - 1 >= 0)
                                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                        }
                        // if (i)
                        // {
                        //         dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                        // }
                        // if (j)
                        // {
                        //         dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                        // }
                        // if (i && j)
                        // {
                        //         dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
                        // }
                }
        }
        for (int i = 0; i <= lena; i++)
        {
                for (int j = 0; j <= lenb; j++)
                {
                        cout << dp[i][j] << " ";
                }
                cout << endl;
        }
        cout << dp[lena][lenb] << endl;
}

//................................
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//         string a, b;
//         cin >> a >> b;
//         int na = a.size(), nb = b.size();
//         vector<vector<int>> dp(na + 1, vector<int>(nb + 1, 1e9));
//         dp[0][0] = 0;
//         for (int i = 0; i <= na; i++)
//         {
//                 for (int j = 0; j <= nb; j++)
//                 {
//                         if (i)
//                         {
//                                 dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
//                         }
//                         if (j)
//                         {
//                                 dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
//                         }
//                         if (i && j)
//                         {
//                                 dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
//                         }
//                 }
//         }
//         for (int i = 0; i <= na; i++)
//         {
//                 for (int j = 0; j <= nb; j++)
//                 {
//                         cout << dp[i][j] << " ";
//                 }
//                 cout << endl;
//         }
//         cout << dp[na][nb] << endl;
// }