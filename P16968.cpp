#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll sup=0x3f3f3f3f3f3f3f3f;
const ll inf=-0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll l,r;
    string s,k;
    ll t;	cin>>t;
    while(t--){
        cin>>s;
        l=0;r=s.size()-1;
        while(l<=r){
            if(l==r){
                if(k!=""){
                    if(k[0]>=s[l]){
                        cout<<k;
                        k="";
                    }
                    else if(k[0]<s[l]){
                        cout<<k<<k;
                        k="";
                    }
                }
                cout<<s[l];
                break;
            }
            if(s[l]==s[r]){
                if(l==r-1){
                    if(k!=""){
                        if(k[0]>=s[l]){
                            cout<<k;
                            k="";
                        }
                        else if(k[0]<s[l]){
                            cout<<k<<k;
                            k="";
                        }
                    }
                    cout<<s[l]<<s[r];
                    break;
                }
                if(k!=""){
                    if(k[0]>s[l]){
                        cout<<k;
                        k="";
                    }
                    else if(k[0]<s[l]){
                        cout<<k<<k;
                        k="";
                    }
                }
                k+=s[l];
                l++;r--;
            }
            else{
                if(s[l]<s[r]){
                    if(k!=""){
                        if(k[0]>s[l]){
                            cout<<k;
                            k="";
                        }
                        else if(k[0]<s[l]){
                            cout<<k<<k;
                            k="";
                        }
                    }
                    cout<<s[l];
                    l++;
                }
                else{
                    if(k!=""){
                        if(k[0]>s[l]){
                            cout<<k;
                            k="";
                        }
                        else if(k[0]<s[r]){
                            cout<<k<<k;
                            k="";
                        }
                    }
                    cout<<s[r];
                    r--;
                }
            }
        }
        if(k!="")cout<<k;
        cout<<"\n";
    }
    return 0;
}