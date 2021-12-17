#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

void insert(struct Node *ptr,int num){
	struct Node *temp;
	temp = (struct Node*)calloc(1,sizeof(struct Node));
	temp->data = num;
	temp->left = NULL;
	temp->right = NULL;
	
	int t=1;
	
	if(ptr->right==NULL && ptr->left==NULL && ptr->data==0){
		ptr->data = num;
		t=0;
	}
	
	while(t){
		if(num>ptr->data){
			if(ptr->right==NULL){
				ptr->right = temp;
				t=0;
			}
			ptr = ptr->right;
		}
		else{
			if(ptr->left==NULL){
				ptr->left = temp;
				t=0;
			}
			ptr = ptr->left;
		}
	}
}

void del(struct Node *ptr, int num){
	struct Node *ktr;
	ktr = (struct Node*)calloc(1,sizeof(struct Node));
	int t=1;
	if(ptr->data==num){
		ptr->data=0;
		ptr->left=NULL;
		ptr->right=NULL;
		t=0;
	}
	while(t){
		if(num>ptr->data){
			ktr = ptr;
			if(ptr->right==NULL){
				printf("Element not in the Structure\n");
				t=0;
				break;
			}
			ptr = ptr->right;
		}
		else if(num<ptr->data){
			ktr = ptr;
			if(ptr->left==NULL){
				printf("Element not in the Structure\n");
				t=0;
				break;
			}
			ptr = ptr->left;
		}
		else if(num==ptr->data){
			if(ktr->right==ptr){
				ktr->right=NULL;
			}
			else{
				ktr->left=NULL;
			}
			t=0;
		}
	}
}

void preorder(struct Node* ptr){
	if(ptr!=NULL){
	    printf("%d ", ptr->data);
	    preorder(ptr->left);
	    preorder(ptr->right);
    }
}

void postorder(struct Node* ptr){
	if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void inorder(struct Node*ptr){
	if(ptr!=NULL){
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void show(struct Node* ptr){
	int t=1;
	if(ptr->right==NULL && ptr->left==NULL && ptr->data==0){
		printf("No Element in Data Structure");
		t=0;
	}
	if(t==1){
		printf("Preorder: ");
		preorder(ptr);
		printf("\n");
    	printf("Postorder: ");
		postorder(ptr);
		printf("\n");
		printf("Inorder: ");
    	inorder(ptr);
	}
}

void search(struct Node* ptr,int num){
	int t=1;
	while(t){
		if(num>ptr->data){
			if(ptr->right==NULL){
				printf("Element not in the Structure\n");
				t=0;
				break;
			}
			ptr = ptr->right;
		}
		else if(num<ptr->data){
			if(ptr->left==NULL){
				printf("Element not in the Structure\n");
				t=0;
				break;
			}
			ptr = ptr->left;
		}
		else if(num==ptr->data){
			printf("Element in Data Structure\n");
			t=0;
		}
	}
}

int main(){
	
	struct Node *head;
	head = (struct Node*)calloc(1,sizeof(struct Node));
	head->left = NULL;
	head->right = NULL;
	
	int task;
	int num;
	printf("Enter:\n\t'1' to Insert an Element\n\t'2' to Delete an Element\n\t'3' to Show the Data Structure\n");
	printf("\t'4' to Check if an Element exists in the Structure\n\t'5' to Exit\n\n");
	while(1){
		printf("Operation: ");
		scanf("%d", &task);
		if(task==1){
			printf("Enter the Number to be Inserted: ");
			scanf("%d", &num);
			insert(head,num);
			printf("\n");
		}
		else if(task==2){
			printf("Enter the Number to be Deleted: ");
			scanf("%d", &num);
			del(head, num);
			printf("\n");
		}
		else if(task==3){
			show(head);
			printf("\n");
			printf("\n");
		}
		else if(task==4){
			printf("Enter the Number to be Searched: ");
			scanf("%d", &num);
			search(head,num);
			printf("\n");
		}
		else if(task==5){
			goto END;
		}
		else{
			printf("Please Enter a Valid Operation\n");
		}
	}
	END:
	return 0;
}
