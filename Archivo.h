#pragma once
#include <iostream>
#include <string>

#include "CambiosRealizados.h"
#include "LetrasTexto.h"
#include "Denegado.h"
using namespace std;

class NodoArchivo {
private:
	NodoArchivo* siguiente;
	CambiosRealizados cambios;
	Denegado* rechazado;
	LetrasTexto* texto;
	string nombre;
public:
	NodoArchivo(CambiosRealizados cambios, Denegado* rechazado, LetrasTexto* texto, string nombre) {
		this->cambios = cambios;
		this->rechazado = rechazado;
		this->texto = texto;
		this->nombre = nombre;
		this->siguiente = 0;
	}

	void setSiguiente(NodoArchivo* siguiente) {
		this->siguiente = siguiente;
	}
	void setCambios(CambiosRealizados cambios) {
		this->cambios = cambios;
	}
	void setRechazado(Denegado* rechazado) {
		this->rechazado = rechazado;
	}
	void setTexto(LetrasTexto* texto) {
		this->texto = texto;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}

	NodoArchivo* getSiguiente() {
		return this->siguiente;
	}
	CambiosRealizados getCambios() {
		return cambios;
	}
	Denegado* getRechazado() {
		return this->rechazado;
	}
	LetrasTexto* getTexto() {
		return this->texto;
	}
	string getNombre() {
		return this->nombre;
	}
};
class Archivo
{
private:
	NodoArchivo* primero;
	NodoArchivo* ultimo;
public:

	void insertar(CambiosRealizados cambios, Denegado* rechazado ,LetrasTexto* texto, string nombre);
	void menuReportes(CambiosRealizados cambios, Denegado* rechazado, LetrasTexto* texto, string nombre);
	void menuArchivos();
	void graficar();

};

