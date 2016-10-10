#include <stdlib.h>
#include <stdio.h>

struct node { int i; struct node *next; };

void print_list( struct node *list );
struct node *insert_front( struct node *list, int data);
struct node *free_list( struct node *list);

void print_list(struct node *list){
	printf("[");
	while((*list).next != 0){
		printf("%d, ", (*list).i);
		list = (*list).next;
	}
	printf("%d]\n", (*list).i);
}

struct node* insert_front(struct node *list, int new) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    (*newNode).i = new;
    (*newNode).next = list;
    return newNode;
}

struct node* free_list(struct node *list) {
    struct node *head = list;
    struct node *temp;
    while (head) {
        temp = (*head).next;
        free(head);
        head = temp;
    }
    return list;
}

int main() {
    struct node *a = (struct node*) malloc(sizeof(struct node));
    struct node *b = (struct node*) malloc(sizeof(struct node));
    struct node *c = (struct node*) malloc(sizeof(struct node));

    (*a).i = 2;
    (*b).i = 13;
    (*c).i = 99;

    (*a).next = b;
    (*b).next = c;
    (*c).next = 0;

    print_list(a);
    a = insert_front(a, 0);
    print_list(a);
    free_list(a);
    print_list(a);
    return 0;
}