#include "header.h"

int prior(char a)
{
	switch (a)
	{
	case '*':
	case '/':
		return 3;

	case '-':
	case '+':
		return 2;

	case '(':
		return 1;
	}
}

void transform(char *exp, char *outstring, Node *opers)
{
	int count = 0, outcount = 0;

	while (exp[count] != '\0')
	{ 
		if (exp[count] == ')') {
			while ((opers->elem) != '(') {
				outstring[outcount++] = PopNode(&opers);
			}
			PopNode(&opers); 
		}


		if (exp[count] >= 'a' && exp[count] <= 'z') {
			outstring[outcount++] = exp[count];
		}


		if (exp[count] == '(') {
			PushNode(&opers, '(');
		}


		if (exp[count] == '+' || exp[count] == '-' || exp[count] == '/' || exp[count] == '*')
		{
			if (IsEmptyNode(opers)) {
				PushNode(&opers, exp[count]);
			}
			else {
				if (prior(opers->elem) < prior(exp[count])) {
					PushNode(&opers, exp[count]);
				}
				else {
					while ((!IsEmptyNode(opers)) && (prior(opers->elem) >= prior(exp[count])))
						outstring[outcount++] = PopNode(&opers);
					PushNode(&opers, exp[count]);
				}
			}
		}

		count++;
	}

	while (!IsEmptyNode(opers)) {
		outstring[outcount++] = PopNode(&opers);
	}
	outstring[outcount] = '\0';
}
