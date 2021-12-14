#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int d2b(int t){
	int k;
	int num=0;
	int a=1;
	while(t!=0){
		k=t%2;
		t/=2;
		num+=k*a;
		a*=10;
	}
	return num;
}

int b2d(int n){
  	int dec = 0, i = 0, rem;

  	while (n!=0) {
    	rem = n % 10;
    	n /= 10;
    	dec += rem * pow(2, i);
    	++i;
 	}
 	return dec;
}

void create(int** ptr,int i){
	int *temp;
	temp = (int*)calloc(3,sizeof(int));
	*(ptr + i) = temp;
}

void insert(int** ptr,int *len, int n, int *height,int arr[],int point){
	int k = 1;
	int t=0;
	int num,p;
	num = n;
	n = d2b(num);
	k*=(*height)*10;
	p = n%k;
	n = b2d(p);
	t=0;
	for(int i=0; i<3; i++){
		if(*(*(ptr + n)+i)!=0){
			t+=1;
		}
	}
	if(t>=3){
		for(int i=0; i<(*len); i++){
			free(*(ptr+i));
		}
		(*len)*=2;
		(*height)*=10;
		ptr=(int**)realloc(ptr,(*len)*sizeof(int*));
		for(int i=0; i<(*len); i++){
			create(ptr,i);
		}
		for(int i=0; i<point;i++){
			insert(ptr,len,arr[i],height,arr,point);
		}
	}
	*(*(ptr+n)+t)=num;
}

void show(int** ptr,int len){
	int i=0;
	while(i<len){
		printf("Index: %d\n", d2b(i));
		printf("%d %d %d", (*(*(ptr+i)+0)),(*(*(ptr+i)+1)),(*(*(ptr+i)+2)));
		printf("\n");
		i++;
	}
}

int main(){
	int **ptr=NULL;
	int len=2;
	int height = 1;
	
	ptr=(int**)calloc(len,sizeof(int*));
	
	int *a;
	int *b;
	a = (int *)calloc(3,sizeof(int));
	b = (int *)calloc(3,sizeof(int));
	
	*ptr = a;
	*(ptr + 1) = b;
	
	int arr[100];
	for(int i=0; i<100;i++){
		arr[i]=0;
	}
	
	int point=0;
	int task;
	int n;
	while(1){
		printf("%s", "\nEnter: ");
		scanf("%d", &task);
					
		if (task==1){
			printf("Enter the Number: ");
			scanf("%d", &n);
			arr[point]=n;
			point++;
		   	insert(ptr, &len, n, &height,arr,point);
		}
		else if (task==2){
		   	show(ptr, len);
		}
		else if(task==3){
			free(ptr);
			ptr=NULL;
  		    goto END;	
		}
		else{
			printf("Enter a Valid Task");
		}
	}
	END:
	return 0;
}