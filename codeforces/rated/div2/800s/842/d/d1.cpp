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

  // fastio();

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
  vector<int> v(n + 1);
  map<int, int> indexOf, valueAt;
  for (int i = 1; i <= n; i++)
  {
    cin >> v[i];
    indexOf[v[i]] = i;
    valueAt[i] = v[i];
  }

  vector<bool> handled(n + 1, false);
  vector<pair<int, vector<pair<int, int>>>> temp;
  for (int i = 1; i <= n; i++)
  {
    if (handled[i])
    {
      continue;
    }
    if (v[i] == i)
      continue;
    vector<pair<int, int>> vp; // mp(index, value)
    int val = v[i];
    vp.pb(mp(i, v[i]));
    int nextIndex, valAtNextIndex = v[i], prevIndex = i;
    handled[i] = true;
    while (1)
    {
      nextIndex = valAtNextIndex;
      if (handled[nextIndex])
        break;
      handled[nextIndex] = true;
      valAtNextIndex = valueAt[nextIndex];
      vp.pb(mp(nextIndex, valAtNextIndex));
      if (valAtNextIndex == prevIndex)
        break;
    }
    sort(vp.begin(), vp.end());
    temp.pb(mp(vp.size(), vp));
  }

  sort(temp.rbegin(), temp.rend());

  for (auto &el : temp)
    sort(el.second.begin(), el.second.end());

  debug(temp);

  bool flag = true;
  int ans = 0;
  for (auto el : temp)
  {
    int lenvp = el.first;
    vector<pair<int, int>> vp = el.second;
    debug(vp);
    if (flag)
    {
      for (int i = 1; i < lenvp; i++)
      {
        if (vp[i].first == vp[i - 1].first + 1)
        {
          debug("if");
          ans += (lenvp - 1) - 1;
          flag = false;
          break;
        }
      }
      if (flag)
      {
        ans += lenvp - 1;
      }
    }
    else
    {
      debug("else");
      ans += lenvp - 1;
    }
    debug(ans);
  }
  if (flag)
  {
    ans++;
  }

  cout << ans << endl;
  debug("------");
}