#ifndef ARCHIVO_H



#define ARCHIVO_H


#include "Node.h"


struct archivo
{
	int izq; // 4 bits
	int valor; // 4bits
	int der; // 4 bits



	
};
void Eliminarenelarchivo(int);
Node * arbolarchivoamemoria();
void guardar(Node*);
void setdatos(int, int, int);
void agragardatos(int, Node *);
void consultarinventario();
int getposRegistro(int);

int returizq(int , Node * );
int returndere(int , Node * );

#endif // !ARBOL_H

int main();
