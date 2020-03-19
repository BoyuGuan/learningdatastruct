#include <iostream>
#include "expression.h"

using namespace std;

int main() {
	char exp[50] = "#(31.54+483.2*6.65)/22.5+3#";
	cout<<EvaluateExpression(exp);
}