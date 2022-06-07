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
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
        cin >> n;
        string s;
        cin >> s;
        vector<int> psg, psh;
        psg.pb(0);
        psh.pb(0);
        if (s[0] == 'G')
        {
                psg.pb(1);
                psh.pb(0);
        }
        else
        {
                psg.pb(0);
                psh.pb(1);
        }
        for (int i = 1; i < n; i++)
        {
                if (s[i] == 'G')
                {
                        psg.pb(psg.back() + 1);
                        psh.pb(psh.back() + 0);
                }
                else
                {
                        psg.pb(psg.back() + 0);
                        psh.pb(psh.back() + 1);
                }
        }
        ll cnt = 0;
        // for g as the single cow
        int l = 1, r = 3;
        int prevL = -1;
        while (1)
        {
                while (psg[r] - psg[l - 1] > 1 || (r - l >= 3))
                {
                        // cnt++;
                        l++;
                }
                if (psg[r] - psg[l - 1] == 1)
                        cnt += (l - prevL);
                prevL = l;
        }

        // for h as the single cow
}

//................................
