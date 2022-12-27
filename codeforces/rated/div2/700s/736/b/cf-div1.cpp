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
        int n;
        cin >> n;
        vector<int> va, vb;
        vector<int> vfinal(n);
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < n; i++)
        {

                if (a[i] == '1')
                {
                        va.pb(i);
                        vfinal[i] = 1;
                }
                else
                {
                        vfinal[i] = 0;
                }

                if (b[i] == '1')
                        vb.pb(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
                if (b[i] == '1')
                {
                        if (i - 1 >= 0 && vfinal[i - 1] == 1)
                        {
                                ans++;
                                vfinal[i - 1] = -1;
                        }
                        else if (vfinal[i] == 0)
                        {
                                ans++;
                                vfinal[i] = -1;
                        }
                        else if (i + 1 < n && vfinal[i + 1] == 1)
                        {
                                ans++;
                                vfinal[i + 1] = -1;
                        }
                }
        }

        cout << ans << endl;
}

//................................
