#include<bits/stdc++.h>
using namespace std;

int binary_search_iterative(int *arr,int size,int key){
int l = 0,mid;
int r = size - 1;

while(l<=r){
    mid = (l+r-1)/2;
    if(arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        l = mid+1;
    else
        r = mid - 1;
}
return -1;
}

int binary_search_recursive(int *arr , int l , int r , int key){
if(l<r){
    int mid = (l+r-1)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid] < key)
        binary_search_recursive(arr,mid+1,r,key);
    else
        binary_search_recursive(arr,l,mid-1,key);
}
return -1;
}


int main(){
int arr[] = {1,4,6,9,10};
int size = sizeof(arr)/sizeof(arr[0]);
int key = 6;
cout<< binary_search_iterative(arr,size,key)<<endl;
cout<< binary_search_recursive(arr,0,size,key);
}
