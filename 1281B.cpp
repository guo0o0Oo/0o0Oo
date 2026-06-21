#include<bits/stdc++.h>
using namespace std;
using pr=pair<char,int>;
int s1,s2;
int t;
priority_queue<pr> pq;
int main(){
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        while(!pq.empty())pq.pop();
        for(int i=1;i<s1.size();i++){
            pq.push({s1[i],i});
        }
        
    }
}