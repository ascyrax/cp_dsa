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
        // ioss
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
int n;
vector<ll> a, b;
ll maxProdSum = 1;
vector<ll> vProd, psvProd;
//...............................

//...............................

void suraj()
{
        cin >> n;
        for (int i = 0; i < n; i++)
        {
                int x;
                cin >> x;
                a.pb(x);
        }
        for (int i = 0; i < n; i++)
        {
                int x;
                cin >> x;
                b.pb(x);
                vProd.pb(a[i] * b[i]);
        }

        //for prefix sum
        psvProd = vector<ll>(n, 0);
        psvProd[0] = vProd[0];
        for (int i = 1; i < n; i++)
        {
                psvProd[i] = psvProd[i - 1] + vProd[i];
        }

        maxProdSum = psvProd[n - 1]; //this covers the case when the subarray length is 1
        //iterating over the midpoint of reversed subarray
        //and the length of the subarray
        for (int c = 0; c < n; c++)
        {
                ll cur = a[c] * b[c];
                for (int l = c - 1, r = c + 1; l >= 0 && r < n; l--, r++)
                { //covers all cases when subarray length is odd
                        cur += a[l] * b[r];
                        cur += a[r] * b[l];
                        if (l - 1 >= 0)
                                maxProdSum = max(maxProdSum, cur + (psvProd[l - 1]) + (psvProd[n - 1] - psvProd[r]));
                        else
                                maxProdSum = max(maxProdSum, cur + (0) + (psvProd[n - 1] - psvProd[r]));
                }
                cur = 0;
                for (int l = c, r = c + 1; l >= 0 && r < n; l--, r++)
                { //covers all cases when subarray length is even
                        cur += a[l] * b[r];
                        cur += a[r] * b[l];
                        if (l - 1 >= 0)
                                maxProdSum = max(maxProdSum, cur + (psvProd[l - 1]) + (psvProd[n - 1] - psvProd[r]));
                        else
                                maxProdSum = max(maxProdSum, cur + (0) + (psvProd[n - 1] - psvProd[r]));
                }
        }
        cout << maxProdSum << endl;
}

//................................
