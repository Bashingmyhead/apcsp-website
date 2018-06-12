#include <stdio.h>

int main(int argc, char* argv[])
{
	char name[256];
	sscanf(argv[1], "%s", &name);
	printf("test %s\n", name);
}
