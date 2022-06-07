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
        int n, t;
        cin >> n >> t;
        // cout << "hello they are billion" << endl;
        int k;
        cin >> k;
        int l = 1, r = n;
        int m = l + (r - l) / 2;
        while (k > 0 && l != r)
        {
                m = l + (r - l) / 2;
                int diff = m - l;
                cout << "? " << l << " " << m << endl;
                cout << flush;
                int sum;
                cin >> sum;
                if (sum == diff + 1)
                {
                        l = m + 1;
                }
                else if (sum < diff + 1)
                {
                        int nzeros = (diff + 1) - sum;
                        if (nzeros < k)
                        {
                                k -= nzeros;
                                l = m + 1;
                        }
                        else if (nzeros >= k)
                        {
                                r = m;
                        }
                }
        }
        cout << "! " << l << endl;
}

//................................
