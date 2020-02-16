#include "Archivo.h"

void Archivo::insertar(CambiosRealizados cambios, Denegado* rechazado, LetrasTexto* texto, string nombre) {
	NodoArchivo* nuevo = new NodoArchivo(cambios, rechazado, texto, nombre);


	if (this->primero == 0) {
		this->primero = this->ultimo = nuevo;
	}
	else {
		this->ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
		nuevo->setSiguiente(this->primero);
	}
		
}


void Archivo::graficar() {
	if (this->primero == 0) {
		cout << "Hermano, no haz creado archivos. Ve y crea uno." << endl;
	}
	else {
		NodoArchivo* auxiliar = this->primero;
		ofstream archivo("archivos.dot");
		archivo << "digraph archivos{" << endl;
		archivo << "node[shape = square];" << endl;
		do {
			/*
cambiosRealizados << "x" << aux << "label[Palabra buscada = \"" << aux->getPalabraB() << "\nPalabra reemplazada = \"" << aux->getPalabraR() << "\nEstado = " << aux->getEstado() << "];" << endl;
cambiosRealizados << "x" << aux << "->" << "x" << aux->getSiguiente() << ";" << endl;
			*/
			
			cout << "x" << auxiliar << "label[archivo = \"" << auxiliar->getNombre() << "\"];" << endl;
			cout << "x" << auxiliar << "-> x" << auxiliar->getSiguiente() << endl;
			auxiliar = auxiliar->getSiguiente();
		} while (auxiliar != this->primero);
		archivo << "}" << endl;
		archivo.close();
		system("dot -Tpng archivos.dot -o archivos.png");
		system("archivos.png");
	}
}

void Archivo::menuReportes(CambiosRealizados cambios, Denegado* rechazado, LetrasTexto* texto, string nombre) {
	bool validador = true;
	int opcion = 0;
	if (this->primero == 0) {
		cout << "Bro no tienes archivos. Lo siento no hay nada para mostrarte." << endl;
		system("pause");
	}
	while (validador) {
		system("cls");
		cout << "[1. Letras] [2. Palabras Buscadas] [3. Palabras Ordenadas] [4. Salir]" << endl;
		cout << "Ingrese su opcion." << endl;
		cin >> opcion;

		//Reporte de letas en texto!!!
		if (opcion == 1) {
			texto->graficar();
		}
		//Reporte de Palabras buscadas, tanto las buena como las malas.
		else if (opcion == 2) {
			cambios.graficar();
			rechazado->graficar();
			
		}
		//Palabras ordenadas de busquedas y reemplazos
		else if (opcion == 3) {
			cambios.graficarBuscadas();
			cambios.graficarReemplazadas();
		}
		else if (opcion == 4) {
			validador = false;
		}

	}

}