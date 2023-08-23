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

    debug("---");
  }

#ifndef ONLINE_JUDGE
  cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

  return 0;
}

bool check(int m, vector<pair<int, int>> &rl, int s)
{
  int n = rl.size();
  int left = 0, right = 0;
  int leftSum = 0, rightSum = 0;
  vector<int> temp;
  for (auto el : rl)
  {
    int l = el.second;
    int r = el.first;
    if (r >= m)
    {
      if (l >= m)
      {
        right++;
        rightSum += l;
      }
      else // l < m
        temp.pb(l);
    }
    else
    {
      left++;
      leftSum += l;
    }
  }

  // debug(left);
  // debug(right);
  // debug(leftSum);
  // debug(rightSum);
  // debug(temp);

  if (right > n / 2 + 1)
    return false;
  else if (right == n / 2 + 1)
  {
    for (auto el : temp)
      leftSum += el;
    // debug(leftSum);
    return (leftSum + rightSum <= s);
  }
  else if (right < n / 2 + 1)
  {
    if (left > n / 2)
      return false;

    sort(temp.begin(), temp.end());
    int ptr = 0;
    while (left < n / 2)
    {
      leftSum += temp[ptr];
      left++;
      ptr++;
    }
    while (right < n / 2)
    {
      right++;
      rightSum += m;
    }
    return (leftSum + m + rightSum <= s);
  }
}

void suraj()
{
  int n, s;
  cin >> n >> s;

  vector<pair<int, int>> rl;
  vector<int> vl, vr;
  for (int i = 0; i < n; i++)
  {
    int l, r;
    cin >> l >> r;
    rl.pb(mp(r, l));
    vl.pb(l);
    vr.pb(r);
  }

  sort(rl.rbegin(), rl.rend());
  sort(vl.begin(), vl.end());

  int l = vl[n / 2], r = 1e9;

  while (l < r)
  {
    int m = l + (r - l) / 2;
    // debug(l);
    // debug(m);
    // debug(r);
    if (r - l == 1)
    {
      if (check(r, rl, s))
        l = r;
      else
        r = l;
      break;
    }
    bool checkVal = check(m, rl, s);

    if (checkVal)
    {
      // debug("true");
      l = m;
      r = r;
    }
    else
    {
      // debug("false");
      r = m - 1;
      l = l;
    }
  }

  cout << l << endl;
}
