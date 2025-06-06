// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define fastio()                    \
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
#define debug(x)     \
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
  }

#ifndef ONLINE_JUDGE
  cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

  return 0;
}

void suraj()
{
  int l, r;
  cin >> l >> r;

  vector<int> cnt1(17, 0), cnt2(17, 0); // 0 to 16

  for (int i = l; i <= r; i++)
  {
    int bitIndex = 0;
    while ((1 << bitIndex) <= i)
    {
      if ((1 << bitIndex) & i)
      {
        cnt1[bitIndex]++;
      }
      bitIndex++;
    }
    int el;
    cin >> el;
    bitIndex = 0;
    while ((1 << bitIndex) <= el)
    {
      if ((1 << bitIndex) & el)
      {
        cnt2[bitIndex]++;
      }
      bitIndex++;
    }
  }
  int len = r - l + 1;
  int x = 0;
  for (int i = 0; i <= 16; i++)
  {
    int initialOnes = cnt1[i];
    int initialZeros = len - initialOnes;

    int finalOnes = cnt2[i];
    int finalZeros = len - finalOnes;

    if (initialOnes > initialZeros)
    {
      if (finalOnes > finalZeros)
        x += 0;
      else
        x += (1 << i);
    }
    else if (initialOnes < initialZeros)
    {
      if (finalOnes > finalZeros)
        x += (1 << i);
      else
        x += 0;
    }
    else if (initialOnes == initialZeros)
    {
      x += (1 << i);
    }
  }
  cout << x << endl;
}
