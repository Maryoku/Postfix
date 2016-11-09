#include "header.h"

int main()
{
	SetConsoleCP(1251); // russian
	SetConsoleOutputCP(1251);

	Node *opers = NULL;
	char exp[80];
	char outstring[80];
	int counter = 0;

	ifstream input("expression.txt");

	while (!input.eof()) {
		input.get(exp[counter]);
		counter++;
	}
	counter--; // особая магия ибо всплывает странный символ "|-"
	exp[counter] = '\0';

	printf("%s\n", exp);

	transform(exp, outstring, opers);

	printf("%s\n", outstring);
}