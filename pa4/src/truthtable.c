#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum
{
	AND,
	OR,
	NAND,
	NOR,
	XOR,
	NOT,
	PASS,
	DECODER,
	MULTIPLEXER
}

mytype_struct;

struct gate
{
	mytype_struct mytype;
	int size;
	char *params[50];
};

int power(int a, int b)
{
	int x = 1;
	int i = 0;
	while (i < b)
	{
		x = x * a;
		i++;
	}

	return x;
}

char str[50];
int insize;
int outsize;

int varvals[100];
char inkeys[100][50];
char outkeys[100][50];
char varkeys[100][50];

int varsize = 0;

struct gate gatelist[100];

int LENgatelist = 0;

int main(int argc, char *argv[])
{
	FILE * fin;
	fin = fopen(argv[1], "r");

	if (fin == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}

	while (fscanf(fin, "%s", str) != EOF)
	{
		if (!strcmp(str, "INPUT"))
		{
			fscanf(fin, "%d", &insize);
			for (int i = 0; i < insize; i++)
			{
				fscanf(fin, "%s", varkeys[varsize]);
				strcpy(inkeys[i], varkeys[varsize]);
				varsize++;
			}
		}
		else if (!strcmp(str, "OUTPUT"))
		{
			fscanf(fin, "%d", &outsize);
			for (int i = 0; i < outsize; i++)
			{
				fscanf(fin, "%s", varkeys[varsize]);
				strcpy(outkeys[i], varkeys[varsize]);
				varsize++;
			}
		}
		else
		{
			struct gate thisGate;

			if (!strcmp(str, "AND"))
			{
				thisGate.mytype = AND;
				thisGate.size = 3;

				for (int i = 0; i < thisGate.size; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);
					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (strcmp(c, varkeys[j]) == 0)
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize], c);
						varvals[varsize++] = strcmp(c, "0") ? 1 : 0;
					}
				}
			}
			else if (!strcmp(str, "OR"))
			{
				thisGate.mytype = OR;
				thisGate.size = 3;
				for (int i = 0; i < thisGate.size; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);
					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (!strcmp(c, varkeys[j]))
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize], c);
						varvals[varsize++] = strcmp(c, "0") ? 1 : 0;
					}
				}
			}
			else if (!strcmp(str, "NAND"))
			{
				thisGate.mytype = NAND;
				thisGate.size = 3;
				for (int i = 0; i < thisGate.size; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);

					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (!strcmp(c, varkeys[j]))
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize], c);
						varvals[varsize++] = strcmp(c, "0") ? 1 : 0;
					}
				}
			}
			else if (!strcmp(str, "NOR"))
			{
				thisGate.mytype = NOR;
				thisGate.size = 3;
				for (int i = 0; i < thisGate.size; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);
					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (!strcmp(c, varkeys[j]))
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize], c);
						varvals[varsize++] = strcmp(c, "0") ? 1 : 0;
					}
				}
			}
			else if (!strcmp(str, "XOR"))
			{
				thisGate.mytype = XOR;
				thisGate.size = 3;
				for (int i = 0; i < thisGate.size; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);
					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (strcmp(c, varkeys[j]) == 0)
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize], c);
						varvals[varsize++] = strcmp(c, "0") ? 1 : 0;
					}
				}
			}
			else if (!strcmp(str, "NOT"))
			{
				thisGate.mytype = NOT;
				thisGate.size = 2;
				for (int i = 0; i < thisGate.size; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);
					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (!strcmp(c, varkeys[j]))
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize++], c);
					}
				}
			}
			else if (!strcmp(str, "PASS"))
			{
				thisGate.mytype = PASS;
				thisGate.size = 2;
				for (int i = 0; i < thisGate.size; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);
					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (strcmp(c, varkeys[j]) == 0)
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize++], c);
					}
				}
			}
			else if (!strcmp(str, "DECODER"))
			{
				thisGate.mytype = DECODER;
				int size;
				fscanf(fin, "%d", &size);
				thisGate.size = size;
				for (int i = 0; i < power(2, size) + size; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);
					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (!strcmp(c, varkeys[j]))
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize], c);
						varvals[varsize++] = strcmp(c, "0") ? 1 : 0;
					}
				}
			}
			else if (!strcmp(str, "MULTIPLEXER"))
			{
				thisGate.mytype = MULTIPLEXER;
				int size;
				fscanf(fin, "%d", &size);
				thisGate.size = size;
				for (int i = 0; i < power(2, size) + size + 1; i++)
				{
					char c[50];
					fscanf(fin, "%s", c);
					thisGate.params[i] = malloc(sizeof(char) *50);
					strcpy(thisGate.params[i], c);
					int flag = 0;
					for (int j = 0; j < varsize; j++)
					{
						if (!strcmp(c, varkeys[j]))
						{
							flag = 1;
							j = 1000;
						}
					}

					if (!flag)
					{
						strcpy(varkeys[varsize], c);
						varvals[varsize++] = strcmp(c, "0") ? 1 : 0;
					}
				}
			}

			gatelist[LENgatelist] = thisGate;
			LENgatelist++;
		}
	}

	for (int i = 0; i < insize; i++)
	{
		varvals[i] = 0;
	}

	for (int i = 0; i < power(2, insize); i++)
	{
		for (int j = 0; j < LENgatelist; j++)
		{
			int en[3] = { 0,
				0,
				0
			};

			int flag[3] = { 0,
				0,
				0
			};

			if (gatelist[j].mytype == AND)
			{
				for (int k = 0; k < varsize; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if (!strcmp(gatelist[j].params[l], varkeys[k]) && !flag[l])
						{
							en[l] = k;
							flag[l] = 1;
						}
					}
				}

				varvals[en[2]] = (varvals[en[0]] && varvals[en[1]]) ? 1 : 0;
			}
			else if (gatelist[j].mytype == OR)
			{
				for (int k = 0; k < varsize; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if (!strcmp(gatelist[j].params[l], varkeys[k]) && !flag[l])
						{
							en[l] = k;
							flag[l] = 1;
						}
					}
				}

				varvals[en[2]] = (varvals[en[0]] || varvals[en[1]]) ? 1 : 0;
			}
			else if (gatelist[j].mytype == NAND)
			{
				for (int k = 0; k < varsize; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if (!strcmp(gatelist[j].params[l], varkeys[k]) && !flag[l])
						{
							en[l] = k;
							flag[l] = 1;
						}
					}
				}

				varvals[en[2]] = (varvals[en[0]] && varvals[en[1]]) ? 0 : 1;
			}
			else if (gatelist[j].mytype == NOR)
			{
				for (int k = 0; k < varsize; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if (!strcmp(gatelist[j].params[l], varkeys[k]) && !flag[l])
						{
							en[l] = k;
							flag[l] = 1;
						}
					}
				}

				varvals[en[2]] = (varvals[en[0]] || varvals[en[1]]) ? 0 : 1;
			}
			else if (gatelist[j].mytype == XOR)
			{
				for (int k = 0; k < varsize; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if (!strcmp(gatelist[j].params[l], varkeys[k]) && !flag[l])
						{
							en[l] = k;
							flag[l] = 1;
						}
					}
				}

				varvals[en[2]] = ((varvals[en[0]] && !varvals[en[1]]) || (!varvals[en[0]] && varvals[en[1]])) ? 1 : 0;
			}
			else if (gatelist[j].mytype == NOT)
			{
				for (int k = 0; k < varsize; k++)
				{
					for (int l = 0; l < 2; l++)
					{
						if (!strcmp(gatelist[j].params[l], varkeys[k]) && !flag[l])
						{
							en[l] = k;
							flag[l] = 1;
						}
					}
				}

				varvals[en[1]] = (varvals[en[0]]) ? 0 : 1;
			}
			else if (gatelist[j].mytype == PASS)
			{
				for (int k = 0; k < varsize; k++)
				{
					for (int l = 0; l < 2; l++)
					{
						if (!strcmp(gatelist[j].params[l], varkeys[k]) && !flag[l])
						{
							en[l] = k;
							flag[l] = 1;
						}
					}
				}

				varvals[en[1]] = varvals[en[0]];
			}
			else if (gatelist[j].mytype == DECODER)
			{
				int newc[50];
				for (int k = 0; k < gatelist[j].size; k++)
				{
					for (int l = 0; l < varsize; l++)
					{
						if (!strcmp(gatelist[j].params[k], varkeys[l]))
						{
							newc[k] = varvals[l];
							break;
						}
					}
				}

				char news[50] = "";
				for (int k = 0; k < gatelist[j].size; k++)
				{
					char temp[50];
					sprintf(temp, "%d", newc[k]);
					strcat(news, temp);
				}

				int aaa = atoi(news);
				// printf("%i", aaa);

				int decimal = 0;
				int a = 1;
				int ones;
				while (aaa != 0)
				{
					ones = aaa % 10;
					aaa /= 10;
					decimal += ones * a;
					a *= 2;
				}

				int output;
				for (int k = 0; k < power(2, gatelist[j].size); k++)
				{
					output = k - k;
					for (int l = 0; l < varsize; l++)
					{
						if (!strcmp(gatelist[j].params[k + gatelist[j].size], varkeys[l]))
						{
							output = l;
							break;
						}
					}

					varvals[output] = (k == decimal) ? 1 : 0;
				}
			}
			else if (gatelist[j].mytype == MULTIPLEXER)
			{
				int newc[50];
				for (int k = 0; k < gatelist[j].size; k++)
				{
					for (int l = 0; l < varsize; l++)
					{
						if (!strcmp(gatelist[j].params[power(2, gatelist[j].size) + k], varkeys[l]))
						{
							newc[k] = varvals[l];
							break;
						}
					}
				}

				char news[50] = "";
				for (int k = 0; k < gatelist[j].size; k++)
				{
					char temp[50];
					sprintf(temp, "%d", newc[k]);
					strcat(news, temp);
				}

				int aaa = atoi(news);

				int decimal = 0;
				int a = 1;
				int ones;

				while (aaa)
				{
					ones = aaa % 10;
					aaa /= 10;
					decimal += ones * a;
					a *= 2;
				}

				int input;
				for (int k = 0; k < varsize; k++)
				{
					if (!strcmp(gatelist[j].params[decimal], varkeys[k]))
					{
						input = varvals[k];
						break;
					}
				}

				for (int k = 0; k < varsize; k++)
				{
					if (!strcmp(gatelist[j].params[power(2, gatelist[j].size) + gatelist[j].size], varkeys[k]))
					{
						varvals[k] = input;
						break;
					}
				}
			}
		}

		for (int j = 0; j < insize; j++)
		{
			int index = 0;
			for (int k = 0; k < varsize; k++)
			{
				if (!strcmp(inkeys[j], varkeys[k]))
				{
					index = k;
					break;
				}
			}

			printf("%d ", varvals[index]);
			if (j == insize - 1) printf("|");
		}

		for (int j = 0; j < outsize; j++)
		{
			int index = 0;
			for (int k = 0; k < varsize; k++)
			{
				if (!strcmp(outkeys[j], varkeys[k]))
				{
					index = k;
					break;
				}
			}

			printf(" %d", varvals[index]);
			if (j == outsize - 1) printf("\n");
		}

		if (i != power(2, insize) - 1)
		{
			varvals[insize - 1]++;
			for (int j = insize - 1; j >= 0; j--)
			{
				if (varvals[j] == 2)
				{
					varvals[j] = 0;
					varvals[j - 1]++;
				}
			}
		}
	}

	for (int i = 0; i < LENgatelist; i++)
	{
		int x = gatelist[i].size + power(2, gatelist[i].size);
		if (gatelist[i].mytype == DECODER)
		{
			for (int j = 0; j < x; j++)
			{
				free(gatelist[i].params[j]);
			}
		}
		else if (gatelist[i].mytype == MULTIPLEXER)
		{
			for (int j = 0; j < (x + 1); j++)
			{
				free(gatelist[i].params[j]);
			}
		}
		else
		{
			for (int j = 0; j < gatelist[i].size; j++)
			{
				free(gatelist[i].params[j]);
			}
		}
	}

	return EXIT_SUCCESS;

}
