#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7ll;
// ll dp[(500ll * 501ll) / 4ll + 10ll][501ll];
// ll lmax = (500ll * 501ll) / 4ll + 1ll;
// ll rmax = 501ll;

//dp[i][j]= total no of ways of obtaining sum i from the first j elements of the array
//...............................

void suraj()
{
        ll n;
        cin >> n;
        // for (ll n = 1; n <= 100; n++)
        // {
        ll target = (n * (n + 1)) / 4;
        // cout << target << endl;
        // vector<vector<int>> dp(target + 1);
        // vector<int> temp(n + 1);
        // for (int k = 0; k <= target; k++)
        //         dp[k] = temp;
        vector<vector<ll>> dp(target + 1, vector<ll>(n + 1, 0));
        if (n % 4 == 1 || n % 4 == 2)
        {
                cout << 0 << endl;
                return;
                // continue;
        }
        else
        {
                for (int i = 1; i <= n; i++)
                {
                        dp[i][i] += 1ll;
                        dp[i][i] %= mod;
                        for (int j = 1; j <= target; j++)
                        {
                                // cout << i << " " << j << endl;
                                if (dp[j][i - 1] > 0)
                                {
                                        // cout << "if 1" << endl;
                                        dp[j][i] += dp[j][i - 1];
                                        dp[j][i] %= mod;
                                }
                                if (j + i < dp.size())
                                {
                                        // cout << "if 2 ->" << i + j << " " << dp.size() << endl;
                                        dp[j + i][i] += dp[j][i - 1];
                                        dp[j + i][i] %= mod;
                                }
                        }
                        // for (int i = 1; i <= n; i++)
                        // {
                        //         for (int j = 1; j <= n; j++)
                        //         {
                        //                 cout << dp[j][i] << " ";
                        //         }
                        //         cout << endl;
                        // }
                }
        }
        // cout << dp[14][6] << " " << dp[14][7] << endl;

        if (dp[target][n] / 2 == dp[target][n - 1])
        {
                cout << dp[target][n] / 2 << endl;
                // cout << "found " << n << endl;

                // if (n == 51 || n == 52 || true)
                // {
                //         cout << dp[(n * (n + 1)) / 4][n] << endl;
                //         cout << dp[(n * (n + 1)) / 4][n] / 2 << endl;
                //         cout << dp[(n * (n + 1)) / 4][n - 1] << endl;
                // }
                // continue;
        }
        else
        {
                cout << (dp[target][n] + mod) / 2 << endl;
        }
        // cout << "not found " << n << endl;
        // if (n == 51 || n == 52 || true)
        // {
        //         cout << dp[(n * (n + 1)) / 4][n] << endl;
        //         cout << dp[(n * (n + 1)) / 4][n] / 2 << endl;
        //         cout << dp[(n * (n + 1)) / 4][n - 1] << endl;
        // }
        // }
}

// ................................

//dp[target][n] = dp[target][n-1]*2 hota lekin %mod ke karan this will get disturbed and we can no longer be sure for this condition to hold
//hence we cannot get the ans by dp[target][n]/2 because dp[target][n] has been modified by %mod operations all along the way....
//hence we directly need to calculate the real ans = dp[target][n-1].

// or if dp[target][n]!=dp[target][n-1]*2
//cout << (dp[target][n] + mod) / 2 << endl;
//and if (dp[target][n] / 2 == dp[target][n - 1])
//cout << dp[target][n] / 2 << endl;

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//         int mod = 1e9 + 7;
//         int n;
//         cin >> n;
//         int target = n * (n + 1) / 2;
//         if (target % 2)
//         {
//                 cout << 0 << endl;
//                 return 0;
//         }
//         target /= 2;

//         vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
//         dp[0][0] = 1;
//         for (int i = 1; i <= n; i++)
//         {
//                 for (int j = 0; j <= target; j++)
//                 {
//                         dp[i][j] = dp[i - 1][j];
//                         int left = j - i;
//                         if (left >= 0)
//                         {
//                                 (dp[i][j] += dp[i - 1][left]) %= mod;
//                         }
//                 }
//         }
//         // cout << dp[n][target] / 2 << endl;
//         cout << dp[n - 1][target] << endl;
// }

//------------------------------------DOUBTS------------------------------------------
//SINCE dp[target][n] != 2*dp[target][n-1] because of the modification by %mod operations
//but this condition can hold for some values of n if dp[target][n] never exceeded the value of mod hence %mod will not change it
//so why are we getting this condition true for some values of n whose dp[target][n] ka value is greater
// than the value of mod;

//solution :---because (mod/2<dp[target][n-1]<mod) hence 2*dp[target][n-1] jo ki barabar hai dp[target][n] ke will be >mod.
//hence dp[target][n] will be reduced down to dp[target][n] % mod whereas dp[target][n - 1] is untouched
// hence dp[target][n] will no longer be 2*dp[target][n-1].
//note:- ye ho sakte hai ki dp[target][n+1](which is 2*dp[target][n]) will now be < mod(since dp[target][n] mod se larger hone ke karan reduce ho gaya tha)
// and therefore dp[target][n]*2=dp[target][n+1] will hold.
//what we saw here was that condition doesn't hold for n-1 and n....but holds for n and n=1; so we
// are never sure as kabhi hold kar bhi sakta hai kabhi nahi bhi
//hence it is better to find dp[target][n-1] for all n kyunki tab seedhe ans mil jayega aur hume divide by 2 karne ka tension hi nahi hai...bhale hi dp[target][n] %mod se modify hua ho ya nahi...hume usse koi lena dena hi nahi hai