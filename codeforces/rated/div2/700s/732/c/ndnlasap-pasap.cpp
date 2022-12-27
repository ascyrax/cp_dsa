#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
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
// int diff[int(1e5) + 1];
int cnt[int(1e5) + 1][2];
//...............................

void suraj()
{
        // int n;
        // cin >> n;
        // vector<int> v(n);
        // for (int &i : v)
        //         cin >> i;
        // vector<int> vcopy = v;
        // sort(vcopy.begin(), vcopy.end());
        // for (int i = 0; i < n; i++)
        // {
        //         if ((i + 1) % 2 == 0)
        //         { //even
        //                 cnt[vcopy[i]][0]++;
        //         }
        //         else
        //         { //odd
        //                 cnt[vcopy[i]][1]++;
        //         }
        // }
        // for (int i = 0; i < n; i++)
        // {
        //         if ((i + 1) % 2 == 0) //even
        //         {
        //                 if (cnt[v[i]][0] > 0)
        //                 {
        //                         cnt[v[i]][0]--;
        //                 }
        //                 else
        //                 {
        //                         cout << "NO" << endl;
        //                         for (int e = 0; e < n; e++)
        //                         {
        //                                 cnt[v[e]][0] = 0;
        //                                 cnt[v[e]][1] = 0;
        //                         }
        //                         return;
        //                 }
        //         }
        //         else //odd
        //         {
        //                 if (cnt[v[i]][1] > 0)
        //                 {
        //                         cnt[v[i]][1]--;
        //                 }
        //                 else
        //                 {
        //                         cout << "NO" << endl;
        //                         for (int e = 0; e < n; e++)
        //                         {
        //                                 cnt[v[e]][0] = 0;
        //                                 cnt[v[e]][1] = 0;
        //                         }
        //                         return;
        //                 }
        //         }
        // }
        // cout << "YES" << endl;
        // for (int e = 0; e < n; e++)
        // {
        //         cnt[v[e]][0] = 0;
        //         cnt[v[e]][1] = 0;
        // }
        // cout << "--------------------------------" << endl;
        // implementation 2---Gassa
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        vector<int> e, o;
        for (int i = 0; i < n; i++)
        {
                if ((i + 1) % 2 == 0)
                {
                        //even
                        e.pb(v[i]);
                }
                else
                {
                        //odd
                        o.pb(v[i]);
                }
        }
        sort(e.begin(), e.end());
        sort(o.begin(), o.end());
        vector<int> final, vcopy;
        vcopy = v;
        // for (int i : vcopy)
        //         cout << i << " ";
        // cout << endl;
        sort(vcopy.begin(), vcopy.end());

        for (int i = 0;; i++)
        {
                // cout << "i " << i << " " << e.size() << endl;
                if (i >= e.size() && i >= o.size())
                        break;
                else
                {
                        if (i < o.size())
                                final.pb(o[i]);
                        if (i < e.size())
                                final.pb(e[i]);
                }
        }
        // for (int i : o)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : e)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : vcopy)
        //         cout << i << " ";
        // cout << endl;
        // for (int i : final)
        //         cout << i << " ";
        // cout << endl;
        if (final == vcopy)
        {
                cout << "YES" << endl;
        }
        else
        {
                cout << "NO" << endl;
        }
}
//
//................................
