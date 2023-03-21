#include<iostream>
using namespace std;

int search(int arr[],int n,int key,int&count){
    for(int i=0;i<n;i++){
        count++;
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,key,count=0;
    cout<<"Enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched\n";
    cin>>key;
    int index= search(arr,n,key,count);
    if (index==-1)  cout<<"key element not found\n";
    else    cout<<"Key Element Found at Index "<<index<<endl;
    cout<<"Total Number of Comparisons: "<<count<<endl;
    return 0;
}
