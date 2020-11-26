#include <iostream>
#include <iomanip>
using namespace std;


class Node 
{

        public:
            int data;
        Node * next;

    };
void printList(Node* head)
{
    for(; head != NULL; head = head->next)
        {
            cout << head->data << endl;
        }
}

void push(struct Node ** head_ref, int new_data){
        struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));
        new_node->data=new_data;
        new_node->next=(* head_ref);
        (* head_ref)=new_node;
}

void append(struct Node ** head_ref, int new_data) {
    struct Node * new_node = (struct Node * )malloc(sizeof(struct Node));
    struct Node * last = * head_ref;
    new_node ->data = new_data;
    new_node->next=NULL;
    while(last->next != NULL)
        last = last->next;
        last->next = new_node;

}
void insertAfter(struct Node * prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }
    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}



int main (){
    
    Node * head = NULL;
    Node * four = NULL;
    Node * third = NULL;

    head = new Node();
    four = new Node();
    third = new Node();

    head->data = 1;
    head->next = four;

    four -> data = 2;
    four ->next = third;

    third ->data = 3;
    third -> next = NULL;

    printList(head);
    push(&head, 11);
    printList(head);
    append(&third,11);
    printList(head);
    insertAfter(four, 12);
    printList(head);

    return 0;
}
