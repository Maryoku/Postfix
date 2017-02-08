#include "header.h"

double calcFunc(double arg, string func)
{
	if (func == "sin")
		return sin(arg);

	if (func == "cos")
		return cos(arg);

	if (func == "tan")
		return tan(arg);

	if (func == "asin")
		return asin(arg);

	if (func == "acos")
		return acos(arg);

	if (func == "atan")
		return atan(arg);

	if (func == "exp")
		return exp(arg);

	if (func == "ln")
		return log(arg);

	if (func == "sqrt")
		return sqrt(arg);

	if (func == "sqrt3")
		return cbrt(arg);

	return 0;
}


void calc(Node * &HelpStack, Node * &Postfix, map <string, double> &var)
{
	Node_double * rezult = NULL;
	double d = 0, b = 0, tmp = 0;
	string str2;

	while (!IsEmptyNode(HelpStack))
	{
		str2 = TopNode(HelpStack);
		if (str2.length() > 1 && (str2 == "sin" || str2 == "cos" || str2 == "tan" || str2 == "asin"
			|| str2 == "acos" || str2 == "atan" || str2 == "exp" || str2 == "ln" || str2 == "sqrt" || str2 == "sqrt3"))
		{
			PopNode(HelpStack);
			if (var.find(TopNode(HelpStack)) != var.end()) {
				PushNode_num(rezult, var.find(PopNode(HelpStack))->second);
				PushNode_num(rezult, calcFunc(PopNode_num(rezult), str2));
				PushNode_num(rezult, calcFunc(PopNode_num(rezult), str2));
			}
			else {
				cout << endl << "Key " << str2 << " doesn't found!" << endl;
				cout << "Enter " << str2 << " value: " << endl;
				cin >> tmp;
				var.insert(pair <string, double>(str2, tmp));
			}
			
		}
		else if (str2.length() >= 1 && !(str2 == "+" || str2 == "-" || str2 == "*" || str2 == "/"
			             || str2 == "^" || str2 == ")" || str2 == "("))
		{
			if (var.find(TopNode(HelpStack)) != var.end()) {
				PushNode_num(rezult, var.find(PopNode(HelpStack))->second);
			}
			else {
				cout << endl << "Key " << str2 << " doesn't found!" << endl;
				cout << "Enter " << str2 << " value: " << endl;
				cin >> tmp;
				var.insert(pair <string, double>(str2, tmp));
			}
		}

		else
		{
			if (str2 == "+") PushNode_num(rezult, (PopNode_num(rezult) + PopNode_num(rezult)));
			if (str2 == "-") PushNode_num(rezult, (-PopNode_num(rezult) + PopNode_num(rezult)));
			if (str2 == "*") PushNode_num(rezult, (PopNode_num(rezult) * PopNode_num(rezult)));
			if (str2 == "/")
			{
				d = PopNode_num(rezult);
				b = PopNode_num(rezult);
				PushNode_num(rezult, b / d);
			}
			if (str2 == "^")
			{
				d = PopNode_num(rezult);
				b = PopNode_num(rezult);
				PushNode_num(rezult, pow(b, d));
			}
			PopNode(HelpStack);
		}

	}

	printf("\nResult: %.2f\n\n", PopNode_num(rezult));
}