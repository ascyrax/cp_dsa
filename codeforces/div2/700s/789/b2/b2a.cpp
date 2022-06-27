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
  cout << "----" << endl;
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
  string s;
  cin >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    v[i] = s[i] - '0';
  }

  // print("v", v);
  int cnt = 1;
  vector<int> segSizes;
  for (int i = 1; i < n; i++)
  {
    if (v[i] == v[i - 1])
      cnt++;
    else
    {
      segSizes.pb(cnt);
      cnt = 1;
    }
  }
  segSizes.pb(cnt);

  // print("segSizes", segSizes);

  int nOper = 0, nSegs = 0;

  // in segSizes, count of odd elements is even in number.
  int lenSegSizes = segSizes.size();

  for (int i = 0; i <= lenSegSizes - 2; i++)
  {
    if (segSizes[i] % 2 == 0)
      continue;
    // current segSize is odd.
    // min no of steps get calculated everytime correctly no matter 0->1 or 1->0.
    // its the min no of segments that troubles us. For all the cases when sizes are 3 and above for odd ones and 4 and above for even ones, we dont care what we do 0->1 or 1->0.
    // only when oddSegSize=1 => we gotta convert this element to its adjacent
    // and when evenSegSize=2 => we gotta convert this element to its adjacent element incase this even sized element(which corresponds to a segmentSize) is surrounded by two odd element(segmentSize). If that is so, then its adjacent element will be different from this viz. if current element's corresponding segment consists of 1 then its adjacent element will correspond to the segments which consist of 1s.
    // and if both above cases occur together, then oddSegSize=1 case will be given more priviledge as it will result in min no of subsegments.
    // ie. for ...00100100... we wanna converts the 1s to 0s.
    if (segSizes[i] == 1)
    {
      if ()
      {
      }
      else
      {
        segSizes[i]--;
        segSizes[i + 1]++;
      }
    }
    // else if (segSizes[i + 1] == 2 && (i + 2 <= lenSegSizes - 1 && (segSizes[i + 2] % 2 == 1)))
    else
    { // segSizes[i] == 3 or 5 or 7 or 9.........
      if (segSizes[i + 1] == 2)
      {
        segSizes[i]++;
        segSizes[i + 1]--;
        // segSizes[i + 2]++;
      }
      else if (segSizes[i + 1] == 1)
      {
        // this will cover the case when segSizes[i+1]=1. e.g. ..31.. which corresponds to ...100010000001111
        segSizes[i]++;
        segSizes[i + 1]--;
      }
      else
      {
        segSizes[i]++;
        segSizes[i + 1]--;
      }
    }
    nOper++;
  }

  // print("segSizes", segSizes);

  vector<int> temp;
  temp.pb(v[0]);
  for (int i = 1; i < segSizes.size(); i++)
    temp.pb((temp[i - 1] + 1) % 2);

  vector<bool> flag(segSizes.size(), true);
  for (int i = 0; i < segSizes.size(); i++)
  {
    if (segSizes[i])
      flag[i] = true;
    else
      flag[i] = false;
  }

  vector<int> temp2;
  for (int i = 0; i < temp.size(); i++)
  {
    if (flag[i])
      temp2.pb(temp[i]);
  }

  vector<int> temp3;
  temp3.pb(temp2[0]);
  for (int i = 1; i < temp2.size(); i++)
    if (temp2[i] != temp3.back())
      temp3.pb(temp2[i]);

  cout << nOper << " " << temp3.size() << endl;
}