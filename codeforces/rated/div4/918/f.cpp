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

void _print(int t)
{
    cerr << t;
}
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

vector<int> a, b, delta, b_sorted, a_sorted;
map<int, int> btoa, index_of;
vector<bool> marked;

// create a segment tree to count the no of marked[i] = true from 0 to index-1
class SegmentTree
{
    vector<int> tree;
    int n;

    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
            {
                update(2 * node, start, mid, idx, val);
            }
            else
            {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }

public:
    SegmentTree(int size)
    {
        n = size;
        tree.assign(4 * n, 0);
    }

    void update(int idx)
    {
        update(1, 0, n - 1, idx, 1);
    }

    int query(int l, int r)
    {
        if (l > r)
            return 0;
        return query(1, 0, n - 1, l, r);
    }
} *seg_tree;

int count_greetings(int current_b)
{
    int corresponding_a = btoa[current_b];
    int index = index_of[corresponding_a];
    // marked[index] = true;
    seg_tree->update(index);
    // from 0 to index-1, count how many are marked
    int cntMarked = 0;
    cntMarked = seg_tree->query(0, index - 1);
    // debug(cntMarked);
    int cnt = 0;
    cnt = lower_bound(a_sorted.begin(), a_sorted.end(), corresponding_a) - a_sorted.begin();
    return cnt - cntMarked;
}

void suraj()
{

    int n;
    cin >> n;
    // vector<int> a(n), b(n), delta(n);
    seg_tree = new SegmentTree(n);

    a = vector<int>(n);
    b = vector<int>(n);
    delta = vector<int>(n);
    a_sorted = vector<int>(n);
    b_sorted = vector<int>(n);
    btoa = map<int, int>();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        delta[i] = b[i] - a[i];
        a_sorted[i] = a[i];
        b_sorted[i] = b[i];
        btoa[b[i]] = a[i];
    }
    sort(a_sorted.begin(), a_sorted.end());
    sort(b_sorted.begin(), b_sorted.end());
    index_of = map<int, int>();
    marked = vector<bool>(n, false);
    for (int i = 0; i < n; i++)
    {
        int val = a_sorted[i];
        index_of[val] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int count = count_greetings(b_sorted[i]);
        // debug(count);
        ans += count;
    }

    cout << ans << endl;
}
