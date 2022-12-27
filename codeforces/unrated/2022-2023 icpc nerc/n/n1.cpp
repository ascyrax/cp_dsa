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
  string s;
  cin >> s;
  int k;
  cin >> k;

  int lens = s.size();

  vector<stack<int>> indicesOf(10, stack<int>());

  for (int j = lens - 1; j >= 0; j--)
  {
    indicesOf[s[j] - '0'].push(j);
  }

  // for (int i = 0; i <= 9; i++)
  // {
  //   auto temp = indicesOf[i];
  //   cout << "i " << i << endl;
  //   while (!temp.empty())
  //   {
  //     int top = temp.top();
  //     cout << top << " ";
  //     temp.pop();
  //   }
  //   cout << endl;
  // }

  vector<bool> ans(lens, false);
  int leftBoundary = -1;
  int last = -1;
  bool flag = false;
  bool check = false;
  while (!flag)
  {
    for (int i = 0; i <= 9; i++)
    {
      if (!check && i == 0)
        continue;
      if (i == last)
      {
        flag = true;
        break;
      }
      if (indicesOf[i].size() == 0)
        continue;
      bool loop = true;
      while (loop)
      {
        if (indicesOf[i].size() == 0)
          break;
        int leftMostIndex = indicesOf[i].top();
        // cout << "leftMostIndex of " << i << " is " << leftMostIndex << endl;
        if (leftMostIndex <= k && leftMostIndex > leftBoundary)
        {
          check = true;
          last = i;
          // cout << "if" << endl;
          indicesOf[i].pop();
          ans[leftMostIndex] = true;
          leftBoundary = leftMostIndex;
          if (leftMostIndex < k)
            k++;
          else
          {
            k += 0;
            break;
          }
        }
        if (leftMostIndex < leftBoundary)
        {
          indicesOf[i].pop();
        }
        if (leftMostIndex > k)
        {
          loop = false;
        }
      }
    }
  }

  for (int i = k; i < lens; i++)
    ans[i] = true;

  for (int i = 0; i < lens; i++)
  {
    if (ans[i])
      cout << s[i];
  }
  cout << endl;
}
