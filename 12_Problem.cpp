#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n,int&comparisons,int&swaps){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            comparisons++;
            if(arr[j]>arr[j+1]){
                swaps++;
                swap(arr[j],arr[j+1]);
            }
        }
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

    bubble_sort(arr,n,comparisons,swaps);

	cout<<"Sorted Array is :- ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Number of Comparisons: "<< comparisons <<endl;
    cout<<"Number of Swaps: "<< swaps <<endl;

	return 0;
}