#include <iostream>
#include "expression.h"

using namespace std;

int main() {
	char exp[50] = "#(7-2)*3#";
	cout<<EvaluateExpression(exp);
}