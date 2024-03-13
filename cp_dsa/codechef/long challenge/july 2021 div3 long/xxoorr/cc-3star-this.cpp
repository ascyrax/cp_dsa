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
        for (int i = 1; i <= t; i++) //{cout<<"Case #"<<i<<": ";
                suraj();
        //}
        return 0;
}

// @author: ascyrax

const int mod = 1e9 + 7;

//...............................

void suraj()
{
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        sort(v.begin(), v.end());
        int largest = v[n - 1];
        // cout << "largest " << largest << endl;
        int sizecnt = 0;
        for (int i = 0; i <= 31; i++)
        {
                if (pow(2, i) > largest)
                        break;
                if (largest & int(pow(2, i)))
                        sizecnt = i;
        }
        // cout << "sizecnt " << sizecnt << endl;
        vector<int> cnt(sizecnt + 1);
        // for (int i : cnt)
        //         cout << i << " ";
        // cout << endl;
        for (int i = 0; i <= sizecnt; i++)
        {
                for (int j : v)
                {
                        if (j & int(pow(2, i)))
                        {
                                cnt[i]++;
                        }
                }
        }
        // for (int i : cnt)
        //         cout << i << " ";
        // cout << endl;

        int ans = 0;
        for (int i : cnt)
        {
                ans += (i / k + ((i % k) ? 1 : 0));
        }

        cout << ans << endl;
}

//................................
