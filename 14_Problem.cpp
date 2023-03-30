#include<bits/stdc++.h>
using namespace std;

void count_sort(int arr[],int n){
    int max_value=arr[0];
    //1st
    for(int i=1;i<n;i++){
        if(arr[i]>max_value)    max_value=arr[i];
    }
    int count[max_value+1]={0};
    int output[n];
    //2nd
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    //3rd
    for(int i=1;i<=max_value;i++){
        count[i]+=count[i-1];
    }
    //4th
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    //5th
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to sort: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    count_sort(arr,n);
	cout<<"Sorted Array is :- ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
	return 0;
}