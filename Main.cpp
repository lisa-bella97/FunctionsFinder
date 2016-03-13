#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List
{
	char* value;
	unsigned int num;
	struct List *next;
} List;

/** \func void pushBack(List *&head, List *&end, List *p) */
void pushBack(List *&head, List *&end, List *p)
{
	p->next = NULL;
	if (head == NULL)
		head = end = p;
	else
	{
		end->next = p;
		end = p;
	}
}

/**
\func List * pop(List *&head)
*/
List * pop(List *&head)
{
	if (head == 0) return 0;
	List *p = head;
	head = head->next;
	return p;
}

/**
\func int main(int argc, char* argv[])
*/
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("ERROR!!!\n");
		return 1;
	}
	FILE *pF;
	List * head = NULL, *end = NULL, *p;
	char* fileName = new char[256];
	unsigned int n = 0;

	sscanf_s(argv[1], "%s", fileName);
	pF = fopen(fileName, "r");

	if (pF == NULL)
	{
		printf("Error: file is not found.\n");
		return 1;
	}

	int i = 0;
	const unsigned int MAX = 500;
	char* text = new char[MAX];
	int size = 0;
	while (!feof(pF))
	{
		if (i >= MAX - 1)
			i = 0;
		text[i] = getc(pF);
		if (text[i] == '/')
		{
			i++;
			text[i] = getc(pF);
			if (text[i] == '*')
			{
				i++;
				text[i] = getc(pF);
				if (text[i] == '*')
				{
					i++;
					text[i] = getc(pF);
					while (true)
					{
						if (text[i] == '*')
						{
							i++;
							text[i] = getc(pF);
							if (text[i] == '/')
							{
								size = i - 2;
								break;
							}
						}
						if (text[i] == '\\')
						{
							i++;
							text[i] = getc(pF);
							if (text[i] == 'f')
							{
								i++;
								text[i] = getc(pF);
								if (text[i] == 'u')
								{
									i++;
									text[i] = getc(pF);
									if (text[i] == 'n')
									{
										i++;
										text[i] = getc(pF);
										if (text[i] == 'c')
										{
											i++;
											text[i] = getc(pF);
											if (text[i] == ' ' || text[i] == '\n')
											{
												i = 0;
												text[i] = getc(pF);
											}
										}
									}
								}
							}
						}
						i++;
						text[i] = getc(pF);
					}
					if (size > 0)
					{
						p = new List;
						p->value = new char[size + 1];
						for (int j = 0; j < size; j++)
						{
							if (text[j] == '\n')
								text[j] = ' ';
							p->value[j] = text[j];
						}
						p->value[size] = '\0';
						p->num = ++n;
						pushBack(head, end, p);
						size = 0;
						i = 0;
					}
				}
			}
		}
		i++;
	}

	for (p = head; p; p = p->next)
		printf("%d. %s\n", p->num, p->value);

	while (p = pop(head))
	{
		delete[]p->value;
		delete p;
	}

	delete[] text;
	delete[] fileName;
	fclose(pF);
	return 0;
}