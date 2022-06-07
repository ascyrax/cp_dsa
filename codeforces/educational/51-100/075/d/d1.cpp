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
int n, s;
vector<pair<int, int>> l, r, vp;
vector<pair<int, int>> vpCopy;
//.....................................
bool check(int mid)
{
  // cout << "checking for " << mid << endl;
  int salarySum = 0;
  for (int i = 0; i <= n / 2 - 1; i++)
  {
    int index = r[i].second;
    // cout << "vpCopy[index].first = " << vpCopy[index].first << endl;
    salarySum += vpCopy[index].first;
    // salarySum += min(vpCopy[index].second, mid);
  }
  // cout << "salarySum: " << salarySum << endl;
  salarySum += max(mid, vpCopy[r[n / 2].second].first);
  // cout << "salarySum: " << salarySum << endl;
  for (int i = n / 2 + 1; i < n; i++)
  {
    int index = r[i].second;
    // cout << "added = " << max(mid, vpCopy[index].first) << endl;
    salarySum += max(mid, vpCopy[index].first);
  }
  // cout << "salarySum = " << salarySum << endl;
  return salarySum <= s;
}
//.....................................
void print(vector<pair<int, int>> temp)
{
  for (auto el : temp)
    cout << el.first << " " << el.second << endl;
}
bool custom(pair<int, int> &a, pair<int, int> &b)
{
  // cout << "hi" << endl;
  // cout << a.first << " " << a.second << endl;
  // cout << b.first << " " << b.second << endl;
  // cout << "vp" << endl;
  // print(vp);
  // cout << "bye" << endl;
  if (a.second < b.second)
  {
    return true; // => swap a and b. i.e bring a to the left of b in the vector.
  }
  else if (a.second == b.second)
  {
    return a.second < b.second;
  }
  else
    return false;
}
//.....................................

void suraj()
{
  cin >> n >> s;
  vp = vector<pair<int, int>>();
  l = vector<pair<int, int>>();
  r = vector<pair<int, int>>();

  map<pair<int, int>, int> index;

  for (int i = 0; i < n; i++)
  {
    pair<int, int> temp;
    cin >> temp.first >> temp.second;
    vp.pb(temp);
    index[temp] = i;
  }

  vpCopy = vp;

  sort(vp.begin(), vp.end());
  // cout << "vp sort-1" << endl;
  // print(vp);
  for (int i = 0; i < n; i++)
  {
    l.pb(make_pair(vp[i].first, index[vp[i]]));
  }
  // cout << "l" << endl;
  // print(l);

  sort(vp.begin(), vp.end(), custom);
  // cout << "vp sort-2" << endl;
  // print(vp);
  for (int i = 0; i < n; i++)
  {
    r.pb(make_pair(vp[i].second, index[vp[i]]));
  }
  // cout << "r" << endl;
  // print(r);

  int left = l[n / 2].first;  // leftmost(minimum) possible value of median
  int right = r[n / 2].first; // max possible value of median
  // binary search for the ans.
  int mid = (left + right) / 2;

  while (left < right)
  {
    mid = (left + right) / 2;
    // cout << "left = " << left << " right = " << right << endl;
    // cout << "mid = " << mid << endl;
    if (check(mid))
    {
      if (left == right - 1)
      {
        // or just check(right) . if true then mid-> right break;
        if (check(right))
        {
          left = right;
          break;
        }
        else
        {
          left = left;
          break;
        }
      }
      else
        left = mid;
    }
    else
    {
      right = mid - 1;
    }
  }

  cout << left << endl;
}
