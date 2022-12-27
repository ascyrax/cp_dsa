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
//.....................................

//.....................................
void print(vector<int> v)
{
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(vector<char> v)
{
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................
bool check(vector<char> v, int len)
{
  int lenv = v.size();
  if (lenv % len != 0)
    return false;
  for (int i = 0; i < lenv - len; i++)
  {
    if (v[i] != v[i + len])
      return false;
  }
  return true;
}
int findSmallestRepeatingUnit(vector<char> v)
{
  // cout << "findSmallestRepeatingUnit" << endl;
  int lenv = v.size();
  // i => length of the smallest repeated unit
  // e.g. for ababab => i = 2
  // e.g. for abccba => i = 6
  int ans = lenv;
  for (int i = 1; i <= lenv; i++)
  {
    // cout << "i = " << i << endl;
    if (check(v, i))
    {
      ans = i;
      break;
    }
  }
  // cout << "ans = " << ans << endl;
  return ans;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> v(n);
  for (int &i : v)
  {
    cin >> i;
    --i;
  }
  // cout << "-------------------------" << endl;

  vector<int> loopLengths;
  vector<bool> flag(n);

  vector<vector<char>> vLoopEls;
  for (int i = 0; i < n; i++)
  {
    if (flag[i])
      continue;
    vector<char> loopEls;
    int cnt = 1;
    int start = i;
    flag[start] = true;
    int next = v[i];
    loopEls.pb(s[i]);
    while (next != start)
    {
      cnt++;
      loopEls.pb(s[next]);
      flag[next] = true;
      next = v[next];
    }
    loopLengths.pb(cnt);
    vLoopEls.pb(loopEls);
  }

  // cout << "loopLengths" << endl;
  // print(loopLengths);
  for (int i = 0; i < loopLengths.size(); i++)
  {
    // cout << "i = " << i << endl;
    // cout << loopLengths[i] << endl;
    // cout << "loop chars =" << endl;
    // print(vLoopEls[i]);
    loopLengths[i] = findSmallestRepeatingUnit(vLoopEls[i]);
  }

  int ans = loopLengths[0];
  for (auto el : loopLengths)
    ans = ((ans * el) / __gcd(ans, el));
  cout << ans << endl;
}
