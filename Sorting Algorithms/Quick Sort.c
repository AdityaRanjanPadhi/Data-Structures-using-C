#include<stdio.h>

int partition(int arr[], int low, int high){
	int c;
	int pivot = high;
	int end = high;
	int start = low;
	int t=1;
	while(t){
		if(pivot==end && start!=end){
			if(arr[start]<arr[pivot]){
				start+=1;
			}
			else if(arr[start]>arr[pivot]){
				c = arr[start];
				arr[start] = arr[pivot];
				arr[pivot] = c;
				end-=1;
				pivot = start;
			}
		}
		else if(pivot==start && start!=end){
			if(arr[end]>arr[pivot]){
				end-=1;
			}
			else if(arr[end]<arr[pivot]){
				c = arr[end];
				arr[end] = arr[pivot];
				arr[pivot] = c;
				start+=1;
				pivot = end;
			}
		}
		else if(start==end){
			t=0;
		}
	}
	return pivot;
}

void quick_sort(int arr[], int low, int high){
	if(high>low){
		int pivot = partition(arr, low, high);
		quick_sort(arr,low, pivot-1);
		quick_sort(arr,pivot+1,high);
	}
}

int main(){
	
	int n;
	printf("Enter the Number of Elements to be Sorted: ");
	scanf("%d", &n);
	
	int arr[n];
	int num;
	for(int i=0; i<n; i++){
		printf("Enter Element %d: ", i+1);
		scanf("%d", &num);
		arr[i] = num;
	}
	
	quick_sort(arr,0,n-1);
	
	printf("Sorted Array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
