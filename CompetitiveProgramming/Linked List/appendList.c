/*
Let's start writing the code to append the list. We have to check for if list contains elements 
before the insertion or not.

Then start adding the nodes to the list by creating the temporary node that will 
vanish off after the addition.

*/

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