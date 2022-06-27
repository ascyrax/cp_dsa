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
void print(string s, vector<int> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
void print(string s, vector<bool> v)
{
  cout << s << endl;
  for (auto el : v)
    cout << el << " ";
  cout << endl;
}
//.....................................

//.....................................
void suraj()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  if (n == 1)
  {
    if (v[0] != 0)
    {
      cout << "NO" << endl;
      return;
    }
    else
    {
      cout << "YES" << endl;
      return;
    }
  }

  if (v[0] == 0)
  {
    for (int i = 1; i < n; i++)
    {
      if (v[i] != 0)
      {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
    return;
  }

  if (n == 2)
  {
    if (v[1] == 0)
    {
      if (v[0] != 0)
      {
        cout << "NO" << endl;
        return;
      }
      else
      {
        cout << "YES" << endl;
        return;
      }
    }
  }

  if (v[0] < 0 || v[n - 1] > 0)
  {
    cout << "NO" << endl;
    return;
  }

  vector<bool> flag(n, true); // true means ptr can go there.
  // for (int i = n - 1; i >= 0; i--)
  // {
  //   // cout << "i = " << i << endl;
  //   if (i == n - 1 && v[i] == 0)
  //   {
  //     // cout << "if" << endl;
  //     flag[i] = false;
  //   }
  //   else
  //   {
  //     // cout << "else" << endl;
  //     if (flag[i + 1] == false && v[i] == 0)
  //     {
  //       // print("flag", flag);
  //       // cout << "change" << endl;
  //       flag[i] = false;
  //     }
  //   }
  // }
  for (int i = n - 1; i >= 0; i--)
  {
    if (v[i] == 0)
      flag = false;
    else
      break;
  }
  // print("flag", flag);

  vector<int> v2(n, 0); // v is the original one

  int ptr = 0;
  // int dir = 1; //"right";
  //              // -1 => left

  // if (ptr == 0)
  // {
  v2[0] = v[0];
  v2[0 + 1] = -1 * (abs(v[0]) - 1);
  ptr = 1;
  // for n = 2, ptr will reach n-1 even before checking if v[n-1] is 0 or not.
  // }
  // cout << "ptr = " << ptr << endl;
  // print("v", v);
  // print("v2", v2);
  // for (int i = 1; i <= n - 3; i++)
  for (; ptr <= n - 2; ptr++)
  {
    // cout << "i = " << i << endl;
    if (flag[ptr + 1] == false)
    {
      // cout << "false found" << endl;
      break;
    }
    else
      v2[ptr]++;
  }
  // cout << "ptr = " << ptr << endl;
  // print("v", v);
  // print("v2", v2);
  // ptr is currently = n-2

  // if (v[n - 1] == 0)
  // {
  //   dir = -1; // start going left now
  // }
  // else
  // {
  //   v2[n - 2]++;
  //   ptr = n - 1;
  //   // decrease by abs(v[n-1]) times
  //   v2[n - 1] = v[n - 1];
  //   v2[n - 2] += (abs(v[n - 1]) - 1);
  //   ptr = n - 2;
  // }

  // cout << "ptr = " << ptr << endl;
  // print("v", v);
  // print("v2", v2);
  // ptr = n-2 now
  // and dir = -1 => left.
  for (int i = ptr; i >= 1; i--)
  {
    // cout << "i = " << i << endl;
    if (v[i] > v2[i])
    {
      cout << "NO" << endl;
      return;
      // since we cannot go the right now.
    }
    else if (v[i] < v2[i])
    {
      int diff = abs(v2[i] - v[i]);
      v2[i] = v[i];
      v2[i - 1] += (diff - 1);
    }
    else if (v[i] == v2[i])
    {
      cout << "NO" << endl;
      return;
      // since it cant go any left now.
    }
  }
  // loop iterated successfully means the current ptr is 1 now.
  cout << "YES" << endl;
}
