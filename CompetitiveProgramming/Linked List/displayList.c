/*
So, now its time to display the list after we have append it.
We have added the nodes in the beggining, middle and at the end so lets look at the elements 
we have entered.


*/

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