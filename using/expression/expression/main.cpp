#include <iostream>
#include "expression.h"

using namespace std;

int main() {
	char exp[50] = "#31.5+5*4-(2+4)/3+60+0.4#";
	cout<<EvaluateExpression(exp);
}