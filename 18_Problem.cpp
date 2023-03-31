#include<bits/stdc++.h>
using namespace std;

void find_pair(int arr[],int n,int key){
    sort(arr,arr+n);
    int left=0;int right=n-1;

    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==key){
            cout<<"Pair found: "<<arr[left]<<"+"<<arr[right]<<"="<<key<<endl;
            return;
        }
        else if(sum<key){
            left++;
        }
        else{
            right--;
        }
    }
    cout<<"Pair not found."<<endl;
}

int main(){
    int n,key;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the key element: ";
    cin>>key;
    find_pair(arr,n,key);
    return 0;
}