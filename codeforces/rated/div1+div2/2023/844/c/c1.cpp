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

bool isValidChar(char ch, vector<pair<int, char>> vp_)
{
  for (auto el : vp_)
    if (el.second == ch)
      return true;
  return false;
}

void modifyvp_(char ch, vector<pair<int, char>> &vp_)
{
  for (int i = 0; i < vp_.size(); i++)
  {
    auto &el = vp_[i];
    if (el.second == ch)
    {
      // debug(el);
      el.first--;
      // debug(el);
      if (el.first == 0)
        vp_.erase(vp_.begin() + i);
      return;
    }
  }
}
void modifyTemp(string &temp, vector<pair<int, char>> &vp_, int j)
{
  temp[j] = vp_[0].second;
  vp_[0].first--;
  if (vp_[0].first == 0)
    vp_.erase(vp_.begin());

  return;
}

void suraj()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  map<char, int> m;
  for (auto el : s)
    m[el]++;
  // debug(m);

  set<pair<int, char>> st;
  for (auto el : m)
    st.insert(mp(-el.second, el.first));
  // debug(st);

  vector<pair<int, char>> vp;
  for (auto el : st)
    vp.pb(mp(-el.first, el.second));
  debug(vp);

  string alphabets = "abcdefghijklmnopqrstuvwxyz";

  for (auto el : alphabets)
    if (m.count(el) == 0)
      vp.pb(mp(0, el));
  // debug(vp);

  int mnStepsReq = INF;
  string ans = s;
  for (int i = 1; i <= min(n, 26ll); i++)
  { // i different characters in the whole string
    int stepsReq = 0;
    string temp = s;

    // sort(temp.begin(), temp.end());

    if (n % i != 0)
      continue;

    int freq = n / i;

    vector<pair<int, char>> vp_;
    for (int j = 1; j <= i; j++)
      vp_.pb(mp(freq, vp[j - 1].second));

    // debug(i);

    // debug(vp_);

    vector<bool> flag(n, false);
    // remove all the desired chars first
    // debug(temp);
    for (int j = 0; j < n; j++)
    {
      char ch = temp[j];
      // debug(ch);
      if (isValidChar(ch, vp_))
      {
        // debug("if");
        // debug(ch);
        flag[j] = true;
        modifyvp_(ch, vp_);
      }
      // debug(j);
      // debug(vp_);
    }

    // now all the left chars need to be modified
    for (int j = 0; j < n; j++)
      if (!flag[j])
      {
        modifyTemp(temp, vp_, j);
        stepsReq++;
      }
    // for (int j = 0; j < n; j++)
    // {
    //   char ch = temp[j];
    //   modify2vp_(ch, vp_);
    // }

    if (stepsReq < mnStepsReq)
    {
      mnStepsReq = stepsReq;
      ans = temp;
    }
    // debug(mnStepsReq);
    // debug(ans);
  }
  cout << mnStepsReq << endl;
  cout << ans << endl;
  debug("----");
}
