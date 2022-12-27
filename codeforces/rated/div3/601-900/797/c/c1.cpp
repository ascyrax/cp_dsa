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

//.....................................
void print(queue<int> q)
{
  while (!q.empty())
  {
    int front = q.front();
    cout << front << " ";
    q.pop();
  }
  cout << endl;
}
//.....................................

void suraj()
{
  int n;
  cin >> n;
  vector<int> s(n), f(n), d(n);

  for (int &i : s)
    cin >> i;
  for (int &i : f)
    cin >> i;

  // vector<pair<int, int>> sf(n);

  queue<int> q;
  // int completed = -1;
  q.push(s[0]);
  int next = 1;    // index
  int current = 0; // index
  // time
  int currentStart = q.front(); // i.e. 0

  while (!q.empty())
  {
    // cout << "current: " << current << " next: " << next << endl;
    for (; next < n; next++)
    {
      // cout << "next = " << next << endl;
      if (s[next] <= f[current])
      {
        // cout << "if" << endl;
        q.push(next);
        // print(q);
      }
      else
      {
        // cout << "else" << endl;
        q.push(next++);
        // print(q);
        break;
      }
    }

    d[current] = f[current] - currentStart;
    q.pop();
    // cout << "task no " << current << " -> finished at time = " << f[current] << endl;
    currentStart = f[current];
    // cout << "q.size() = " << q.size() << endl;
    if (!q.empty())
      current = q.front();
    // else
    //   current = next++;
    currentStart = max(currentStart, s[current]);
    // cout << "currentStart = " << currentStart << endl;
    // cout << "current: " << current << " next: " << next << endl;
  }

  for (auto el : d)
    cout << el << " ";
  cout << endl;
}
