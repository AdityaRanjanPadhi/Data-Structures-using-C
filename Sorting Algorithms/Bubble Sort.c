#include<stdio.h>
#include<stdbool.h>

void bubble_sort(int arr[], int n, bool k){
	int t;
	if(k==0){
		for(int i=0; i<n; i++){
			for(int j=0; j<n-1; j++){
			    if(arr[j]>arr[j+1]){
				    t = arr[j];
		 			arr[j] = arr[j+1];
					arr[j+1] = t;  	    
				}
			}
		}
	}
	else{
		for(int i=0; i<n; i++){
			for(int j=0; j<n-1; j++){
			    if(arr[j]<arr[j+1]){
				    t = arr[j];
		 			arr[j] = arr[j+1];
					arr[j+1] = t;  	    
				}
			}
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
	
	printf("%s", "Enter: 1 to Print the Array in Ascending Order\n       2 to Print the Array in Descending Order\n");
	printf("%s", "Enter: ");
	scanf("%d", &p);
	
	bubble_sort(initial, n, p-1);
	
	return 0;
}
