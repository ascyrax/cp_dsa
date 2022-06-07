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
// bool custom(pair<int, int> &a, pair<int, int> &b)
// {
//         if (a.second < b.second)
//                 return true;
//         else if (b.second == a.second)
//         {
//                 return a.first < b.first;
//         }
//         else
//                 return false;
// }

// //...............................

// void suraj()
// {
//         int n, k;
//         cin >> n >> k;
//         vector<pair<int, int>> vp;
//         for (int i = 0; i < n; i++)
//         {
//                 int a, b;
//                 cin >> a >> b;
//                 vp.pb(make_pair(a, b));
//         }
//         sort(vp.begin(), vp.end(), custom);
//         cout << "after sort" << endl;
//         for (auto el : vp)
//                 cout << el.first << " " << el.second << endl;
//         // priority_queue<int, vector<int>, greater<int>> end_times; // assuming smallest value comes first in priority queue
//         multiset<int> end_times;
//         int movieWatched = 0;
//         for (auto el : vp)
//         {
//                 // cout << el.first << " " << el.second << endl;
//                 if (end_times.size() < k)
//                 {
//                         // cout << "if" << endl;
//                         end_times.push(el.second);
//                         movieWatched++;
//                 }
//                 else
//                 {
//                         // cout << "else " << endl;
//                         if (end_times.top() <= el.first) // among currently being watched movie, the first
//                         // movie to end , ends before starting of the el i.e. the current movie
//                         {
//                                 // cout << "else if" << endl;
//                                 end_times.pop();
//                                 end_times.push(el.second);
//                                 movieWatched++;
//                         }
//                         else
//                         {
//                                 // do nothing
//                                 // cout << "else else" << endl;
//                                 continue;
//                         }
//                 }

//                 // for (auto i : end_times)
//                 //         cout << i << " ";
//                 // cout << endl;
//         }
//         cout << movieWatched << endl;
// }

// //................................
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) // read start time, end time
                cin >> v[i].second >> v[i].first;
        sort(begin(v), end(v)); // sort by end time

        int maxMovies = 0;
        multiset<int> end_times; // times when members will finish watching movies
        for (int i = 0; i < k; ++i)
                end_times.insert(0);

        for (int i = 0; i < n; i++)
        {
                auto it = end_times.upper_bound(v[i].second);
                if (it == begin(end_times))
                        continue;
                // assign movie to be watched by member in multiset who finishes at time *prev(it)
                end_times.erase(--it);
                // member now finishes watching at time v[i].first
                end_times.insert(v[i].first);
                ++maxMovies;
        }

        cout << maxMovies;
}