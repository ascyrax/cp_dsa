// @author: ascyrax

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>

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

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

vector<vector<int>> graph;
queue<int> evens;
vector<int> nodeValues;
vector<int> visited;
queue<int> bfsQ;
bool flag;

void bfs()
{
    while (!bfsQ.empty())
    {
        // cout << "bfsQ: ";
        // printQueue(bfsQ);
        int curNode = bfsQ.front();
        bfsQ.pop();
        int nodeValue = nodeValues[curNode];
        vector<int> neighs = graph[curNode];
        for (int neigh : neighs)
        {
            if (!visited[neigh])
            {
                visited[neigh] = 1;

                bfsQ.push(neigh);

                vector<int> temp;

                while (!evens.empty()) // todo check for infinite loop :)
                {
                    int topEven = evens.front();
                    if (abs(topEven - nodeValue) > 2)
                    {
                        nodeValues[neigh] = topEven;
                        evens.pop();
                        break;
                    }
                    else
                    {
                        temp.push_back(topEven);
                        if (evens.size() == 1)
                        {
                            flag = false;
                            return;
                        }
                        evens.pop();
                    }
                }
                for (int el : temp)
                    evens.push(el);
            }
        }
    }
    return;
}

void suraj()
{
    int n;
    cin >> n;
    graph = vector<vector<int>>(n, vector<int>());
    nodeValues = vector<int>(n);
    visited = vector<int>(n, 0);
    bfsQ = queue<int>();
    flag = false;

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int el = 2; el <= 2 * n; el += 2)
    {
        evens.push(el);
    }

    visited[0] = 1;
    nodeValues[0] = 2;
    evens.pop(); // pop 2 ie the first element of the queue evens
    bfsQ.push(0);

    bfs();

    if (!flag)
    {
        cout << -1 << endl;
        return;
    }

    for (int el : nodeValues)
        cout << el << " ";
    cout << endl;
}
