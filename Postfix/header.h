#ifndef HEADER
#define HEADER

#pragma warning (disable: 4996)
#include "stdio.h"
#include <iostream>
#include <string>
#include <fstream>
#include <errno.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

typedef struct Node_tag
{
	char elem;
	struct Node_tag *next;
}Node;

bool IsEmptyNode(Node *head);
bool PushNode(Node **head, char elem);
int TopNode(Node *head);
int PopNode(Node **head);
int prior(char a);
void transform(char *exp, char *outstring, Node *opers);

#endif
