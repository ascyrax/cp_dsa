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
        int n;
        cin >> n;
        vector<int> v(2 * n);
        int neven = 0, nodd = 0;
        for (int i = 0; i < 2 * n; i++)
        {
                cin >> v[i];
                if (v[i] % 2 == 0)
                        neven++;
                else
                        nodd++;
        }
        // cout << nodd << " " << neven << endl;
        if (nodd == neven)
                cout << "YES" << endl;
        else
                cout << "NO" << endl;
}

//................................
