#include "header.h"

link strtolist(char s[]) {
	link head;
	
	if(s[0] == '\0') {
		return NULL;
	}
	else {
		head = (link)malloc(sizeof(element));
		head -> d = s[0];
		head -> next = strtolist(s+1);
		return head;
	}
}

int main()
{
	char s[] = "as";
	link a;
	a = strtolist(s);
	cout << endl;
	cout << a->next->next->d << endl;
	return 0;
}