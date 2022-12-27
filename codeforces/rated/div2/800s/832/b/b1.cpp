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
int inf = 1e18;
int mod = 1e9 + 7;
// int mod = 998244353;
//.....................................

//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;

  vector<char> v(n * 3);
  for (int i = 0; i < n * 3; i++)
  {
    if (i % 3 == 0)
    {
      v[i] = 'B';
    }
    else if (i % 3 == 1)
    {
      v[i] = 'A';
    }
    else if (i % 3 == 2)
    {
      v[i] = 'N';
    }
  }

  // for (auto el : v)
  //   cout << el;
  // cout << endl;

  if (n == 1)
    cout << 1 << endl
         << 1 << " " << 2 << endl;
  else if (n == 2)
    cout << 1 << endl
         << 2 << " " << 6 << endl;
  else
  {

    vector<pair<int, int>> swaps;
    int left = 1; // 0-index
    for (int i = n * 3 - 1; i >= 0 && left < i; i -= 3)
    {
      if (v[i] == 'N')
      {
        // cout << "i: " << i << endl;
        swaps.pb(make_pair(left, i));
        char temp = v[left];
        v[left] = v[i];
        v[i] = temp;
        left += 3;
        // if ((left + 1 <= 3 * n - 1) && (left + 1 < i) && v[left + 1] != 'N')
        // {
        //   left++;
        // }
        // else if ((left + 2 <= 3 * n - 1) && (left + 2 < i) && v[left + 2] != 'N')
        // {
        //   left += 2;
        // }
      }
    }
    // for (auto el : v)
    //   cout << el;
    // cout << endl;
    cout << swaps.size() << endl;
    for (auto el : swaps)
    {
      cout << el.first + 1 << " " << el.second + 1 << endl;
    }
  }
}
