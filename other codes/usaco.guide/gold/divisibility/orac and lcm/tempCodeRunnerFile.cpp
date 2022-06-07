ll ans = 1;
        for (ll i = 2; i <= 200000; i++)
        {
                sort(cntPrime[i].begin(), cntPrime[i].end());
                if (cntPrime[i].size() == n)
                {
                        ans *= pw(i, cntPrime[i][1]);
                }
                else if (cntPrime[i].size() == n - 1)
                {
                        ans *= pw(i, cntPrime[i][0]);
                }
                else
                {
                        ans = ans;
                }
        }
        cout << ans << endl;