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
ll n;
vector<ll> v;
stack<ll> s1, s1gcd, s2, s2gcd;
ll l = 0, r = 0;
ll nGoodSubarrays = 0;
//...............................
void add(ll vr)
{
        s2.push(vr);
        s2gcd.push(__gcd(s2gcd.top(), vr));
}
void remove()
{
        if (s1.empty())
        {
                while (!s2.empty())
                {
                        ll top2 = s2.top();
                        ll top2gcd = s2gcd.top();
                        s2.pop();
                        s2gcd.pop();
                        s1.push(top2);
                        if (s1gcd.size() > 0)
                                s1gcd.push(__gcd(s1gcd.top(), top2));
                        else
                                s1gcd.push(top2);
                }
        }
        s1.pop();
        s1gcd.pop();
}

bool good()
{
        if (s1gcd.size() > 0 && s2gcd.size() > 0)
                return __gcd(s1gcd.top(), s2gcd.top()) == 1;
        else if (s1gcd.size() > 0)
                return s1gcd.top() == 1;
        else if (s2gcd.size() > 0)
                return s2gcd.top() == 1;
}
//...............................

void suraj()
{
        cin >> n;
        v = vector<ll>(n);
        for (ll &i : v)
                cin >> i;
        for (r = 0; r < n; r++)
        {
                add(v[r]);
                if (good())
                {
                        nGoodSubarrays += r - l + 1;
                }
                else
                {
                        while (l < r && !good())
                        {
                                remove();
                                l++;
                        }
                        nGoodSubarrays += r - l + 1;
                }
        }
        cout << nGoodSubarrays << endl;
}

//................................
