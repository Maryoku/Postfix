#include "header.h"

void transform(ifstream &file, string &input, Node * &HelpStack, Node * &Postfix, map <string, double> &var, int prior[6][7])
{
	string output, func;
	char name;
	double value = 0;
	int flag = 0, i = 0, j = 0;
	bool mark = 0;

	getline(file, input);

	cout << "infix:\n" << input << endl;

	PushNode(HelpStack, "\0");
	file >> name; // считываем посимвольно т.к. переменная char

	while (file)
	{
		while (name != '=')
		{
			output += name; // посимвольно закидываю имя переменной
			file >> name; // считываю след. символ
		}
		file >> value; // считываю число

		var.insert(pair <string, double>(output, value)); // сую в map
		
		file >> name; // считываю начало следующей переменной
		output = ""; // обнуляю output
	}

	for (auto it = var.begin(); it != var.end(); ++it)
	{
		cout << it->first << "=" << it->second << endl;
	}

	for (int k = 0; flag == 0; k++)
	{
		if (!isalnum(input[k])) //является ли буквой или цифрой (цифра-буква - 1, иначе - 0)
		{
			if (k >= 1)
			{
				if ((input[k - 1] == '+' || input[k - 1] == '-' || input[k - 1] == '*' || input[k - 1] == '/'
					|| input[k - 1] == '^') && ((input[k] == '+' || input[k] == '-' || input[k] == '*' 
						|| input[k] == '/' || input[k] == '^')))
				{
					printf("Uncorrect expression!\n");
					exit(1);
				}
			}

			if (mark == 1)
			{
				//определение строки как название функции или название переменной
				if (!(func == "sin" || func == "cos" || func == "tan" || func == "asin" || func == "acos"
					     || func == "atan" || func == "exp" || func == "ln" || func == "sqrt" || func == "sqrt3")) {
					func = func;
				}
				
				PushNode(Postfix, func);
				func = "";
				mark = 0;
			}

			if (TopNode(HelpStack) == "\0") i = 0;
			if (TopNode(HelpStack) == "+") i = 1;
			if (TopNode(HelpStack) == "-") i = 1;
			if (TopNode(HelpStack) == "*") i = 2;
			if (TopNode(HelpStack) == "/") i = 3;
			if (TopNode(HelpStack) == "(") i = 4;
			if (TopNode(HelpStack) == "^") i = 5;

			switch (input[k])
			{
			case '\0': j = 0; break;
			case '+': j = 1; break;
			case '-': j = 1; break;
			case '*': j = 2; break;
			case '/': j = 3; break;
			case '(': j = 4; break;
			case ')': j = 5; break;
			case '^': j = 6; break;
			}

			switch (prior[i][j])
			{
			case 1: output = input[k]; PushNode(HelpStack, output);  break;
			case 2: PushNode(Postfix, PopNode(HelpStack)); k--;  break;
			case 3: PopNode(HelpStack);  break;
			case 4: flag = 1; break;
			case 5: flag = 2; break;
			}
		}
		else
		{
			mark = 1;
			func += input[k];
		}
	}

	while (!IsEmptyNode(Postfix))
		PushNode(HelpStack, PopNode(Postfix));

	cout << endl << "postfix:\n";

	while (!IsEmptyNode(HelpStack))
	{
		output = TopNode(HelpStack);
		PushNode(Postfix, PopNode(HelpStack));
		cout << output;
	}
	cout << endl;

	while (!IsEmptyNode(Postfix))
		PushNode(HelpStack, PopNode(Postfix));
}