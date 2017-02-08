#include "header.h"

int main()
{
	ifstream file("expression1.txt");
	string input;

	Node *Postfix = NULL;
	Node *HelpStack = NULL;
	map <string, double> var;
	                 // \0 +/- * /  (  )  ^
	int prior[6][7] = { 4, 1, 1, 1, 1, 5, 1,   // \0
		                2, 2, 1, 1, 1, 2, 1,   // +/- 
		                2, 2, 2, 2, 1, 2, 1,   // *
		                2, 2, 2, 2, 1, 2, 1,   // /
		                5, 1, 1, 1, 1, 3, 1,   // (
		                2, 2, 2, 2, 1, 2, 2 }; // ^

	transform(file, input, HelpStack, Postfix, var, prior);
	calc(HelpStack, Postfix, var);

	return 0;
}