// @author: ascyrax
//cnt[v[r]]!=0 correct
//cnt[v[r]]>0 error
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
ll n, k;
vector<ll> v;
//...............................

//...............................

void suraj()
{
        cin >> n >> k;
        v = vector<ll>(n);
        for (ll &i : v)
                cin >> i;
        ll l = 0, r = 0;
        map<ll, ll> cnt; //map containing the count of each element in the current subarray
        ll nGoodSubarrays = 0;
        ll nDistinct = 0;
        for (; r < n;)
        {
                // if v[r] is a new element for the current subarray
                //check if subarray l to r contain<=k distince elements
                //if true then nGoodSubarrays+=r-l+1 r++
                //if false then l++
                //else nGoodSubarrays+=r-l+1; r++;
                //
                if (cnt.count(v[r]) > 0 && cnt[v[r]] > 0)
                {
                        cnt[v[r]]++;
                        nGoodSubarrays += r - l + 1; //all the subarrays inside v[l,r] ending at r
                        r++;
                }
                else
                {
                        if (nDistinct < k)
                        {
                                cnt[v[r]]++;
                                nDistinct++;
                                nGoodSubarrays += r - l + 1;
                                r++;
                        }
                        else
                        {
                                cnt[v[l]]--;
                                if (cnt[v[l]] == 0)
                                        nDistinct--;
                                l++;
                        }
                }
        }
        cout << nGoodSubarrays << endl;
}