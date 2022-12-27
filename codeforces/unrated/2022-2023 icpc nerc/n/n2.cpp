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

  // ioss

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
  int lens = s.size();
  int k;
  cin >> k;

  vector<stack<int>> indicesOf(10, stack<int>());

  for (int i = lens - 1; i >= 0; i--)
  {
    indicesOf[s[i] - '0'].push(i);
  }

  int ptrLeft = -1;

  vector<bool> ans(lens, false);

  for (int i = 1; i <= 9; i++)
  {
    if (indicesOf[i].size() > 0)
    {
      int leftMostIndex = indicesOf[i].top();
      if (leftMostIndex == k)
      {
        cout << s.substr(leftMostIndex) << endl;
        return;
      }
      else if (leftMostIndex < k)
      {
        k++;
        ptrLeft = leftMostIndex;
        ans[leftMostIndex] = true;
        indicesOf[i].pop();
        break;
      }
    }
  }
  // for (auto el : ans)
  //   cout << el << " ";
  // cout << endl;
  // cout << "ans" << endl;
  // for (int i = 0; i < lens; i++)
  //   if (ans[i])
  //     cout << s[i];
  // cout << endl;
  bool outerRepeat = false, whileBreak = false;
  while (1)
  {
    outerRepeat = false;
    if (k >= lens)
      break;
    for (int i = 0; i <= 9; i++)
    {
      // cout << "i " << i << endl;
      while (indicesOf[i].size() > 0)
      {

        int leftMostIndex = indicesOf[i].top();
        // cout << "lmi " << leftMostIndex << endl;
        if (leftMostIndex < ptrLeft)
        {
          indicesOf[i].pop();
          continue;
        }
        else
        {
          if (leftMostIndex < k)
          {
            ptrLeft = leftMostIndex;
            k++;
            ans[leftMostIndex] = true;
            outerRepeat = true;
            indicesOf[i].pop();
            break;
          }
          else if (leftMostIndex == k)
          {
            ptrLeft = leftMostIndex;
            ans[leftMostIndex] = true;
            whileBreak = true;
            break;
          }
          else
          {
            break;
          }
        }
      }
      if (whileBreak || outerRepeat)
        break;
    }
    // cout << "ans" << endl;
    // for (auto el : ans)
    //   cout << el << " ";
    // cout << endl;
    // for (int i = 0; i < lens; i++)
    //   if (ans[i])
    //     cout << s[i];
    // cout << endl;
    if (whileBreak)
      break;
  }

  for (int i = k; i < lens; i++)
    ans[i] = true;

  for (int i = 0; i < lens; i++)
    if (ans[i])
      cout << s[i];
  cout << endl;
}
