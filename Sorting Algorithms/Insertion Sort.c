#include<stdio.h>
//To change the array
void func1(int arr[], int num, int j, int i){
	for(int k=i-1; k>=j; k--){
		arr[k+1]=arr[k];
	}
	arr[j]=num;
}
//To Check the element, is smaller to which number. When found function goes to "func1".
void func(int arr[], int num, int i){
	for(int j=0; j<i; j++){
		if(num<arr[j]){
			func1(arr, num, j, i);
			break;
		}
	}
}
//To Check if the next element is smaller, if yes function goes to "func".
int insertion_sort(int arr[], int n){
	int t,p;
	for(int i=1; i<n; i++){
		if(arr[i]<arr[i-1]){
			func(arr,arr[i],i);
		}	
	}
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);			 
	}
}

int main(){
	int n,p;
	printf("%s", "Enter the length of the Array: ");
	scanf("%d", &n);
	int initial[n];
	
	for(int i=0; i<n; i++){
		printf("%s", "Enter the Element ");
		printf("%d", i+1);
		printf("%s", ": ");			 
	 	scanf("%d", &initial[i]);
	}

	
	insertion_sort(initial, n);
	
	return 0;
}
