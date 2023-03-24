#include<bits/stdc++.h>
using namespace std;

void swap(int&a,int&b){
    int temp=a;
    a=b;
    b=temp;
}

int partition(int arr[],int start,int end,int&comparisons,int&swaps){
    int pivot=arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        comparisons++;
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
            swaps++;
        }
    }
    swap(arr[i+1],arr[end]);
    swaps++;
    return i+1;
}

void quick_sort(int arr[],int start,int end,int&comparisons,int&swaps){
    if(start<end){
        int pivotindex=partition(arr,start,end,comparisons,swaps);
        quick_sort(arr,start,pivotindex-1,comparisons,swaps);
        quick_sort(arr,pivotindex+1,end,comparisons,swaps);
    }
}

int main(){
    int n,swaps=0,comparisons=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to sort: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    srand(time(NULL));

    quick_sort(arr,0,n-1,comparisons,swaps);

	cout<<"Sorted Array is :- ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Number of Comparisons: "<< comparisons <<endl;
    cout<<"Number of Swaps: "<< swaps <<endl;

	return 0;
}