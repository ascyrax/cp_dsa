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

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//...............................

//...............................

//...............................

void suraj()
{
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        ll ans = n * a;
        //if all 0 or all1
        for (int i = 0; i < n; i++)
        {
                if (s[i] == '0')
                        cnt0++;
                else
                        cnt1++;
        }

        //b will be added to ans x times where x is the no of operations done
        if (b > 0)
        {
                //maximise the no of operations
                ans += n * b;
        }
        else
        {
                //remove all zeroes first
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                        if (i == 0)
                        {
                                if (s[i] == '0')
                                        cnt++;
                        }
                        else if (s[i] == '0' && s[i - 1] != '0')
                        {
                                cnt++;
                        }
                }
                ans += cnt * b;
                //and then remove all ones in the end
                //if all zeros or all ones only then dont do this step
                if (cnt0 == n || cnt1 == n)
                        ans = ans;
                else
                        ans += b;
        }
        cout << ans << endl;
}

//................................
