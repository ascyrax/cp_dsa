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
        cin >> n;
        string s;
        cin >> s;

        int subseqNo = 1;
        vector<int> one, zero;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
                if (s[i] == '0')
                {
                        // check if any subseq ending with 1 is present or not
                        // yes then change it to a subseq ending with 0
                        if (one.size() > 0)
                        {
                                zero.pb(one.back());
                                one.erase(one.end() - 1);
                                ans[i] = zero.back();
                        }
                        // else create a new subseq ending with 0
                        else
                        {
                                zero.pb(subseqNo);
                                ans[i] = subseqNo;
                                subseqNo++;
                        }
                }
                else
                {
                        if (zero.size() > 0)
                        {
                                one.pb(zero.back());
                                zero.erase(zero.end() - 1);
                                ans[i] = one.back();
                        }
                        else
                        {
                                one.pb(subseqNo);
                                ans[i] = subseqNo;
                                subseqNo++;
                        }
                }
                // cout << "zero" << endl;
                // for (int i : zero)
                //         cout << i << " ";
                // cout << endl;
                // cout << "one" << endl;
                // for (int i : one)
                //         cout << i << " ";
                // cout << endl;
        }
        cout << subseqNo - 1 << endl;
        for (int i : ans)
                cout << i << " ";
        cout << endl;
}

//................................
