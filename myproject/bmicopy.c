#include <stdio.h>
#include <string.h>

//initializing character list
char arrInfoBMI[6][100] = {"name", "age", "gender (M/F)", "height (ft)", "height (in)",  "weight"};
char arrInputBMI[6][100];


//verification of information function
void verify (char Info[], char Input[])
{
char holding[100];
if (strcmp(Info, "gender (M/F)") == 0)
{
	while(1)
	{
	if (!(strcmp(Input, "F") == 0) && !(strcmp(Input, "M") == 0))
		{
		printf("Please type either M (male) or F (female) for your gender.\n");
		fgets(holding, 100, stdin);
		sscanf(holding, "%s", Input);
		verify ("gender (M/F)", Input);
		}
		else {break;}
	}
}
if (strcmp(Info, "age") == 0 || strcmp(Info, "weight") == 0 || strcmp(Info, "height (ft)") == 0 || strcmp(Info, "height (in)") == 0)
{
	char d[100];
	while(1)
	{
	if (sscanf(Input, "%d", holding) == 0)
		{
		printf("Please input a valid number.\n");
		fgets(holding, 100, stdin);
		sscanf(holding, "%s", Input);
		verify(d, Input);
		}
		else {break;}
	}
}
}

//Inches is less than 12
void inchesCheck(char Info[], char Input[])
{
if (strcmp(Info, "height (in)") == 0)
{
	//changing into number instead of string
	float H;
	sscanf(arrInputBMI[4], "%f", &H);

	char holding[100];
	while(1)
	{
	if (H > 12)
		{
		printf("Please enter a valid height for inches that is under 12.\n");
		fgets(holding, 100, stdin);
		sscanf(holding, "%s", Input);
		inchesCheck(holding, Input);
		}
	else {break;}
	}
}
}

//print BMI
float bmi (char inches[], char feet[], char weight[])
{
	float bmi;
	float in;
	float ft;
	float total;
	float W;
	sscanf(arrInputBMI[5], "%f", &W);
	sscanf(arrInputBMI[4], "%f", &in);
	sscanf(arrInputBMI[3], "%f", &ft);

	total = in + (ft * 12);
	bmi = (W/total/total) * 703;
	printf("Your BMI is  %f. \n", bmi);
}


//start of actual program
int main()

{
	char input[256];

	printf("Hello! Please input your information.\n");


  for (int i = 0; i < 6; i++)
  {
  printf("Enter your %s:\n", arrInfoBMI[i]);
  fgets(input, 256, stdin);
  sscanf(input, "%s", arrInputBMI[i]);
  verify(arrInfoBMI[i], arrInputBMI[i]);
  }


	for (int i = 0; i < 5; i++)
	{
	printf("%s: %s\n", arrInfoBMI[i], arrInputBMI[i]);
	}

bmi(arrInputBMI[4], arrInputBMI[3], arrInputBMI[5]);
	
}
