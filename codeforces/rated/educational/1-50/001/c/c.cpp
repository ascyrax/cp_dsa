// // @author: ascyrax

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef long double ld;

// #define endl "\n"
// #define ioss                         \
//         ios::sync_with_stdio(false); \
//         cin.tie(0);
// #define pb push_back

// double startTime;
// double gct() // get_current_time
// {
//         return ((double)clock() - startTime) / CLOCKS_PER_SEC;
// }
// void suraj();

// int main()
// {
//         // ioss
//         startTime = (double)clock();
//         // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
//         // cout << setprecision(15) << fixed;
//         // int t;cin>>t;for(int i=1;i<=t;i++)
//         {
//                 // cout<<"Case #"<<i<<": ";
//                 suraj();
//         }
//         return 0;
// }

// const ll MOD = 1e9 + 7;
// const int INF = int(1e9);
// const int NEG_INF = int(-1e9);
// // const int INF = 2147483647;
// // const int NEG_INF = -2147483647 - 1;
// //............................... dont declare any variable named y1 or (y2 maybe) as it is already present in some library and they may collide

// //...............................

// //...............................

// void suraj()
// {
//         int n;
//         cin >> n;
//         vector<pair<int, int>> vxy;
//         vector<pair<double, int>> vtheta;
//         for (int i = 0; i < n; i++)
//         {
//                 int x, y;
//                 cin >> x >> y;
//                 vxy.pb(make_pair(x, y));
//                 vtheta.pb(make_pair(atan2(y, x), i));
//         }

//         double mnDiff = 100;
//         pair<int, int> ptr;
//         vector<bool> flag(n, 0);
//         for (int i = 0; i < n; i++)
//         {

//                 if (vtheta[i].first < 0)
//                 {
//                         vtheta[i].first += 6.28319;
//                         flag[vtheta[i].second] = 1;
//                 }
//                 // becz 360 degrees = 6.28319 radians
//                 // cout << vtheta[i].first << endl;
//         }
//         sort(vtheta.begin(), vtheta.end());

//         for (int i = 0; i < n; i++)
//         {
//                 // cout << "i = " << i << endl;
//                 // cout << vtheta[(i) % n].first << " " << vtheta[(i + 1) % n].first << endl;
//                 if (flag[vtheta[i].second] == 1)
//                 {
//                         if (abs(vtheta[(i + 1) % n].first - (vtheta[i].first - 6.28319)) < mnDiff)
//                         {
//                                 // cout << "if" << endl;
//                                 // cout << "i = " << i << " , i+1 = " << i + 1 << endl;
//                                 // cout << vtheta[i].second << " " << vtheta[i + 1].second << endl;
//                                 // cout << vtheta[(i + 1) % n].first - vtheta[(i)].first << " " << mnDiff << endl;
//                                 ptr = make_pair(vtheta[i % n].second + 1, vtheta[(i + 1) % n].second + 1);
//                                 mnDiff = min(mnDiff, abs(vtheta[(i + 1) % n].first - (vtheta[i].first - 6.28319)));
//                                 // cout << "mnDiff = " << mnDiff << endl;
//                         }
//                 }
//                 else
//                 {
//                         if (abs(vtheta[(i + 1) % n].first - vtheta[i].first) < mnDiff)
//                         {
//                                 // cout << "if" << endl;
//                                 // cout << "i = " << i << " , i+1 = " << i + 1 << endl;
//                                 // cout << vtheta[i].second << " " << vtheta[i + 1].second << endl;
//                                 // cout << vtheta[(i + 1) % n].first - vtheta[(i)].first << " " << mnDiff << endl;
//                                 ptr = make_pair(vtheta[i % n].second + 1, vtheta[(i + 1) % n].second + 1);
//                                 mnDiff = min(mnDiff, vtheta[(i + 1) % n].first - vtheta[i].first);
//                                 // cout << "mnDiff = " << mnDiff << endl;
//                         }
//                 }
//         }

//         cout << ptr.first << " " << ptr.second << endl;
// }

// //................................

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
        // int t;cin>>t;for(int i=1;i<=t;i++)
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
        vector<pair<int, int>> vxy;
        vector<pair<double, int>> vtheta;
        for (int i = 0; i < n; i++)
        {
                int x, y;
                cin >> x >> y;
                vxy.pb(make_pair(x, y));
                vtheta.pb(make_pair(atan2(y, x), i));
        }

        double mnDiff = 100;
        pair<int, int> ptr;

        for (int i = 0; i < n; i++)
        {

                if (vtheta[i].first < 0)
                        vtheta[i].first += 6.28319;
                // becz 360 degrees = 6.28319 radians
        }
        sort(vtheta.begin(), vtheta.end());

        for (int i = 0; i < n; i++)
        {
                // cout << "i = " << i + 1 << endl;
                // cout << vtheta[(i) % n].first << " " << vtheta[(i + 1) % n].first << endl;
                if (abs(vtheta[(i + 1) % n].first - vtheta[i].first) > 3.14159)
                {
                        cout << "if" << endl;
                        cout << vtheta[i % n].first << " " << vtheta[(i + 1) % n].first << endl;
                        if (abs(vtheta[(i + 1) % n].first - vtheta[i].first) - 3.14159 < mnDiff)
                        {

                                cout << "if" << endl;
                                // cout << "i = " << i << " , i+1 = " << i + 1 << endl;
                                // cout << vtheta[i].second << " " << vtheta[i + 1].second << endl;
                                // cout << vtheta[(i + 1) % n].first - vtheta[(i)].first << " " << mnDiff << endl;
                                ptr = make_pair(vtheta[i % n].second + 1, vtheta[(i + 1) % n].second + 1);
                                mnDiff = min(mnDiff, abs(vtheta[(i + 1) % n].first - vtheta[i].first) - 3.14159);
                                cout << "mnDiff = " << mnDiff << endl;
                        }
                }
                else
                {
                        if (abs(vtheta[(i + 1) % n].first - vtheta[i].first) < mnDiff)
                        {
                                cout << "else if" << endl;
                                // cout << "i = " << i << " , i+1 = " << i + 1 << endl;
                                // cout << vtheta[i].second << " " << vtheta[i + 1].second << endl;
                                cout << vtheta[(i) % n].first << " " << vtheta[(i + 1) % n].first << endl;
                                ptr = make_pair(vtheta[i % n].second + 1, vtheta[(i + 1) % n].second + 1);
                                mnDiff = min(mnDiff, vtheta[(i + 1) % n].first - vtheta[i].first);
                                cout << "mnDiff = " << mnDiff << endl;
                        }
                }
        }

        cout << ptr.first << " " << ptr.second << endl;
}

//................................