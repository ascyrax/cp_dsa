/*
ID: ascyrax1
TASK: test
LANG: C++14
*/

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

void suraj()
{ ///////////////////////

        int ntrees, nbaskets;
        cin >> ntrees >> nbaskets;

        vector<int> berries(ntrees);
        for (int &i : berries)
        {
                cin >> i;
        }

        sort(berries.rbegin(), berries.rend());
        if (int(berries.size()) == 3)
        {
                berries.pb(berries[0] / 2);
                berries.pb(berries[0] / 2);
                berries.erase(berries.begin());
                sort(berries.begin(), berries.end());
        }
        else if (int(berries.size()) == 2)
        {
                berries.pb(berries[0] / 2);
                berries.pb(berries[0] / 2);
                berries.erase(berries.begin());
                sort(berries.begin(), berries.end());
                //copy if casse when berries.size==3
                berries.pb(berries[0] / 2);
                berries.pb(berries[0] / 2);
                berries.erase(berries.begin());
                sort(berries.begin(), berries.end());
        }
        else if (int(berries.size()) == 1)
        {
                cout << berries[0] / 2 << endl;
        }
        int a = berries[0], b = berries[1], c = berries[2], d = berries[3];
        vector<int> temp = {a, b, c, d};
        sort(temp.rbegin(), temp.rend());

        while (temp[0] > temp[2] + temp[3])
        {                        //for(int i:temp)cout<<i<<" ";cout<<endl;
                if (temp[0] % 2) //odd
                {
                        temp.pb(temp[0] / 2);
                        temp.pb(temp[0] / 2 + 1);
                }
                else //even
                {
                        temp.pb(temp[0] / 2);
                        temp.pb(temp[0] / 2);
                }
                temp.erase(temp.begin());
                sort(temp.rbegin(), temp.rend());
        }
        cout << temp[2] + temp[3] << endl;

} ////////////////////////////

int main()
{
        startTime = (double)clock();
                freopen("berries.in", "r", stdin);
                freopen("berries.out", "w", stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}
