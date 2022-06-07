#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss                     \
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

    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    vector<ll> vstudReq;
    for (ll i = 1; i < n; i++)
    {
        ll studReq = 0;
        ll diff = v[i] - v[i - 1];
        ll quo = diff / x;
        ll rem = diff % x;
        // cout << diff << " " << quo << " " << rem << endl;
        if (quo == 0)
        {
            //        cout<<"if"<<endl;
            //no worries
        }
        else if (quo == 1 && rem == 0)
        {
            //no worries
            //        cout<<"else if"<<endl;
        }
        else if (rem == 0)
        {
            studReq += quo - 1;
            vstudReq.pb(studReq);
        }
        else
        {
            studReq += quo;
            vstudReq.pb(studReq);
            //        cout<<"else"<<endl;
        }
        //    cout<<"vstudReq : ";
        //    for(ll i:vstudReq)cout<<i<<" ";cout<<endl;
    }
    sort(vstudReq.begin(), vstudReq.end());
    // for (ll i : vstudReq)
    // cout << i << " ";
    // cout << endl;

    for (ll i = 0; i < vstudReq.size() && k > 0; i++)
    {
        if (k >= vstudReq[i])
        {
            k -= vstudReq[i];
            vstudReq[i] = 0;
        }
        else
            k = 0;

        //    cout<<"K "<<k<<endl;
    }
    ll ngrps = 1;
    for (ll i : vstudReq)
    {
        //    cout<<"i "<<i;
        if (i > 0ll)
        { //cout<<"if"<<endl;
            ngrps++;
        }
    }
    cout << ngrps << endl;
}

//................................
