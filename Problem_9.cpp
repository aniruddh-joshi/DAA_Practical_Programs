#include<iostream>
#include<algorithm>
using namespace std;

bool dublicate(int arr[],int n){
    sort(arr,arr+n);
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])    return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to sort: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(dublicate(arr,n)){
        cout<<"The array contains dublicate elements"<<endl;
    }
    else{
        cout<<"The array does not contain dublicates elements"<<endl;
    }
	return 0;
}