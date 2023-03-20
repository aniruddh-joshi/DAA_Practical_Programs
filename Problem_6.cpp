#include<iostream>
#include<algorithm>
using namespace std;

int count_pairs(int arr[],int n, int key){
    int i=0,j=1,count=0;
    sort(arr,arr+n);
    while(j<n){
        int diff=arr[j]-arr[i];
        if(diff==key){
            count++;
            i++;
            j++;
        }
        else if(diff<key){
            j++;
        }
        else{
            i++;
        }
    }
    return count;
}

int main(){
    int n,key;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in sorted form: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the key element: ";
    cin>>key;
    cout<<"Number of Pairs with difference "<<key<<" are: "<<count_pairs(arr,n,key)<<endl;
    return 0;
}
