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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  set<int> sp, sq;
  for (int i = 1; i <= n; i++)
  {
    sp.insert(i);
    sq.insert(i);
  }
  vector<int> p(n), q(n);

  vector<pair<int, int>> vp, vq;
  for (int i = 0; i < n; i++)
  {
    // a[i]
    auto locsp = sp.find(a[i]);
    auto locsq = sq.find(a[i]);
    if (locsp != sp.end())
    {
      p[i] = a[i];
      sp.erase(locsp);
      vp.pb(mp(a[i], i));
    }
    else
    {
      if (locsq == sq.end())
      {
        cout << "NO" << endl;
        return;
      }
      q[i] = a[i];
      sq.erase(locsq);
      vq.pb(mp(a[i], i));
    }
  }
  sort(vq.begin(), vq.end());
  int ptr = 0;
  for (auto el : sp)
  {
    int val = vq[ptr].first;
    int index = vq[ptr].second;
    if (val < el)
    {
      cout << "NO" << endl;
      return;
    }
    else
    {
      p[index] = el;
    }
    ptr++;
  }

  sort(vp.begin(), vp.end());
  ptr = 0;
  for (auto el : sq)
  {
    int val = vp[ptr].first;
    int index = vp[ptr].second;
    if (val < el)
    {
      cout << "NO" << endl;
      return;
    }
    else
    {
      q[index] = el;
    }
    ptr++;
  }

  cout << "YES" << endl;
  for (auto el : p)
    cout << el << " ";
  cout << endl;
  for (auto el : q)
    cout << el << " ";
  cout << endl;
}
