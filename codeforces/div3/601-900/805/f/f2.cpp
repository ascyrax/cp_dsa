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
  multiset<int> a, b;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    while (temp % 2 == 0)
      temp /= 2;
    a.insert(temp);
  }
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    while (temp % 2 == 0)
      temp /= 2;
    b.insert(temp);
  }
  vector<int> vb;
  for (auto el : b)
    vb.pb(el);
  sort(vb.begin(), vb.end());

  for (int i = 0; i < n; i++)
  {
    int val = vb[i];
    auto it = a.find(val);
    bool flag = false;
    while (val >= 1)
    {
      if (it == a.end())
      {
        val /= 2;
        it = a.find(val);
      }
      else if (*it == val)
      {
        flag = true;
        a.erase(it);
        break;
        // b.erase(b.find(vb[i]));
      }
    }
    if (!flag)
    {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
