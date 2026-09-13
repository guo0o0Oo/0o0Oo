#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;
ll y=-4713,m=1,d=1,s1=1721423,s2=2299160;//1582.10.4
ll dom[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void check(){
    if(y>=1582){
        if(y%400==0||(y%4==0&&y%100))dom[2]=29;
        else dom[2]=28;
    }
    else{
        if(y<0){
            if((y+1)%4==0)dom[2]=29;
            else dom[2]=28;
        }
        else{
            if(y%4==0)dom[2]=29;
            else dom[2]=28;
        }
    }
}
void find(ll k){
    y=-4713;m=1;d=1;
    check();
    if(k-s2>=0){
        k-=s2;
        y=1582;m=10;d=4;
        if(k){
            k--;
            d=15;
        }
        while(k>=14609700000){
            k-=14609700000;
            y+=40000000;
        }
        while(k>=1460970000){
            k-=1460970000;
            y+=4000000;
        }
        while(k>=146097000){
            k-=146097000;
            y+=400000;
        }
        while(k>=14609700){
            k-=14609700;
            y+=40000;
        }
        while(k>=1460970){
            k-=1460970;
            y+=4000;
        }
        while(k>=146097){
            k-=146097;
            y+=400;
        }
        check();
        while(k>=dom[m]){
            k-=dom[m];
            m++;
            if(m==13){
                m=1;
                y++;
                check();
            }
        }
        while(k){
            k--;
            d++;
            if(d==dom[m]+1){
                d=1;
                m++;
            }
            if(m==13){
                m=1;
                y++;
                check();
            }
        }
    }
    else if(k>=s1){
        k-=s1;
        y=-1;m=12;d=31;
        if(k){
            k--;
            y=1;m=1;d=1;
        }
        while(k-146100>=0){
            y+=400;
            k-=146100;
        }
        while(k-1461>=0){
            y+=4;
            k-=1461;
        }
        check();
        while(k>=dom[m]){
            k-=dom[m];
            m++;
            if(m==13){
                m=1;
                y++;
                check();
            }
        }
        while(k){
            k--;
            d++;
            if(d==dom[m]+1){
                d=1;
                m++;
            }
            if(m==13){
                m=1;
                y++;
                check();
            }
        }
    }
    else{
        while(k-146100>=0){
            y+=400;
            k-=146100;
        }
        while(k-1461>=0){
            y+=4;
            k-=1461;
        }
        check();
        while(k&&d!=1){
            k--;d++;
            if(d==dom[m]+1){
                d=1;
                m++;
            }
            if(m==13){
                m=1;
                y++;
                check();
            }
        }
        while(k>=dom[m]){
            k-=dom[m];
            m++;
            if(m==13){
                m=1;
                y++;
                check();
            }
        }
        while(k){
            k--;
            d++;
            if(d==dom[m]+1){
                d=1;
                m++;
            }
            if(m==13){
                m=1;
                y++;
                check();
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T;	cin>>T;
    while(T--){
        ll r;
        cin>>r;
        find(r);
        if(y<0)cout<<d<<" "<<m<<" "<<-y<<" BC\n";
        else cout<<d<<" "<<m<<" "<<y<<"\n";
    }
    return 0;
}