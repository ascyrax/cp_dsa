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
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    while ((a[i] & 1) == 0)
    {
      a[i] /= 2;
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    while ((b[i] & 1) == 0)
      b[i] /= 2;
    mx = max(mx, b[i]);
  }
  // print("a", a);
  // print("b", b);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  // print("a", a);
  // print("b", b);
  map<int, int> cnt;
  for (auto el : b)
    cnt[el]++;

  bool flag = false;
  int cnt1 = 0;
  for (int i = 0; i < n; i++)
  {
    // cout << "i:::::::::::::: " << i << endl;
    // cout << "a[i]: " << a[i] << endl;
    // print("b", b);
    if (a[i] == 1)
    {
      cnt1++;
      continue;
    }

    if (cnt.count(a[i]) > 0 && cnt[a[i]] > 0)
    {
      cnt[a[i]]--;
      // if (cnt[a[i]] == 0)
      b.erase(lower_bound(b.begin(), b.end(), a[i]));
    }
    else
    {
      int pow2 = 2;
      bool flag = false;
      while (a[i] * pow2 <= mx)
      {
        auto it = lower_bound(b.begin(), b.end(), a[i] * pow2);
        if (it == b.end())
        {
          cout << "NO" << endl;
          return;
        }
        if ((*it) / (pow2) == a[i])
        {
          if (cnt.count((*it)) > 0 && cnt[(*it)] > 0)
          {
            cnt[(*it)]--;
            // if (cnt[(*it)] == 0)
            b.erase(lower_bound(b.begin(), b.end(), (*it)));
            flag = true;
          }
          break;
        }
        else
          pow2 *= 2;
      }
      if (!flag)
      {
        cout << "NO" << endl;
        return;
      }
    }
  }
  if (b.size() == cnt1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
