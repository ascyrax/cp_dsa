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
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................

void suraj()
{

        ll n, q;
        cin >> n >> q;
        string song;
        cin >> song;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
                v[int(i)] = song[int(i)] - 'a' + 1;
        }
        vector<ll> ps(n + 1);
        for (int i = 1; i <= n; i++)
        {
                ps[i] = ps[i - 1] + v[i - 1];
        }
        //    cout<<0<<" ";
        //    for(int i:v)cout<<i<<" ";cout<<endl;
        //    for(int i:ps)cout<<i<<" ";cout<<endl;
        for (int i = 0; i < q; i++)
        {
                int a, b;
                cin >> a >> b;
                cout << ps[b] - ps[a - 1] << endl;
        }
}

//................................
