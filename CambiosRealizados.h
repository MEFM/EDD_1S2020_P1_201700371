#pragma once
#include <iostream>
#include <string>
#include <fstream>



using namespace std;
class NodoCambios {
private:
	NodoCambios* siguiente;
	string palabraB;
	string palabraR;
	bool estado;
public:
	NodoCambios(string palabraB, string palabraR, bool estado)
	{
		this->palabraB = palabraB;
		this->palabraR = palabraR;
		this->estado = estado;
		this->siguiente = 0;
	}

	
	void setSiguiente(NodoCambios* nuevo)
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

	NodoCambios* getSiguiente()
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
		if (estado == true) {
			return "Sin alterar";
		}
		else {
			return "Alterado";
		}
		
	}

};

class CambiosRealizados
{ 
private:

	NodoCambios* primero;
	NodoCambios* primeroB;
	NodoCambios* primeroR;
public:
	void push(string buscar, string reemplazo, bool estado);
	void insertListaOrdenadaB(string buscar);
	void insertListaOrdenadaR(string reemplazo);
	void pop();
	void eliminarListaB();
	void eliminarListaR();
	void graficar();
	void graficarBuscadas();
	void graficarReemplazadas();

};

