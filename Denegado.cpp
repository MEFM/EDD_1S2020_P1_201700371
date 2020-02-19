#include "Denegado.h"


void Denegado::insertar(string buscar, string reemplazo, bool estado) {
	NodoDenegado* nuevo = new NodoDenegado(buscar, reemplazo, false);

	if (this->primero == 0) {
		this->primero = nuevo;
	}
	else {
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
}

void Denegado::graficar() {
	ofstream cambiosRealizados("denegado.dot");
	cambiosRealizados << "digraph a{" << endl;
	cambiosRealizados << "rankdir = LR;" << endl;
	cambiosRealizados << "node[shape = square];" << endl;
	NodoDenegado* aux = this->primero;
	while (aux != 0) {
		cambiosRealizados << "x" << aux << "[label = \"Palabra buscada = " << aux->getPalabraB() << "\\nPalabra reemplazada = " << aux->getPalabraR() << "\\nEstado = " << aux->getEstado() << "\"];" << endl;
		cambiosRealizados << "x" << aux << "->" << "x" << aux->getSiguiente() << ";" << endl;
		aux = aux->getSiguiente();
	}
	cambiosRealizados << "}" << endl;
	cambiosRealizados.close();
	system("dot -Tpng denegado.dot -o denegado.png");
	system("denegado.png");
}

void Denegado::pop() {
	if (this->primero == 0) {
		cout << "" << endl;
	}
	else {
		primero = primero->getSiguiente();
	}
}

