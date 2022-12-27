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
        // ioss
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
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        int odds = 0;
        map<char, int> cnt, fcnt;
        for (int i = 0; i < s.size(); i++)
        {
                cnt[s[i]]++;
        }
        /////
        // for (auto el : cnt)
        //         cout << el.first << " " << el.second << endl;
        /////
        vector<char> v;
        for (auto el : cnt)
        {
                if (el.second % 2 == 1)
                {
                        if (el.second - 1 > 0)
                                fcnt[el.first] = el.second - 1;
                        v.pb(el.first);
                }
                else
                        fcnt[el.first] = el.second;
        }

        sort(v.begin(), v.end());
        int l = 0, r = v.size() - 1;

        while (l < r)
        {
                v[r--] = v[l++];
        }

        for (char c : v)
                fcnt[c]++;

        string ansLeft = "";
        char temp = '$';
        for (auto el : fcnt)
        {
                if (el.second % 2 == 1)
                        temp = el.first;
                for (int i = 0; i < el.second / 2; i++)
                {
                        ansLeft += el.first;
                }
        }
        sort(ansLeft.begin(), ansLeft.end());
        string ansRight = ""; // reverse of ansLeft
        for (char c : ansLeft)
                ansRight = c + ansRight;
        string ans;
        if (temp != '$')
                ans = ansLeft + temp + ansRight;
        else
                ans = ansLeft + ansRight;
        cout << ans << endl;
}

//................................
