#include<iostream>
using namespace std;

void find_indices(int arr[],int n){
    for(int k=2;k<n;k++){
        int i=0,j=k-1;
        while(i<j){
            if(arr[i]+arr[j]==arr[k]){
                cout<<"Indices are: "<<i<<","<<j<<","<<k<<endl;
                return;
            }
            else if(arr[i]+arr[j]<arr[k]){
                i++;
            }
            else{
                j--;
            }
        }
    }
    cout<<"No such Indices exist"<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in sorted form: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    find_indices(arr,n);
    return 0;
}