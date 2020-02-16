#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class NodoLetras
{
private:
	int catidad = 0;
	char letra;
	NodoLetras* siguiente;
	NodoLetras* anterior;
public:
	NodoLetras() {}
	NodoLetras(char letra)
	{
		this->letra = letra;
		this->siguiente = 0;
		this->anterior = 0;
	}
	void setCantidad(int cantidad)
	{
		this->catidad = cantidad;
	}
	void setLetra(char letra)
	{
		this->letra = letra;
	}
	void setSiguiente(NodoLetras* nuevo)
	{
		this->siguiente = nuevo;
	}
	void setAnterior(NodoLetras* nuevo)
	{
		this->anterior = nuevo;
	}

	int getCantidad()
	{
		return catidad;
	}
	char getLetra()
	{
		return letra;
	}
	NodoLetras* getSiguiente()
	{
		return this->siguiente;
	}
	NodoLetras* getAnterior()
	{
		return this->anterior;
	}
};

class LetrasTexto
{
	NodoLetras* primero;
	NodoLetras* ultimo;
public:
	void insertarPrimero(char);
	void insertarUltimo(char);

	void eliminarPrincipio();
	void eliminarFinal();

	void graficar();
};


