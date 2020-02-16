#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class NodoDenegado {
private:
	NodoDenegado* siguiente;
	string palabraB;
	string palabraR;
	bool estado;
public:
	NodoDenegado(string palabraB, string palabraR, bool estado)
	{
		this->palabraB = palabraB;
		this->palabraR = palabraR;
		this->estado = estado;
		this->siguiente = 0;
	}

	void setSiguiente(NodoDenegado* nuevo)
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

	NodoDenegado* getSiguiente()
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

class Denegado
{
private:
	NodoDenegado* primero;
public:
	void insertar(string buscar, string reemplazo, bool estado);
	void graficar();
	void pop();

};

