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

    debug("---");
  }

#ifndef ONLINE_JUDGE
  cerr << "Execution Time : " << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << endl;
#endif

  return 0;
}
int n, m;
vector<int> vSmartness;
vector<set<int>> chapterExperts;
int choiceLeft = INF, choiceRight = -1;
int setOfSizeOne = 0, smallestSetSize = n, smallestSetChapterNumber = -1;

int solve()
{
  int leftMost = choiceLeft, rightMost = choiceRight;
  for (int i = 1; i <= m; i++)
  {
    debug(i);
    set<int> sTemp = chapterExperts[i];
    debug(sTemp);
    auto itLeft = sTemp.lower_bound(choiceLeft);

    if (itLeft != sTemp.end())

      leftMost = min(leftMost, *(itLeft));
    if (itLeft != sTemp.begin())
      leftMost = min(leftMost, *(--itLeft));

    auto itRight = sTemp.lower_bound(choiceRight);
    if (itRight != sTemp.end())
      rightMost = max(rightMost, *(itRight));
    if (itRight != sTemp.begin())
      rightMost = max(rightMost, *(--itRight));

    debug(leftMost);
    debug(rightMost);
  }

  // considering we take both leftmost and the rightmost
  int ans = rightMost - leftMost;

  // considering we take only leftmost. gotta check if this is possible or not

  // considering we take only rightmost. gotta check if this is possible or not
  return ans;
}

void suraj()
{
  choiceLeft = INF, choiceRight = -1;
  setOfSizeOne = 0, smallestSetSize = n, smallestSetChapterNumber = -1;

  cin >> n >> m;

  vSmartness = vector<int>(n);
  for (int &i : vSmartness)
    cin >> i;

  chapterExperts = vector<set<int>>(m + 1, set<int>());

  for (auto smartness : vSmartness)
  {
    // debug(smartness);
    for (int i = 1; i * i <= smartness; i++)
    {
      if (i > m)
        continue;
      if ((smartness % i) == 0)
      {
        // debug(i);
        if (i <= m)
          chapterExperts[i].insert(smartness);
        if (smartness / i <= m)
          chapterExperts[smartness / i].insert(smartness);
        // debug(chapterExperts);
      }
    }
  }

  debug(vSmartness);
  debug(chapterExperts);

  for (int i = 1; i <= m; i++)
  {
    debug(i);
    set<int> sTemp = chapterExperts[i];
    debug(sTemp);
    if (sTemp.size() == 0)
    {
      cout << -1 << endl;
      return;
    }
    else if (sTemp.size() == 1)
    {
      choiceLeft = min(choiceLeft, *(sTemp.begin()));
      choiceRight = max(choiceRight, *(sTemp.begin()));
      setOfSizeOne++;
    }
    else
    {
      if (sTemp.size() < smallestSetSize)
      {
        smallestSetSize = min(smallestSetSize, (int)sTemp.size());
        smallestSetChapterNumber = i;
      }
    }
    debug(choiceLeft);
    debug(choiceRight);
  }
  int ans = 0;
  if (setOfSizeOne == 0)
  {
    debug("if");
    // iterate over the smallest set
    set<int> sTemp = chapterExperts[smallestSetChapterNumber];
    for (auto el : sTemp)
    {
      choiceLeft = el;
      choiceRight = el;
      ans = min(ans, solve());
    }
  }
  else
  {
    debug("else");
    ans = solve();
  }
  cout << ans << endl;
}
