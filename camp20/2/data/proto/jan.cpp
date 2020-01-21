#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i<b; ++i)
#define FR(a, b) for(int i = a; i>=b;--i)
#define _upgrade cin.tie(0); ios_base::sync_with_stdio(0)
#define pb push_back
#define mp make_pair
#define INF 1e9

using namespace std;

typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef pair<int, int> iPair;

const int MAX = 1e5+5;
const int MOD = 1e9+7;

struct data
{
    int rok, miesac, dzien, h, mi, sek;
};
void str_to_int(data &dt, string d, string godz)
{
    dt.rok = dt.h = dt.mi = dt.miesac = dt.sek = dt.dzien = 0;
    int id = 0;
    for(id = 0; id<4; ++id)
    {
        dt.rok *=10;
        dt.rok += (d[id]-'0');
    }
    id = 5;
    dt.miesac = 10*(d[id]-'0') + d[id+1]-'0';
    id = 8;
    //zamiana godziny
    dt.dzien = 10*(d[id]-'0') + d[id+1]-'0';
    dt.h = 10*(godz[0]-'0')+ godz[1]-'0';
    dt.mi =  10*(godz[3]-'0')+ godz[4]-'0';
    dt.sek = 10*(godz[6]-'0')+ godz[7]-'0';
}
struct ans
{
    int dni, godz, mi, sek;
};
int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    _upgrade;
    int podzad;
    string dt, godz, dt2, godz2;
    cin>>dt>>godz>>dt2>>godz2>>podzad;
    data pocz, kon;
    str_to_int(pocz, dt, godz);
    str_to_int(kon, dt2, godz2);
 //  cout<<pocz.rok<<"-"<<pocz.miesac<<"-"<<pocz.dzien<<" "<<pocz.h<<"-"<<pocz.mi<<"-"<<pocz.sek<<"\n";
   // cout<<kon.rok<<"-"<<kon.miesac<<"-"<<kon.dzien<<" "<<kon.h<<"-"<<kon.mi<<"-"<<kon.sek<<"\n";
    ans rozw;
    rozw.dni = 0;
    rozw.godz = kon.h - pocz.h;
    rozw.mi = kon.mi - pocz.mi;
    rozw.sek = kon.sek - pocz.sek;
    //cout<<rozw.dni<<" "<<rozw.godz<<" "<<rozw.mi<<" "<<rozw.sek<<"\n";
    while(pocz.dzien != kon.dzien || pocz.miesac != kon.miesac || pocz.rok != kon.rok)
    {
        //cout<<pocz.rok<<" "<<pocz.miesac<<" "<<pocz.dzien<<"\n";
        pocz.dzien++;
        rozw.dni++;
        //dla dlat przestepnych luty - 29 dni
        if(pocz.miesac == 2 && pocz.rok%4 == 0 && (pocz.rok%100 != 0 || pocz.rok%400 ==0))
        {
            if(pocz.dzien == 30)
            {
                pocz.dzien = 1;
                pocz.miesac++;
                if(pocz.miesac == 13)
                {
                    pocz.rok++;
                    pocz.miesac = 1;
                }
            }
        }
        else if(pocz.dzien > months[pocz.miesac-1])
        {
            pocz.dzien = 1;
            pocz.miesac++;
            if(pocz.miesac == 13)
            {
                pocz.rok++;
                pocz.miesac = 1;
            }
        }
    }
    //cout<<rozw.dni<<" "<<rozw.godz<<" "<<rozw.mi<<" "<<rozw.sek<<"\n";
    rozw.dni -= 2;
    rozw.godz += 48;
    rozw.godz -= 2;
    rozw.mi += 120;
    rozw.mi -= 2;
    rozw.sek += 120;
    while(rozw.sek >= 60)
    {
        rozw.mi++;
        rozw.sek -= 60;
    }
    while(rozw.mi >= 60)
    {
        rozw.godz++;
        rozw.mi -= 60;
    }
    while(rozw.godz >= 24)
    {
        rozw.dni++;
        rozw.godz -= 24;
    }
   // cout<<rozw.dni<<" "<<rozw.godz<<" "<<rozw.mi<<" "<<rozw.sek<<"\n";
    if(rozw.dni != 0)
    {
        cout<<rozw.dni<<" ";
        if(rozw.dni == 1)cout<<"dzien";
        else cout<<"dni";
        if(rozw.sek + rozw.godz + rozw.mi > 0)cout<<" ";
    }
    if(rozw.godz != 0)
    {
        cout<<rozw.godz<<" ";
        if(rozw.godz == 1)cout<<"godzina";
        else if((rozw.godz >= 2 && rozw.godz <=4) || (rozw.godz >= 22 && rozw.godz <=23))cout<<"godziny";
        else cout<<"godzin";
        if(rozw.sek + rozw.mi > 0)cout<<" ";
    }
    if(rozw.mi != 0)
    {
        cout<<rozw.mi<<" ";
        if(rozw.mi == 1)cout<<"minuta";
        else if(rozw.mi%10 > 1 && rozw.mi%10 <= 4 && (rozw.mi <11 || rozw.mi > 20))cout<<"minuty";
        else cout<<"minut";
        if(rozw.sek != 0)cout<<" ";
    }
    if(rozw.sek != 0)
    {
        cout<<rozw.sek<<" ";
        if(rozw.sek == 1)cout<<"sekunda";
        else if(rozw.sek%10 > 1 && rozw.sek%10 <= 4 && (rozw.sek <11 || rozw.sek > 20))cout<<"sekundy";
        else cout<<"sekund";
    }
}
