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

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        deque<int> ansL, ansR;
        if (n % 2 == 0)
        {
                for (int i = n - 1; i >= 1; i -= 2)
                {
                        ansL.push_back(i);
                        ansL.push_front(i);
                }
                ansR.pb(n);
                for (int i = n - 2; i >= 2; i -= 2)
                {
                        ansR.push_back(i);
                        ansR.push_front(i);
                }
                ansR.pb(n);
        }
        else
        {
                ansL.pb(n);
                for (int i = n - 2; i >= 1; i -= 2)
                {
                        ansL.push_back(i);
                        ansL.push_front(i);
                }

                for (int i = n - 1; i >= 2; i -= 2)
                {
                        ansR.push_back(i);
                        ansR.push_front(i);
                }
                ansR.pb(n);
        }
        for (int i : ansL)
                cout << i << " ";
        for (int i : ansR)
                cout << i << " ";
        cout << endl;
}

//................................