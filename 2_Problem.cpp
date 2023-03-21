#include<iostream>
using namespace std;

int search(int arr[],int n,int key,int&count){
    int start=0,end=n-1,mid;
    while(start<=end){
        mid=start+(end-start)/2;
        count++;
        if(arr[mid]==key) return mid;
        else if (arr[mid]<key) start=mid+1;
        else end=mid-1;
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
