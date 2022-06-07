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

const ll mod = 998244353;
const ll MOD = 1e9 + 7;
const int INF = int(1e9);
const int NEG_INF = int(-1e9);
// const int INF = 2147483647;
// const int NEG_INF = -2147483647 - 1;
//............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

int main()
{
        // ioss
        // startTime=(double)clock();
        freopen("race.in", "r", stdin);
        freopen("race.out", "w", stdout);
        // cout << setprecision(15) << fixed;
        // int t;cin>>t;for(int i=1;i<=t;i++)
        {
                // cout<<"Case #"<<i<<": ";
                suraj();
        }
        return 0;
}

//...............................

//...............................

void suraj()
{
        ll k, n;
        cin >> k >> n;

        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                ll dist = 0;
                int time = 0;
                int flag = -1;
                for (int j = 1; j < x; j++)
                {
                        if (k - dist >= j)
                        {
                                dist += j;
                                time++;
                        }
                        else
                        {
                                time++;
                                dist = k;
                                flag = 1;
                                break;
                        }
                }
                // cout << "time: " << time << endl;
                // cout << "dist: " << dist << endl;
                // cout << "flag: " << flag << endl;
                if (flag == 1 || dist == k)
                {
                        cout << time << endl;
                        continue;
                }
                for (int j = x;;)
                {
                        if (k - dist <= j)
                        {
                                time++;
                                break;
                        }
                        else if (k - dist > j && k - dist < 2 * j)
                        {
                                // time++; // for j
                                // time++; // for (k-dist-j) value
                                time += 2;
                                break;
                        }
                        else if (k - dist > 2 * j)
                        {
                                dist += 2 * j;
                                j++;
                                time += 2;
                        }
                        else if (k - dist == 2 * j)
                        {
                                time += 2;
                                break;
                        }
                }
                cout << time << endl;
        }
}

//................................
// int
// int
// int
// int
