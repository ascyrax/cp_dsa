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
        cout << setprecision(15) << fixed << endl;
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
        int n;
        cin >> n;
        vector<ll> v(n);
        ll sum = 0ll;
        for (ll &i : v)
        {
                cin >> i;
                sum += i;
        }
        sort(v.begin(), v.end());
        double avg = double(sum - v[n - 1]) / double(n - 1);
        avg = avg + v[n - 1];
        cout.precision(7);
        cout << fixed << avg << endl;
}

//................................
