
#include "Node.h"
#include "Archivo.h"
#include<stdio.h>
#include<stdlib.h>

#include <algorithm>

#include <iostream>
#define nullptr 0

using namespace std;



 Node *crearNodo(int n) {


	 Node* newnodo = new Node();

	newnodo->dato = n;
	newnodo->der = nullptr;
	newnodo->izq = nullptr;
	newnodo->altura = 0;

	return newnodo;

}



 Node * insertarArbol( Node *arbol, int n) {



	if (arbol == NULL)
		return(crearNodo(n));

	if (n < arbol->dato)
		arbol->izq = insertarArbol(arbol->izq, n);
	else if (n > arbol->dato)
		arbol->der = insertarArbol(arbol->der, n);
	else 
		return arbol;
	

	arbol->altura = max(getHeight(arbol->izq), getHeight(arbol->der));

	


	int balance = FactorEquilibrio(arbol);

	

	//  desbalanceo en parte izquierda // rotacion derecha
	if (balance < -1 && n < arbol->izq->dato)
		return Roatacionder(arbol);

	// Desbalanceo en la parte derecha Rotacion izquierda
	if (balance > 1 && n > arbol->der->dato)
		return Rotacionizq(arbol);

	//  Rotacion Izquierdda Derecha
	if (balance < -1 && n > arbol->izq->dato)
	{
		arbol->izq = Rotacionizq(arbol->izq);
		return Roatacionder(arbol);
	}

	// Rotacion Derecha Izquierda R
	if (balance > 1 && n < arbol->der->dato)
	{
		arbol->der = Roatacionder(arbol->der);
		return Rotacionizq(arbol);
	}


	return arbol;




}

void preOrder( Node *root)
{
	if (root != NULL)
	{
		cout << " "<< root->dato << " " ;
		preOrder(root->izq);
		preOrder(root->der);
	}
}





 Node * Roatacionder( Node *raiz)
{
	  Node *tmp = raiz->izq;
	  Node *arbol = tmp->der;


	  tmp->der = raiz;
	raiz->izq = arbol;


	raiz->altura = getHeight(raiz);
	tmp->altura = getHeight(tmp);


	return tmp;
}

 int getHeight(Node *& tmp){

	 if (tmp == 0)
		 return 0;
	 else
		 return 1 + max(getHeight(tmp->izq), getHeight(tmp->der));
 }




  Node * Rotacionizq(  Node * raiz)
 {

	   Node *tmp = raiz->der;
	   Node *arbol = tmp->izq;


	   tmp->izq = raiz;
	   raiz->der = arbol;

	  

	 raiz->altura = getHeight(raiz);
	 tmp->altura = getHeight(tmp);

	
	 return tmp;
 }


 int FactorEquilibrio( Node *N)
 {
	 if (N == NULL)
		 return 0;
	 return getHeight(N->der) - getHeight(N->izq);
 }



 int nodoizq(Node *& tmp, int val) {

	
	
	 if (tmp == 0)
		 return 0;
	
	 if (tmp->dato == val)
	 {
		 

		 return tmp->izq->dato;
	 }
	
	 

	 return nodoizq(tmp->izq,val);




 }

 int nododer(Node *& tmp, int val) {



	 if (tmp == 0)
		 return 0;

	 if (tmp->dato == val)
	 {
		 return tmp->der->dato;
	 }



	 return nododer(tmp->der, val);




 }

 void writeBinaryTree(Node *p, ostream &out) {

	 archivo nuevo;

	 if (!p) {
		 out << "-1";
	 }
	 else {


	/*	 out << p->dato << " ";*/
		 nuevo.valor = p->dato;
		 writeBinaryTree(p->izq, out);
		 writeBinaryTree(p->der, out);





		 out.write(reinterpret_cast <const char *>(&nuevo), sizeof(archivo));







		
	 }

	
 }

 Node * minValueNode( Node* node)
{
	 Node* current = node;

	
	while (current->izq != NULL)
		current = current->izq;

	return current;
}


 Node* deleteNode( Node* raiz, int valor)
{

	if (raiz == NULL)
		return raiz;

	
	if (valor < raiz->dato)
		raiz->izq = deleteNode(raiz->izq, valor);

	
	else if (valor > raiz->dato)
		raiz->der = deleteNode(raiz->der, valor);

	
	else
	{
		
		if ((raiz->izq == NULL) || (raiz->der == NULL))
		{
			 Node *temp = raiz->izq ? raiz->izq : raiz->der;

		
			if (temp == NULL)
			{
				temp = raiz;
				raiz = NULL;
			}
			else 
				*raiz = *temp; 
							  
			free(temp);
		}
		else
		{
			
			 Node* temp = minValueNode(raiz->der);

			
			 raiz->dato = temp->dato;

			
			 raiz->der = deleteNode(raiz->der, temp->dato);
		}
	}


	if (raiz == NULL)
		return raiz;

	
	raiz->altura = max(getHeight(raiz->izq), getHeight(raiz->der));


	
	int balance = FactorEquilibrio(raiz);

	if (balance < -1 && valor < raiz->izq->dato) {

		return Roatacionder(raiz);
	}

	if (balance > 1 && valor > raiz->der->dato) {

		return Rotacionizq(raiz);
	}

	if (balance < -1 && valor > raiz->izq->dato)
	{
		raiz->izq = Rotacionizq(raiz->izq);
		return Roatacionder(raiz);
	}

	if (balance > 1 && valor < raiz->der->dato)
	{
		raiz->der = Roatacionder(raiz->der);
		return Rotacionizq(raiz);
	}

	return raiz;
 
}

 void posorden( Node* node)
 {
	 if (node == NULL)
		 return;

	 posorden(node->izq);

	 posorden(node->der);

	 cout << node->dato << " ";
 }
 void inorden( Node* node)
 {
	 if (node == NULL)
		 return;

	 inorden(node->izq);


	 cout << node->dato << " ";

	 inorden(node->der);
 }