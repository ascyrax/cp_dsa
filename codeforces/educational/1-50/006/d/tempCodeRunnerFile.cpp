for (ll i = 0; i < m; i++)
        // {
        //         for (ll j = i + 1; j < m; j++)
        //         {
        //                 ll tb = sb - (b[i] + b[j]);
        //                 ll ta = sa + (b[i] + b[j]);
        //                 //x=corresponding a[i]+a[j]
        //                 //tb+x and ta-x
        //                 //we want (abs((ta-x)-(tb+x))) to be as small as possible
        //                 //viz sa+b[i]+b[j]-x -(sb -(b[i] + b[j]+x))
        //                 //viz sa-sb+2(b[i]+b[j])-2x to be as small as possible
        //                 //viz sa-sb-2(b[i]+b[j]) to be as close as 2x
        //                 auto it = ma.lower_bound(abs(ta - tb));
        //                 auto temp = it;
        //                 ll twoX;
        //                 if (it == ma.end())
        //                 {
        //                         twoX = (*(--temp)).first;
        //                 }
        //                 else if (it == ma.begin())
        //                 {
        //                         twoX = (*it).first;
        //                 }
        //                 else
        //                 {
        //                         if (abs(abs(ta - tb) - (*it).first) < abs(abs(ta - tb) - (*(--temp)).first))
        //                         {
        //                                 twoX = (*it).first;
        //                         }
        //                         else
        //                                 twoX = (*temp).first;
        //                 }

        //                 if (twoX == abs(ta - tb))
        //                 {
        //                         ta = ta - twoX;
        //                         tb = tb + twoX;
        //                         if (abs(ta - tb) < ans)
        //                         {
        //                                 nSwaps = 2;
        //                                 ans = abs(ta - tb);
        //                                 ansPair.clear();
        //                                 ansPair.pb(make_pair((*it).second.first, i));
        //                                 ansPair.pb(make_pair((*it).second.second, j));
        //                         }
        //                 }
        //         }
        // }