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
        ioss int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

// @author: ascyrax

const ll mod = 1e9 + 7;

//...............................

void suraj()
{
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m, vector<int>(26));
        for (int i = 0; i <= 2 * n - 2; i++)
        {
                string s;
                cin >> s;
                for (int j = 0; j < m; j++)
                {
                        char ch = s[j];
                        v[j][ch - 'a']++;
                }
        }
        vector<char> ans(m);
        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < 26; j++)
                {
                        if (v[i][j] % 2 == 1)
                                ans[i] = 'a' + j;
                }
        }
        for (char ch : ans)
                cout << ch;
        cout << endl;
}

//................................
