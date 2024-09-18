//
//  main.cpp
//  d
//
//  Created by Suraj Singh Raman on 14/04/24.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
using lld = long double;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

void suraj();

signed main()
{

    fastio();

#ifndef ONLINE_JUDGE
    clock_t startTime = clock();
#endif

    // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

    // cout << setprecision(15) << fixed;

    int t = 1;

    // cin>>t;

    for (int i = 1; i <= t; i++)
    {

        // cout<<"Case #"<<i<<": ";

        suraj();

        debug("---");
    }

#ifndef ONLINE_JUDGE
    cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

    return 0;
}

void suraj()
{
    constexpr int mod = 998244353;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int totBalls = 0, mxBallsOfAColor = 0;
    for (int i : v)
    {
        totBalls += i;
        mxBallsOfAColor = max(i, mxBallsOfAColor);
    }

    int mxPossibleGrps = mxBallsOfAColor;
    int remainingBalls = totBalls - mxBallsOfAColor;
    if (remainingBalls <= mxBallsOfAColor)
        mxPossibleGrps = mxBallsOfAColor;
    else
    {
        mxPossibleGrps += ((remainingBalls - mxBallsOfAColor) + 1) / 2;
    }

    sort(v.begin(), v.end());

    debug(mxPossibleGrps);
    debug(v);

    vector<vector<int>> dp(mxPossibleGrps + 1, vector<int>(mxPossibleGrps + 1, 0)); // dp[i][j] = count of values such that
    // value is i with j groups filled (filled => grp contains 2 elements)

    dp[0][0] = 1;
    // debug(dp);

    for (int i = 0; i < n; i++)
    {
        // if all v[i] elements of type i are taken
        int nBallsOfColorI = v[i];
        // debug(nBallsOfColorI);
        // for (int ngrps = 0; ngrps <= mxPossibleGrps; ngrps++)
        for (int ngrps = mxPossibleGrps; ngrps >= 0; ngrps--)
        {
            // debug(ngrps);
            // for (int filledGrps = 0; filledGrps <= ngrps; filledGrps++)
            for (int filledGrps = ngrps; filledGrps >= 0; filledGrps--)
            {
                // debug(filledGrps);
                if (dp[ngrps][filledGrps] == 0)
                    continue;
                int totGrps = nBallsOfColorI;
                int prevBallCnt = filledGrps + ngrps;
                // prevBallCnt %= mod;

                int nFullGrps = 0;
                if (prevBallCnt <= totGrps)
                {
                    nFullGrps = prevBallCnt;
                }
                else
                {
                    totGrps += ((prevBallCnt - totGrps) + 1) / 2;
                    // totGrps %= mod;
                    nFullGrps = nBallsOfColorI + (prevBallCnt - totGrps) / 2;
                    // nFullGrps %= mod;
                }
                if (totGrps <= mxPossibleGrps)
                {
                    dp[totGrps][nFullGrps] += dp[ngrps][filledGrps];
                    dp[totGrps][nFullGrps] %= mod;
                }
            }
        }

//        debug(dp);

        // debug(dp);

        // if none of them are taken
    }

    int ans = 0;

    for (int i = 1; i <= mxPossibleGrps; i++)
    {
        // debug(i);
        for (int j = 0; j <= i; j++)
        {
            // debug(j);
            ans += dp[i][j] * i;
            ans %= mod;
        }
        // debug(ans);
    }
    cout << ans << endl;
}
