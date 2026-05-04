#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Gerbong {
    int id;
    struct Gerbong* next;
} Gerbong;

void sortGerbong (Gerbong* head){
    if (head == NULL) {
        printf("id kosong.\n");
        return;
    }
}

void addGerbong(struct Gerbong **head, int id){ 
    Gerbong* newGerbong = (Gerbong*)malloc(sizeof(Gerbong));
    newGerbong->id = id;
    
    // Append di head
    newGerbong->next = *head;
    *head = newGerbong;
} 

void bubbleSort(struct Gerbong *head){ 
    int swapped, i; 
    struct Gerbong *ptr1; 
    struct Gerbong *lptr = NULL; 

    /* Checking for empty list */
    if (head == NULL) 
        return; 

    do
    { 
        swapped = 0; 
        ptr1 = head; 

        while (ptr1->next != lptr) 
        { 
            if (ptr1->id > ptr1->next->id) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}

void swap(struct Gerbong *a, struct Gerbong *b) 
{ 
    int temp = a->id; 
    a->id = b->id; 
    b->id = temp; 
}

void printList(struct Gerbong *start){ 
    struct Gerbong *temp = start; 
    printf("MERGE "); 
    while (temp!=NULL) 
    { 
        printf("%d ", temp->id); 
        temp = temp->next; 
    } 
}

struct Gerbong* createGerbong(int id) {
    struct Gerbong* newGerbong
      = (struct Gerbong*)malloc(sizeof(struct Gerbong));
    newGerbong->id = id;
    newGerbong->next = NULL;
    return newGerbong;
}

struct Gerbong* mergeList(struct Gerbong* head1, struct Gerbong* head2) {
    struct Gerbong* dummy = createGerbong(-1);
    struct Gerbong* curr = dummy;

    // Iterate through both linked lists
    while (head1 != NULL && head2 != NULL) {
        if (head1->id <= head2->id) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    if (head1 != NULL) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }
    return dummy->next;
}

int main(){
    int n, i, id;
    struct Gerbong *head1 = NULL; 
    struct Gerbong *head2 = NULL; 
    struct Gerbong *head3 = NULL; 

    // List 1
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &id);
        addGerbong(&head1, id);
    }
    bubbleSort(head1);

    // List 2
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &id);
        addGerbong(&head2, id);
    }
    bubbleSort(head2);

    struct Gerbong* result = mergeList(head1, head2);
    printList(result);
    return 0; 
}
