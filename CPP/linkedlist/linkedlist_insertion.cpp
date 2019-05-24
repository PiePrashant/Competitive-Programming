#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node *insertNodebegining(struct Node *head, int new_data );
struct Node *insertNodeend(struct Node *head, int new_data );
void printNode(struct Node* head);


int main() {

    int test = 1; //cin >> test;
    while(test--) {
        int n; cin >> n;
        int a;
        int flag;
        struct Node *head = (struct Node*)malloc(sizeof(struct Node)); 
        head = NULL;

        for(int i = 0; i < n; i++) {
            cin >> a;
            cin >> flag;
            if(flag == 0) {
                head = insertNodebegining(head, a);
            }
            else {
                head = insertNodeend(head, a);
            }
        }

        printNode(head);
        cout << endl ;
        printf("hi there");
    }

    return 0;
}


struct Node *insertNodebegining(struct Node *head, int new_data) {
    
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node -> data = new_data;
        new_node -> next = head;
        head = new_node;
        return head;  
}

struct Node *insertNodeend(struct Node *head, int new_data) {
    
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    if(head == NULL) {
        head = new_node;
        head -> data = new_data;
        head -> next = NULL;
        
    }
    else {
        while(temp -> next != NULL) {
        temp = temp -> next;
        }
        new_node -> data = new_data;
        new_node -> next = NULL;
        temp -> next = new_node;
        
       
    }
     return head;
}

void printNode(struct Node *head) {
    while(head != NULL){
        cout << head -> data;
        head = head -> next;
        cout << " ";
    }
    return;
}