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
ll n, k;
vector<ll> v;
ll nGoodSub = 0;
ll l = 0, r = 0;
stack<ll> s1, s1Min, s1Max, s2, s2Min, s2Max;
ll elMin = 1e18, elMax = 0;

//...............................

void add(ll a)
{
        s2.push(a);
        if (s2Min.size() > 0)
                s2Min.push(min(s2Min.top(), a));
        else
                s2Min.push(a);
        if (s2Max.size() > 0)
                s2Max.push(max(s2Max.top(), a));
        else
                s2Max.push(a);
}
bool good()
{
        if (s1.size() > 0 && s2.size() > 0)
        {
                return max(s1Max.top(), s2Max.top()) - min(s1Min.top(), s2Min.top()) <= k;
        }
        else if (s1.size() > 0)
        {
                return s1Max.top() - s1Min.top() <= k;
        }
        else if (s2.size() > 0)
        {
                return s2Max.top() - s2Min.top() <= k;
        }
}

void remove()
{
        if (s1.empty())
        {
                while (!s2.empty())
                {
                        ll t1 = s2.top();
                        ll tMax = t1;
                        ll tMin = t1;
                        s2.pop();
                        s2Max.pop();
                        s2Min.pop();
                        if (s1Max.size() > 0)
                                tMax = max(s1Max.top(), t1);
                        else
                                tMax = t1;
                        if (s1Min.size() > 0)
                                tMin = min(s1Min.top(), t1);
                        else
                                tMin = t1;
                        s1.push(t1);
                        s1Max.push(tMax);
                        s1Min.push(tMin);
                }
        }
        s1.pop();
        s1Min.pop();
        s1Max.pop();
}
//...............................

void suraj()
{
        cin >> n >> k;
        v = vector<ll>(n);
        for (ll &i : v)
                cin >> i;

        for (r = 0; r < n; r++)
        {
                add(v[r]);
                while (!good())
                {
                        remove();
                        l++;
                }
                nGoodSub += r - l + 1;
                // cout << "l = " << l << " r = " << r << endl;
                // cout << s1.size() << " " << s2.size() << endl;
                // cout << elMin << " " << elMax << endl;
                // cout << "nGoodSub = " << nGoodSub << endl;
        }
        cout << nGoodSub << endl;
}

//................................
