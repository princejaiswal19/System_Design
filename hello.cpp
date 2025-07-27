#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
   int n;
   cin>>n;
   vector<int>v(n);
   for(int i=0; i<n; i++){
    cin>>v[i];
   }
   int i=0;
   int j=n-1;
   bool t=true;
   string s="";
   while(i<j){
    if(t){
     if(v[i]>v[j]){
        s=s+'L';
     }
     else{
        s=s+'R';
     }
    }
    else{
        if(v[i]<v[j]){
        s=s+'L';
     }
     else{
        s=s+'R';
     }
    }
    !t;
   }
   cout<<s<<"\n";

}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int m;
cin>>m;

while(m--){
solve();
}
    return 0;
}