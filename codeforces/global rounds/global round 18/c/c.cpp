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
        ioss
            startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n;
        string a, b;
        cin >> n >> a >> b;
        if (a == b)
        {
                cout << 0 << endl;
                return;
        }
        else
        {
                int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
                for (char c : a)
                        if (c == '0')
                                a0++;
                        else
                                a1++;
                for (char c : b)
                        if (c == '0')
                                b0++;
                        else
                                b1++;
                if (a0 == n)
                {
                        cout << -1 << endl;
                        return;
                }
                vector<bool> diff(n);
                int ndiff = 0;
                for (int i = 0; i < n; i++)
                {
                        if (a[i] != b[i])
                        {
                                diff[i] = true;
                                ndiff++;
                        }
                }
                if(ndiff==1){
                        
                }
                int diff0 = 0, diff1 = 0;
                for (int i = 0; i < n; i++)
                {
                        if (diff[i] == true)
                        {
                                if (a[i] == '0')
                                        diff0++;
                                else
                                        diff1++;
                        }
                }
                if (diff0 == diff1)
                {
                        cout << diff0 + diff1 << endl;
                }
                else
                {
                        cout << -1 << endl;
                        return;
                }
        }
}

//................................
