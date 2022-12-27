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
void print(string s, set<int> st)
{
  cout << s << endl;
  for (auto el : st)
    cout << el << " ";
  cout << endl;
}
//.....................................

//.....................................

void suraj()
{
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  set<int> engines;
  engines.insert(1);
  int prev = inf;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    if (i >= 1)
      if (v[i] < prev)
        engines.insert(i + 1);
    prev = min(prev, v[i]);
  }

  // print("engines", engines);

  for (int i = 0; i < m; i++)
  {
    int index, delta;
    cin >> index >> delta;
    // index--;
    // change v[index]
    // cout << "i: " << i << endl;
    // cout << index << " " << v[index] - delta << endl;
    int newVal = v[index - 1] - delta;
    // cout << "newVal : " << newVal << endl;

    // check whether this index's value acts as the engine of a new train or not.
    auto left = engines.lower_bound(index);
    if (left == engines.begin())
    {
      if (*left == index)
      {
        // cout << "if" << endl;
        // engines.erase(left);
        // print("engines a: ", engines);
        // engines.insert(index);
        // print("engines b: ", engines);
        // now iterate towards right and erase any element > newVal.
        // break the iteration when an element<newVal is found

        // note currently the iterator is at the index element.
      }
      else
      {
        engines.insert(index);
        // now iterate towards right and erase any element > newVal.
        // break the iteration when an element<newVal is found

        // note currently the iterator is at the index element.
      }
    }
    else if (left != engines.end())
    {
      if (*left == index)
      {
        engines.erase(left);
        engines.insert(index);
        // now iterate towards right and erase any element > newVal.
        // break the iteration when an element<newVal is found

        // note currently the iterator is at the index element.
      }
      else
      {
        --left;
        if (newVal < v[*left - 1])
        {
          engines.insert(index);
        }
        // now iterate towards right and erase any element > newVal.
        // break the iteration when an element<newVal is found

        // note currently the iterator is at the index element.
      }
    }
    else if (left == engines.end())
    {
      --left;
      if (newVal < v[*left - 1])
      {
        engines.insert(index);
      }
      // now iterate towards right and erase any element > newVal.
      // break the iteration when an element<newVal is found

      // note currently the iterator is at the index element.
    }
    left = engines.upper_bound(index);
    // cout << "*left before while: " << *left << endl;
    // print("engines before while : ", engines);
    while (1)
    {
      left = engines.upper_bound(index);
      // cout << "*left inside while: " << *left << endl;
      if (left == engines.end())
        break;
      if (v[*left - 1] >= newVal)
      {
        engines.erase(left);
      }
      else
        break;
      // print("inside while: ", engines);
    }
    // print("engines", engines);
    v[index - 1] = newVal;
    // print("v", v);
    // cout << "-------------------------" << endl;
    cout << engines.size() << " ";
  }
  cout << endl;
}
