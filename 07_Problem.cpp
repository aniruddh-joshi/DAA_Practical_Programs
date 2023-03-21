#include<iostream>
using namespace std;

void insertion(int arr[],int n,int& comparisons,int& shifts)
{
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
            shifts++;
            comparisons++;
        }
        arr[j+1]=key;
        shifts++;
    }
}

int main()
{
	int n,shifts=0,comparisons=0;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to sort: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	insertion(arr,n,comparisons,shifts);
	printf("Sorted Array is :- ");
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of Comparisons: "<< comparisons <<endl;
    cout<<"Numeber of Shifts: "<< shifts <<endl;
	return 0;
}
