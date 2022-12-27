#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define size(x) (int)(x).size()
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
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        int ans = a * n;
        int cnt = 0;

        if (n == 1)
        {
                ans += b;
                cout << ans << endl;
                return;
        }
        if (b > 0)
        { //maximize the no of operations = n
                // for (int i = 0; i <= n - 2; i++)
                // {
                //         if (s[i] != s[i + 1])
                //                 cnt++;
                // }
                // if (s[n - 2] != s[n - 1])
                //         cnt++;
                cnt = n;
        }
        else if (b < 0)
        {
                //all 0s together
                int cnt1 = 0;
                int lastEl = 3;
                for (int i = 0; i < n; i++)
                {
                        if (s[i] == '1')
                        {
                                if (lastEl != 1)
                                        cnt1++;
                                lastEl = 1;
                        }
                        else
                        {
                                lastEl = 0;
                        }
                }
                //all 1s together
                int cnt0 = 0;
                lastEl = 3;
                for (int i = 0; i < n; i++)
                {
                        if (s[i] == '0')
                        {
                                if (lastEl != 0)
                                        cnt0++;
                                lastEl = 0;
                        }
                        else
                        {
                                lastEl = 1;
                        }
                }
                // cout << cnt0 << " " << cnt1 << endl;
                cnt = min(cnt0, cnt1) + 1;
                // cout << "else if :- cnt = " << cnt << endl;
        }
        else
        {
                cnt = 0; //since b is already 0
        }
        ans += cnt * b;
        cout << ans << endl;
}

//................................
