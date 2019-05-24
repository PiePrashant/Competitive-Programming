#include <iostream>
#include <stdlib.h>
using namespace std;
typedef char data;
struct list {
	data d;
	struct list* next;

};
typedef list element;
typedef element* link;