/*
Lets make the new node and try to add in the beginning of the first node.

Make the node by creating temp variable then try to make the links and connections to 
the data part and link part of first node.

------IMPORTANT---------
Always try to make the connection from right side i.e. link part bcoz if we make the data part connection first
then we will loose the root element address. So always make link connection first with other nodes..

*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};

struct node* root = NULL;
void main()
{
	int ch;
	while(1)
	{
		printf("1.addAtBegin");
		printf("2.addAtEnd");
		printf("3.Display");
		printf("4.Quit");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: addAtBegin()
			break;
			case 2: addAtEnd()
			break;
			case 3: display()
			break;
			case 4: exit(-1)
			default: printf("Invalid\n");
		}
	}
}


void addAtBegin(){
	
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(root == NULL){
		root = temp;
	}
	else{
		temp->link = root;		//Left side Connection with first node.
		root = temp;			//Right side Connection with root node.
	}

}

void append(){
	struct node* temp;									//Initializing the node...
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data");							// Enter data value and initially link to null value.
	scanf("%d",&temp -> data);
	temp -> link = NULL;

	if(root == NULL){
		root = temp;
	}
	else{
		struct node* p;				//Traversing till the end node and then adding the newly created node.
		p = root;
		while(p -> link != NULL){
			p = p->link;
		}
		p->link = temp;
	}
}

void display(){
	struct node* temp;
	temp = root;

	if(root == NULL){
		printf("Empty List");
	}
	else{
		while(temp != NULL){
			printf("%d ->",temp->data);
			temp = temp->link;
		}
		printf("%d", temp->data)		//Printing last element where temp is!
	}
}