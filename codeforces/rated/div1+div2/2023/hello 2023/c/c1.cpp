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

#ifndef ONLINE_JUDGE
  clock_t startTime = clock();
#endif

  // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

  // cout << setprecision(15) << fixed;

  fastio();

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
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }

  vector<int> ps(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    ps[i] = ps[i - 1] + v[i];
  }
  // debug(ps);

  set<int> st;
  int left = 0;
  // debug(ps[m]);

  st.insert(-v[m]);
  for (int i = m - 1; i >= 1; i--)
  {
    if (ps[i] < ps[m])
    {
      // debug(i);
      // debug(ps[i]);
      while (ps[m] > ps[i])
      {
        left++;
        // debug(left);
        int top = *(st.begin());
        // debug(top);
        ps[m] += 2 * top;
        // debug(ps[m]);
        st.erase(st.begin());
        // debug(st);
      }
    }
    if (v[i] > 0)
      st.insert(-1 * v[i]);
  }

  int right = 0;
  int psCurrent = ps[m];
  set<int> str;
  for (int i = m + 1; i <= n; i++)
  {
    if (v[i] < 0)
      str.insert(v[i]);
    psCurrent += v[i];
    // debug(i);
    if (psCurrent < ps[m])
    {
      // debug("if");
      while (psCurrent < ps[m])
      {
        right++;
        // debug(right);
        int top = *(str.begin());
        // debug(top);
        psCurrent += 2 * abs(top);
        // debug(psCurrent);
        str.erase(str.begin());
        // debug(str);
      }
    }
  }

  cout << left + right << endl;
}
