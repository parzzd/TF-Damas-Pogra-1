#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>

using namespace std;
using namespace System;

char tablero[17][33]{
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|',' ','O',' ','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
};
struct jugador
{
	char color;
	int x, y;
	int mov = 0;
};

//MENU
void Pantalla_Inicio() {
	//LETRA D
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Console::SetCursorPosition(10 + j, 6 + i);
			if (i == 0 || i == 6)
			{
				if (j != 4)
				{
					cout << "*";
				}
			}
			else
			{
				if (j == 0 || j == 4)
				{
					cout << "*";
				}
			}
		}
	}
	//LETRA A
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Console::SetCursorPosition(17 + j, 6 + i);
			if (i == 0 && j == 2)
			{
				cout << "*";
			}
			if ((i > 0 && i < 3) && (j == 1 || j == 3))
			{
				cout << "*";
			}
			if ((i >= 3 && i != 4) && (j == 0 || j == 4))
			{
				cout << "*";
			}
			if (i == 4)
			{
				cout << "*";
			}
		}
	}
	//LETRA M
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Console::SetCursorPosition(24 + j, 6 + i);
			if (j == 0 || j == 4)
			{
				cout << "*";
			}
			if (i == 1 && (j == 1 || j == 3))
			{
				cout << "*";
			}
			if (i == 2 && j == 2)
			{
				cout << "*";
			}

		}
	}
	//LETRA A
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Console::SetCursorPosition(31 + j, 6 + i);
			if (i == 0 && j == 2)
			{
				cout << "*";
			}
			if ((i > 0 && i < 3) && (j == 1 || j == 3))
			{
				cout << "*";
			}
			if ((i >= 3 && i != 4) && (j == 0 || j == 4))
			{
				cout << "*";
			}
			if (i == 4)
			{
				cout << "*";
			}
		}
	}
	//LETRA S
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Console::SetCursorPosition(38 + j, 6 + i);
			if (i == 0 || i == 6 || i == 3)
			{
				cout << "*";
			}
			else
			{
				if ((j == 0 && (i == 1 || i == 2)) || (j == 4 && (i == 4 || i == 5)))
				{
					cout << "*";
				}
			}
		}
	}
	//MENSAJE
	Console::SetCursorPosition(10, 14);
	cout << "presione cualquier tecla para continuar";
	_getch();
}
void Menu_Principal(int* op) {
	Console::SetCursorPosition(10, 6);
	cout << "MENU PRINCIPAL" << endl;
	Console::SetCursorPosition(10, 7);
	cout << "1. NUEVO JUEGO" << endl;
	Console::SetCursorPosition(10, 8);
	cout << "2. INSTRUCCIONES" << endl;
	Console::SetCursorPosition(10, 9);
	cout << "3. CREDITOS" << endl;
	Console::SetCursorPosition(10, 10);
	cout << "4. SALIR" << endl;
	do
	{
		Console::SetCursorPosition(10, 13);
		cout << "                                            " << endl;
		Console::SetCursorPosition(10, 13);
		cout << "seleccione una opcion: ";
		cin >> *op;
		if (*op < 1 || *op > 4)
		{
			Console::SetCursorPosition(10, 16);
			cout << "Opcion invalida, seleccione una del menu";
		}
	} while (*op < 1 || *op > 4);
}
void Instrucciones(int* op) {
	Console::SetCursorPosition(23, 4);
	cout << "INSTRUCCIONES Y REGLAS DEL JUEGO";

	Console::SetCursorPosition(10, 8);
	cout << "1. Las piezas se mueven  una posición hacia delante en diagonal, a la derecha o a la izquierda, a una  ";
	Console::SetCursorPosition(13, 9);
	cout << "posición adyacente vacía siempre que esté saltando sobre un aliado.";

	Console::SetCursorPosition(10, 11);
	cout << "2. Si una ficha se encuentra en una casilla diagonal contigua a otra del contrario,estando ";
	Console::SetCursorPosition(13, 12);
	cout << "la posterior vacía, puede saltar por encima de esta hasta la casilla vacía, retirando ";
	Console::SetCursorPosition(13, 13);
	cout << "la ficha del contrario del tablero.";

	Console::SetCursorPosition(10, 15);
	cout << "3. Cuando una ficha llega al lado contrario se convierte en reina, moviendose en diagonal, horizontal";
	Console::SetCursorPosition(13, 16);
	cout << "como vertical ";
	Console::SetCursorPosition(10, 18);
	cout << "FIN DE LA PARTIDA";
	Console::SetCursorPosition(10, 20);
	cout << "- La partida finaliza cuando un jugador se queda sin piezas, no puede mover llegado su turno(estan bloqueadas)";
	Console::SetCursorPosition(10, 21);
	cout << "o si hay un numero igual y reducido de piezas, por lo que nunca se resolvería la partida";



	Console::SetCursorPosition(10, 25);

	if (*op == 2)
	{
		cout << "PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU";
	}
	else
	{
		cout << "PRESIONE CUALQUIER TECLA PARA EMPEZAR A JUGAR";
	}
	_getch();
}
void Creditos() {
	Console::SetCursorPosition(35, 4);
	cout << "CREDITOS";
	Console::SetCursorPosition(10, 7);
	cout << "ESTUDIANTES:";
	Console::SetCursorPosition(10, 9);
	cout << "- Eduardo Puglisevich";
	Console::SetCursorPosition(10, 10);
	cout << "- Samuel Valera";
	Console::SetCursorPosition(10, 11);
	cout << "- Pedro Retuerto";
	Console::SetCursorPosition(10, 13);
	cout << "PROFESOR: ";
	Console::SetCursorPosition(10, 15);
	cout << "- Luis Vives ";
	Console::SetCursorPosition(10, 18);
	cout << "PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU";
	_getch();
}

