// @author: ascyrax

#include <bits/stdc++.h>

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

void suraj()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int mxPos = -21, mnNeg = 21;
    int cntPos = 0, cntNeg = 0, cntZero = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            cntPos++;
            mxPos = max(mxPos, v[i]);
        }
        else if (v[i] < 0)
        {
            cntNeg++;
            mnNeg = min(mnNeg, v[i]);
        }
        else
        {
            cntZero++;
        }
    }

    if (cntPos * cntNeg == 0)
    {
        cout << n - 1 << endl;
        if (cntNeg == 0)
        {
            for (int i = 1; i < n; i++)
            {
                cout << i << " " << i + 1 << endl;
            }
        }
        else if (cntPos == 0)
        {
            for (int i = n - 1; i >= 1; i--)
            {
                cout << i << " " << i + 1 << endl;
            }
        }
        return;
    }
    int ans = 0, index = -1;
    if (abs(cntPos - cntNeg) > 4)
    {
        if (cntPos > cntNeg)
        {
            int temp = 0;
            while (mxPos < abs(mnNeg))
            {
                mxPos *= 2;
                ans++;
                temp++;
            }
            ans += cntNeg;
            cout << ans + 19 << endl;
            for (int i = 0; i < n; i++)
                if (v[i] == mxPos)
                    index = i;
            while (temp--)
                cout << index + 1 << " " << index + 1 << endl;
            for (int i = 0; i < n; i++)
                if (v[i] < 0)
                    cout << i + 1 << " " << index + 1 << endl;
            for (int i = 1; i < n; i++)
                cout << i << " " << i + 1 << endl;
        }
        else if (cntNeg > cntPos)
        {
            int temp = 0;
            while (abs(mnNeg) < mxPos)
            {
                mnNeg *= 2;
                ans++;
                temp++;
            }
            ans += cntPos;
            cout << ans + 19 << endl;
            for (int i = 0; i < n; i++)
                if (v[i] == mnNeg)
                    index = i;
            while (temp--)
                cout << index + 1 << " " << index + 1 << endl;
            for (int i = 0; i < n; i++)
                if (v[i] > 0)
                    cout << i + 1 << " " << index + 1 << endl;
            for (int i = n - 1; i >= 1; i++)
                cout << i << " " << i + 1 << endl;
        }
        return;
    }

    if (abs(mnNeg) > mxPos)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] > 0)
            {
                ans++;
            }
            if (v[i] == mnNeg)
                index = i;
        }
        cout << ans + 19 << endl;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > 0)
                cout << (i + 1) << " " << (index + 1) << endl;
        }
        for (int i = n - 1; i >= 1; i--)
        {
            cout << i << " " << i + 1 << endl;
        }
    }
    else if (mxPos >            abs(mnNeg))
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] < 0)
                ans++;
            if (v[i] == mxPos)
                index = i;
        }
        cout << ans + 19 << endl;
        for (int i = 0; i < n; i++)
        {
            if (v[i] < 0)
                cout << i + 1 << " " << index + 1 << endl;
        }
        for (int i = 1; i < n; i++)
            cout << i << " " << i + 1 << endl;
    }
}
