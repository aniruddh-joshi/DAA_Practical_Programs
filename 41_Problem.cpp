#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    unordered_map<char, int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    vector<pair<char, int>> v;
    for(auto it:mp){
        v.push_back(it);
    }
    sort(v.begin(), v.end());
    for(auto it:v){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}