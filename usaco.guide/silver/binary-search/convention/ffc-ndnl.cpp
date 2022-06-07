#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)(x).size()
#define endl "\n"
#define ioss                         \
        ios::sync_with_stdio(false); \
        cin.tie(0);
#define pb push_back

double startTime;
double gct() //get_current_time
{
        return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}
void suraj();

int main()
{
        startTime = (double)clock();
        freopen("convention.in", "r", stdin);
        freopen("convention.out", "w", stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

//...............................

void suraj()
{
        ll ncows, nbuses, busCapacity;
        cin >> ncows >> nbuses >> busCapacity;
        vector<ll> vcows(ncows);
        for (ll &i : vcows)
                cin >> i;
        ll maxwaittime = 0;
        sort(vcows.begin(), vcows.end());
        // if (nbuses * busCapacity == ncows)
        // {
        //         //cows get into the bus as they arrive
        //         //until the bus is full and then the bus leaves

        //         //check the wait time of the first cow on each bus
        // }
        // else if (nbuses * busCapacity > ncows)
        // {
        // }

        //minwait=0 maxwait=vcows[size()-1] midwait=dono ka mid
        ll minwait = 0, maxwait = vcows[ll(vcows.size()) - 1], midwait = minwait + (maxwait - minwait) / 2;
        ll nloop = 0;

        //iterate over vcows
        while (minwait < maxwait)
        {
                midwait = minwait + (maxwait - minwait) / 2;
                nloop++;
                if (nloop == 20)
                        break;
                // cout << minwait << " " << midwait << " " << maxwait << endl;
                ll count = busCapacity;
                ll busesused = 1;
                ll first = vcows[0], last = vcows[0];
                for (ll i = 1; i < ncows; i++)
                {
                        //if vcows[a]-vcows[a-1]>midwait
                        //cow a will go the next bus

                        if (vcows[i] - first > midwait)
                        {
                                count = busCapacity;
                                first = vcows[i];
                                last = vcows[i];
                                busesused++;
                        }
                        //else in the same bus
                        else
                        {
                                last = vcows[i];
                                count--;
                        }
                        if (count == 0)
                        {
                                count = busCapacity;
                                first = vcows[i + 1];
                                last = vcows[i + 1];
                                busesused++;
                        }
                }
                if (busesused > nbuses)
                {
                        minwait = midwait + 1;
                }
                else if (busesused <= nbuses)
                {
                        maxwait = midwait;
                }
        }
        cout << minwait << endl;
}

//................................
