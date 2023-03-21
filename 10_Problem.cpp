#include<iostream>
using namespace std;

int merge(int arr[],int l,int mid,int r,int&comparisons,int&inverse){
    int i=l,j=mid+1,k=0,inv=0;
    int temp[r-l+1];
    while(i<=mid && j<=r){
        comparisons++;
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            inv+=mid-i+1;
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)   temp[k++]=arr[i++];
    while(j<=r)     temp[k++]=arr[j++];
    
    for(i=l,k=0;i<=r;i++,k++)   arr[i]=temp[k];
    inverse+=inv;
    return inv;
}

int merge_sort(int arr[],int l,int r,int&comparisons,int&inverse){
    int inv=0;
    if(l<r){
        int mid=l+(r-l)/2;
        inv+=merge_sort(arr,l,mid,comparisons,inverse);
        inv+=merge_sort(arr,mid+1,r,comparisons,inverse);
        inv+=merge(arr,l,mid,r,comparisons,inverse);
    }
    return inv;
}

int main(){
    int n,inverse=0,comparisons=0;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to sort: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    inverse=merge_sort(arr,0,n-1,comparisons,inverse);
	cout<<"Sorted Array is :- ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of Comparisons: "<< comparisons <<endl;
    cout<<"Number of Inverse: "<< inverse <<endl;
	return 0;
}
