#include <iostream>

using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

//Funcion agregar elementos a la lista
void agregarNodo(Nodo*& cabeza, int valor) {
	Nodo* nuevoNodo = new Nodo; //Creando el apuntador hacia el nuevo nodo
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = nullptr;

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
	}
	else {
		Nodo* actual = cabeza;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		actual->siguiente = nuevoNodo;
	}

}
void imprimirlista(Nodo* cabeza) {
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->dato << " ";
		actual = actual->siguiente;
	}
	cout << endl;
}

void borrarLista(Nodo* cabeza) {
	while (cabeza != nullptr) {
		Nodo* siguiente = cabeza->siguiente;
		delete cabeza;
		cabeza = siguiente;
		cout << "Elemento borrado ";
	}
}


int main() {
	Nodo* cabeza = nullptr; //Declaramos un puntero de memoria nulo
	int tamanolista;
	cout << "Ingrese la cantidad de elementos que desea agregar a la lista:";
	cin >> tamanolista;

	if (tamanolista <=0) {
		cout << "Cantidad de elementos no valida" << endl;
		return 1;
	}
	for (int i = 0; i < tamanolista; i++) {
		int valor;
		cout << "Ingrese dato" << i + 1 << ": ";
		cin >> valor;
		//Invocamos nuestra funcion de agregar Nodo
		agregarNodo(cabeza, valor);

	}

	cout << "Imprimiendo lista de numeros" << endl;
	imprimirlista(cabeza);

		borrarLista(cabeza);

		return 0;
}