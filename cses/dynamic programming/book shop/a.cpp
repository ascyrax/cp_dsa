// // @author: ascyrax

// #include <iostream>
// #include <vector>
// #include <set>
// #include <map>
// #include <algorithm>
// #include <cmath>
// #include <iomanip>

// using namespace std;

// #define fastio()                      \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL)
// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define endl "\n"
// #define int long long
// #define pb push_back
// #define ppb pop_back
// #define mp make_pair
// #define PI 3.141592653589793238462
// #define set_bits __builtin_popcountll
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

// using ll = long long;
// using ull = unsigned long long;
// using lld = long double;

// #ifndef ONLINE_JUDGE
// #define debug(x)       \
//     cerr << #x << " "; \
//     _print(x);         \
//     cerr << endl;
// #else
// #define debug(x)
// #endif

// void _print(int t) { cerr << t; }
// void _print(string t) { cerr << t; }
// void _print(char t) { cerr << t; }
// void _print(lld t) { cerr << t; }
// void _print(double t) { cerr << t; }
// void _print(ull t) { cerr << t; }

// template <class T, class V>
// void _print(pair<T, V> p);
// template <class T>
// void _print(vector<T> v);
// template <class T>
// void _print(set<T> v);
// template <class T, class V>
// void _print(map<T, V> v);
// template <class T>
// void _print(multiset<T> v);
// template <class T, class V>
// void _print(pair<T, V> p)
// {
//     cerr << "{";
//     _print(p.first);
//     cerr << ",";
//     _print(p.second);
//     cerr << "}";
// }
// template <class T>
// void _print(vector<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T>
// void _print(set<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T>
// void _print(multiset<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T, class V>
// void _print(map<T, V> v)
// {
//     cerr << "[ ";
//     for (auto i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }

// void suraj();

// signed main()
// {

//     fastio();

// #ifndef ONLINE_JUDGE
//     clock_t startTime = clock();
// #endif

//     // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

//     // cout << setprecision(15) << fixed;

//     int t = 1;

//     // cin>>t;

//     for (int i = 1; i <= t; i++)
//     {

//         // cout<<"Case #"<<i<<": ";

//         suraj();

//         debug("---");
//     }

// #ifndef ONLINE_JUDGE
//     cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
// #endif

//     return 0;
// }

// void suraj()
// {
//     int n, maxPrice; // consider x = maxPrice
//     cin >> n >> maxPrice;

//     vector<int> prices(n), pages(n);
//     for (int &i : prices)
//         cin >> i;
//     for (int &i : pages)
//         cin >> i;

//     // int sumPrices = 0, sumPages = 0;
//     // int cnt1 = 0, cnt2 = 0;
//     // for (int i : prices)
//     // {
//     //     if (i == 1)
//     //         cnt1++;
//     //     else if (i == 2)
//     //         cnt2++;
//     //     sumPrices += i;
//     // }
//     // for (int i : pages)
//     //     sumPages += i;

//     // debug(cnt1);
//     // debug(cnt2);
//     // debug(sumPrices);
//     // debug(sumPages);

//     // debug(prices);
//     // debug(pages);
//     // vector<int> dp(maxPrice + 1, 0); // dp[i] = most pages for price of i :)
//     map<int, int> mpEven, mpOdd;
//     mpEven[0] = 0;
//     mpOdd[0] = 0;
//     // cnt1 = 0;
//     // cnt2 = 0;
//     for (int i = 0; i < n; i++)

//     {
//         int price = prices[i];
//         int page = pages[i];
//         // mp[price] = max(mp[price], page);
//         vector<int> temp;

//         if (i & 1)                 // i = odd
//             for (auto el : mpEven) // o(x)
//             {
//                 int k = el.first;
//                 int v = el.second;
//                 if (k + price <= maxPrice)
//                     mpOdd[k + price] = v + page;
//             }
//         else                      // i = even
//             for (auto el : mpOdd) // o(x)
//             {
//                 int k = el.first;
//                 int v = el.second;
//                 if (k + price <= maxPrice)
//                     mpEven[k + price] = v + page;
//             }
//         // if (i < 20)
//         // {
//         //     if (price == 1)
//         //         cnt1++;
//         //     else
//         //         cnt2++;
//         //     debug(cnt1);
//         //     debug(cnt2);
//         //     // debug(mp[cnt1]);
//         //     debug(mp);
//         // }
//         debug(mpOdd);
//         debug(mpEven);
//     }

//     int ans = 0;
//     // for (int i = 0; i <= maxPrice; i++)
//     // ans = max(ans, dp[i]);
//     if ((n - 1) & 1)
//         for (auto el : mpOdd)
//         {
//             int k = el.first;
//             int v = el.second;
//             // if (k <= maxPrice)
//             ans = max(ans, v);
//         }
//     else
//         for (auto el : mpEven)
//         {
//             int k = el.first;
//             int v = el.second;
//             // if (k <= maxPrice)
//             ans = max(ans, v);
//         }
//     cout << ans << endl;
// }

