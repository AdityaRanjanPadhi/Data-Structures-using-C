#include<stdio.h>

void bubble_sort(int arr[], int node1[], int node2[], int n){
	int t;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
		    if(arr[j]>arr[j+1]){
			    t = arr[j];
	 			arr[j] = arr[j+1];
				arr[j+1] = t;
				t = node1[j];
	 			node1[j] = node1[j+1];
				node1[j+1] = t; 
				t = node2[j];
	 			node2[j] = node2[j+1];
				node2[j+1] = t;   	    
			}
		}
	}
}

int check(int arr[], int *ptr, int x, int y){
	int t1=0,t2=0;
	for(int i=0; i<*ptr; i++){
		if(arr[i]==x){
			t1 = 1;
		}
	}
	for(int i=0; i<*ptr; i++){
		if(arr[i]==y){
			t2 = 1;
		}
	}
	if(t1!=t2){
		if(t1==1){
			arr[*ptr]=y;
			*ptr+=1;
		}
		else{
			arr[*ptr]=x;
			*ptr+=1;
		}
		return 1;
	}	
	else{
		return 0;
	}
}

int main(){
	int n,p;
	printf("Enter the Number of Nodes: ");
	scanf("%d", &n);
	printf("Enter the Number of Edges: ");
	scanf("%d", &p);
	
	int nodes1[p], nodes2[p], weight[p];
	printf("Enter the Graph in the following format:\n");
	printf("Node 1 	Node 2	 Weight\n");
	int a, b, w, t;
	for(int i=0; i<p; i++){
		scanf("%d %d %d", &a, &b, &w);
		if(a>b){t=a; a=b; b=t;}
		nodes1[i]=a; nodes2[i]=b; weight[i]=w;
	}
	
	bubble_sort(weight, nodes1, nodes2, p);
	
	for(int i=0; i<p; i++){
		printf("Weight of Edge (%d, %d) = %d\n", nodes1[i], nodes2[i], weight[i]);			 
	}
	printf("\n");printf("\n");
	
	int sum=0;
	int arr[n];
	
	for(int i=0; i<n; i++){
		arr[i]=0;
	}
	
	printf("Shotest Path has Nodes of Weight: \n");
	arr[0]=nodes1[0];
	arr[1]=nodes2[0];
	printf("\t(%d, %d) = %d\n", nodes1[0], nodes2[0], weight[0]);
	sum+=weight[0];
	int ptr=2;
	int l;
	for (int i=0; i<p; i++){
		if(check(arr,&ptr,nodes1[i],nodes2[i])==1){
			printf("\t(%d, %d) = %d\n", nodes1[i], nodes2[i], weight[i]);
			sum+=weight[i];
			i=0;
			l++;
			if(l>p){
				break;
			}
		}
	}
	
	printf("\n");
	printf("Minimum Spanning Tree: %d\n", sum);
	
	return 0;
}
