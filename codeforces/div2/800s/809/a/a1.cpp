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
void print(string s, vector<char> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el;
  cout << endl;
}
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................
vector<char> s;
//.....................................
void change(int index)
{
  cout << "index: " << index << endl;
  if (s[index] == 'A')
    s[index] = 'B';
  else
    s[index] = 'A';
}
//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  s = vector<char>(m, 'B');
  for (int i = 0; i < n; i++)
  {
    // cout << "i: " << i << endl;
    if (a[i] <= (m - 1) / 2)
    {
      // cout << "if" << endl;
      if (s[a[i]] == 'A')
        // change(m - 1 - a[i]);
        s[m - 1 - a[i]] = 'A';
      else
        s[a[i]] = 'A';
    }
    else
    {
      // cout << "else" << endl;
      if (s[m - 1 - a[i]] == 'A')
        // change(a[i]);
        s[a[i]] = 'A';
      else
        s[m - 1 - a[i]] = 'A';
    }
    // print("s", s);
  }
  for (auto el : s)
    cout << el;
  cout << endl;
}
