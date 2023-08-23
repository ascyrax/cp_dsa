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
template <class T>
void _print(stack<T> st)
{
  // cerr << "[ ";
  vector<T> v;
  while (!st.empty())
  {
    v.pb(st.top());
    // _print(st.top());
    // cerr << " ";
    st.pop();
  }
  // cerr << "]";
  reverse(v.begin(), v.end());
  _print(v);
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
  vector<int> a(n), b(n);
  for (int &i : a)
    cin >> i;
  for (int &i : b)
    cin >> i;
  int m;
  cin >> m;
  vector<int> x(m);
  map<int, int> sCnt; // scissors cnt
  for (int &i : x)
  {
    cin >> i;
    sCnt[i]++;
  }
  // debug(sCnt);

  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    // debug(mp(i, b[i]));
    if (b[i] > a[i])
    {
      cout << "NO" << endl;
      return;
    }
    // debug(st);
    // debug(sCnt);
    while (!st.empty())
    {
      // debug("while");
      if (st.top() < b[i])
      {
        int top = st.top();
        st.pop();
        if (sCnt.count(top) == 0)
        {
          cout << "NO" << endl;
          return;
        }
        else
        {
          if (sCnt[top] == 0)
          {
            cout << "NO" << endl;
            return;
          }
          else
          {
            sCnt[top]--;
          }
        }
      }
      else
        break;
    }
    // debug(st);
    // debug(sCnt);
    if (st.empty() && b[i] < a[i])
      st.push(b[i]);
    else if (!st.empty() && st.top() != b[i] && b[i] < a[i])
      st.push(b[i]);
  }
  while (!st.empty())
  {
    int top = st.top();
    if (sCnt.count(top) > 0)
    {
      if (sCnt[top] > 0)
      {
        sCnt[top]--;
      }
      else
      {
        cout << "NO" << endl;
        return;
      }
    }
    else
    {
      cout << "NO" << endl;
      return;
    }
    st.pop();
  }
  cout << "YES" << endl;
}
