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
        ll n, k, x;
        cin >> n >> k >> x;
        string s;
        cin >> s;

        vector<int> v;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
                if (s[n - 1 - i] == '*')
                {
                        cnt++;
                }
                else
                {
                        cout << "cnt = " << cnt << endl;
                        if (v.size() == 0)
                                v.pb(cnt * k);
                        else
                        {
                                v.pb(v.back() * (cnt * k + 1));
                        }
                        cnt = 0;
                }
        }
        if (s[0] == '*')
        {
                if (v.size() == 0)
                        v.pb(cnt * k);
                else
                {
                        v.pb(v.back() * (cnt * k + 1));
                }
        }

        for (int &i : v)
                i++;
        // v ={9,63}
        for (int i : v)
                cout << i << " ";
        cout << endl;
        while (x > 0)
        {
                auto loc = lower_bound(v.begin(), v.end(), x);
                int loc_int = loc - v.begin();
                //
                // x = x - (loc_int + 1);

                // For each testcase x doesn't exceed the total number of different BA-strings
                // => loc for the scanned x will never be equal to v.end()
                int quo;
                if (loc == v.begin() && x == 0)
                {
                        int flag = 0;
                        for (int i = (int)s.size() - 1; i >= 0; i--) // loop to find the target series of * where bs will be added.
                        {
                                if (s[i] == '*')
                                {
                                        flag = 1;
                                        if (loc_int == 0)
                                        {
                                                string left = s.substr(0, i);
                                                string right = s.substr(i);
                                                string mid = "";
                                                for (int temp = 0; temp < *(loc))
                                                        s = left + mid + right; // * are still inside
                                                // s. in the end remove all * from s.
                                                break;
                                        }
                                }
                                else
                                {
                                        if (flag == 1)
                                        {
                                                loc_int--;
                                                flag = 0;
                                        }
                                }
                        }
                }
                else if (loc == v.begin())
                {
                        quo = x;
                        x = 0;
                }
                else
                {
                        quo = x / (*(loc - 1));
                        x = x % (*(loc - 1));
                        // if (x == 0)
                        // {
                        //         quo--;
                        //         x = *(loc - 1);
                        // }
                        // else
                        // {
                        //         quo = quo;
                        //         x--;
                        // }
                }

                int flag = 0;
                for (int i = (int)s.size() - 1; i >= 0; i--) // loop to find the target series of * where bs will be added.
                {
                        if (s[i] == '*')
                        {
                                flag = 1;
                                if (loc_int == 0)
                                {
                                        string left = s.substr(0, i);
                                        string right = s.substr(i);
                                        string mid = "";
                                        if (x == 0)
                                                for (int temp = 0; temp < quo - 1; temp++)
                                                        mid += "b";
                                        else
                                                for (int temp = 0; temp < quo; temp++)
                                                        mid += "b";
                                        s = left + mid + right; // * are still inside
                                        // s. in the end remove all * from s.
                                        break;
                                }
                        }
                        else
                        {
                                if (flag == 1)
                                {
                                        loc_int--;
                                        flag = 0;
                                }
                        }
                }
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
                if (s[i] != '*')
                {
                        ans += s.substr(i, 1);
                }
        }
        cout << ans << endl;
}

//................................