//JUEGO
void Ingresar_nombres(char* name1, char* name2) {
	Console::SetCursorPosition(2, 2);
	cout << "INGRESE EL NOMBRE DEL JUGADOR 1: ";
	cin >> name1;
	strupr(name1);
	Console::SetCursorPosition(2, 4);
	cout << "INGRESE EL NOMBRE DEL JUGADOR 2: ";
	cin >> name2;
	strupr(name2);
}
void Color_Fichas(char* name1, char* name2, jugador* j1, jugador* j2) {
	Random r;
	int jugador;
	Console::SetCursorPosition(2, 6);
	cout << "Seleeccionando al jugador que escogera el color de fichas..." << endl;
	jugador = r.Next(1, 11);
	_sleep(1000);
	if (jugador % 2 == 0)
	{
		Console::SetCursorPosition(2, 8);
		cout << "Jugador escogido: " << name1 << endl;
		do
		{
			Console::SetCursorPosition(2, 10);
			cout << "                                                   ";
			Console::SetCursorPosition(2, 10);
			cout << "Selecciona el color de tus fichas(R:Rojas/N:Negras): ";
			cin >> j1->color;
			j1->color = toupper(j1->color);
		} while (j1->color != 'R' && j1->color != 'N');
		if (j1->color == 'R')
		{
			j2->color = 'N';
		}
		else
		{
			j2->color = 'R';
		}
	}
	else
	{
		Console::SetCursorPosition(2, 8);
		cout << "Jugador escogido: " << name2 << endl;
		do
		{
			Console::SetCursorPosition(2, 10);
			cout << "                                                   ";
			Console::SetCursorPosition(2, 10);
			cout << "Selecciona el color de tus fichas(R:Rojas/N:Negras): ";
			cin >> j2->color;
			j2->color = toupper(j2->color);
		} while (j2->color != 'R' && j2->color != 'N');
		if (j2->color == 'R')
		{
			j1->color = 'N';
		}
		else
		{
			j1->color = 'R';
		}
	}
}
void Filas_y_Columnas() {
	int filas = 1;
	char columnas = 'a';
	Console::ForegroundColor = ConsoleColor::Yellow;
	for (int i = 0; i < 8; i++)
	{
		Console::SetCursorPosition(1, 3 + i * 2);
		cout << filas;
		cout << endl;
		filas++;
	}
	for (int j = 0; j < 8; j++)
	{
		Console::SetCursorPosition(5 + j * 4, 1);
		cout << columnas;
		columnas++;
	}
	Console::ForegroundColor = ConsoleColor::White;
}
void Generar_Tablero() {
	for (int i = 0; i < 17; i++)
	{
		Console::SetCursorPosition(3, 2 + i);
		for (int j = 0; j < 33; j++)
		{
			cout << tablero[i][j];
		}
	}
}

//SALIR
void Mensaje_Final() {
	Console::SetCursorPosition(5, 10);
	cout << "GRACIAS POR USAR EL PROGRAMA, PRESIONE CUALQUIER TECLA PARA FINALIZAR" << endl;
	_getch();
}

int main() {
	locale::global(locale("spanish"));
	int turno=0;
	int* opcion = new int;
	char* nombreJ1 = new char[20];
	char* nombreJ2 = new char[20];
	jugador* Jugador1 = new jugador;
	jugador* Jugador2 = new jugador;
	Console::CursorVisible = false;
	Pantalla_Inicio();
	do
	{
		Console::Clear();
		Menu_Principal(opcion);
		Console::Clear();
		switch (*opcion)
		{
		case 1:
			Ingresar_nombres(nombreJ1, nombreJ2);
			Color_Fichas(nombreJ1, nombreJ2, Jugador1, Jugador2);
			Console::Clear();
			Instrucciones(opcion);
			Console::Clear();
			Filas_y_Columnas();
			Generar_Tablero();
			_getch();
			break;
		case 2:
			Instrucciones(opcion);
			break;
		case 3:
			Creditos();
			break;
		case 4:
			Mensaje_Final();
			break;
		}
	} while (*opcion != 4);
	return 0;
}
