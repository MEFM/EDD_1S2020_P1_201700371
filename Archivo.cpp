#include "Archivo.h"

void Archivo::insertar(CambiosRealizados* cambios, Denegado* rechazado, LetrasTexto* texto, string nombre) {
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
		archivo << "rankdir = LR;" << endl;
		do {

			archivo << "x" << auxiliar << "[label=\"archivo = " << auxiliar->getNombre() << "\"];" << endl;
			archivo << "x" << auxiliar << "-> x" << auxiliar->getSiguiente() << endl;
			auxiliar = auxiliar->getSiguiente();
		} while (auxiliar != this->primero);
		archivo << "}" << endl;
		archivo.close();
		system("dot -Tpng archivos.dot -o archivos.png");
		system("archivos.png");
	}
}

void Archivo::menuArchivos() {
	if (this->primero == 0) {
		cout << "Sory bro, it can not be open." << endl;
	}
	else {
		system("cls");
		bool validador = true;
		while (validador) {
			NodoArchivo* auxiliar = this->primero;
			int contador = 1;
			do {
				cout << contador++ << ". " << auxiliar->getNombre() << endl;
				auxiliar = auxiliar->getSiguiente();
			} while (auxiliar != this->primero);
			
			cout << "Si desea ver el reporte de archivos presione X." << endl;
			cout << "Presione cualquier tecla para volver al menu principal." << endl;
			char controlador = _getch();
			
			if (controlador == 'X') {
				graficar();
			}
			else {
				validador = false;
			}
		}

	}
	system("cls");
}

void Archivo::menuReportes(CambiosRealizados* cambios, Denegado* rechazado, LetrasTexto* texto, string nombre) {
	bool validador = true;
	int opcion = 0;
	if (this->primero == 0) {
		cout << "Bro no tienes archivos. Lo siento no hay nada para mostrarte." << endl;
		system("pause");
	}
	while (validador) {
		system("cls");
		cout << "[1. Letras] [2. Log Reemplazos] [3. Palabras Busquedas] [4. Reemplazos]" << endl;
		cout << "Ingrese su opcion." << endl;
		cin >> opcion;

		//Reporte de letas en texto!!!
		if (opcion == 1) {
			texto->graficar();
		}
		//Reporte de Palabras buscadas, tanto las buena como las malas.
		else if (opcion == 2) {
			cambios->graficar();
			rechazado->graficar();

		}
		//Palabras ordenadas de busquedas y reemplazos
		else if (opcion == 3) {
			cambios->graficarBuscadas();
			//cambios->graficarReemplazadas();

		}
		else if (opcion == 4) {
			cambios->graficarReemplazadas();
		}
		else {
			break;
		}
	}
	
}

void Archivo::menuReportesAbrir(string nombre) {
	if (this->primero == 0) {
		cout << "Lo siento brou el menu de reportes no esta disponible para ti" << endl;
	}
	else {
		NodoArchivo* auxiliar = this->primero;
		while (auxiliar->getNombre() != nombre) {
			if (auxiliar->getSiguiente() == 0) {
				break;
			}
			auxiliar = auxiliar->getSiguiente();
		}

		bool validador = true;
		int opcion = 0;
		while (validador) {
			cout << "[1. Letras] [2. Log Reemplazos] [3. Palabras Busquedas] [4. Reemplazos] [5. Menu Principal]" << endl;
			cout << "Ingrese su opcion." << endl;
			cin >> opcion;

			switch (opcion)
			{
			case 1:
				auxiliar->getTexto()->graficar();
				break;
			case 2:
				auxiliar->getCambios()->graficar();
				auxiliar->getRechazado()->graficar();
				break;
			case 3:
				auxiliar->getCambios()->graficarBuscadas();
				break;
			case 4:
				auxiliar->getCambios()->graficarReemplazadas();
				break;
			case 5:
				validador = false;
				break;
			default:
				break;
			}
		}
	}
}