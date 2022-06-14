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
bool custom(string &a, string &b)
{
  // initially  .... b a .... (positioning of the elements)
  if (a.size() < b.size()) // a will be swapped to the left of b.
    return true;
  else if (a.size() == b.size())
  {
    if (a[0] < b[0])
      return true;
    else if (a[0] == b[0])
    {
      return false;
    }
    else if (a[0] > b[0])
      return false;
  }
  else if (a.size() > b.size())
    return false; // i.e. a will remain on the right of b
}
//.....................................
void print(string s, vector<string> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................

void suraj()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  string s;
  cin >> s;

  int cntA = 0, cntB = 0;

  for (char c : s)
  {
    if (c == 'A')
      cntA++;
    else
      cntB++;
  }
  if (cntA != a + c + d)
  {
    cout << "NO" << endl;
    return;
  }

  int lens = s.size();

  // vector<string> v;

  // char prevChar = s[0];
  vector<string> even, odd;
  int ptrBegin = 0;
  for (int i = 1; i < lens; i++)
  {
    if (s[i] == s[i - 1])
    {
      string temp = s.substr(ptrBegin, i - ptrBegin);
      if (temp.size() & 1)
        odd.pb(temp);
      else
        even.pb(temp);
      ptrBegin = i;
    }
  }
  string temp = s.substr(ptrBegin);
  if (temp.size() & 1)
    odd.pb(temp);
  else
    even.pb(temp);
  // v.pb(s.substr(ptrBegin));

  // for (string el : v)
  // {
  //   if (el.size() & 1)
  //     odd.pb(el);
  //   else
  //     even.pb(el);
  // }

  sort(even.begin(), even.end(), custom);
  sort(odd.begin(), odd.end(), custom);

  // print("v", v);
  // print("even", even);
  // print("odd", odd);
  // cout << "-------------------------" << endl;

  for (int i = 0; i < even.size(); i++)
  {
    if (even[i][0] == 'A')
    {
      int cntAB = even[i].size() / 2;
      if (cntAB == c)
        c = 0;
      else if (cntAB > c)
      {
        int del = cntAB - c;
        if (del > 1)
        {
          // a--;
          string temp = even[i].substr(c * 2);
          odd.pb(temp.substr(0, temp.size() - 1));
          b--;
        }
        else
        {
          a--;
          b--;
        }
        c = 0;
      }
      else if (cntAB < c)
        c -= cntAB;
    }
    else
    {
      int cntBA = even[i].size() / 2;
      if (cntBA == d)
        d = 0;
      else if (cntBA > d)
      {
        int del = cntBA - d;
        if (del > 1)
        {
          // b--;
          string temp = even[i].substr(d * 2);
          odd.pb(temp.substr(0, temp.size() - 1));
          a--;
        }
        else
        {
          a--;
          b--;
        }
        d = 0;
      }
      else if (cntBA < d)
        d -= cntBA;
    }
    // cout << a << " " << b << " " << c << " " << d << endl;
  }
  // cout << "loop 1 ended" << endl;
  // print("v", v);
  // print("even", even);
  // print("odd", odd);
  // cout << "-------------------------" << endl;
  for (int i = 0; i < odd.size(); i++)
  {
    // cout << i << " " << odd.size() << endl;
    // cout << odd[i] << endl;
    if (c == 0 && d == 0)
      break;
    int cnt = odd[i].size() / 2;
    // cout << "cnt = " << cnt << endl;
    if (odd[i][0] == 'A')
      a--;
    else
      b--;
    // cout << "begin -> " << a << " " << b << " " << c << " " << d << endl;
    if (c > 0)
    {
      if (cnt == c)
      {
        c = 0;
        cnt = 0;
      }
      else if (cnt < c)
      {
        c -= cnt;
        cnt = 0;
      }
      else if (cnt > c)
      {
        cnt -= c;
        c = 0;
        // odd.pb(odd[i].substr(c * 2 + 1));
      }
    }

    if (d > 0)
    {
      if (cnt == d)
      {
        d = 0;
        cnt = 0;
        continue;
      }
      else if (cnt < d)
      {
        d -= cnt;
        cnt = 0;
      }
      else if (cnt > d)
      {
        cnt -= d;
        d = 0;
      }
    }
    // cout << "cnt = " << cnt << endl;
    if (cnt)
      odd.pb(odd[i].substr(odd[i].size() - 2 * cnt));
    // cout << a << " " << b << " " << c << " " << d << endl;
  }
  if (c == 0 && d == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
