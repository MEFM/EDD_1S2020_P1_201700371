#include "LetrasTexto.h"


void LetrasTexto::insertarPrimero(char letra)
{
	NodoLetras* nuevo = new NodoLetras(letra);
	if (this->primero == 0)
	{
		this->primero = this->ultimo = nuevo;
	}
	else
	{
		nuevo->setSiguiente(this->primero);
		primero->setAnterior(nuevo);
		primero = nuevo;
	}
}

void LetrasTexto::insertarUltimo(char letra)
{
	NodoLetras* nuevo = new NodoLetras(letra);
	if (this->primero == 0)
	{
		this->primero = this->ultimo = nuevo;
	}
	else
	{
		nuevo->setAnterior(this->ultimo);
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
	}
}

void LetrasTexto::eliminarPrincipio() {
	if (primero == 0) {
		cout << "Lo siento, no hay nada para eliminar entiendes??" << endl;
	}
	else {
		primero = this->primero->getSiguiente();
		primero->getAnterior()->setSiguiente(0);
		primero->setAnterior(0);
	}
}


void LetrasTexto::graficar()
{
	if (this->primero == 0)
	{
		cout << "Lo siento, no hay letras :(" << endl;
	}
	else
	{
		ofstream archivoDot("Grafica.dot");
		archivoDot << "digraph{" << endl;
		archivoDot << "node[shape = square];" << endl;
		NodoLetras* auxiliar = this->ultimo;
		while (auxiliar->getAnterior() != 0)
		{
			archivoDot << "x" << auxiliar << "[label =\"" << auxiliar->getLetra() << "\"];" << endl;
			if (auxiliar->getSiguiente() != 0)
			{
				archivoDot << "x" << auxiliar << " ->" << "x" << auxiliar->getSiguiente() << ";" << endl;
				archivoDot << "x" << auxiliar->getAnterior() << " ->" << "x" << auxiliar << ";" << endl;
			}
			else if (auxiliar->getAnterior() != 0)
			{
				archivoDot << "x" << auxiliar << " ->" << "x" << auxiliar->getSiguiente() << ";" << endl;
				archivoDot << "x" << auxiliar->getAnterior() << " ->" << "x" << auxiliar << ";" << endl;
			}

			auxiliar = auxiliar->getAnterior();
		}
		archivoDot << "}" << endl;
		archivoDot.close();
		system("dot -Tpng Grafica.dot -o Letras.png");
		system("Letras.png");
	}
}

