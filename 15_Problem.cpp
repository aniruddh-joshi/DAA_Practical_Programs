#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int start,int end){
    int pivot=arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

int quick_sort(int arr[],int start,int end,int k){
    if(start==end){
        return arr[start];
    }
    int pivotindex=partition(arr,start,end);
    if(k==pivotindex){
        return arr[k];
    }
    else if(k<pivotindex){
        return quick_sort(arr,start,pivotindex-1,k);
    }
    else{
        return quick_sort(arr,pivotindex+1,end,k);
    }
}

int main(){
    int n,k;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the value of k (1-based index): ";
    cin>>k;
    srand(time(NULL));

    cout<< k <<"th smallest element is: "<<quick_sort(arr,0,n-1,k-1)<<endl;
	return 0;
}