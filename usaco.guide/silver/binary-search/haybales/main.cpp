#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define endl "\n"
#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()

double startTime;
double gct() //get_current_time
{
    return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(begin(v), end(v));
    for (int i : v)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < Q; ++i)
    {
        int A, B;
        cin >> A >> B;
        cout << upper_bound(begin(v), end(v), B) - lower_bound(begin(v), end(v), A) << "\n";
    }
}

//

int main()
{
    startTime = (double)clock();
    // freopen("haybales.in","r",stdin);
    //freopen("haybales.out","w",stdout);
    ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}
