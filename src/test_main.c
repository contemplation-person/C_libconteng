#include "conteng.h"

typedef struct s_TestStruct{
	int a;
	char *b;
	struct s_TestStruct* next;
} TestStruct;

void test_func(){
	//test: smart_ptr, new_mem, new_str
	smart_ptr(str) = new_str("smart pointer");
	smart_ptr(mem) = new_mem(1024);
	smart_ptr(ts) = new_mem(sizeof(TestStruct));
	TestStruct* test = ts;
	test->a = 1;
}

int main() {
	//test: let
	let(name,"hello");
	printf("%s\n",name);

	let(a, 1);
	let(b, 2);

	//test: swap
	SWAP(a, b);
	printf("a:%d b:%d\n", a, b);
}
