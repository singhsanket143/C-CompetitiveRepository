/*
Lets make the new node and try to add in the middle of the first node.

Now we have to add the node in middle of 2 nodes. So we will first make connection of link part with right node and then
the connection of left node to the new node.

To do this we need 2 pointers because we will enter the value from user where we have to insert the new node that 
is called location then after the location we will add newly created node.....

*/

void addAtMiddle(){
	struct node* temp;
	struct node* p;
	int i, len, loc;

	printf("Enter the location");
	scanf("%d",&loc);

	len = length();			//length function defined in next commit.
	if(loc > len){
		printf("wrong Location");
	}
	else{
		p = root;
		while(i<loc){
			p = p->link;
			i++;
		}
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Emter node data");
		scanf("%d",&temp->data);
		temp->link = p->link;		//Building Connections.
		p->link = temp;
	}
}