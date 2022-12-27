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
        ioss
            startTime = (double)clock();
        //freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        //cout << setprecision(15) << fixed << endl;
        //int t;cin>>t;for(int i=1;i<=t;i++)
        {
                //cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
//const int INF = 2147483647;
//const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        int l = 0, r = 0;
        int cnt0 = 0;
        int lenMax = 0;
        pair<int, int> ans = {-1, -1};
        for (r = 0; r < n; r++)
        {
                if (v[r] == 0)
                        cnt0++;
                while (cnt0 > k)
                {
                        if (v[l] == 0)
                                cnt0--;
                        l++;
                }
                if (r - l + 1 > lenMax)
                        ans = make_pair(l, r);
                lenMax = max(lenMax, r - l + 1);
        }
        cout << lenMax << endl;
        for (int i = 0; i < n; i++)
        {
                if (i >= ans.first && i <= ans.second)
                        cout << 1 << " ";
                else
                        cout << v[i] << " ";
        }
        cout << endl;
}

//................................
