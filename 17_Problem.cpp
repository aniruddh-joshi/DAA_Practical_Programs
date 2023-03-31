#include<bits/stdc++.h>
using namespace std;

const int Max_Size=26;

void findmax(char arr[],int n){
    int freq[Max_Size]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]-'a']++;
    }
    int maxFreq=0;
    char maxChar;
    for(int i=0;i<Max_Size;i++){
        if(freq[i]>maxFreq){
            maxFreq=freq[i];
            maxChar=i+'a';
        }
    }
    if(maxFreq > 1){
        cout<<"Max Occuring Element is: "<<maxChar<<"-"<<maxFreq<<endl;
    }
    else{
        cout<<"No Dublicates Present"<<endl;
    }
}

int main(){
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    char arr[n];
    cout<<"Enter the elements in array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    findmax(arr,n);
}
    return 0;
}