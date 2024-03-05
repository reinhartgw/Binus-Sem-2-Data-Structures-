#include <stdio.h>
#include <stdlib.h>
// Double Linked List

struct data{
	int age;
	struct data *next;
	struct data *prev;
};

struct data *head = NULL;
struct data *tail = NULL;

struct data *createNode(int age){
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->next = NULL;
	node->prev = NULL;
	node->age = age;
	
	return node;
}

void pushHead(int age){
	struct data *node = createNode(age);
	node->next = head;
	head->prev = node;
	
	head = node;	
}

void pushTail(int age){
	struct data *node = createNode(age);
	node->prev = tail;
	tail->next = node;
	
	tail = node;
}

void pushMid(int age){
	struct data *temp = head;
    struct data *node = createNode(age);

    // Find the middle position
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int mid = count / 2;

    // Traverse to the middle position
    count = 0;
    temp = head;
    while (count < mid && temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Insert the node
    node->next = temp->next;
    node->prev = temp;
    temp->next->prev = node;
    temp->next = node;
}

void popHead(){\
	if(head==NULL)
		return;
		
	struct data *temp = head;
	head = head->next;
	if(head != NULL)
		head->prev = NULL;
	else
		tail = NULL;
	
	free(temp);
}

void popTail(){
	if(tail == NULL)
		return;
		
	struct data *temp = tail;
	tail = tail->prev;
	if(tail != NULL)
		tail->next = NULL;
	else
		head = NULL;
		
	free(temp);
}

void popSearch(int age){
	struct data *temp = head;

    // Find the node with the given age
    while (temp != NULL) {
        if (temp->age == age) {
            if (temp == head) {
                head = temp->next;
                head->prev = NULL;
            } else if (temp == tail) {
                tail = temp->prev;
                tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Data with age %d not found\n", age);
}

void printLinkedList(){
	struct data *temp = head;
	int count=1;
	while(temp!=NULL){
		printf("Data %d: %d\n", count, temp->age);
		temp = temp->next;
		count++;
	}
}

int main(){
	head = createNode(2);
	tail = createNode(5);
	
	head->next = tail;
	tail->prev = head;
	
	pushHead(1);
	pushTail(10);
	pushMid(3);
	pushMid(7);
	popHead();
	popTail();
	popSearch(5);
	printLinkedList();
	
	return 0;
}
