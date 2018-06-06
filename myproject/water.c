#include <stdio.h>
#include <string.h>

char arrPrompt[4][100] = {"name","gender (M/F)","age","weight"};
char arrInput[4][100];

void verify(char prompt[], char input[])
{
char buffer[256];
	if (strcmp(prompt, "gender (M/F)") == 0 )
	{
		while(1)
		{
		if (!(strcmp(input, "F") == 0) && !(strcmp(input, "M") == 0))
		{
			printf("Please type and M or F for your gender\n");
			fgets(buffer, 256, stdin);
			sscanf(buffer, "%s", input);
			verify("name", input);
		}
			else {break;}
		}
	}
	if (strcmp(prompt, "age") == 0 || strcmp(prompt, "weight") == 0)
	{
		char q[256];
		while(1)
		{
		if (sscanf(input, "%d", buffer) != 1)
		{
			printf("Please input a valid integer\n");
			fgets(buffer, 256, stdin);
			sscanf(buffer, "%s", input);
			verify(q, input);
		}
			else {break;}
		}
	}
}

float Water (char gender[], char weight[])
{
	float water;
	float W;
	//how do I get the char weight into a float so I can multiply this 
	sscanf(weight, "%f", &W);
	if (strcmp(gender, "M") == 0)
	{
		water = W * 0.6;
	}
	if (strcmp(gender, "F") == 0)
	{
		water = W * 0.5;
	}
	printf("You need to drink %f ounces of water a day\n", water);
}

int main()
{
        char input[256];

        printf("Welcome! Please input your information\n");

	for (int i=0; i<4; i++)
	{
		printf("Enter your %s:\n", arrPrompt[i]);
		fgets(input, 256, stdin);
		sscanf(input, "%s", arrInput[i]);
		verify(arrPrompt[i], arrInput[i]);
	}

	Water (arrInput[1], arrInput[3]);
}
