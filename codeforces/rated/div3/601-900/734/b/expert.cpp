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
        string s;
        cin >> s;
        int lens = int(s.size());
        vector<pair<char, int>> vp(lens);
        for (int i = 0; i < lens; i++)
        {
                vp[i] = make_pair(s[i], i);
        }

        sort(vp.begin(), vp.end());
        // for (auto el : vp)
        //         cout << el.first << " ";
        // cout << endl;
        // for (auto el : vp)
        //         cout << el.second << " ";
        // cout << endl;
        int current = 1; //1 for red , 2 for green
        int started = 1;
        vector<int> vColor(lens);
        vColor[vp[0].second] = current++;
        // cout << "hi " << vColor[vp[0].second] << " " << current << endl;
        for (int i = 1; i < lens; i++)
        {
                // cout << vp[i].first << " " << current << endl;
                if (vp[i].first == vp[i - 1].first)
                {
                        if (current != started)
                        {
                                vColor[vp[i].second] = current++;
                        }
                        else
                        {
                                vColor[vp[i].second] = 0;
                        }
                }
                else
                {
                        started = current;
                        vColor[vp[i].second] = current++;
                }
                if (current > 2)
                        current %= 2; //since no of colors is 2 here
        }
        if (current == 1)
        {
                //both colors are same in no
                //do nothing
        }
        else
        {
                //color 1 is more than color 2 by 1 occurence
                for (int &i : vColor)
                {
                        if (i == 1)
                        {
                                i = 0;
                                break;
                        }
                }
        }
        int ans = 0;
        for (int i : vColor)
        {
                // cout << i << " ";
                if (i == 1)
                        ans++;
        }
        cout << ans << endl;
}

//................................
