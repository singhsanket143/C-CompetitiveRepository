/*
Now let us start with Linked Lists.

It is a type of dynamic collection. Elements are stored in the form of nodes.
Nodes contains two parts:
1) data part. (Stores data inside)
2) link part. (connect one node to other)(Stores the address of the previous node.)

There are 3 types of linked list i.e. 
.Single linked Lists
.Double linked Lists
.Circular linked Lists

First we will discuss "single linked list" and various operations on it.

So, let's make a setup int his and we will use this a s a common for all the operations.
(Also called Implementation)
*/

#include<stdio.h>
#include<stdlib.h>

struct node{				//Node Creation
	int data;
	struct node* link; 
};
struct node* root = NULL;		//First node always connect to root node that contains only address

void main(){
	int choice;
	while(1){
		printf("1. Add at End\n");
		printf("2. Add at Begin\n");
		printf("3. Add at Middle\n");
		printf("4. Delete the node\n");
		printf("5. Display\n");
		printf("6. Length\n");
		printf("7. Node Swap\n");
		printf("8. Reverse the list\n");
		printf("9. Sort\n");
		printf("10. Quit\n");
		
		printf("enter the choice");
		scanf("%d",&choice);

		switch(choice){
			case 1: append();				//Fn's that we are going to perform on Single LInked list. 
			break;
			case 2: addAtBegin();
			break;
			case 3: addAtMiddle();
			break;
			case 4: delete();
			break;
			case 5: display();
			break;
			case 6: length();
			break;
			case 7: swap();
			break;
			case 8: sort();
			break;
			case 9: exit(0);
			break;
			default : printf("Wrong Choice");
		}
	}
}

// Will be adding regularly about the List.... Stay Tuned!