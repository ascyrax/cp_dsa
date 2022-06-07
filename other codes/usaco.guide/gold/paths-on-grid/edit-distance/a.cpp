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
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;
int dp[5001][5001];
//...............................
int find(string a, string b)
{
        int lena = a.size();
        int lenb = b.size();
        for (int i = 1; i <= lena; i++)
        {
                for (int j = 1; j <= lenb; j++)
                {
                        if (a[i - 1] == b[j - 1])
                        {
                                dp[i][j] = 1 + dp[i - 1][j - 1];
                        }
                        else
                        {
                                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                        }
                }
        }
        return dp[lena][lenb];
}
void suraj()
{
        string a, b;
        cin >> a >> b;
        int lena = a.size();
        int lenb = b.size();
        int lcs = find(a, b);
        cout << lcs << endl;
        cout << max(lena, lenb) - lcs << endl;
}

//................................
