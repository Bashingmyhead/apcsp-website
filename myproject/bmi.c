#include <stdio.h>
#include <string.h>

//initializing character list
char arrInfoBMI[5][100] = {"heightft", "heightin", "weight", "age", "gender"};
char arrInputBMI[5][100];

//verification of information function
void verify (int cmdLine, char Info[], char Input[])
{
char holding[100];
if (strcmp(Info, "gender") == 0)
{
	while(1)
	{
	if (!(strcmp(Input, "F") == 0) && !(strcmp(Input, "M") == 0))
		{
		printf("Please type either M (male) or F (female) for your gender.\n");
		if (cmdLine == 0) {
		  fgets(holding, 100, stdin);
		  sscanf(holding, "%s", Input);
		}
		else {break;}
		}
		else {break;}
	}
}
if (strcmp(Info, "age") == 0 || strcmp(Info, "weight") == 0 || strcmp(Info, "height (ft)") == 0 || strcmp(Info, "height (in)") == 0)
{
	while(1)
	{
	if (sscanf(Input, "%d", holding) == 0)
		{
		printf("Please input a valid number.\n");
		if (cmdLine == 0) {
			fgets(holding, 100, stdin);
			sscanf(holding, "%s", Input);
		} else {break;}
		}
		else {break;}
	}
}
}


//print BMI
float bmi (char feet[], char inches[], char weight[])
{
	float bmi;
	float in;
	float ft;
	float total;
	float W;
	sscanf(feet, "%f", &ft);
	sscanf(inches, "%f", &in);
	sscanf(weight, "%f", &W);

	total = in + (ft * 12);
	bmi = (W/total/total) * 703;
	printf("%f. \n", bmi);
}


//start of actual program
int main(int argc, char* argv [])


{

  if (argc == 6) {
    sscanf(argv[1], "%s", arrInputBMI[0]);
    sscanf(argv[2], "%s", arrInputBMI[1]);
    sscanf(argv[3], "%s", arrInputBMI[2]);
    sscanf(argv[4], "%s", arrInputBMI[3]);
    sscanf(argv[5], "%s", arrInputBMI[4]);
  }

 for (int i = 0; i < 5; i++)
 {
  verify(argc!=1, arrInfoBMI[i], arrInputBMI[i]);
 }

  bmi(arrInputBMI[0], arrInputBMI[1], arrInputBMI[2]);
}
