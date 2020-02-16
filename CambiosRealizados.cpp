#include "CambiosRealizados.h"



void CambiosRealizados::push(string buscar, string reemplazo, bool estado) {
	NodoCambios* nuevo = new NodoCambios(buscar, reemplazo, estado);

	if (primero == 0) {
		primero = nuevo;

		//insertListaOrdenadaB(nuevo->getPalabraB());
		//insertListaOrdenadaR(nuevo->getPalabraR());
	}
	else {
		//insertListaOrdenadaB(nuevo->getPalabraB());
		//insertListaOrdenadaR(nuevo->getPalabraR());
		nuevo->setSiguiente(primero);
		primero = nuevo;
	}
}

void CambiosRealizados::insertListaOrdenadaB(string palabraB) {
	NodoCambios* nuevo = new NodoCambios(palabraB, "", true);

	if (this->primeroB == 0) {
		this->primeroB = nuevo;
	}
	else {
		//Insertar Ordenado
		NodoCambios* auxiliar = this->primeroB;

		while (auxiliar->getSiguiente() != 0 && strcmp(auxiliar->getPalabraB().c_str(), auxiliar->getSiguiente()->getPalabraB().c_str()) > 0) {

			auxiliar = auxiliar->getSiguiente();
		}
		if (auxiliar->getSiguiente() != 0) {
			nuevo->setSiguiente(auxiliar->getSiguiente());
		}
		auxiliar->setSiguiente(nuevo);
	}
}

void CambiosRealizados::insertListaOrdenadaR(string palabraR) {
	NodoCambios* nuevo = new NodoCambios("", palabraR, true);

	if (this->primeroR == 0) {
		cout << "No hay palabras" << endl;
	}
	else {
		//Insertar Ordenado
		NodoCambios* auxiliar = this->primeroR;

		while (auxiliar->getSiguiente() != 0 && strcmp(auxiliar->getPalabraR().c_str(), auxiliar->getSiguiente()->getPalabraR().c_str()) > 0) {
			auxiliar = auxiliar->getSiguiente();
		}
		if (auxiliar->getSiguiente() != 0) {
			nuevo->setSiguiente(auxiliar->getSiguiente());
		}
		auxiliar->setSiguiente(nuevo);
	}
}

void CambiosRealizados::pop() {
	if (this->primero == 0) {
		cout << "Nada" << endl;
	}
	else {

		primero = primero->getSiguiente();
	}
}

void CambiosRealizados::eliminarListaB() {
	if (this->primeroB == 0) {
		cout << "" << endl;
	}
	else {
		primeroB = primeroB->getSiguiente();
		eliminarListaR();
	}
}

void CambiosRealizados::eliminarListaR() {
	if (this->primeroR == 0) {
		cout << "Esta vacio" << endl;
	}
	else {
		primeroR = primeroR->getSiguiente();
	}
}

void CambiosRealizados::graficar() {
	ofstream cambiosRealizados("cambios.dot");
	cambiosRealizados << "digraph a{" << endl;
	cambiosRealizados << "rankdir = LR;" << endl;
	cambiosRealizados << "node[shape = square];" << endl;
	NodoCambios* aux = this->primero;
	while (aux != 0) {
		cambiosRealizados << "x" << aux << "label[Palabra buscada = \"" << aux->getPalabraB() << "\nPalabra reemplazada = \"" << aux->getPalabraR() <<" ];" << endl;
		cambiosRealizados << "x" << aux << "->" << "x" << aux->getSiguiente() << ";" << endl;
		aux = aux->getSiguiente();
	}
	cambiosRealizados << "}" << endl;
	cambiosRealizados.close();
	system("dot -Tpng cambios.dot -o cambios.png");
	system("cambios.png");
}

void CambiosRealizados::graficarBuscadas() {
	ofstream cambiosRealizados("cambiosB.dot");
	cambiosRealizados << "digraph a{" << endl;
	cambiosRealizados << "rankdir = LR;" << endl;
	cambiosRealizados << "node[shape = square];" << endl;
	NodoCambios* aux = this->primeroB;
	while (aux != 0) {
		cambiosRealizados << "x" << aux << "label[Palabra buscada = \"" << aux->getPalabraB() << "\nPalabra reemplazada = \"" << aux->getPalabraR() << "\nEstado = " << aux->getEstado() << "];" << endl;
		cambiosRealizados << "x" << aux << "->" << "x" << aux->getSiguiente() << ";" << endl;
		aux = aux->getSiguiente();
	}
	cambiosRealizados << "}" << endl;
	cambiosRealizados.close();
	system("dot -Tpng cambiosB.dot -o cambiosB.png");
	system("cambiosB.png");
}

void CambiosRealizados::graficarReemplazadas() {
	ofstream cambiosRealizados("cambiosR.dot");
	cambiosRealizados << "digraph a{" << endl;
	cambiosRealizados << "rankdir = LR;" << endl;
	cambiosRealizados << "node[shape = square];" << endl;
	NodoCambios* aux = this->primeroR;
	while (aux != 0) {
		cambiosRealizados << "x" << aux << "label[Palabra buscada = \"" << aux->getPalabraB() << "\nPalabra reemplazada = \"" << aux->getPalabraR() << "\nEstado = " << aux->getEstado() << "];" << endl;
		cambiosRealizados << "x" << aux << "->" << "x" << aux->getSiguiente() << ";" << endl;
		aux = aux->getSiguiente();
	}
	cambiosRealizados << "}" << endl;
	cambiosRealizados.close();
	system("dot -Tpng cambiosR.dot -o cambiosR.png");
	system("cambiosR.png");
}