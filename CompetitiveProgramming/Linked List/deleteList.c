/*
Now let's start deleting the node from the beginning or any location you want.
It means you can remove any node from the list just by giving the location.

*/

void delete(){
	struct node* temp;
	int loc,len;
	printf("Enter the location: "); // Ask the location from the user
	scanf("%d",&loc);

len = length()
	if(loc > len){
		printf("Invalid Location");		// Check if loc is valid or not.
	}

	else if(loc == 1){				//Deleting the node at beginning...
		temp = root;
		root = temp->link;
		temp->link = NULL;
		free(temp);
	}

	else{						// Deleting the node from somewhere in the middle or at the end.
		struct node* p;
		struct node* q;
		p = root;
		while(i < loc-1){
			p = p->link;
			i++;
		}
		q = p->link;
		p->link = q->link;
		q->link = NULl;
		free(q); 
	}
}