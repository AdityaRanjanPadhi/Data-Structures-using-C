#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
 
int linkedListTraversal(struct Node *ptr, struct Node *ktr, char a)
{
	if(a==0){
		int t=0;
	    while (ptr != NULL)
	    {
	        ptr = ptr->next;
	        t++;
	    }
	    return t;
	}
	else if(a==1){
 	    while(ptr!=NULL){
		    printf("%d\n", ptr->data);
		    ptr = ptr->next;			 	
	    }
	}
	else if(a==2) {
	    while(ktr!=NULL){
		    printf("%d\n", ktr->data);
		    ktr = ktr->prev;			 	
	    } 	
	} 
}
 
void insert(struct Node *ptr, struct Node *ktr, int pos, int val){
	struct Node *temp;
	struct Node *temph;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temph = (struct Node *)malloc(sizeof(struct Node));
	int num = linkedListTraversal(ptr,ptr,0);
	if(pos==1){
		temp->data=ptr->data;
	 	temp->next=ptr->next;
	 	temp->prev=ptr;
		temph = ptr->next;
		temph->prev=temp; 			   
   		ptr->data=val;
	  	ptr->next=temp;
	}
	else if(pos==num+1){
		temp->data = ktr->data;
	 	temp->next = ktr;
   		temp->prev = ktr->prev;
		temph = ktr->prev;
		temph->next = temp;
		ktr->prev = temp;
		ktr->data = val; 
	}
	else if(pos!=1 && pos!=num+1){
		for(int i=1; i<pos-1; i++){
		    ptr = ptr->next;
		}
		temp->prev=ptr;	 
		temp->next = ptr->next;
		temph = ptr->next;
		temph->prev = temp;
		ptr->next = temp;
		temp->data = val;
	}
} 
 
void del(struct Node *ptr, struct Node *ktr, int pos){
	struct Node *temp;
	struct Node *temph;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temph = (struct Node *)malloc(sizeof(struct Node));
	int num = linkedListTraversal(ptr,ptr,0);
	if(pos==1){
		temp = ptr->next;
		ptr->data = temp->data;
		ptr->next = temp->next;
		temph = temp->next;
		temph->prev = ptr;	 
	}
	else if(pos==num){
		temp = ktr->prev;
		ktr->data = temp->data;
		ktr->prev = temp->prev;
		temph = temp->prev;
		temph->next = ktr;	 
	}
	else if(pos!=1 && pos!=num){
		for(int i=1; i<pos-1; i++){
		    ptr = ptr->next;
		}
		temp = ptr->next;
		temph = temp->next;
		ptr->next = temph;
		temph->prev = ptr;	 
	}
} 

void search(struct Node *ptr, int val){
	int t = 0;
	while(ptr!=NULL){
		t++;
		if(ptr->data==val){
			printf("%s", "Position: ");
			printf("%d\n", t);
		}
		ptr = ptr->next; 
	}
}

void menu(){
	printf("%s", "Enter:\n '1' for Viewing the Linked List\n '2' for Inserting an Element\n '3' for Deleting an Element\n '4' for Searching the Position of an Element\n");
	printf("%s", " '5' for Viewing the Options\n '6' for Quiting\n");
}
 
int main()
{
 	struct Node *head;
 	struct Node *end;

    head = (struct Node *)malloc(sizeof(struct Node));
    end = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = end;
    head->prev = NULL;
 	
 	end->data = 0;
 	end->next = NULL;
 	end->prev = head;
 	
 	menu();
 	
 	int task;
 	int pos, val;
 	while(1){
 		printf("%s", "\nEnter: ");
		scanf("%d", &task);
	
		if (task==1){
		   	printf("%s", "Enter: '1' to Print Elements from Start\n       '2' to Print Elements from End\n");
	    	printf("%s", "Type: ");
			scanf("%d", &val);
 	  		if(val==1){
			    linkedListTraversal(head,end,1);
	   		}
			else{
		 	    linkedListTraversal(head,end,2);	  	
			}  		  
		}
		else if (task==2){
	 	    printf("%s", "Enter the Position where you want to Insert an Element: ");   	
		 	scanf("%d", &pos);
 	  		printf("%s", "Enter the Value of the Element: ");   	
		 	scanf("%d", &val);	
  		    insert(head,end,pos,val);	
		}
		else if (task==3){
	 	    printf("%s", "Enter the Position where you want to Delete an Element: ");   	
		 	scanf("%d", &pos);	
  		    del(head,end,pos);	
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
