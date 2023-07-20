#include <stdio.h>
#include <string.h>

struct customer {
	char name[40];
	int age;
};

int main(void)
{
	// 나)
	struct customer aCustomer = {"박수희", 36};
	printf("Name = %s, Age = %d\n", aCustomer.name, aCustomer.age);

	// 다)
	struct customer cArray[2] = { {"장동건", 38}, {"고소영", 38} };
	for (int i = 0; i < 2; i++)
		printf("Name = %s, Age = %d\n", cArray[i].name, cArray[i].age);

	// 라)
	struct customer* p = &aCustomer;
	printf("Name = %s, Age = %d", p->name, p->age);
}