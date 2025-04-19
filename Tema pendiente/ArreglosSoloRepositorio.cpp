#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int numeros[10];
	int numerosMultiplicados[10];
	int numerosOrdenados[10];
	for (int i = 0; i < 10; i++) {
		cout << "Ingrese el numero " << i + 1 << " : ";
		cin >> numeros[i];
	}
	for (int i = 0; i < 10; i++) {
		numerosMultiplicados[i] = numeros[i] * 2;
	}
	for (int i = 0; i < 10; i++) {
		numerosOrdenados[i] = numerosMultiplicados[i];
	}
	sort(numerosOrdenados, numerosOrdenados + 10);
	cout << "\nArreglo original de numeros : ";
	for (int i = 0; i < 10; i++) {
		cout << numeros[i] << " ";
	}
	cout << endl;
	cout << "Arreglo de numeros multiplicados por 2 : ";
	for (int i = 0; i < 10; i++) {
		cout << numerosMultiplicados[i] << " ";
	}
	cout << endl;
	cout << "Arreglo de numeros ordenados : ";
	for (int i = 0; i < 10; i++) {
		cout << numerosOrdenados[i] << " ";
	}
	cout << endl;
	return 0;
}