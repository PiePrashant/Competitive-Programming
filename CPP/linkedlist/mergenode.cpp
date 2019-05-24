#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node 
{ 
  int data; 
  struct Node* next; 
}; 

int getMergeNode(Node* head1, Node* head2) {
    int count1 = 0, count2 = 0;
    for(auto i = head1; i != NULL; i = i-> next) {
        count1++;
	}
	for(auto i = head2; i != NULL; i = i-> next) {
        count2++;
	}
    cout << count1<<'\n'<<count2 << endl;
    int d = count2 - count1;
    cout << "yes";
    if(d > 0) {
    	// list2 is larger than list a
    	// give head start to list 2
    	Node* str2 = head2;
    	for(int i = 0; i < d; i++) {
    		str2 = str2->next;
    	}
    	while(str2 != head1) {
    		str2 = str2 -> next;
    		head1 = head1 -> next;
    	}
    	return head1 -> data;
    }
    else {
    	// list2 is larger than list a
    	// give head start to list 2
    	Node* str1 = head1;
    	for(int i = 0; i < -d; i++) {
    		str1 = str1->next;
    	}
    	while(str1 != head2) {
    		str1 = str1 -> next;
    		head2 = head2 -> next;
    	}
    	return head2 -> data;
    }

}


int main() 
{ 
  /* 
    Create two linked lists 
  
    1st 3->6->9->15->30 
    2nd 10->15->30 
  
    15 is the intersection point 
  */
  
  struct Node* newNode; 
  struct Node* head1 = 
            (struct Node*) malloc(sizeof(struct Node)); 
  head1->data  = 10; 
  
  struct Node* head2 = 
            (struct Node*) malloc(sizeof(struct Node)); 
  head2->data  = 3; 
  
  newNode = (struct Node*) malloc (sizeof(struct Node)); 
  newNode->data = 6; 
  head2->next = newNode; 
  
  newNode = (struct Node*) malloc (sizeof(struct Node)); 
  newNode->data = 9; 
  head2->next->next = newNode; 
  
  newNode = (struct Node*) malloc (sizeof(struct Node)); 
  newNode->data = 15; 
  head1->next = newNode; 
  head2->next->next->next  = newNode; 
  
  newNode = (struct Node*) malloc (sizeof(struct Node)); 
  newNode->data = 30; 
  head1->next->next= newNode; 
  
  head1->next->next->next = NULL; 
  
  printf("\n The node of intersection is %d \n", 
          getMergeNode(head1, head2)); 
  
  getchar(); 
} 