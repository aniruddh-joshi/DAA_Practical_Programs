#include<iostream>
using namespace std;

int find_first(int arr[],int n,int key){
    int start=0,end=n-1;
    int result=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            result=mid;
            end=mid-1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return result;
}

int find_last(int arr[],int n,int key){
    int start=0,end=n-1;
    int result=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            result=mid;
            start=mid+1;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return result;
}

int count_occurrence(int arr[],int n,int key){
    int first=find_first(arr,n,key);
    int last=find_last(arr,n,key);
    if(first==-1||last==-1){
        return 0;
    }
    return last-first+1;
}

int main(){
    int n,key;
    cout<<"Enter the size of an array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in array with sorted order: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the key element to be searched\n";
    cin>>key;
    int count=count_occurrence(arr,n,key);
    if(count>0){
        cout<<"Key element "<<key<<" is present in the array "<<count<<" times."<<endl;
    }
    else{
        cout<<"Key element "<<key<<" is not present in the array."<<endl;
    }
    return 0;
}
