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
double gct() // get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        // ioss
        startTime = (double)clock();
        // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
        // cout << setprecision(15) << fixed;
        int t;
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

//...............................

//...............................

void suraj()
{
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
                cin >> i;
        int l = 0, r = n - 1;
        int choice1, choice2;
        while (l < r)
        {
                if (v[l] == v[r])
                {
                        l++;
                        r--;
                }
                else
                {
                        choice1 = v[l];
                        choice2 = v[r];
                        break;
                }
        }
        // cout << "choice1: " << choice1 << "choice2: " << choice2 << endl;
        l = 0, r = n - 1;
        int flag = 1; // -1 => no and 1=>yes
        // case 1
        // x=v[l]
        while (l < r)
        {
                if (v[l] == v[r])
                {
                        l++;
                        r--;
                }
                else
                {
                        if (v[l] == choice1 || v[r] == choice1)
                        {
                                if (v[l] == choice1)
                                {
                                        l++;
                                }
                                else
                                {
                                        r--;
                                }
                        }
                        else
                        {
                                flag = -1;
                                break;
                        }
                }
        }
        if (flag == 1)
        {
                cout << "YES" << endl;
                return;
        }
        // case 2
        // x=v[r]
        flag = 1;
        l = 0, r = n - 1;
        while (l < r)
        {
                if (v[l] == v[r])
                {
                        l++;
                        r--;
                }
                else
                {
                        if (v[l] == choice2 || v[r] == choice2)
                        {
                                if (v[l] == choice2)
                                {
                                        l++;
                                }
                                else
                                {
                                        r--;
                                }
                        }
                        else
                        {
                                flag = -1;
                                break;
                        }
                }
        }
        if (flag == -1)
        {
                cout << "NO" << endl;
        }
        else
        {
                cout << "YES" << endl;
        }
}

//................................
