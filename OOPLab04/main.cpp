#include <iostream>
#include "method.h"
#include "Function.h"
using namespace std;
#define K 3

int main()
{

	Rest_aboard *a = new Rest_aboard[K];

	Input(a, K);
	Print(a, K);
	cout << endl;
	sort(a, K);
	cout << endl;
	Print(a, K);
	cout << "Sum :" << endl;

	cout << sum(a, K, "USD") << "USD" << endl;
	cout << sum(a, K, "EUR") << "EUR" << endl;;
	cout << sum(a, K, "RUR") << "RUR" << endl;
	cout << sum(a, K, "UAH") << "uah" << endl;

	delete(a);

	return 0;
}