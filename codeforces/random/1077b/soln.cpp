#include <bits/stdc++.h>

using namespace std;

void solve()
{
        int n, ans = 0;
        cin >> n;
        vector<int> v, dis;
        for (int i = 0; i < n; i++)
        {
                int t;
                cin >> t;
                v.push_back(t);
        }
        //cout<<"it come here 1 "<<endl;
        for (int i = 1; i < n - 1; i++)
        {
                if (v[i] == 0 && v[i - 1] == 1 && v[i + 1] == 1)
                {
                        dis.push_back(i);
                        ans += 1;
                }
        }
        //cout<<"Dis size "<<dis.size()<<endl;
        //cout<<"IT come here 2 "<<endl;
        //cout << typeid(dis).name() << endl;

        /*if(dis.size()<2){
        cout<<ans<<endl;
        return;
    }*/

        cout << "a" << endl;
        //  line below
        int suraj = 74;
        cout << suraj << " " << typeid(suraj).name() << endl;
        cout << typeid(dis.size()).name() << " " << typeid(dis.size() - 1).name() << endl;
        cout << dis.size() << " " << dis.size() - 1 << endl;
        for (int i = 0; i < int(dis.size()) - 1; i++)
        {
                cout << "inside the loop" << endl;
                // line above

                //cout<<"IT comes here 3 "<<endl;

                if (dis[i + 1] - dis[i] == 2)
                {
                        //  cout<<"It comes here 4 "<<endl;
                        ans--;
                        i++;
                }
        }
        cout << "b" << endl;
        cout << ans << endl;
}

int main()
{
        solve();
        return 0;
}