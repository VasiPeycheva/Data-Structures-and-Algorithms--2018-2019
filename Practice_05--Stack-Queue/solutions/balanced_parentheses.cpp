#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;
using std::cout;
using std::cin;


/********** Task1 - Check for balanced parentheses *************/

/**
* help variables for isOpen(char) and match(char,char) functions
*/
char open[] = { '(', '[', '{' ,'<'};
char close[] = { ')', ']', '}' , '>'};

/**
* check if the given symbol is open parentheses
*/
bool isOpen(char symbol) {
	for (int i = 0; i < sizeof(open); i++) {
		if (symbol == open[i]) {
			return true;
		}
	}
	return false;
}

/**
* It checks if both openBracket and closing bracket are same type parentheses
* and they match
*/
bool match(char openBracket, char closingBracket) {
	for (int i = 0; i < sizeof(close); i++) {
		if (openBracket == open[i] && closingBracket == close[i]) {
			return true;
		}
	}
	return false;
}

/**
* Check if given string is correctly closed parentheses. To solve this task we
* use one Stack. Each time if the symbol is open bracket, we push it into the
* Stack. If it is closing bracket, we check if in the top of the stack we have
* the same type bracket, but opening one. If two brackets do not match, we push
* the symbol into the Stack. In the end we see if we have symbols in the stack.
* If so, that means we have incorrect brackets order (not correctly closed)
*/
bool isCorrect(const string & str) {
	stack<char> openedBrackets;
	for (int i = 0; i < str.length(); i++) {
		if (isOpen(str[i])) {
			openedBrackets.push(str[i]);
		}
		else if ((openedBrackets.size() > 0) && match(openedBrackets.top(), str[i])) {
			openedBrackets.pop();
		}
		else 
			return false;
	}
	return openedBrackets.empty();
}

int main()
{
	string brackets[] = {"[]","{)","())", "[(])" ,"<()()[()]><{()}>", "[(])<[]>[{{}]}" };

	for (string expression : brackets)
	{
		std::cout << "brackets " << expression << " are ";
		if (isCorrect(expression))
		{
			cout << "correct \n";
		}
		else
		{
			cout << "incorrect \n";
		}
	}

	return 0;
}