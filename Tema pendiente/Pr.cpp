#include <iostream>
using namespace std;
int main()
{
	int numeros[10];
	int numerosPares[10];
	int numerosImpares[10];
	int Pares = 0;
	int Impares = 0;
	for (int i = 0; i < 10; i++) {
		cout << "Ingrese los 10 numeros del Array: ";
		cin >> numeros[i];
	}
	cout << endl;
	cout << " Array original : ";
	for (int i = 0; i < 10; i++) {
		cout << numeros[i] << " ";
	}
	for (int i = 0; i < 10; i++) {
		if (numeros[i] % 2 == 0) {
			numerosPares[Pares] = numeros[i];
			Pares++;
		}
		else
		{
			numerosImpares[Impares] = numeros[i];
			Impares++;
		}
	}
	if (Pares == 0) {
		cout << endl;
		cout << "No se encontraron nueros Pares: ";
	}
	else {
		cout << endl;
		cout << " Numerso Pares ; ";
		for (int i = 0; i < Pares; i++) {
			cout << numerosPares[i] << " ";
		}
	}
	if (Impares == 0) {
		cout << endl;
		cout << "No se encontraron numeros Impares: ";
	}
	else {
		cout << endl;
		cout << " Numeros Impares : ";
		for (int i = 0; i < Impares; i++) {
			cout << numerosImpares[i] << " ";
		}
	}
	cout << endl;
	return 0;
}