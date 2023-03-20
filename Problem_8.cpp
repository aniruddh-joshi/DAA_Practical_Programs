#include<iostream>
using namespace std;

void selection(int arr[],int n,int&comparisons,int&swaps){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            comparisons++;
            if(arr[j]<arr[min_index])
            min_index=j;
        }
        swaps++;
        swap(arr[min_index],arr[i]);
    }
}

int main(){
    int n,swaps=0,comparisons=0;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to sort: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	selection(arr,n,comparisons,swaps);
	printf("Sorted Array is :- ");
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of Comparisons: "<< comparisons <<endl;
    cout<<"Number of Swap: "<< swaps <<endl;
	return 0;
}