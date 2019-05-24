#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char data;
struct list {
	data d;
	struct list *next;

};
typedef struct list element;
typedef element *link;

link SToL (char s[]) {
	link head = NULL, tail;
	int i;

	if (s[0] != '\0')   {
		head = (link)malloc(sizeof(element));
		head->d = s[0];
		tail = head;
		for (i=1; s[i] != '\0'; i++)  {
			tail->next = (link)malloc(sizeof(element));
			tail = tail->next;
			tail->d = s[i];
		}
		tail->next = NULL;
	}
	return head;
}

int main()
{
	char s[] = "asdasd";
	cout << 	s[2];
	return 0;
}