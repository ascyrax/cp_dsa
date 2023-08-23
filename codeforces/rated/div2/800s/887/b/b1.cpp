// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// #define MOD 1000000007
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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
typedef vector<vector<long long>> matrix;

const long long MOD = 1000000007; // If you need to calculate Fibonacci modulo some value, update this constant.

matrix multiply(matrix A, matrix B, long long mod = 0)
{
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();

    matrix result(rows_A, vector<long long>(cols_B, 0));

    for (int i = 0; i < rows_A; i++)
    {
        for (int j = 0; j < cols_B; j++)
        {
            for (int k = 0; k < cols_A; k++)
            {
                if (mod == 0)
                {
                    result[i][j] += A[i][k] * B[k][j];
                }
                else
                {
                    result[i][j] = (result[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
                }
            }
        }
    }

    return result;
}

matrix matrix_power(matrix m, long long n, long long mod = 0)
{
    if (n == 1)
    {
        return m;
    }

    matrix half_power = matrix_power(m, n / 2, mod);
    matrix result = multiply(half_power, half_power, mod);

    if (n % 2 == 1)
    {
        result = multiply(result, m, mod);
    }

    return result;
}

long long fib(long long k, long long mod = 0)
{
    if (k == 0)
    {
        return 0;
    }
    else if (k == 1)
    {
        return 1;
    }

    matrix M = {{1, 1}, {1, 0}};
    matrix result = matrix_power(M, k - 1, mod);

    return result[0][0];
}

void suraj()
{
    int n, k;
    cin >> n >> k;

    int normalFibK = fib(k-1), normalFibKMinus1 = fib(k - 1-1); // 0 1 1 2 3 5 8 13
    int diff = n - normalFibK;
    cout<<"fib(x):"<< fib(30)<<endl;
    if (diff < 0)
        cout << 0 << endl;
    else if (diff == 0)
        cout << 1 << endl;
    else // since n<=2e5, => k should be always less than sth around 30
    {
        // +a at index0 leads to + a+0+a+a+2a+3a+5a+8a...+a*fib(k-1-1) till index k
        // +b at index1 leads to + 0+b+b+2b+3b+5b+8b+...+b*fib(k-1) till index k
        int ans = 0;
        for (int b = 1; b <= n; b++)
        {
            for (int a = 0; a < b; a++)
            {
                if (a * normalFibKMinus1 + b * normalFibK == diff)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
}
