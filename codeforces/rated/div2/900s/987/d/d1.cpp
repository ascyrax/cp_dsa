// @author: ascyrax

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
// #define int long long
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

vector<int> v;
vector<int> minOnTheRight, maxOnTheLeft;
vector<int> visited;
vector<vector<int>> gRight, gLeft;
// int ans;

void printStack(stack<int> st)
{
    cout << "printStack ...";
    while (!st.empty())
    {
        int top = st.top();
        cout << top << " ";
        st.pop();
    }
    cout << "...." << endl;
}

class SegmentTree
{
private:
    int size;
    vector<int> tree;
    void update(int node, int start, int end, int idx, int val)
    {
        if (start == end)
        {
            // Leaf node
            tree[node] = max(tree[node], val);
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
            {
                // Update left child
                update(2 * node, start, mid, idx, val);
            }
            else
            {
                // Update right child
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            // Internal node will have the max of both children
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            // No overlap
            return -1;
        }
        if (l <= start && end <= r)
        {
            // Complete overlap
            return tree[node];
        }
        // Partial overlap
        int mid = (start + end) / 2;
        int leftQuery = query(2 * node, start, mid, l, r);
        int rightQuery = query(2 * node + 1, mid + 1, end, l, r);
        return max(leftQuery, rightQuery);
    }

public:
    SegmentTree(int n)
    {
        size = n;
        tree.assign(4 * n, -1);
    }
    void update(int idx, int val)
    {
        update(1, 1, size, idx, val);
    }
    int query(int l, int r)
    {
        if (l > r)
            return -1;
        return query(1, 1, size, l, r);
    }
};

vector<int> findRightmostSmallerIndex(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n);
    SegmentTree st(n);

    // Process the array from right to left
    for (int i = n - 1; i >= 0; --i)
    {
        // Update the Segment Tree with the current element
        st.update(arr[i], i);

        // Query for the maximum index where the value is less than arr[i]
        int maxIndex = st.query(1, arr[i] - 1);

        // Assign the result
        result[i] = (maxIndex > i) ? maxIndex : i;
    }

    return result;
}

vector<int> findRightmostSmallerIndexUsingStack(const vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> result(n);
    // debug(n);
    for (int i = n - 1; i >= 0; i--)
    {
        // debug(i);
        // printStack(st);
        if (st.empty())
        {
            // debug("empty stack");
            st.push(i);
            result[i] = i;
            continue;
        }
        int top = st.top();
        if (v[i] <= v[top])
        {
            // debug("here");
            st.push(i);
            result[i] = i;
            continue;
        }
        // debug("else");
        // else
        stack<int> temp;
        while (!st.empty())
        {
            int top = st.top();
            if (v[top] < v[i])
            {
                result[i] = top;
                temp.push(top);
                st.pop();
            }
            else
                break;
        }
        // int stSize = st.size(), tempSize = temp.size();
        // if (stSize >= tempSize)
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        // else
        // {
        //     while (!st.empty())
        //     {
        //         temp.push(st.top());
        //         st.pop();
        //     }
        //     st = temp;
        // }
        // printStack(st);
    }
    return result;
}
vector<int> ans;
void solve(int index)
{
    if (ans[index])
    {
        return;
    }
    // debug(index);
    int right = minOnTheRight[index];
    int left = maxOnTheLeft[right];

    if (ans[left])
    {
        ans[index] = ans[left];
        return;
    }
    else
    {
        if (v[left] > v[index])
        {
            solve(left);
            ans[index] = ans[left];
        }
        else if (v[left] == v[index])
        {
            ans[index] = index;
        }
        return;
    }
}

void suraj()
{
    int n;
    cin >> n;
    ans = vector<int>(n, 0);
    minOnTheRight = vector<int>(n);
    maxOnTheLeft = vector<int>(n);
    gRight = vector<vector<int>>(n, vector<int>());
    gLeft = vector<vector<int>>(n, vector<int>());
    v = vector<int>(n);
    for (int &i : v)
        cin >> i;

    int mxVal = v[0], mxIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= mxVal)
        {
            mxVal = v[i];
            mxIndex = i;
        }
        maxOnTheLeft[i] = mxIndex;
    }

    // set<int> st;
    // int mnVal = v[n - 1], mnIndex = n - 1;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     st.insert(v[i]);
    //     // int firstEl = *st.begin(); // = v[i] if it is < mnVal
    //     if (v[i] < mnVal)
    //     { // this newly added element is the new smallest :)
    //         mnVal = v[i];
    //         mnIndex = i;
    //     }
    //     else if (v[i] == mnVal)
    //     {
    //         mnIndex = i;
    //     }
    //     minOnTheRight[i] = mnIndex;
    // }

    minOnTheRight = findRightmostSmallerIndex(v);
    // minOnTheRight = findRightmostSmallerIndexUsingStack(v);
    // debug(minOnTheRight);
    // deubg(st);
    // printStack(st);
    // debug(maxOnTheLeft);

    for (int i = 0; i < n; i++)
    {
        // ans[i] = v[i];
        // debug(ans);
        solve(i);
        cout << v[ans[i]] << " ";
    }
    cout << endl;
}
