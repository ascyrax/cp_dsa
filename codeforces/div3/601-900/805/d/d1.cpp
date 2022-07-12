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
  string s;
  cin >> s;
  int p;
  cin >> p;

  int lens = s.size();
  vector<int> cnt(26, 0);
  int sum = 0;
  for (int i = 0; i < lens; i++)
  {
    cnt[s[i] - 'a']++;
    sum += ((s[i] - 'a') + 1);
  }
  if (sum <= p)
  {
    cout << s << endl;
    return;
  }
  // cout << "sum: " << sum << endl;
  // print("cnt", cnt);

  int ptr = 25;
  while (sum > p)
  {
    char tempChar = ('a' + ptr);
    // cout << "ptr: " << ptr << " " << tempChar << endl;
    // cout << "sum: " << sum << endl;
    int diff = sum - p;
    int valChar = cnt[ptr] * (ptr + 1);
    // cout << "valChar: " << valChar << endl;
    // cout << "diff: " << diff << endl;
    if (valChar > diff)
    {
      // cout << "if" << endl;
      int q = (valChar - diff) / (ptr + 1);
      // int r = (valChar - diff) % (ptr + 1);
      // cout << "q: " << q << " , r: " << r << endl;
      // if (r > 0)
      //   q++;
      // cout << "q: " << q << endl;
      cnt[ptr] = q;
      break;
    }
    else if (valChar == diff)
    {
      // cout << "else if" << endl;
      cnt[ptr] = 0;
      break;
    }
    else if (valChar < diff)
    {
      // cout << "else if 2 " << endl;
      sum -= valChar;
      cnt[ptr] = 0;
      ptr--;
    }
  }
  vector<bool> flag(lens, true);
  for (int i = 0; i < lens; i++)
  {
    int ch = s[i] - 'a';
    if (cnt[ch] > 0)
    {
      cnt[ch]--;
    }
    else if (cnt[ch] == 0)
    {
      flag[i] = false;
    }
  }
  for (int i = 0; i < lens; i++)
  {
    if (flag[i])
      cout << s[i];
  }
  cout << endl;
}