// // 1000 1000
// // 2 2 1 2 1 2 2 2 2 1 1 1 1 2 1 2 1 2 2 1 2 2 1 2 2 1 1 2 2 1 1 2 2 2 1 2 1 1 2 2 1 2 2 2 1 1 2 1 2 2 1 2 1 2 1 1 1 2 1 1 2 2 2 1 2 1 1 1 1 2 1 2 1 2 1 1 2 1 2
// // 2 1 2 1 2 1 2 2 2 2 1 1 2 2 2 1 2 1 1 2 1 1 1 1 2 2 1 1 1 2 1 2 1 1 2 1 1 2 2 1 1 2 1 1 1 1 2 2 1 2 1 1 1 2 1 1 2 1 1 2 1 1 1 2 1 1 1 2 2 2 2 2 2 1 2 2 2 1 1
// // 2 2 2 1 2 1 1 2 2 1 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 2 2 1 2 2 1 1 1 1 2 2 2 2 2 1 2 2 2 2 1 2 2 2 1 2 1 2 1 2 1 1 2 1 2 1 1 2 2 1 1 1 1 1 2 1 1 2 1 2 1 1 2 2 1
// // 1 1 1 1 2 1 2 1 1 2 1 2 2 1 1 1 2 1 1 2 1 1 1 1 2 2 1 1 2 2 1 1 1 2 1 1 2 2 2 2 1 2 1 2 2 2 2 1 2 2 2 1 1 2 1 2 1 1 1 1 2 2 2 2 1 2 2 1 1 1 1 2 2 2 1 1 1 2 2
// // 1 2 1 2 1 1 2 2 1 2 2 2 1 1 1 1 2 1 2 1 1 1 2 2 1 1 2 1 2 2 1 1 1 2 1 1 1 2 1 2 1 1 2 2 2 2 2 1 2 1 2 2 1 1 2 2 1 2 1 1 1 2 1 1 2 2 2 2 1 1 1 2 1 2 1 2 1 2 2
// // 1 2 2 2 1 1 2 2 2 1 1 1 1 1 1 1 1 2 1 2 1 2 1 2 1 1 1 2 2 1 1 1 2 1 2 2 2 2 2 2 1 2 2 1 1 1 2 2 1 1 2 1 1 1 2 2 2 1 2 1 1 2 2 1 2 2 2 2 1 2 1 1 2 2 1 1 1 1 2
// // 1 2 1 2 1 1 1 1 2 1 2 1 2 2 1 1 2 1 1 2 1 1 2 1 1 2 1 1 1 1 2 1 2 2 1 1 2 2 1 1 1 2 2 2 2 1 1 2 2 2 2 2 1 1 1 1 2 1 1 1 1 1 2 1 2 1 2 2 2 2 2 1 2 1 1 2 2 2 2
// // 2 2 1 2 1 1 1 2 2 2 2 2 1 2 2 2 1 2 1 1 1 1 2 1 2 2 1 2 1 2 1 2 1 2 2 1 2 2 2 1 2 1 1 2 1 1 1 2 1 1 1 2 1 2 2 2 1 2 1 1 1 2 2 1 2 1 2 1 2 1 1 1 2 2 1 2 1 1 2
// // 1 1 2 1 1 2 2 2 1 1 2 1 2 1 2 2 1 1 1 2 2 1 1 1 2 2 2 2 2 1 2 1 2 2 1 2 1 1 2 2 2 1 2 1 2 1 1 1 1 1 2 2 1 2 2 2 1 2 2 1 1 1 2 1 2 2 1 1 2 1 2 2 1 1 2 2 2 1 2
// // 2 1 1 2 2 2 2 2 2 1 2 1 2 1 1 1 1 2 1 1 1 1 2 2 1 1 1 2 2 1 2 1 1 1 2 2 1 1 1 2 1 1 1 2 2 2 2 1 1 1 2 2 2 2 2 1 1 1 2 2 2 2 1 1 2 1 2 1 2 2 2 2 2 2 1 1 2 2 1
// // 1 1 2 2 1 2 2 2 2 2 2 2 2 2 2 1 1 2 1 2 2 2 1 1 1 1 1 2 1 1 2 2 1 2 1 2 1 1 2 2 1 2 2 1 1 2 1 1 1 2 1 1 2 2 2 2 2 2 2 2 1 2 1 1 1 2 1 2 2 1 2 1 2 2 2 2 1 2 1
// // 2 1 1 1 2 2 2 2 2 2 1 1 2 1 2 2 2 1 1 2 2 2 1 2 2 2 1 1 2 1 1 1 2 2 1 1 2 2 1 1 2 1 2 2 2 1 2 2 2 2 2 2 2 1 2 2 1 1 1 2 1 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 2 2 1
// // 1 1 2 1 2 2 2 2 1 1 2 1 2 1 1 2 2 2 2 1 1 1 2 2 1 2 1 2 2 1 2 1 1 1 1 1 1 1 2 1 1 2 1 1 1 1 2 2 1 2 1 2

// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// // 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1