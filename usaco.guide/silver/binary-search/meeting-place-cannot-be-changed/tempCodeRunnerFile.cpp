int cnt = 0;
                for (auto i : vp)
                {
                        cnt += i.second;
                        if (cnt == n)
                                break;
                }
                if (cnt == n)
                {
                        tmax = tmid;
                }
                // //else check for a bigger tmid
                else
                {
                        tmin = tmid;
                }