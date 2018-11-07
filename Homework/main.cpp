#include "Stack.h"
#include <stdio.h>
#include <conio.h>
using namespace std;
int main()
{
	int n;
	cout << "Enter the amount of memory allocated" << endl;
	cin >> n;
	Calc a(n);
	int f;
	int Elem;
	int v = 0;
	while (v != 27)
	{
		system("cls");
		cout << "Select operation " << '\n' << endl;
		cout << "1. Operation plus" << endl << "2. Opereation minus" << endl << "3. Operation undo" << endl;
		cout << "4. Operation do" << endl << "5. Clear the history" << endl << "6. Allocate new memory" << endl;
		cout << "7. Exit" << endl;
		cout << a;
		cin >> f;
		cout << endl;
		try{
			switch (f)
			{
			case 1:
				system("cls");
				cout << "Enter your element" << endl;
				cin >> Elem;
				a.plus(Elem);
				break;
			case 2:
				system("cls");
				cout << "Enter your element" << endl;
				cin >> Elem;
				a.minus(Elem);
				break;
			case 3:
				system("cls");
				a.fundo();
				break;
			case 4:
				system("cls");
				a.fdo();
				break;
			case 5:
				system("cls");
				a.clr();
				break;
			case 6:
				system("cls");
				a.newmem(n);
				cout << "Enter the amount of memory allocated" << endl;
				cin >> n;
				break;
			case 7:
				v = 27;
				break;
			}
		}
		catch(...){}
	}
	return 0;
}