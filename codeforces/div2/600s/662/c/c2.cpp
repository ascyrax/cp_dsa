#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100009;
int cnt[MAXN];
vector<int> a;
int n;

bool check(int x) // can the max distance be equal to x or not
{
        cout << "checking for : " << x << endl;
        for (int i = 1; i <= n; i++)
                cnt[i] = 0;
        for (int i = 0; i < n; i++)
                cnt[a[i]]++;

        set<pair<int, int>, greater<pair<int, int>>> ss; // use greater comparator to sort set in descending order
        for (int i = 1; i <= n; i++)
        {
                if (cnt[i] > 0)
                        ss.insert({cnt[i], i});
        }
        for (auto el : ss)
                cout << el.first << " " << el.second << endl;
        vector<int> b;
        cout << "for loop started" << endl;
        for (int i = 0; i < n; i++)
        {
                cout << "i = " << i << endl;
                if (i >= x && cnt[b[i - x]])
                {
                        ss.insert({cnt[b[i - x]], b[i - x]});
                }

                if (ss.empty())
                        return 0;
                b.push_back(ss.begin()->second);
                ss.erase(ss.begin());
                cnt[b.back()]--;
                cout << "set s:" << endl;
                for (auto el : ss)
                        cout << el.first << " " << el.second << ",";
                cout << endl;
                cout << "vector b :" << endl;
                for (int i : b)
                        cout << i << " ";
                cout << endl;
        }
        cout << "for loop ended" << endl;
        return 1;
}

signed main()
{
        ios ::sync_with_stdio(0);
        cin.tie(0);

        int ttt = 1;
        // cin >> ttt;

        while (ttt--)
        {
                cin >> n;

                a.resize(n);
                for (int i = 0; i < n; i++)
                {
                        cin >> a[i];
                }

                int l = 0, r = n;
                while (r - l > 1)
                {
                        int m = (r + l) / 2;
                        if (check(m))
                        {
                                l = m;
                        }

                        else
                        {
                                r = m;
                        }
                }

                cout << l - 1 << "\n";
        }

        return 0;
}