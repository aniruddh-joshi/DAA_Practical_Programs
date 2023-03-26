#include<iostream>
using namespace std;
void swap(int&a,int&b){
    int temp=a;
    a=b;
    b=temp;
}

void heapify(int arr[],int n,int i,int&comparisons,int&swaps){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l] > arr[largest]){
        comparisons++;
        largest=l;
    }
    if(r<n && arr[r] > arr[largest]){
        comparisons++;
        largest=r;
    }
    if(largest!=i){
        comparisons++;
        swap(arr[i],arr[largest]);
        swaps++;
    }
    heapify(arr,n,largest,comparisons,swaps);
}

void heap_sort(int arr[],int n,int &comparisons,int &swaps){
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        swaps++;
        heapify(arr,i,0,comparisons,swaps);
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

    heap_sort(arr,n,comparisons,swaps);

	cout<<"Sorted Array is :- ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Number of Comparisons: "<< comparisons <<endl;
    cout<<"Number of Swaps: "<< swaps <<endl;

	return 0;
}