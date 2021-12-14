#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

struct Node
{
    int data;
    struct Node *next;
};
 
int linkedListTraversal(struct Node *ptr, bool a)
{
	struct Node *ktr;
	struct Node *rtr;
    ktr = (struct Node *)malloc(sizeof(struct Node));
	rtr = (struct Node *)malloc(sizeof(struct Node));
    rtr = ptr;
	if(a==0){
		int t=0;
	    while (ptr != ktr)
	    {
		    ktr = rtr;	
	        ptr = ptr->next;
	        t++;
	    }
	    return t;
	}
	else{
		while(ptr!=ktr){
			ktr = rtr;				
			printf("%d\n", ptr->data);
			ptr = ptr->next;			 	
		}
	}
	
}

void insert(struct Node *ptr, int pos, int val){
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	int num = linkedListTraversal(ptr, 0);
	
	for(int i=1; i<pos-1; i++){
	    ptr = ptr->next;
	}
	temp->next = ptr->next;
	ptr->next = temp;
	temp->data = val;
}
 
void del(struct Node *ptr, int pos){
 	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
 	int num = linkedListTraversal(ptr, 0);
 	
 	if (pos!=1){
 		for(int i=1; i<pos-1; i++){
			ptr = ptr->next;
		}
		temp->next = ptr->next;
		temp = temp->next;		   
		ptr->next = temp->next; 
	}
	else{
		temp = ptr->next;
		ptr->data = temp->data;
		ptr->next = temp->next;	 
	}
}
 
void search(struct Node *ptr, int val){
	int t = 0;
	struct Node *ktr;
	struct Node *rtr;
    ktr = (struct Node *)malloc(sizeof(struct Node));
	rtr = (struct Node *)malloc(sizeof(struct Node));
    rtr = ptr;
	while(ptr!=ktr){
		ktr = rtr;
		t++;
		if(ptr->data==val){
			printf("%s", "Position: ");
			printf("%d\n", t);
		}
		ptr = ptr->next; 
	}
} 
 
void menu(){
	printf("%s", "Enter:\n '1' for Viewing the Linked List\n '2' for Inserting an Element\n '3' for Deleting an Element\n '4' for Searchung the Position of an Element\n");
	printf("%s", " '5' for Viewing the Options\n '6' for Quiting\n");
} 
 
int main()
{
 	struct Node *head;

    head = (struct Node *)malloc(sizeof(struct Node));
	
    head->data = 1;
    head->next = head;	
 	
 	int task;
 	int pos, val;
 	menu();
	while(1){
		printf("%s", "\nEnter: ");
		scanf("%d", &task);
					
		if (task==1){
		   	linkedListTraversal(head,1);
		}
	    else if(task==2){   	
		 	printf("%s", "Enter the Position where you want to Insert an Element: ");   	
		 	scanf("%d", &pos);
 	  		printf("%s", "Enter the Value of the Element: ");   	
		 	scanf("%d", &val);
	   		insert(head, pos, val);
	    }
	    else if(task==3){   	
		 	printf("%s", "Enter the Position where you want to Delete an Element: ");   	
		 	scanf("%d", &pos);
	   		del(head, pos);
	    }
	    else if(task==4){   	
		 	printf("%s", "Enter the Value of the Element you want to find the Position for: ");   	
		 	scanf("%d", &val);
	   		search(head, val);
	    }   
		else if(task==5){
	 	    menu();
		}
		else if(task==6){
  		    break;	
		}    
	}
	
    return 0;
}
