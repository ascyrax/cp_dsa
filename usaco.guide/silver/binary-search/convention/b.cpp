// @author: ascyrax

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

#define pb push_back

int n, m, c;
vector<int> vTime;

bool check(int mid)
{
        //POINTERS for the cows to be added in the CURRENT BUS
        int left = 0, right = 0;
        //maximum time that the first cow in the CURRENT BUS  has to wait
        int maxWait = 0;
        //nBuses is the number of buses which cannot accomodate any other cow
        int nBuses = 0, filled = 0; //filled is the number of places filled in the CURRENT BUS
        for (right = 0; right < n; right++)
        {
                //if the first cow in the CURRENT BUS does not have to wait for more than "mid" time
                //and also the CURRENT BUS is not filled yet
                if (vTime[right] - vTime[left] <= mid && filled < c)
                {
                        filled++;
                        maxWait = max(maxWait, vTime[right] - vTime[left]);
                }
                else if (vTime[right] - vTime[left] > mid) //if we add the current cow in the current bus then
                //the first cow will have to wait more than "mid" time
                //therefore THIS COW will become the first cow of the NEXT BUS
                {
                        left = right;
                        filled = 1;
                        nBuses++;
                }

                if (filled == c) //if the current bus is filled then the NEXT COW will be the first cow of the NEXT BUS
                {
                        filled = 0;
                        left = right + 1;
                        nBuses++;
                }
        }
        //if the last bus has even a single cow than it will also be added among the total buses that were used
        if (filled > 0)
                nBuses++;
        //total no of buses cannot be greater than m
        return nBuses <= m;
}

int main()
{
        freopen("convention.in", "r", stdin);
        freopen("convention.out", "w", stdout);

        cin >> n >> m >> c;

        vTime = vector<int>(n);

        for (int &i : vTime)
                cin >> i;

        sort(vTime.begin(), vTime.end());

        //we can binary search on the answer
        int l = 0, r = (int)1e9 + 1;

        while (l < r)
        {
                int mid = l + (r - l) / 2;
                if (check(mid))
                        r = mid;
                else
                        l = mid + 1;
        }

        cout << l << endl;

        return 0;
}
