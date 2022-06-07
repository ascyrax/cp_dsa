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
        freopen("cowdance.in", "r", stdin);
        freopen("cowdance.out", "w", stdout);
        ioss
        //int t;cin>>t;for(int i=1;i<=t;i++)//{cout<<"Case #"<<i<<": ";
        suraj();
        //}
        return 0;
}

// @author: ascyrax

ll time(ll kmid, vector<ll> duration)
{
        vector<int> v(kmid);
        for (int i = 0; i < kmid; i++)
        {
                v[i] = duration[i];
        }
        for (int i = kmid; i < duration.size(); i++)
        {
                v[v.size() - 1] += duration[i];
                sort(v.rbegin(), v.rend());
        }
        return v[0];
}
//...............................
//what is wrong with this solution?

//implement using priority_queue

void suraj()
{
        ll n, tmax;
        cin >> n >> tmax;
        vector<ll> duration(n);
        for (ll &i : duration)
                cin >> i;
        sort(duration.rbegin(), duration.rend());
        ll kmin = 0, kmax = n, kmid = n / 2;
        while (kmin < kmax)
        {
                kmid = kmin + (kmax - kmin) / 2; //no of cows dancing at a time
                // cout << kmin << " " << kmid << " " << kmax << " " << time(kmid, duration) << endl;
                if (time(kmid, duration) <= tmax)
                {
                        kmax = kmid;
                }
                else
                {
                        kmin = kmid + 1;
                }
        }
        // ll ans=n;
        // if(time(kmin,duration)<=tmax)ans=min(ans,kmin);
        // if(time(kmax, duration)<=tmax)ans=min(ans,kmax);
        // cout<<ans<<endl;
        cout << kmax << endl;
}

//................................
// #include <bits/stdc++.h>

// using namespace std;

// int main () {
// 	freopen("cowdance.in", "r", stdin);
// 	freopen("cowdance.out", "w", stdout);

// 	int n, t;
// 	cin >> n >> t;
// 	int ar[n];

// 	for (int i = 0; i < n; i++) {
// 		cin >> ar[i];
// 	}

// 	int hi = n, lo = 1;
// 	int sol = n;

// 	while (lo <= hi) {
// 		int mid = lo + (hi - lo)/2;
// 		int time = 0, j = 0;
// 		priority_queue<int> pq;
// 		int size = 0;
// 		while (size < mid && j < n) {
// 			pq.push(-ar[j]);
// 			size++;
// 			j++;
// 		}

// 		while ((int) pq.size()) {
// 			time += max(0, -pq.top() - time);
// 			pq.pop();
// 			if (j < n) {
// 				pq.push(-(ar[j] + time));
// 				j++;
// 			}

// 		}

// 		if (time > t) {
// 			lo = mid + 1;
// 		} else {
// 			sol = min(sol, mid);
// 			hi = mid - 1;
// 		}
// 	}

// 	cout << sol << '\n';
// }