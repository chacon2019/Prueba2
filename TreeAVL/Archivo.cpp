
#include "Archivo.h"

#include  "Node.h"
#include <fstream>

#include  <iostream>

using namespace std;






void  agragardatos(int dato,Node * arbol)
{


	fstream archivoAVL("ArbolAVL.dat", ios::out | ios::app | ios::binary);

	if (!archivoAVL)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return;
	}

	

	//int a;
	//archivoAVL.write(reinterpret_cast <const char *>(&a), 4);

	archivo nuevo;
		nuevo.izq = -1;
		nuevo.valor = dato; // funcion segun el dato tirrar el hijo izq o dercho

		nuevo.der =-1;

		


		archivoAVL.write(reinterpret_cast <const char *>(&nuevo), sizeof(archivo));


	




	archivoAVL.close();
	


	



}



void guardar(Node * root)
{


	fstream archivoModef("ArbolAVL.dat", ios::in | ios::out | ios::binary);
	ifstream archivoIn("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoModef)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return;
	}


	archivo actual;

	archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(archivo));
	int pos = getposRegistro(actual.valor);
	archivoIn.seekg(1 * sizeof(archivo), ios::beg);


	archivo nuevo;
	
	archivoModef.seekp(pos * sizeof(archivo), ios::beg);

	

	while (!archivoIn.eof()) {

		
		nuevo.izq = getposRegistro(returizq(actual.valor, root));
		nuevo.valor = actual.valor;
		nuevo.der = getposRegistro(returndere(actual.valor, root));;


		
		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(archivo));
		archivoModef.write(reinterpret_cast <const char *>(&nuevo), sizeof(archivo));
	
	
	}




	archivoModef.close();







}

void Eliminarenelarchivo(int dato)
{


	fstream archivoModef("ArbolAVL.dat", ios::in | ios::out | ios::binary);
	ifstream archivoIn("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoModef)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return;
	}


	archivo actual;

	archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(archivo));
	int pos = getposRegistro(actual.valor);
	archivoIn.seekg(1 * sizeof(archivo), ios::beg);


	archivo nuevo;

	archivoModef.seekp(pos * sizeof(archivo), ios::beg);



	while (!archivoIn.eof()) {


		if (actual.izq==getposRegistro(dato))
		{
			nuevo.izq = -1;
			nuevo.valor = actual.valor;
			nuevo.der = actual.der;
		}
		else if (actual.der == getposRegistro(dato))
		{
			nuevo.izq = actual.izq;
			nuevo.der = -1;
			nuevo.valor = actual.valor;
		}

		
		else if (actual.valor==dato)
		{
			nuevo.izq = -1;
			nuevo.der = -1;
			nuevo.valor = -1;
		}

		else
		{

			nuevo.izq = actual.izq;
			nuevo.valor = actual.valor;
			nuevo.der = actual.der;
		}
		
		
	

		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(archivo));
		archivoModef.write(reinterpret_cast <const char *>(&nuevo), sizeof(archivo));


	}




	archivoModef.close();







}

void setdatos(int valor, int val, int val2)
{


	fstream archivoModef("ArbolAVL.dat", ios::in | ios::out | ios::binary);

	if (!archivoModef)
	{
		cout << " Error al intentar abrir archivo ferreteria.dat";
		return;
	}


	int pos = getposRegistro(valor);

	archivoModef.seekp(pos * sizeof(archivo), ios::beg);

	archivo nuevo;

	nuevo.izq = val;
	nuevo.valor = valor;
	nuevo.der = val2;

	



	archivoModef.write(reinterpret_cast <const char *>(&nuevo), sizeof(archivo));





	cout << "Registro Modificado! \n\n";



	archivoModef.close();







}

int returndere(int dato, Node * arbol)
{
	if (arbol == NULL)
		return -1;
	
	if (dato == arbol->dato)
	{
		/*return (arbol->der->dato == NULL) ? -1: arbol->der->dato;*/
		return (arbol->der == nullptr) ? -1 : arbol->der->dato;
	}
	else if (dato > arbol->dato)
	{
		return returndere(dato, arbol->der);
	}
	else 
	{
		return returndere(dato, arbol->izq);
	}

	return -1;
}

int returizq(int dato, Node * arbol)
{
	if (arbol == NULL)
		return -1;

	if (dato == arbol->dato)
	{
		return (arbol->izq == nullptr) ? -1 : arbol->izq->dato;
		/*return arbol->izq->dato;*/
	}
	else if (dato < arbol->dato)
	{
		return returizq(dato, arbol->izq);
	}
	else
	{
		return returizq(dato, arbol->der);
	}

	return -1;
}

int getposRegistro(int codigo) {

	ifstream archivoPos("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoPos)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return -1;
	}

	archivoPos.seekg(0, ios::beg);
	archivo nuevo;

	archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(archivo)); //la cantidad que voy a leer 
	int posicion = 0;

	while (!archivoPos.eof())
	{

		if (nuevo.valor == codigo)
		{


			archivoPos.close();
			return posicion;
		}
		posicion++;
		archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(archivo)); //la cantidad que voy a leer 

	}

	archivoPos.close();
	return -1;



}

void consultarinventario()
{

	ifstream archivoIn("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoIn)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return;
	}


	archivoIn.seekg(0, ios::beg);


	cout << "\n\n*** C O N S U L T A ***\n\n";

	archivo actual;

	archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(archivo));

	while (!archivoIn.eof()) // devuelve la posicion de donde finaliza el archivo
	{

		cout << "izq: " << actual.izq << "\nvalor: " << actual.valor
			<< "\nderecha: " << actual.der  ;

		cout << "\n------------------------------------------\n";

		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(archivo));




	}

	archivoIn.close();

}
Node * arbolarchivoamemoria()
{

	ifstream archivoIn("ArbolAVL.dat", ios::in | ios::binary);

	if (!archivoIn)
	{
		cout << " Error al intentar abrir archivo ArbolAVL.dat";
		return NULL;
	}


	archivoIn.seekg(0, ios::beg);


	

	archivo actual;
		Node *root = NULL;
		

	archivoIn.read(reinterpret_cast <char *>(&actual), sizeof(archivo));

	while (!archivoIn.eof()) // devuelve la posicion de donde finaliza el archivo
	{

		if (actual.valor==-1)
		{
			
		}
		else
		{
			root = insertarArbol(root, actual.valor);
		}
		


		
		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(archivo));


	

	}

	archivoIn.close();
	return root;
}



