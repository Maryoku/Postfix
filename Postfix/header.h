#ifndef HEADER
#define HEADER

#include <fstream>
#include <map> 
#include <stdio.h>
#include <iostream>
#include "stack_header.h"

using namespace std;

void transform(ifstream &fStream, string &str, Node * &HelpStack, Node * &Postfix, map <string, double> &var, int prior[6][7]);
double calcFunc(double arg, string func);
void calc(Node * &HelpStack, Node * &Postfix, map <string, double> &var);

#endif