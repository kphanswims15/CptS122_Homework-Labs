#include "function.h"

int main(void)
{
	Node *pTop = NULL;
	int num = 0;
	double data = 3.3, data2 = 6.7, num2 = 0.0;

	//num = isEmpty(pTop);
	push(&pTop, data);
	push(&pTop, data2);
	pop(&pTop);
	num2 = peek(pTop);
	printf("%.2lf\n", num2);
	print_list(pTop);
	
	/*if (num == 0)
	{
		printf("True.\n");
	}
	else
	{
		printf("False.\n");
	}*/

	return 0;
}