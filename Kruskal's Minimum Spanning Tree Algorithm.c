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

void push(int a, int stack[], int *r){stack[*r]=a;*r+=1;}
int pop(int stack[], int *r){*r-=1;return stack[*r];}

void search(int a,int b, int d1[][2], int d2[][2], int stack[], int *r, int p, int *t){
	for(int i=0; i<p; i++){
		if(d1[i][0]==a && d1[i][1]==0){push(d2[i][0], stack, r); d1[i][1]=1;}
		if(d2[i][0]==a && d2[i][1]==0){push(d1[i][0], stack, r); d2[i][1]=1;}
	}
}

int notrelated(int a, int b, int d1[][2], int d2[][2], int stack[], int p){
	int t=1;
	int k; 	int r=0;
	search(a,b,d1,d2,stack,&r,p, &t);
	while(r>0){
		k = pop(stack, &r);
		if (k==b){
			t = 0;
			goto Next;
		}
		search(k,b,d1,d2,stack, &r, p, &t);
	}
	Next:
	return t;
}

int main(){
	int n,p;
	printf("%s", "Enter the Number of Nodes: ");
	scanf("%d", &n);
	printf("%s", "Enter the Number of Edges: ");
	scanf("%d", &p);
	
	int nodes1[p], nodes2[p], weight[p];
	printf("%s", "Enter the Graph in the following format:\n");
	printf("%s", "Node 1 	Node 2	 Weight\n");
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
	
	printf("\n\n");
	
	int stack[50];
	int d1[p][2]; int d2[p][2];
	
	for(int i=0; i<p; i++){
		d1[i][0]=0; d2[i][0]=0;
		d1[i][1]=0; d2[i][1]=0;
	}

	int sum=0;
	for(int i=0; i<p; i++){
		if(notrelated(nodes1[i], nodes2[i], d1, d2, stack, p)==1){
			d1[i][0]=nodes1[i]; d2[i][0]=nodes2[i];
			printf("Weight of Edge (%d, %d) = %d\n", nodes1[i], nodes2[i], weight[i]);
			sum += weight[i];
		}
		for(int i=0; i<p; i++){
			d1[i][1]=0; d2[i][1]=0;
		}
	}

	printf("\n");
	printf("Minimum Spanning Tree: %d\n", sum);
	
	return 0;
}

/*Sample Input
Enter the Number of Nodes: 7
Enter the Number of Edges: 9
Enter the Graph in the following format:
Node 1  Node 2   Weight
1 2 28 (Relation from node 1 to node 2 having weight 28)
2 3 16 (Relation from node 2 to node 3 having weight 16)
3 4 12 (Relation from node 3 to node 4 having weight 12)
4 5 22
5 6 25
6 1 10
2 7 14
7 5 24
4 7 18
*/
