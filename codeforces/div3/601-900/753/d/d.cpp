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
//         ioss
//             startTime = (double)clock();
//         // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);
//         // cout << setprecision(15) << fixed;
//         int t;
//         cin >> t;
//         for (int i = 1; i <= t; i++)
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
//         vector<int> a(n);
//         for (int &i : a)
//                 cin >> i;
//         vector<char> col(n);
//         int cntB = 0, cntR = 0;
//         for (char &c : col)
//         {
//                 cin >> c;
//                 if (c == 'R')
//                         cntR++;
//                 if (c == 'B')
//                         cntB++;
//         }
//         vector<int> dp(n + 1, 0);
//         for (int i = 0; i < n; i++)
//         {
//                 if (col[i] == 'R')
//                 {
//                         // matlab top cntR inko bharna hai
//                         if (a[i] <= n - cntR + 1)
//                         {
//                                 dp[n - cntR + 1]++;
//                         }
//                         else
//                         {
//                                 dp[a[i]]++;
//                         }
//                 }
//                 else
//                 {
//                         // matlab bottom cntB inko fill karna hai
//                 }
//         }
//         int bag = dp[n - cntR + 1];
//         if (bag == 0)
//         {
//                 cout << -1 << endl;
//                 return;
//         }
//         else
//         {
//                 bag = bag - 1;
//         }
//         for (int i = n - cntR + 1 + 1; i <= n && bag != 0; i++)
//         {
//                 if (dp[i] == 0)
//                 {
//                         bag--;
//                         dp[i]++;
//                 }else if(dp[i]>1){
//                         bag+=
//                 }
//         }
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
        ioss
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
        vector<int> a(n);
        for (int &i : a)
                cin >> i;
        vector<char> c(n);
        for (char &el : c)
                cin >> el;
        map<int, int> m;
        vector<int> red, blue;
        for (int i = 0; i < n; i++)
        {
                if (m[a[i]] > 0)
                {
                        if (c[i] == 'R')
                                red.pb(a[i]);
                        else
                                blue.pb(a[i]);
                }
                else
                {
                        m[a[i]]++;
                }
        }
        sort(red.rbegin(), red.rend());
        sort(blue.begin(), blue.end());
        int pblue = 0, pred = 0;
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
                if (m[i] != 1)
                {
                        while (pblue < (int)blue.size() && blue[pblue] < i)
                        {
                                pblue++;
                        }
                        if (pblue < (int)blue.size() && blue[pblue] >= i)
                        {
                                continue;
                        }
                        else
                        {
                                while (pred < (int)red.size() && red[pred] > i)
                                        pred++;
                                if (pred < (int)red.size() && red[pred] <= i)
                                        continue;
                                else
                                {
                                        cout << "NO" << endl;
                                        return;
                                }
                        }
                }
        }
        cout << "YES" << endl;
}

//................................
