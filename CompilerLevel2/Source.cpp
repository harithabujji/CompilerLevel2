#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
FILE *f1;
struct intermediate
{
	int inNo;
	int opcode;
	int *parameters;
};
void printIntermediateTable(struct intermediate **intermediatetable, int len)
{
	printf("\n\ninNO\tOpCode\t\tParameters\n");
	int i = 0, j = 0, k;
	for (i = 0; i < len; i++)
	{
		printf("\n%d", intermediatetable[i]->inNo);
		printf("\t%d", intermediatetable[i]->opcode);
		for (j = 0; j < 5; j++)
		{
			k = intermediatetable[i]->parameters[j];
			if (k > 100 || k<-100)
				printf("\t\t%s", " ");
			else
				printf("\t%d", k);
		}
	}
}
void interpreter(struct intermediate **intermediatetable, int first, int len, int *memory, int *reg)
{
	int i;
	for (i = first; i < len; i++)
	{
		if (intermediatetable[i]->opcode == 14)
		{
			printf("\n enter value :");
			scanf("%d", &reg[intermediatetable[i]->parameters[0]]);
		}
		else if (intermediatetable[i]->opcode == 1)
		{
			memory[intermediatetable[i]->parameters[0]] = reg[intermediatetable[i]->parameters[1]];
		}
		else if (intermediatetable[i]->opcode == 2)
		{
			if (intermediatetable[i]->parameters[1] == -1)
			{
				reg[intermediatetable[i]->parameters[0]] = intermediatetable[i]->parameters[2];
				//printf("\n mov reg %d %d \n", reg[intermediatetable[i]->parameters[0]], memory[intermediatetable[i]->parameters[2]]);
			}
			else
				reg[intermediatetable[i]->parameters[0]] = memory[intermediatetable[i]->parameters[1]];
		}
		else if (intermediatetable[i]->opcode == 3)
		{
			int c = reg[intermediatetable[i]->parameters[0]];
			reg[intermediatetable[i]->parameters[0]] = reg[intermediatetable[i]->parameters[1]] + reg[intermediatetable[i]->parameters[2]];
			//printf("\ncx %d %d %d %d \n", c, reg[intermediatetable[i]->parameters[0]], reg[intermediatetable[i]->parameters[1]], reg[intermediatetable[i]->parameters[2]]);
		}
		else if (intermediatetable[i]->opcode == 4)
		{
			reg[intermediatetable[i]->parameters[0]] = reg[intermediatetable[i]->parameters[1]] - reg[intermediatetable[i]->parameters[2]];
		}
		else if (intermediatetable[i]->opcode == 5)
		{
			reg[intermediatetable[i]->parameters[0]] = reg[intermediatetable[i]->parameters[1]] * reg[intermediatetable[i]->parameters[2]];
		}
		else if (intermediatetable[i]->opcode == 13)
		{
			if (intermediatetable[i]->parameters[0] == -1)
			{
				printf("\n Value is %d \n:", intermediatetable[i]->parameters[1]);
			}
			else
				printf("\n Value is %d \n:", reg[intermediatetable[i]->parameters[0]]);
		}
		else if (intermediatetable[i]->opcode == 7)
		{
			if (intermediatetable[i]->parameters[2] == 8)
			{
				if (reg[intermediatetable[i]->parameters[0]] == reg[intermediatetable[i]->parameters[1]])
				{
					interpreter(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, memory, reg);
					int x = intermediatetable[i]->parameters[3] - 2;
					i = intermediatetable[x]->parameters[0] - 1;
				}
				else
				{
					int x = intermediatetable[i]->parameters[3] - 2;
					interpreter(intermediatetable, x + 1, intermediatetable[x]->parameters[0] - 1, memory, reg);
					i = intermediatetable[x]->parameters[0] - 1;
				}
			}
			else if (intermediatetable[i]->parameters[2] == 9)
			{
				if (reg[intermediatetable[i]->parameters[0]] < reg[intermediatetable[i]->parameters[1]])
				{
					interpreter(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, memory, reg);
					int x = intermediatetable[i]->parameters[3] - 2;
					i = intermediatetable[x]->parameters[0] - 1;
				}
				else
				{
					int x = intermediatetable[i]->parameters[3] - 2;
					interpreter(intermediatetable, x + 1, intermediatetable[x]->parameters[0] - 1, memory, reg);
					i = intermediatetable[x]->parameters[0] - 1;
				}
			}
			else if (intermediatetable[i]->parameters[2] == 10)
			{
				if (reg[intermediatetable[i]->parameters[0]] > reg[intermediatetable[i]->parameters[1]])
				{
					interpreter(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, memory, reg);
					int x = intermediatetable[i]->parameters[3] - 2;
					i = intermediatetable[x]->parameters[0] - 1;
				}
				else
				{
					int x = intermediatetable[i]->parameters[3] - 2;
					if (x != 98)
					{
						interpreter(intermediatetable, x + 1, intermediatetable[x]->parameters[0] - 1, memory, reg);
						i = intermediatetable[x]->parameters[0] - 1;
					}
				}
			}
			else if (intermediatetable[i]->parameters[2] == 11)
			{
				if (reg[intermediatetable[i]->parameters[0]] <= reg[intermediatetable[i]->parameters[1]])
				{
					interpreter(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, memory, reg);
					int x = intermediatetable[i]->parameters[3] - 2;
					i = intermediatetable[x]->parameters[0] - 1;
				}
				else
				{
					int x = intermediatetable[i]->parameters[3] - 2;
					interpreter(intermediatetable, x + 1, intermediatetable[x]->parameters[0] - 1, memory, reg);
					i = intermediatetable[x]->parameters[0] - 1;
				}
			}
			else if (intermediatetable[i]->parameters[2] == 12)
			{
				if (reg[intermediatetable[i]->parameters[0]] >= reg[intermediatetable[i]->parameters[1]])
				{
					interpreter(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, memory, reg);
					int x = intermediatetable[i]->parameters[3] - 2;
					i = intermediatetable[x]->parameters[0] - 1;
				}
				else
				{
					int x = intermediatetable[i]->parameters[3] - 2;
					interpreter(intermediatetable, x + 1, intermediatetable[x]->parameters[0] - 1, memory, reg);
					i = intermediatetable[x]->parameters[0] - 1;
				}
			}

		}
		else if (intermediatetable[i]->opcode == 6)
		{
			interpreter(intermediatetable, intermediatetable[i]->parameters[0] - 1, i, memory, reg);
		}
	}
}
void generateCFile(struct intermediate **intermediatetable, int first, int len,char regnames[8][3],char variables[26],int *alive,int *regalive)
{
	int i;
	for (i = first; i < len; i++)
	{
		if (intermediatetable[i]->opcode == 14)
		{
			if (regalive[intermediatetable[i]->parameters[0]] == 0)
			{
				fprintf(f1, "int %s;\n", regnames[intermediatetable[i]->parameters[0]]);
				fprintf(f1, "scanf(\"%%");
				fprintf(f1, "d\",&%s);\n", regnames[intermediatetable[i]->parameters[0]]);
				regalive[intermediatetable[i]->parameters[0]] = 1;
			}
			else
			{
				//fprintf(f1, "int %s;\n", regnames[intermediatetable[i]->parameters[0]]);
				fprintf(f1, "scanf(\"%%");
				fprintf(f1, "d\",&%s);\n", regnames[intermediatetable[i]->parameters[0]]);
			}
		}
		else if (intermediatetable[i]->opcode == 1)
		{
			if (alive[intermediatetable[i]->parameters[0]] == 0)
			{
				fprintf(f1, "int %c;\n", variables[intermediatetable[i]->parameters[0]]);
				fprintf(f1, "%c=%s;\n", variables[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]]);
				alive[intermediatetable[i]->parameters[0]] = 1;
			}
			else
				fprintf(f1, "%c=%s;\n", variables[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]]);
		}
		else if (intermediatetable[i]->opcode == 2)
		{
			if (intermediatetable[i]->parameters[1] == -1)
			{
				if (regalive[intermediatetable[i]->parameters[0]] == 0)
				{
					fprintf(f1, "int %s;\n", regnames[intermediatetable[i]->parameters[0]]);
					fprintf(f1, "%s=%d;\n", regnames[intermediatetable[i]->parameters[0]], intermediatetable[i]->parameters[2]);
					regalive[intermediatetable[i]->parameters[0]] =1;
				}
				else
				{
					fprintf(f1, "int %s;\n", regnames[intermediatetable[i]->parameters[0]]);
					fprintf(f1, "%s=%d;\n", regnames[intermediatetable[i]->parameters[0]], intermediatetable[i]->parameters[2]);
				}
				
			}
			else
				if (regalive[intermediatetable[i]->parameters[0]] == 0)
				{
					fprintf(f1, "int %c;\n", variables[intermediatetable[i]->parameters[1]]);
					fprintf(f1, "%s=%c;\n", regnames[intermediatetable[i]->parameters[0]], variables[intermediatetable[i]->parameters[1]]);
					regalive[intermediatetable[i]->parameters[0]] = 1;
				}
				else
					fprintf(f1, "%s=%c;\n", regnames[intermediatetable[i]->parameters[0]], variables[intermediatetable[i]->parameters[1]]);

		}
		else if (intermediatetable[i]->opcode == 3)
		{
			if (regalive[intermediatetable[i]->parameters[0]] == 0)
			{
				fprintf(f1, "int %s;\n", regnames[intermediatetable[i]->parameters[0]]);
				fprintf(f1, "%s=%s+%s;\n", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]], regnames[intermediatetable[i]->parameters[2]]);
				regalive[intermediatetable[i]->parameters[0]] =1;
			}
			else
				fprintf(f1, "%s=%s+%s;\n", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]], regnames[intermediatetable[i]->parameters[2]]);
			
		}
		else if (intermediatetable[i]->opcode == 4)
		{
			if (regalive[intermediatetable[i]->parameters[0]] == 0)
			{
				fprintf(f1, "int %s;\n", regnames[intermediatetable[i]->parameters[0]]);
				fprintf(f1, "%s=%s-%s;\n", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]], regnames[intermediatetable[i]->parameters[2]]);
				regalive[intermediatetable[i]->parameters[0]] = 1;
			}
			else
			fprintf(f1, "%s=%s-%s;\n", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]], regnames[intermediatetable[i]->parameters[2]]);
		}
		else if (intermediatetable[i]->opcode == 5)
		{
			if (regalive[intermediatetable[i]->parameters[0]] == 0)
			{
				fprintf(f1, "int %s;\n", regnames[intermediatetable[i]->parameters[0]]);
				fprintf(f1, "%s=%s*%s;\n", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]], regnames[intermediatetable[i]->parameters[2]]);
				regalive[intermediatetable[i]->parameters[0]] = 1;
			}
			else
			fprintf(f1, "%s=%s*%s;\n", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]], regnames[intermediatetable[i]->parameters[2]]);
		}
		else if (intermediatetable[i]->opcode == 13)
		{
			if (intermediatetable[i]->parameters[0] == -1)
			{
				fprintf(f1, "printf(\"%d\");\n", intermediatetable[i]->parameters[0]);
			}
			else
			{
				fprintf(f1, "printf(\"%%");
				fprintf(f1, "d\",%s);\n", regnames[intermediatetable[i]->parameters[0]]);
			}
		}
		else if (intermediatetable[i]->opcode == 7)
		{
			if (intermediatetable[i]->parameters[2] == 8)
			{
				
				fprintf(f1, "if(%s==%s){", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]]);
				//generateCFile(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2,regnames,variables,alive,regalive);
			}
			else if (intermediatetable[i]->parameters[2] == 9)
			{
				fprintf(f1, "if(%s<%s){", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]]);
				//generateCFile(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, regnames, variables, alive, regalive);
			}
			else if (intermediatetable[i]->parameters[2] == 10)
			{
				fprintf(f1, "if(%s>%s){", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]]);
				//generateCFile(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, regnames, variables, alive, regalive);
			}
			else if (intermediatetable[i]->parameters[2] == 11)
			{
				fprintf(f1, "if(%s<=%s)\n{", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]]);
				//generateCFile(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, regnames, variables, alive, regalive);
			}
			else if (intermediatetable[i]->parameters[2] == 12)
			{
				fprintf(f1, "if(%s>=%s){", regnames[intermediatetable[i]->parameters[0]], regnames[intermediatetable[i]->parameters[1]]);
				//generateCFile(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, regnames, variables, alive, regalive);
			}

		}
		else if (intermediatetable[i]->opcode == 16)
		{
			fprintf(f1, "}\nelse\n{");
			//generateCFile(intermediatetable, i + 1, intermediatetable[i]->parameters[3] - 2, regnames, variables, alive, regalive);
		}
		else if (intermediatetable[i]->opcode == 15)
		{
			fprintf(f1, "}\n");
		}
		else
		{
		}
	}
}
void main()
{
	int i = 0,lenintermediatetable=0;
	struct intermediate **intermediatetable = (struct intermediate**)malloc(30 * sizeof(intermediate*));
	for (i = 0; i < 30; i++)
	{
		intermediatetable[i] = (struct intermediate*)malloc(sizeof(intermediate));
		intermediatetable[i]->parameters = (int*)malloc(5 * sizeof(int));
	}
	int *memory = (int *)calloc(40, sizeof(int));
	int *registercodes = (int *)calloc(8, sizeof(int));
	FILE *fp;
	fopen_s(&fp,"hari.txt", "r");
	if (fp == 0)
	{
		printf("\nenter the correct file name\n");
		exit(0);
	}
	char *line = (char *)malloc(sizeof(char)*60);
	while (fgets(line, 60, fp) != NULL)
	{
		char *text = (char *)malloc(sizeof(char) * 60);
		strcpy(text, line);
		text = strtok(text, " ");
		intermediatetable[lenintermediatetable]->inNo = atoi(text);
		text=strtok(NULL, " ");
		intermediatetable[lenintermediatetable]->opcode = atoi(text);
		for (i = 0; i < 5; i++)
		{
			text = strtok(NULL, " ");
			intermediatetable[lenintermediatetable]->parameters[i] = atoi(text);
		}
		lenintermediatetable++;
	}
	fclose(fp);
	printIntermediateTable(intermediatetable, lenintermediatetable);
	//interpreter(intermediatetable, 0, lenintermediatetable, memory, registercodes);
	char regnames[8][3] = { "AX", "BX" ,"CX","DX","EX","FX","GX","HX" };
	char variables [26]= { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char *name= (char *)malloc(sizeof(char) * 60);
	int *alive = (int *)calloc(26, sizeof(int));
	int *regalive = (int *)calloc(8, sizeof(int));
    printf("\n Enter the C filename:");
	fflush(stdin);
	gets(name);
    fopen_s(&f1, name, "w");
	if (f1 == 0)
	{
		printf("\nenter the correct file name\n");
		exit(0);
	}
	fprintf(f1, "#define _CRT_SECURE_NO_WARNINGS\n#include<stdio.h>\n#include<stdlib.h>\n#include<string.h>\nvoid main()\n{\n");
	generateCFile(intermediatetable, 0, lenintermediatetable,regnames,variables,alive,regalive);
	fprintf(f1, "system(\"pause\");\n}");
	fclose(f1);
	getchar();
}