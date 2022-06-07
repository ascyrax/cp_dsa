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
        startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        ioss
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

// @author: ascyrax

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................

//...............................

//...............................

void suraj()
{
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> binS;
        for (int i = 0; i < n; i++)
        {
                if (s[i] == '+')
                {
                        binS.pb(1);
                }
                else
                        binS.pb(-1);
        }

        vector<int> ps(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
                ps[i] = ps[i - 1] + binS[i - 1];
        }
        for (int i : ps)
                cout << i << " ";
        cout << endl;
        for (int i = 0; i < q; i++)
        {
                int l, r;
                cin >> l >> r;
                cout << l << " " << r << endl;
                cout << ps[r] << " " << ps[l] << " " << ps[l - 1] << endl;
                int sum = ps[r] - ps[l - 1];
                cout << abs(sum) << endl;
        }
}

//................................
