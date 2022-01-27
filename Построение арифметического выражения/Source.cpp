#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main()
{
	int x;
	int n;
	cin >> x >> n;

	if (n == 0)
	{
		cout << x;
		return 0;
	}

	deque<string> result;
	result.push_back(to_string(x));

	string previous_operation = " ";
	while (n!=0)
	{
		string operation;
		string number;
		cin >> operation>>number;

		if ((operation == "*" || operation == "/") && (previous_operation == "+" || previous_operation == "-"))
		{
			result.push_front("(");
			result.push_back(")");
			result.push_back(" " + operation + " " + number);
		}
		else
		{
			result.push_back(" " + operation + " " + number);
		}

		previous_operation = operation;
		n--;
	}

	for (auto x : result)
	{
		cout << x;
	}
	cout << endl;

	//system("pause");
	return 0;
}