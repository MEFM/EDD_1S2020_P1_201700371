// X.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <thread>
#include <fstream>
#include <Windows.h>

#include "LetrasTexto.h"
#include "CambiosRealizados.h"
#include "Denegado.h"
#include "Archivo.h"

#define alfa1 97
#pragma warning(suppress : 4996)

using namespace std;


void cajaTexto();
void buscarReemplazar(string& texto, string buscar, string reemplazar);
void abrir();
Archivo* archiv = new Archivo();

int contadorArchivos = 1;
void menu()
{
	system("color 0A");
	int opcion = 0;
	bool validador = true;

	string str;
	cout << "proba" << endl;
	getline(cin, str);

	while (validador)
	{
		cout << "	Practica 1" << endl << "	Mynor Estuardo Florian Machado" << endl << "	201700371" << endl << endl;
		cout << "		MENU" << endl << "	1. Crear Archivo" << endl << "	2. Abrir archivo" << endl << "	3. Archivos Recientes" << endl << "	4.Salir";
		cout << endl;
		cout << "	Ingrese una opcion." << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			cajaTexto();
			//abrir();
			break;
		case 2:
			//Arbrir
			break;
		case 3:
			//Recientes
			break;
		case 4:
			validador = false;
			break;
			break;
		default:
			validador = true;
			break;
		}
	}
}

void buscarReemplazar(string& texto, string buscar, string reemplazar) {
	int pos = texto.find(buscar);
	while (pos != -1) {
		texto.replace(pos, buscar.size(), reemplazar);
		pos = texto.find(buscar, pos + reemplazar.size());
	}
}

void abrir() {
	char codigo1 = ' ';
	char codigo2;
	string texto = "";
	cout << "Ingresar cosas" << endl;
	LetrasTexto* letras = new LetrasTexto();
	while (true) {
		codigo1 = _getch();
		cout << "" << codigo1;
		texto += codigo1 + "";
		if (codigo1 == 94) {
			codigo2 = _getch();
			if (codigo2 == 99) {
				cout << "Q" << endl;
			}
		}
		else if (codigo1 == 8) {
			//Metodo de eliminar
			letras->eliminarPrincipio();
		}
		else if (codigo1 == 115) {
			break;
		}


		letras->insertarPrimero(codigo1);
	}
	cout << texto << endl;
	letras->graficar();
}

void cajaTexto() {
	//Caja de texto y envio de cosas
	string text = "";
	string todo = "";
	char abrirAux = ' ';
	bool validador = true;
	string archivoActual = "";
	string nombreArchivo = "";

	LetrasTexto* letras = new LetrasTexto();
	CambiosRealizados cambios =  CambiosRealizados();
	Denegado* rechazado = new Denegado();

	ofstream auxiliar("auxiliar.txt");
	while (validador) {
		system("cls");
		cout << text << endl;
		cout << "Guardar ^s		Reportes ^c		Buscar y Reemplazar ^w" << endl;
		cout << "Ingresa el texto!!" << endl;
		getline(cin, todo, '^');//^
		text += todo;
		auxiliar << text << endl;
		char codigo = _getch();

		/*
		Realmente no se donde poner este objeto de tipo letras, pero por el momento se queda aca!
		*/


		
		//Este es el if para reportes
		if (codigo == 99) {
			//c Reportes
			system("cls");
			cout << text << endl;
			cout << "Unicamente puedes acceder a los reportes si haz guardado el archivo." << endl;
			cout << "Reportes" << endl;
			if (nombreArchivo != "") {
				archiv->menuReportes(cambios, rechazado, letras, nombreArchivo);
			}
			auxiliar.close();	
			system("cls");
			cout << text << endl;

		}
		//Este es el if para buscar y reemplazar
		else if (codigo == 119) {
			//w Buscar y reemplazar 
			cout << "Buscar y reemplazar" << endl;
			string buscar = "";
			string reemplazar = "";
			string soporte = text; // Si los cambios son rechazados esta variable almacena el texto anterior al cagadal

			cout << "[Ingrese palabra a reemplazar]: ";
			cin.ignore();// setea valor en la variable buscar
			getline(cin, buscar);
			cout << endl;
			cout << "[Ingrese palabra de reemplazo]: ";
			getline(cin, reemplazar); // setea valor en la variable reemplazar
			cout << endl;//^ ascii 94
			buscarReemplazar(text, buscar, reemplazar);
			
			
			system("cls");
			//char cambio = _getch();
			cout << "Si cierras sin haber guardado tus cambios, you are f*** up dude" << endl;
			cout << "Desea realizar cambios? ^y(SI)/^z(NO)" << endl;
			cin.ignore();
			string cambio = "";
			getline(cin, cambio);
			
			if (cambio == "^z") { //aca se revierten los cambios que se realizaron con anterioridad
				text = soporte;
				auxiliar << text << endl;
				cambios.pop();
				rechazado->insertar(buscar, reemplazar, false);
			}
			else if(cambio =="^y") // aca se realizan los cambios que se pidieron en la consola
			{
				
				cambios.push(buscar, reemplazar, true);
				rechazado->pop();
				auxiliar << text << endl;
				auxiliar.close();
				cambios.graficar();
			}
			
			char confir = _getch();
			cout << "Desea regresar al menú principal? [S/N]" << endl;
			if (confir == 's' || confir == 'S') {
				break;
			}

			system("cls");
			cout << text << endl;
			cout << "Solo puedes editar con ^w" << endl;
		}
		//Este es el if para guardar archivo
		else if (codigo == 115) {
			//s guardar
			cout << "Guardar Archivo!" << endl << "*NO GUARDE ARCHIVOS CON ESPACIOS*" << endl;
			
			cout << "[Ingrese el nombre del archivo a guardar]: ";
			cin >> nombreArchivo;
			ofstream archivoGuardado(nombreArchivo + ".txt");
			archivoGuardado << text << endl;
			archivoGuardado.close();
			char* letra = new char[text.length() + 1];
			strcpy(letra, text.c_str());
			for (int i = 0; i < (text.length() + 1); i++) {
				if (letra[i] != ' ') {
					letras->insertarPrimero(letra[i]);
				}

			}
			cout << "[Archivo guardado]" << endl;
			archiv->insertar(cambios, rechazado, letras, nombreArchivo);
			cambios.graficar();
			cout << "Desea regresar al menú principal? [S/N]" << endl;
			char confir = _getch();
			if (confir == 's' || confir == 'S') {
				abrirAux = confir;
				break;
			}
			system("cls");
			cout << "Solo puedes editar con ^w" << endl;
		}

	}



}


int main()
{
	//menu();

	CambiosRealizados lista;
	lista.push("hola", "adios", true);
	lista.push("hola", "adios", true);
	lista.graficar();
	system("pause");
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
