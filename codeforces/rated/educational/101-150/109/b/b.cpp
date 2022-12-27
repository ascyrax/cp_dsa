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
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
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
int n;
vector<int> v;
//...............................

//...............................

void suraj()
{
        cin >> n;

        v = vector<int>(n);

        int cnt = 0;

        for (int &i : v)
                cin >> i;
        vector<int> copy = v;
        sort(copy.begin(), copy.end());
        if (copy == v)
        {
                cout << 0 << endl;
        }
        else
        {
                if (copy[0] == v[0] || copy[n - 1] == v[n - 1])
                {
                        cout << 1 << endl;
                }
                else if (v[0] == copy[n - 1] && v[n - 1] == copy[0])
                {
                        cout << 3 << endl;
                }
                else
                        cout << 2 << endl;
        }
        return;
}

//................................
