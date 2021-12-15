#include<stdio.h>
#include<stdbool.h>

void selection_sort(int arr[], int n, bool k){
	int a;
	if(k==0){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (arr[i] < arr[j]){
				   a=arr[j];
				   arr[j]=arr[i];
				   arr[i]=a; 
				}
			}
		}
	}
	else{
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (arr[i] > arr[j]){
				   a=arr[j];
				   arr[j]=arr[i];
				   arr[i]=a; 
				}
			}
		}
	}
	for (int k=0; k<n; k++){
		printf("%d", arr[k]);
	 	printf("%s", " ");
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
	
	selection_sort(initial, n, p-1);
	
	return 0;
}
