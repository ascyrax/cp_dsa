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

const ll mod = 1e9 + 7;
const int inf = 2147483647;
const int ninf = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide
int n, m;
vector<int> va, vb;

//...............................

//...............................

void suraj()
{
        ll ans = 0;
        // cout << "ans = " << ans << endl;
        cin >> n >> m;
        va = vector<int>(n);
        vb = vector<int>(m);
        for (int &i : va)
                cin >> i;
        for (int &i : vb)
                cin >> i;
        // cout << "a" << endl;
        int pa = 0, pb = 0;
        while (pa < n && pb < m)
        {
                // cout << pa << " " << pb << endl;
                // if (pa >= n || pb >= m)
                //         break;
                if (va[pa] == vb[pb])
                {
                        int cnta = 1, cntb = 1;
                        while (pa < n)
                        {
                                if (pa + 1 >= n)
                                {
                                        pa++;
                                        break;
                                }
                                else if (va[pa + 1] == va[pa])
                                {
                                        pa++;
                                        cnta++;
                                }
                                else
                                {
                                        pa++;
                                        break;
                                }
                        }
                        while (pb < m)
                        {
                                if (pb + 1 >= m)
                                {
                                        pb++;
                                        break;
                                }
                                else if (vb[pb + 1] == vb[pb])
                                {
                                        pb++;
                                        cntb++;
                                }
                                else
                                {
                                        pb++;
                                        break;
                                }
                        }

                        ans += ((ll)cnta * (ll)cntb);
                }
                else
                {
                        if (va[pa] < vb[pb])
                                pa++;
                        else
                                pb++;
                }
        }
        // cout << "b" << endl;
        cout << ans << endl;
}

//................................
