//#include "infixToPostfix.h"
//#include "ListStack.h"
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//int GetOpPrec(char op)
//{
//	switch (op)
//	{
//	case '*':
//	case '/':
//		return 5;
//	case '+':
//	case '-':
//		return 3;
//	case '(':
//		return 1;
//
//	default:
//		break;
//	}
//
//	return -1;
//}
//
//int WhoPrecOp(char op1, char op2)
//{
//	int prec1 = GetOpPrec(op1);
//	int prec2 = GetOpPrec(op2);
//
//	if (prec1 > prec2)
//		return 1;
//	else if (prec1 < prec2)
//		return -1;
//	else
//		return 0;
//}
//
//
//
//void ConvToRPNExp(char exp[])
//{
//	//�ϴ� ���⼭ ���� ��ü ���ڿ��� �޴´�
//	//����, ���ڿ����� �ϳ��ϳ� �˻��ؼ� stack�� �����ž�
//	//�׷� �ϴ� ��ƾ��� stack �ʿ��ϰ�,
//	//���ڿ��� �ε����� ��Ÿ�� �����ϳ� �ʿ��ϰ�,
//	//���ڿ��� ���� ���� �ʿ��ϰ�
//	//��������� �迭���·� ���� exp�� ��ȯ�Ұ��̱� ������ ������ �������?�� �ʿ��ϰ�
//
//	Stack stack;
//	int expLen = strlen(exp);
//	int idx = 0;
//	int i;
//	char* convExp = (char*)malloc(expLen + 1); // +1 ���ִ� ������ ���ڿ� Ư���� ������ \n �����ΰ�?
//	memset(convExp, 0, (sizeof(char)) * expLen + 1); // sizeof(char)�� ���� �����ұ�?
//	stackInit(&stack);
//
//	char tok, popOp;
//
//	for (i = 0; i < expLen; i++)
//	{
//		tok = exp[i];
//		if (isdigit(tok))
//		{
//			convExp[idx++] = tok;
//		}
//		else
//		{
//			switch (tok)
//			{
//			case '(' :
//				stackPush(&stack, tok);
//				break;
//
//			case ')':
//				while (!stackEmpty(&stack))
//				{
//					popOp = stackPop(&stack);
//					if (popOp == '(')
//						break;
//					convExp[idx++] = popOp;
//				}
//				break;
//			
//			case '+':
//			case '-':
//			case '*':
//			case '/':
//				while (!stackEmpty(&stack) && WhoPrecOp(stackPeek(&stack), tok) >= 0)
//				{
//					convExp[idx++] = stackPop(&stack);
//				}
//
//				stackPush(&stack, tok);
//				break;						   
//			}
//		}
//	}
//
//	while (!stackEmpty(&stack))
//	{
//		convExp[idx++] = stackPop(&stack);
//	}
//
//	strcpy_s(exp, expLen + 1, convExp);
//	free(convExp);
//
//}
