#include<iostream>
#include<cmath>
using namespace std;

int search(int arr[],int n,int key,int&count){
    int step=sqrt(n),prev=0;
    while(arr[min(step,n)-1]<key){
        prev=step;
        step+=sqrt(n);
        if(prev>=n){
            return -1;
        }
        count++;
    }
    while(arr[prev]<key){
        prev++;
        if(prev==min(step,n)){
            return -1;
        }
        count++;
    }
    if(arr[prev]==key){
        count++;
        return prev;
    }
    return -1;
}

int main(){
    int n,key,count=0;
    cout<<"Enter the size of an array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in array with sorted order: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the key element to be searched\n";
    cin>>key;
    int index=search(arr,n,key,count);
    if(index==-1) cout<<"Element not Found\n";
    else cout<<"Element found at Index "<<index<<endl;
    cout<<"Total Number of Comparisons: "<<count<<endl;
    return 0;
}
