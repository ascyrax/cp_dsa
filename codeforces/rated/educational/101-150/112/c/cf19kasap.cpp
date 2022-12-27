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
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................
int m;
vector<int> va, vb, psTop, psBottom;
//...............................

//...............................

void suraj()
{
        cin >> m;

        va = vector<int>(m, 0);
        vb = vector<int>(m, 0);
        psTop = vector<int>(m, 0);    //psTop[i]=ps till the ith element (from rhs)
        psBottom = vector<int>(m, 0); //psBottom[i]=ps till the ith element (from lhs)

        int ans = 2e9;

        //input
        for (int &i : va)
                cin >>
                    i;
        for (int &i : vb)
                cin >> i;

        //psBottom
        psBottom[0] = vb[0];
        for (int i = 1; i < m; i++)
        {
                psBottom[i] = psBottom[i - 1] + vb[i];
        }

        //psTop
        psTop[m - 1] = va[m - 1];
        for (int i = m - 2; i >= 0; i--)
        {
                psTop[i] = psTop[i + 1] + va[i];
        }

        for (int i = 0; i < m; i++)
        {
                //alice moved down in the ith column;
                int sumTop = 0;
                if (i + 1 < m)
                        sumTop = psTop[i + 1];
                else
                        sumTop = 0;
                int sumBottom = 0;
                if (i - 1 >= 0)
                        sumBottom = psBottom[i - 1];
                else
                        sumBottom = 0;
                // cout << sumTop << " " << sumBottom << endl;
                ans = min(ans, max(sumTop, sumBottom));
        }
        cout << ans << endl;
}

//................................
