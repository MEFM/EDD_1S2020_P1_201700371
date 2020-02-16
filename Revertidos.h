#pragma once
#include "CambiosRealizados.h"

class NodoRevertidos {
private:
	NodoRevertidos* siguiente;
	string palabraB;
	string palabraR;
	bool estado;
public:
	NodoRevertidos(string palabraB, string palabraR, bool estado)
	{
		this->palabraB = palabraB;
		this->palabraR = palabraR;
		this->estado = estado;
		this->siguiente = 0;
	}
	void setSiguiente(NodoRevertidos* nuevo)
	{
		this->siguiente = nuevo;
	}
	void setPalabraB(string palabra)
	{
		this->palabraB = palabra;
	}
	void setPalabraR(string palabra)
	{
		this->palabraR = palabra;
	}
	void setEstado(bool estado)
	{
		this->estado = estado;
	}

	NodoRevertidos* getSiguiente()
	{
		return siguiente;
	}
	string getPalabraB()
	{
		return palabraB;
	}
	string getPalabraR()
	{
		return palabraR;
	}
	string getEstado()
	{
		if (estado == true)
		{
			return "No revertido";
		}
		else {
			return "Revertido";
		}
	}

};

class Revertidos
{
	NodoRevertidos* primero;
public:
	void pushh(string buscar, string reemplazo, bool estado);
	void pop();
};

