#include "header.h"

int main(void)
{
	Queue Q = { NULL , NULL };
	int success = 0;

	success = is_empty(Q);

	printf("%d\n", success);

	return 0;
}