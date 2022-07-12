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
//.....................................
bool isVowel(char c)
{
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return true;
  else
    return false;
}
//.....................................

//.....................................

void suraj()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<string> left, right;
  int prev = n - 1, cur = n - 1;

  int direction = 1; // -1 => left and 1 =>right
  while (cur >= 0)
  {
    if (direction == 1)
    {
      while (!isVowel(s[cur]))
      {
        if (cur == 0)
          break;
        cur--;
      }
      string temp = s.substr(cur, prev - cur + 1);
      // cout << "temp: " << temp << endl;
      right.pb(temp);
    }
    else
    {
      while (!isVowel(s[cur]))
      {
        if (cur == 0)
          break;
        cur--;
      }
      string temp = s.substr(cur, prev - cur + 1);
      // cout << "temp: " << temp << endl;
      reverse(temp.begin(), temp.end());
      // cout << "temp reversed: " << temp << endl;
      left.pb(temp);
    }
    direction *= -1;
    cur--;
    prev = cur;
  }
  for (auto el : left)
    cout << el;
  reverse(right.begin(), right.end());
  for (auto el : right)
    cout << el;
  cout << endl;
}
