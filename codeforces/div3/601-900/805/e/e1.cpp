// @author: ascyrax
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define ioss                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

double startTime;

double gct() // get_current_time
{
  return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

void suraj();

signed main()
{

  ioss

      // startTime=(double)clock();

      // freopen("shell.in","r",stdin);freopen("shell.out","w",stdout);

      // cout << setprecision(15) << fixed;

      int t = 1;

  cin >> t;

  for (int i = 1; i <= t; i++)
  {

    // cout<<"Case #"<<i<<": ";

    suraj();
  }

  return 0;
}

int inf = 1e18;
int mod = 1e9 + 7;
//.....................................

void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
void print(string s, vector<pair<int, int>> vp)
{
  cout << s << endl;
  for (auto el : vp)
  {
    cout << el.first << " " << el.second << endl;
  }
}
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<pair<int, int>> vp;
  bool flag = true; // corresponds to the answer as YES
  map<int, int> cnt;
  map<pair<int, int>, int> cntPairs;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    if (a == b)
      flag = false;
    cnt[a]++;
    cnt[b]++;
    if (cnt[a] >= 3 || cnt[b] >= 3)
      flag = false;
    cntPairs[make_pair(min(a, b), max(a, b))]++;
    vp.pb(make_pair(min(a, b), max(a, b)));
  }

  if (!flag)
  {
    cout << "NO" << endl;
    return;
  }

  int lenvp = vp.size(); // = n obviously
  set<int> sa, sb;
  map<int, int> setCount;
  for (int i = 0; i < lenvp; i++)
  {

    int a = vp[i].first;
    int b = vp[i].second;

    if (cntPairs[vp[i]] == 2)
      continue;
    // cout << "i:::::::::::::::: " << i << endl;
    // cout << "a: " << a << " , b: " << b << endl;
    // print("sa", sa);
    // print("sb", sb);

    if (sa.empty() && sb.empty())
    {
      // cout << "if:" << endl;
      sa.insert(a);
      sa.insert(b);
      setCount[a]++;
      setCount[b]++;
    }
    else if (sa.empty())
    {
      // cout << "else if: 1" << endl;
      sa.insert(a);
      sa.insert(b);
      setCount[a]++;
      setCount[b]++;
      if (setCount[a] == 2)
      {
        sa.erase(sa.find(a));
        sb.erase(sb.find(a));
        setCount[a] = 0;
      }
      if (setCount[b] == 2)
      {
        sa.erase(sa.find(b));
        sb.erase(sb.find(b));
        setCount[b] = 0;
      }
    }
    else if (sb.empty())
    {
      // cout << "else if: 2" << endl;
      sb.insert(a);
      sb.insert(b);
      setCount[a]++;
      setCount[b]++;
      if (setCount[a] == 2)
      {
        sa.erase(sa.find(a));
        sb.erase(sb.find(a));
        setCount[a] = 0;
      }
      if (setCount[b] == 2)
      {
        sa.erase(sa.find(b));
        sb.erase(sb.find(b));
        setCount[b] = 0;
      }
    }
    else
    {
      // cout << "else:: " << endl;
      // none is empty
      // auto it1 = sb.find(a);
      // auto it2 = sb.find(b);
      // cout << "*it1: " << (*it1) << "  "
      // << "sb.find(a)==sb.end() or not: " << (sb.find(a) == sb.end()) << endl;
      // cout << "*it2: " << (*it2) << "  "
      // << "sb.find(b)==sb.end() or not: " << (sb.find(b) == sb.end()) << endl;

      if ((sa.find(a) == sa.end()) && (sa.find(b) == sa.end()))
      {
        // cout << "E if" << endl;
        // ab can go to sa
        sa.insert(a);
        sa.insert(b);
        setCount[a]++;
        setCount[b]++;
        if (setCount[a] == 2)
        {
          sa.erase(sa.find(a));
          sb.erase(sb.find(a));
          setCount[a] = 0;
        }
        if (setCount[b] == 2)
        {
          sa.erase(sa.find(b));
          sb.erase(sb.find(b));
          setCount[b] = 0;
        }
      }
      else if ((sb.find(a) == sb.end()) && (sb.find(b) == sb.end()))
      {
        // cout << "E else if" << endl;
        // ab can go to sb
        sb.insert(a);
        sb.insert(b);
        setCount[a]++;
        setCount[b]++;
        if (setCount[a] == 2)
        {
          sa.erase(sa.find(a));
          sb.erase(sb.find(a));
          setCount[a] = 0;
        }
        if (setCount[b] == 2)
        {
          sa.erase(sa.find(b));
          sb.erase(sb.find(b));
          setCount[b] = 0;
        }
      }
      else
      {
        // cout << "E else " << endl;
        // a and b can go to neither of the set
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
}
