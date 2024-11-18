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

vector<vector<int>> tree;
vector<bool> visited;
vector<string> val;
map<int, string> leafVal;
int nQMarks;

void dfs(int node, string value)
{
    // debug("dfs");
    // debug(node);
    // debug(value);
    if (tree[node].size() == 1 && node != 0)
    {
        leafVal[node] = value;
        visited[node] = true;
        return;
    }
    for (int neigh : tree[node])
    {
        if (!visited[neigh])
        {
            visited[neigh] = true;
            dfs(neigh, value + val[neigh]);
        }
    }
    return;
}

void suraj()
{
    int n;
    cin >> n;

    tree = vector<vector<int>>(n, vector<int>());
    visited = vector<bool>(n, false);
    val = vector<string>(n, "");
    leafVal.clear();
    nQMarks = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    string nodeValues;
    cin >> nodeValues;
    for (int i = 0; i < n; i++)
    {
        val[i] = nodeValues[i];
        if (nodeValues[i] == '?')
            nQMarks++;
    }

    // debug(tree);
    // debug(val);
    // debug(visited);

    // get the string for each leaf
    visited[0] = true;
    dfs(0, val[0]);

    // debug(leafVal);
    int ans = 0;
    if (val[0] == "?")
    {
        int endW0 = 0, endW1 = 0;
        int cntEndWQMark = 0; // cnt of leaf values ending with '?'
        for (auto el : leafVal)
        {
            int nodeNo = el.first;
            string nodeStr = el.second;
            int firstEl = nodeStr[0];
            int lastEl = nodeStr[nodeStr.size() - 1];

            if (firstEl != '?' && firstEl != lastEl)
                ans++;

            if (lastEl == '?')
                cntEndWQMark++;

            if (firstEl == '?')
            {
                if (lastEl == '1')
                    endW1++;
                else if (lastEl == '0')
                    endW0++;
            }
        }
        int extraQMarks = nQMarks - cntEndWQMark - 1; // -1 cz we are not counting the root node here :)
        // debug(cntEndWQMark);
        // debug(extraQMarks);
        // debug(ans);
        if (cntEndWQMark % 2 == 0)
        {
            ans += max(endW0, endW1); // iris change the vertex value from '?' to whatever will increase the score by most :)
            ans += cntEndWQMark / 2;
        }
        else if (cntEndWQMark % 2 == 1) // iris will not change the node root first now :)
        {                               // she will want to change the extra ie the mid quest marks
            // change the extra q marks first
            if (extraQMarks % 2 == 0) // iris has no choice but to go first among the leaf nodes containing qmarks either at the beginning or at the end
            {
                ans += max(endW0, endW1); // iris change the vertex value from '?' to whatever will increase the score by most :)
                ans += (cntEndWQMark) / 2;
            }
            else
            {
                // min becz for this case dora is the one changing the first ques mark value of either the vertex or the leaf nodes
                // and she wants to go minimize the ans, she can't do anything for leaves ending with '?' but she 
                // can do sth about leaves ending with either 0 or 1
                ans += min(endW0, endW1); // iris change the vertex value from '?' to whatever will increase the score by most :)
                ans += (cntEndWQMark + 1) / 2;
            }
        }
    }
    else
    {
        // ? can be in the end only
        int cnt = 0;
        for (auto el : leafVal)
        {
            int leafNode = el.first;
            string leafStr = el.second;
            int lenStr = leafStr.size();
            char firstEl = leafStr[0];
            char lastEl = leafStr[lenStr - 1];
            if (lastEl == '?')
                cnt++;
            else if (firstEl != lastEl)
                ans++;
        }

        ans += (cnt + 1) / 2;
    }
    cout << ans << endl;
}
