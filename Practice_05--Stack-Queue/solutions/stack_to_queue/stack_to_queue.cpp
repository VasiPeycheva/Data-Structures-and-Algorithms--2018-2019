#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::cin;

/********** Task2 - Stack to Queue *************/

void stackToQueue()
{
	stack<int> front;
	stack<int> rear;

	short type;
	unsigned int element;
	unsigned int queries;

	cin >> queries;
	while (queries--)
	{
		cin >> type;
		if (type == 1)
		{
			cin >> element;
			rear.push(element);
		}
		else
		{
			if (front.empty())
			{
				while (!rear.empty())
				{
					front.push(rear.top());
					rear.pop();
				}
			}
			if (!front.empty())
			{
				if (type == 2)
				{
					front.pop();
				}
				if (type == 3)
				{
					cout << front.top() << '\n';
				}  
			}

		}
	}
}


int main()
{
	stackToQueue();
}