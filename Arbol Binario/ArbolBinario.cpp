#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Nodo {
	int dato;
	Nodo* izq;
	Nodo* der;
	Nodo(int val): dato(val), izq(nullptr), der(nullptr) {}

};

class ArbolBinario {
private:
	Nodo* raiz;

	void destruirArbol(Nodo* nodo) {
		if (nodo) {
			destruirArbol(nodo->izq);
			destruirArbol(nodo->der);
			delete nodo;
		}
	}
	void mostrarPreOrden(Nodo* nodo) {
		if (!nodo) return;
		cout << nodo->dato << " ";
		mostrarPreOrden(nodo->izq);
		mostrarPreOrden(nodo->der);
	}

	void mostrarInOrden(Nodo* nodo) {
		if (!nodo) return;
		mostrarInOrden(nodo->izq);
		cout << nodo->dato << " ";
		mostrarInOrden(nodo->der);
	}
	void mostrarPostOrden(Nodo* nodo) {
		if (!nodo) return;
		mostrarPostOrden(nodo->izq);
		mostrarPostOrden(nodo->der);
		cout << nodo->dato << " ";
	}

	void mostrarNiveles() {
		if (!raiz) return;

		queue<Nodo*> q;
		q.push(raiz);

		while (!q.empty()) {
			int tamaniodeNivel = q.size();
			for (int i = 0; i < tamaniodeNivel; i++) {
				Nodo* actual = q.front();
				q.pop();
				cout << actual->dato << " ";

				if (actual->izq) q.push(actual->izq);
				if (actual->der) q.push(actual->der);

			}
			cout << endl;
		}

		/*int altura(Nodo * nodo) {
			if (!nodo)return 0;
			return 1 + max(altura(nodo->izq), altura(nodo->der));

		}

		int tamanio(Nodo * nodo) {
			if (!nodo) reutrn 0;
			return 1 + tamanio(nodo->izq) + tamanio(nodo->der);
		}

		bool buscar(Nodo * nodo, int val) {
			if (!nodo) return false;
			if (nodo->dato == val) return true;
			return buscar(nodo->izq, val) || buscar(nodo->der, val);
		}*/


	}

	int altura(Nodo* nodo) {
		if (!nodo)return 0;
		return 1 + max(altura(nodo->izq), altura(nodo->der));

	}

	int tamanio(Nodo* nodo) {
		if (!nodo) return 0;
		return 1 + tamanio(nodo->izq) + tamanio(nodo->der);
	}

	bool buscar(Nodo* nodo, int val) {
		if (!nodo) return false;
		if (nodo->dato == val) return true;
		return buscar(nodo->izq, val) || buscar(nodo->der, val);
	}

public:
	ArbolBinario() : raiz(nullptr) {}
	~ArbolBinario() { destruirArbol(raiz); }

	void insertar(int val) {
		if (!raiz) {
			raiz = new Nodo(val);
			return;
		}

		queue<Nodo*> q;
		q.push(raiz);

		while (!q.empty())
		{
			Nodo* temp = q.front();
			q.pop();

			if (!temp->izq) {
				temp->izq = new Nodo(val);
				break;
			}
			else {
				q.push(temp->izq);
			}

			if (!temp->der) {
				temp->der = new Nodo(val);
				break;
			}
			else {
				q.push(temp->der);
			}
		}

	}

	void mostrar(const string& tipoRecorrido) {
		cout << "Recorrido " << tipoRecorrido << ": ";
		if (tipoRecorrido == "PreOrden")mostrarPreOrden(raiz);
		else if (tipoRecorrido == "InOrden")mostrarInOrden(raiz);
		else if (tipoRecorrido == "PostOrden")mostrarPostOrden(raiz);
		else if (tipoRecorrido == "PorNiveles") {
			cout << endl;
			mostrarNiveles();
			return;
		}
		cout << endl;
	}

	int obtenerAltura() {
		return altura(raiz);

	}
	int obtenerTamanio() {
		return tamanio(raiz);
	}

	bool existe(int val) {
		return buscar(raiz, val);
	}

	bool estaVacio() {
		return raiz == nullptr;
	}

	void limpiar() {
		destruirArbol(raiz);
		raiz = nullptr;
	}

};

void menuArbolBinario() {
	ArbolBinario arbol;
	int opcion, valor;
	do {
		cout << "\n===== MENU ARBOL BINARIO =====" << endl;
		cout << "1. Insertar valor" << endl;
		cout << "2. Mostrar PreOrden" << endl;
		cout << "3. Mostrar InOrden" << endl;
		cout << "4. Mostrar PostOrden" << endl;
		cout << "5. Mostrar por Niveles" << endl;
		cout << "6. Obtener Altura" << endl;
		cout << "7. Obtener Tamaño" << endl;
		cout << "8. Buscar valor" << endl;
		cout << "9. Verificar si esta vacio" << endl;
		cout << "10. Limpiar arbol" << endl;
		cout << "0. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "Ingrese el valor a insertar: ";
			cin >> valor;
			arbol.insertar(valor);
			break;
		case 2:
			arbol.mostrar("PreOrden");
			break;
		case 3:
			arbol.mostrar("InOrden");
			break;
		case 4:
			arbol.mostrar("PostOrden");
			break;
		case 5:
			arbol.mostrar("PorNiveles");
			break;
		case 6:
			cout << "Altura del arbol: " << arbol.obtenerAltura() << endl;
			break;
		case 7:
			cout << "Tamaño del arbol: " << arbol.obtenerTamanio() << endl;
			break;
		case 8:
			cout << "Ingrese el valor a buscar: ";
			cin >> valor;
			cout << (arbol.existe(valor) ? "El valor existe en el arbol." : "El valor NO existe en el arbol.") << endl;
			break;
		case 9:
			cout << (arbol.estaVacio() ? "El arbol esta vacio." : "El arbol NO esta vacio.") << endl;
			break;
		case 10:
			arbol.limpiar();
			cout << "Arbol limpiado correctamente." << endl;
			break;
		case 0:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
		}

	} while (opcion != 0);

	return;

}


int main() {
	menuArbolBinario();
	return 0;
}