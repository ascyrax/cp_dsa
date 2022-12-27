// @author: ascyrax

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

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
int n, k;
vector<int> v;
vector<int> cnt(1e6 + 1, 0);
int nDistinct = 0;
int l = 0, r = 0;
pair<int, int> lr;
int ans = 0;
//...............................

//...............................

void suraj()
{
    cin >> n >> k;
    v = vector<int>(n);
    for (int &i : v)
        cin >> i;

    for (r = 0; r < n; r++)
    {
        if (cnt[v[r]] == 0)
            nDistinct++;
        cnt[v[r]]++;
        while (nDistinct > k)
        {
            cnt[v[l]]--;
            if (cnt[v[l]] == 0)
                nDistinct--;
            l++;
            if (l == r)
                break;
        }
        // cout << "l = " << l << " r = " << r << endl;
        if (nDistinct <= k && r - l + 1 > ans)
        {
            ans = r - l + 1;
            lr = make_pair(l, r);
        }
    }
    cout << lr.first + 1 << " " << lr.second + 1 << endl;
}

//................................
