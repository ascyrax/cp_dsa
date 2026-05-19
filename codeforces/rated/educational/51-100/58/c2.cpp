// @author: ascyrax

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
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

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

    cin >> t;

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
    int n;
    cin >> n;
    vector<pair<int, int>> ranges;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        ranges.push_back(make_pair(l, r));
    }
    sort(ranges.begin(), ranges.end());
    debug(ranges);

    map<int, vector<int>> rToIndex;
    vector<int> grp(n, -1);
    multiset<int> st;

    for (int i = 0; i < n; i++)
    {
        int l = ranges[i].first;
        int r = ranges[i].second;
        int lenSt = st.size();
        auto itl = st.lower_bound(l);
        if (itl == st.begin())
        {
            debug("IF");
            // if (l == *st.begin())
            // {
            // }
            // else if (l < *st.begin())
            // {
            // }
            if (lenSt >= 2)
            {
                cout << -1 << endl;
                return;
            }
            else if (lenSt == 1)
            {
                // choose other grp
                int rTop = *st.begin();
                int index = rToIndex[rTop][0];
                // if(rToIndex[rTop].size() > 1){}

                int grpValue = grp[index];
                grp[i] = (grpValue + 1) % 2;
                rToIndex[r].push_back(i);

                auto itr = st.lower_bound(r);
                st.erase(st.begin(), itr);
                st.insert(r);
            }
            else if (lenSt == 0)
            {
                // choose any grp
                grp[i] = 0;
                rToIndex[r].push_back(i);

                auto itr = st.lower_bound(r);
                st.erase(st.begin(), itr);
                st.insert(r);
            }
        }
        else if (itl == st.end())
        {
            debug("ELSE IF");
            // choose any grp
            grp[i] = 0;
            rToIndex[r].push_back(i);

            st.clear();
            st.insert(r);
        }
        else
        { // somewhere in between
            debug("ELSE");
            auto itl = st.lower_bound(l);
            st.erase(st.begin(), itl);
            lenSt = st.size();
            if (lenSt >= 2)
            {
                cout << -1 << endl;
                return;
            }
            else if (lenSt == 1)
            {
                // choose other grp
                int rTop = *st.begin();
                int index = rToIndex[rTop][0];
                // if(rToIndex[rTop].size() > 1){}

                int grpValue = grp[index];
                grp[i] = (grpValue + 1) % 2;
                rToIndex[r].push_back(i);

                auto itr = st.lower_bound(r);
                st.erase(st.begin(), itr);
                st.insert(r);
            }
            else if (lenSt == 0)
            {
                // choose any grp
                grp[i] = 0;
                rToIndex[r].push_back(i);

                auto itr = st.lower_bound(r);
                st.erase(st.begin(), itr);
                st.insert(r);
            }
        }
        debug(st);
        debug(grp);
        debug(rToIndex);
    }

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (grp[i] == 0)
            cnt0++;
        else
            cnt1++;
    }
    if (cnt0 == 0 || cnt1 == 0)
    {
        if (cnt0 == 0)
            grp[0] = 0;
        else
            grp[1] = 1;
    }

    for (int i = 0; i < n; i++)
        cout << grp[i] + 1 << " ";
    cout << endl;
}
