#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
};
int main() {
    // struct Node* head; // heaad is a variable to a node (that is it will create a space for node and will have address in it)
    // head = NULL;  // starting the value it is pointing to null
    // struct Node second;
    // second.data = 3;
    // head = &second;
    // cout << head -> data;  
    // cout << "done";

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    /* -------------- inserting numbers in two different linked list and printing them -------------------*/ 
    int n = 3;
    struct Node list1[n];
    struct Node list2[n];

    struct Node* head1 = &list1[0];
    struct Node* head2 = &list2[0];

    for(int i = 0; i < n; i++) {
        cin >> list1[i].data;
        list1[i].next = &list1[i+1];
    }

    for(int i = 0; i < n; i++) {
        cin >> list2[i].data;
        list2[i].next = &list2[i+1]; 
    }

    cout << head1 -> data;
    list1[n-1].next = NULL;

    for(int i = 0; i < n - 1; i++) {
        cout << "--->" << list1[i].next -> data;
    }

    cout << endl;
    cout << head2 -> data;
    list1[n-1].next = NULL;

    for(int i = 0; i < n - 1; i++) {
        cout << "--->" << list2[i].next -> data;
    }

    cout << endl << head1 -> next -> next << endl;

    while(head1 != NULL) {
        cout << " " << head1 -> data;
        head1 = head1 -> next;
    }

    head1 = &list1[0];
    for ( auto i = 0; i < n; i++) {
        head1 -> data = head2 -> data;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    head1 = &list1[0];
    while(head1 != NULL) {
        cout << " " << head1 -> data;
        head1 = head1 -> next;
    }
    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    
    
    cout << endl << "done";
    return 0;
}