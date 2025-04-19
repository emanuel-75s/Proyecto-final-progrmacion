#include <iostream>
using namespace std;

class Cola {
private:
	class Nodo {
	public:
		int valor;
		Nodo* siguiente;

	};
	Nodo* frente;
	Nodo* final;
public:
	Cola();
	~Cola();
	void insertar(int valor);
	int extraer();
	void imprimir();
	bool estaVacia();

};

Cola::Cola() {
	frente = NULL;
	final = NULL;
}

Cola::~Cola() {
	Nodo* actual = frente;
	Nodo* temporal;
	while (actual != NULL) {
		temporal = actual;
		actual = actual->siguiente;
		delete temporal;
	}
}

void Cola::insertar(int valor) {
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->valor = valor;
	nuevoNodo->siguiente = NULL;
	if (estaVacia()) {
		frente = nuevoNodo;
		final = nuevoNodo;
	}
	else {
		final->siguiente = nuevoNodo;
		final = nuevoNodo;
	}
}

int Cola::extraer() {
	if (!estaVacia()) {
		int valorExtraido = frente->valor;
		Nodo* temporal = frente;
		if (frente == final) {
			frente = NULL;
			final = NULL;
		}
		else {
			frente = frente->siguiente;
		}
		delete temporal;
		return valorExtraido;
	}
	return -1;
}
void Cola::imprimir() {
	Nodo* actual = frente;
	cout << "Listado de todos los elementos de la cola: " << endl;
	while (actual != NULL) {
		cout << actual->valor << " - ";
		actual = actual->siguiente;
		cout << endl;
	}
}
bool Cola::estaVacia() {
	return frente == NULL;
}

class Pila {
private:
	class Nodo {
	public:
		int valor;
		Nodo* siguiente;
	};
	Nodo* tope;
public:
	Pila();
	~Pila();
	void insertar(int valor);
	int extraer();
	void imprimmir();
	bool estaVacia();
};

Pila::Pila() {
	tope = NULL;
}

Pila::~Pila() {
	Nodo* actual = tope;
	Nodo* temporal;
	while (actual != NULL) {
		temporal = actual;
		actual = actual->siguiente;
		delete temporal;
	}
}

void Pila::insertar(int valor) {
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->valor = valor;
	nuevoNodo->siguiente = tope;
	tope = nuevoNodo;
}

int Pila::extraer() {
	if (tope != NULL) {
		int valorExtraido = tope->valor;
		Nodo* temporal = tope;
		tope = tope->siguiente;
		delete temporal;
		return valorExtraido;
	}
	return -1;
}

void Pila::imprimmir() {
	Nodo* actual = tope;
	cout << "Listado de todods los elementos Pila; " << endl;
	while (actual != NULL) {
		cout << actual->valor << " - ";
		actual = actual->siguiente;
	}
	cout << endl;
}

bool Pila::estaVacia() {
	return tope == NULL;
}

int main() {
	Cola* cola = new Cola();
	Pila* pila = new Pila();
	int opcion, valor;
	char confirmacion;

	do {
		cout << "------------------------------------" << endl;
		cout << "_-_-_-_-_-_-_- Menu -_-_-_-_-_-_-_-_" << endl;
		cout << "------------------------------------" << endl;
		cout << "1. Agregar Valores a Pila y Cola    " << endl;
		cout << "2. -Menu Cola                       " << endl;
		cout << "3. -Menu Pila                       " << endl;
		cout << "4.  Salir                           " << endl;
		cout << " -----------------------------------" << endl;
		cout << "  INGRESE UNA OPCION                " << endl;
		cin >> opcion;
		system("cls");

		while (cin.fail() || opcion < 1 || opcion >4) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << " Opcion no valida, ingrese una opcion de 1 a 4";
			cin >> opcion;
		}
		switch (opcion) {

		case 1: {
			cout << "INGRESE UN VALOR PARA INSERTAR EN LA COLA Y EN LA PILA ";
			cin >> valor;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Opcion invalida. ingrese un numero enre: ";
				cin >> valor;
			}
			cola->insertar(valor);
			pila->insertar(valor);
			cout << " valor insertado correctamente al a pila y cola " << endl;
			break;
		}
		case 2: {
			int subopcion;
			do {
				cout << "---Menu Cola---" << endl;
				cout << "---------------" << endl;
				cout << "1.- Insertar" << endl;
				cout << "2.- Extraer " << endl;
				cout << "3.- Imprimir " << endl;
				cout << "4.- Regresar al menu principal" << endl;
				cout << "-----------------" << endl;
				cout << "Ingrese una opcion : " << endl;
				cin >> subopcion;
				system("cls");

				while (cin.fail() || subopcion < 1 || subopcion > 4) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Opcion invalida. Ingrese un numero entre 1 y 4: ";
					cin >> subopcion;
				}
				switch (subopcion) {
				case 1:
					cout << "Ingrese un valor para insertar en la cola: ";
					cin >> valor;
					cola->insertar(valor);
					cout << "Valor insertado correctamente.\n";
					break;
				case 2:
					if (cola->estaVacia()) {
						cout << "La cola esta vacia, no se puede extraer.\n";
					}
					else {
						cout << "Elemento extraido: " << cola->extraer() << "\n";
					}
					break;
				case 3:
					cola->imprimir();
					break;
				case 4:
					cout << "Regresando al menu principal...\n";
					break;
				}
			} while (subopcion != 4);
			break;
		}
		case 3: {
			int subopcion;
			do {
				cout << "---Menu Pila---" << endl;
				cout << "---------------" << endl;
				cout << "1.- Insertar" << endl;
				cout << "2.- Extraer " << endl;
				cout << "3.- Imprimir " << endl;
				cout << "4.- Regresar al menu principal" << endl;
				cout << "----------------" << endl;
				cout << "Ingrese una opcion : " << endl;
				cin >> subopcion;
				system("cls");

				while (cin.fail() || subopcion < 1 || subopcion > 4) {
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Opcion invalida. Ingrese un numero entre 1 y 4: ";
					cin >> subopcion;
				}
				switch (subopcion) {
				case 1:
					cout << "Ingrese un valor para insertar en la pila: ";
					cin >> valor;
					pila->insertar(valor);
					cout << "Valor insertado correctamente.\n";
					break;
				case 2:
					if (pila->estaVacia()) {
						cout << "La pila esta vacia, no se puede extraer.\n";
					}
					else {
						cout << "Elemento extraido: " << pila->extraer() << "\n";
					}
					break;
				case 3:
					pila->imprimmir();
					break;
				case 4:
					cout << "Regresando al menu principal...\n";
					break;
				}
			} while (subopcion != 4);
			break;

		}
		case 4: {
			cout << " Al salir todos los cambios se perderan!!" << endl;
			cout << " ¿Esta seguro que desea salir? ( s / n ): ";
			cin >> confirmacion;
			if (confirmacion == 's' || confirmacion == 'S') {
				cout << " Saliendo del progrmaa .............." << endl;
				exit(0);
			}
			break;
		}
		default:
			cout << "opcion invalida " << endl;
		}

	} while (opcion != 4);
	delete cola;
	delete pila;

	return 0;
}





