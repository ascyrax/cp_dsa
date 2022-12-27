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
        stack<char> st;
        vector<char> open = {'[', '{', '(', '<'};
        vector<char> close = {']', '}', ')', '>'};
        map<char, int> m;
        for (int i = 0; i < 4; i++)
        {
                m[open[i]] = i + 1;
                m[close[i]] = i + 1;
        }
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++)
        {
                for (char c : open)
                        if (s[i] == c)
                                l++;
                for (char c : close)
                        if (s[i] == c)
                                r++;
        }
        if (l != r)
        {
                cout << "Impossible" << endl;
                return;
        }
        else
        {
                int ans = 0;
                for (char c : s)
                {
                        for (char op : open)
                                if (c == op)
                                {
                                        st.push(c);
                                }
                        for (char cl : close)
                                if (c == cl)
                                {
                                        if (st.empty())
                                        {
                                                cout << "Impossible" << endl;
                                                return;
                                        }
                                        char top = st.top();
                                        st.pop();
                                        if (m[cl] != m[top])
                                        {
                                                // cout << "c = " << c << endl;
                                                // cout << "top = " << top << endl;
                                                ans++;
                                        }
                                }
                }
                cout << ans << endl;
        }
}

//................................
