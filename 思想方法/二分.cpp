//small to big
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int search(int *arr,int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(arr[mid]==key) return mid;
		else if(arr[mid]>key) right=mid-1;
		else left=mid+1;
	}
	return -1;
}
int searchFirstEqual(int *arr,int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(arr[mid]>=key) right=mid-1;
		else left=mid+1;
	}
	if(left<n&&arr[left]==key){
		return left;
	}
	return -1;
}
int searchLastEqual(int *arr,int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(arr[mid]>key) right=mid-1;
		else left=mid+1;
	}
	if(right>=0&&arr[right]==key){
		return right;
	}
	return -1;
}
int searchLastEqualOrSmaller(int *arr,int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(arr[mid]>key) right=mid-1;
		else left=mid+1;
	}
	return right;
}
int searchLastSmaller(int *arr,int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(arr[mid]>=key) right=mid-1;
		else left=mid+1;
	}
	return right;
}
int searchFirstEqualOrLarger(int *arr,int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(arr[mid]>=key) right=mid-1;
		else left=mid+1;
	}
	return left;
}
int searchFirstLarger(int *arr,int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(arr[mid]>key) right=mid-1;
		else left=mid+1;
	}
	return left;
}

int main(){
	int arr[17] = {1, 
                   2, 2, 5, 5, 5, 
                   5, 5, 5, 5, 5, 
                   5, 5, 6, 6, 7};
    printf("First Equal           : %2d \n", searchFirstEqual(arr, 16, 5));
    printf("Last Equal            : %2d \n", searchLastEqual(arr, 16, 5));
    printf("First Equal or Larger : %2d \n", searchFirstEqualOrLarger(arr, 16, 5));
    printf("First Larger          : %2d \n", searchFirstLarger(arr, 16, 5));
    printf("Last Equal or Smaller : %2d \n", searchLastEqualOrSmaller(arr, 16, 5));
    printf("Last Smaller          : %2d \n", searchLastSmaller(arr, 16, 5));
    return 0;
}
