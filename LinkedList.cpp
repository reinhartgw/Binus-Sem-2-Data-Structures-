#include <stdio.h>
#include <stdlib.h>
// Single Linked List

struct data{
	int age;
	struct data *next;
	
};

struct data *createNode(int age){
	// dynamic memory allocation and typecasting
	struct data *node = (struct data*)malloc(sizeof(struct data));
	// -> similar to ., for example *data.age is similar to node->age, how to access an attribute of a data
	node->next=NULL;
	node->age=age;
	return node;
}

// push = insert data
struct data *pushHead(struct data *head, int age){
	struct data *node = createNode(age);
	node->next = head;
	head = node;
	return head;
}

struct data *pushTail(struct data *head, int age){
	struct data *node = createNode(age);
	struct data *temp = head; // stores the same variable address as head, to check the last node
	
	// assign temp to last node
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = node;
	return head;
}

// pop = delete data
struct data *popHead(struct data *head){
	struct data *temp = head;
	// assign new value at head to store 2nd address
	head = head->next;
	free(temp);
	
	return head;
}

struct data *popTail(struct data *head){
	struct data *del = head;
	struct data *temp = head;
	
	while(del->next != NULL){
		temp = del;
		del = del->next;
	}
	temp->next = NULL;
	free(del);
	return head;
}

struct data* pushMid(struct data* head, int age, int pos) {
    struct data* node = createNode(age);
    struct data* temp = head;
    int count = 1;
    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position is not within range\n");
        return head;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}

struct data* popSearch(struct data* head, int age) {
    struct data* temp = head;
    struct data* prev = NULL;
    // iterates until temp is empty and it finds the age that is same
    while (temp != NULL && temp->age != age) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data not found\n");
        return head;
    }
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

void printLinkedList(struct data *head){
	struct data *temp;
	temp = head;
	int count = 1;
	while(temp!=NULL){
		printf("Data %d: %d\n", count, temp->age);
		temp = temp->next;
		count++;
	}
}

int main(){
	struct data *head;
	head = createNode(10);
	head = pushHead(head, 5); // Insert from the front
	head = pushHead(head, 2);
	head = pushTail(head, 15); // Insert from the back
	head = popHead(head);
	head = popTail(head);
	head = pushMid(head, 7, 2); // Inserting 7 at position 2
    head = popSearch(head, 5);  // Deleting node with age 5
	printLinkedList(head);
	
	return 0;
}
	
