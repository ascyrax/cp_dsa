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

  // cin >> t;

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
map<int, int> cnt;
void join(vector<pair<int, int>> &arr, int const left, int const mid, int const right)
{
  int lenLeft = mid - left + 1, lenRight = right - mid;

  vector<pair<int, int>> leftArr, rightArr;
  for (int i = 0; i < lenLeft; i++)
    leftArr[i] = arr[left + i];
  for (int i = 0; i < lenRight; i++)
    rightArr[i] = arr[mid + 1 + i];

  int pLeft = 0, pRight = 0, pAns = left;

  // vector<pair<int, int>> ans;
  while (pLeft < lenLeft && pRight < lenRight)
  {
    if (leftArr[pLeft].first < rightArr[pRight].first)
    {
      arr[pAns] = leftArr[pLeft];
      pLeft++;
    }
    else
    {
      arr[pAns] = rightArr[pRight];
      cnt[rightArr[pRight].second]++;
      pRight++;
    }
    pAns++;
  }
  while (pLeft < lenLeft)
  {
    arr[pAns] = leftArr[pLeft];
    pLeft++;
    pAns++;
  }
  while (pRight < lenRight)
  {
    arr[pAns] = rightArr[pAns];
    pRight++;
    pAns++;
  }
  // print("ans", ans);
  // return ans;
}
// int cntr = 0;
void merge(vector<pair<int, int>> &arr, int const begin, int const end)
{
  cout << begin << " " << end << endl;
  if (begin >= end)
    return;
  int mid = begin + (end - begin) / 2;
  // if (cntr == 20)
  //   return vector<pair<int, int>>();
  // cntr++;
  // cout << "arr" << endl;
  // for (auto el : arr)
  //   cout << el.first << " " << el.second << ", ";
  // cout << endl;
  // if (arr.size() < 2)
  //   return arr;

  // vector<pair<int, int>> left, right;
  // int lenarr = arr.size();
  // for (int i = 0; i <= (lenarr - 1) / 2; i++)
  // {
  //   left.pb(arr[i]);
  // }
  // for (int i = (lenarr - 1) / 2 + 1; i < lenarr; i++)
  // {
  //   right.pb(arr[i]);
  // }
  // print("left", left);
  // print("right", right);
  merge(arr, begin, mid);
  // print("left: ", left);
  merge(arr, mid + 1, end);
  // print("right: ", right);
  join(arr, begin, mid, end);
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++)
  {
    int el;
    cin >> el;
    v.pb(make_pair(el, i));
  }
  int lenv = v.size();

  merge(v, 0, lenv - 1);

  int ans = 0;
  for (auto el : cnt)
    ans = max(ans, el.second);
  cout << ans << endl;
}
