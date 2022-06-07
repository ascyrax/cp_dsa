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
        // ioss
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v;
        int cnt2 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
                if (s[i] == '2')
                {
                        v.pb(i);
                        cnt2++;
                }
                else
                        cnt1++;
        }
        if (cnt2 == 1 || cnt2 == 2)
        {
                cout << "NO" << endl;
                return;
        }
        // if (n == 2 && s == "22")
        // {
        //         cout << "NO" << endl;
        //         return;
        // }
        vector<vector<char>> matrix(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        matrix[i][j] = '=';
                }
        }

        for (int i = 0; i < n; i++)
        {

                if (s[i] == '1')
                {
                        for (int j = 0; j < n; j++)
                                matrix[i][j] = '=';
                }
                else if (s[i] == '2')
                {
                        // for (int j = 0; j < n; j++)
                        //         matrix[i][j] = '=';

                        auto itr = lower_bound(v.begin(), v.end(), i) - v.begin();
                        // cout << "i= " << i << " itr= " << itr << endl;
                        auto itrCopy = itr;
                        if (itr == (int)v.size() - 1)
                        {
                                itr = v[0];
                        }
                        else
                        {
                                itr = v[itr + 1];
                        }
                        //i wins agains the next 2-type
                        matrix[i][itr] = '+';
                        //i loose against the prev 2-type
                        if (itrCopy == 0)
                        {
                                itrCopy = v[(int)v.size() - 1];
                        }
                        else
                        {
                                itrCopy = v[itrCopy - 1];
                        }
                        matrix[i][itrCopy] = '-';
                }
        }
        // cout << "here" << endl;
        for (int i = 0; i < n; i++)
                matrix[i][i] = 'X';
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        cout << matrix[i][j];
                }
                cout << endl;
        }
}

//................................
