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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}
int n;
int ans = 0;
// vector<pair<int, int>> perm;
// vector<vector<pair<int, int>>> perms;
vector<string> board;
vector<bool> col, row;
vector<bool> diag1, diag2;
//...............................
// n*n grid & n queense
void backtrack(int i) // placing queen in the ith row
{
        if (ans > 0 && ans % 10000 == 0)
        {
                cout << "ans = " << ans << endl;
        }
        // i acts as the row index for the chessboard
        if (i == n)
        {
                ans++;
                // perms.pb(perm);
        }
        else
        {
                for (int j = 0; j < n; j++)
                {
                        if (board[i][j] == '*' || col[j] || diag1[i + j] || diag2[i - j + n - 1])
                                continue;

                        // perm.pb(make_pair(i, j));
                        row[i] = col[j] = diag1[i + j] = diag2[i - j + n - 1] = true;

                        backtrack(i + 1);

                        row[i] = col[j] = diag1[i + j] = diag2[i - j + n - 1] = false;
                        // perm.pop_back();
                }
        }
        return;
}
//...............................

void suraj()
{
        // cin >> n;
        for (int i = 0; i < 8; i++)
        {
                string a;
                cin >> a;
                board.pb(a);
        }
        for (n = 8; n <= 8; n++)
        {
                ans = 0;
                // cout << "n = " << n << endl;
                col = vector<bool>(n, false);
                row = vector<bool>(n, false);
                diag1 = vector<bool>(n + (n - 1), false);
                diag2 = vector<bool>(n + (n - 1), false);

                // cout << gct() << endl;

                backtrack(0);

                cout << ans << endl;

                // cout << perms.size() << endl;
                // cout << gct() << endl;
        }
        // for (auto el : perms)
        // {
        //         cout << "perm" << endl;
        //         for (auto i : el)
        //                 cout << i.first << " " << i.second << ", ";
        //         cout << endl;
        // }
}

//................................
// int
// int
// int
// int
