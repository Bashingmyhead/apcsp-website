#include <stdio.h>
#include <string.h>

char gender[256];
char weight[256];
int W;

void verifyGender(char input[])
{
                if (!(strcmp(input, "F") == 0) && !(strcmp(input, "M") == 0) == 0 )
                {
                        printf("Please type and M or F for your gender\n");
			return 1;
                }

}

void verifyWeight(char input[])
{

		if (sscanf(input, "%d", weight) != 1)
		{
			printf("Please input a valid integer\n");
			return 1;
		}
		else { sscanf(weight, "%d", &W);}
}


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
	printf("%f\n", water);
}

int main(int argc, char* argv[])
{
	char prompt [2][10] = {"gender","weight"};
	for (int i = 1; i < 3; i++)
	{
	sscanf(argv[i], "%s", prompt[i-1]);
	}

	sscanf(prompt[0], "%s", gender);
	sscanf(prompt[1], "%s", weight);

	verifyGender(gender);
	verifyWeight(weight);

	sscanf(weight, "%d", &W);

	Water (gender, W);

	return 0;
}
