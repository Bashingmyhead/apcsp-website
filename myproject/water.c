#include <stdio.h>
#include <string.h>

char gender[256];
char weight[256];
char buffer[256];
int W;
int count;
char verify[] = "MmFf";

float Water (char gender[], int weight)
{
	float water;

	if (strcmp(gender, "M") == 0)
	{
		water = weight * 0.6;
	}
	if (strcmp(gender, "F") == 0)
	{
		water = weight * 0.5;
	}
	printf("%f ounces of water per day\n", water);
}

int main(int argc, char* argv[])
{
	sscanf(argv[1], "%s", gender);
	sscanf(argv[2], "%s", weight);

	//verify gender
	int count = 1;
	for (int i = 0; i<4; i++)
	{
		if (gender[0] == verify[i])
		{
			count = 0;
		}
	}

	if (count == 1)
	{
		printf("Please input a valid gender\n");
		return 1;
	}

	//verify weight
	if (sscanf(weight, "%d", buffer) != 1)
	{
		printf("Please input a valid integer\n");
		return 1;
	}
	else {sscanf(weight, "%d", &W);}

	Water (gender, W);

}
