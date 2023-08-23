// @author: ascyrax

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#define pb push_back

int getAngle(int h, int m)
{

  int ah = (360 / 12) * h + 30 * (m / 60.0);

  int am = 360 * (m / 60.0);

  int diff1 = abs(am - ah);
  int diff2 = 360 - diff1;

  return min(diff1, diff2);
}
int main()
{
  int h, m;
  cin >> h >> m;
  cout << getAngle(h, m) << endl;
  return 0;
}