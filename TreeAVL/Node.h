#ifndef NODE_H


#define NODE_H

#include <fstream>

#include <iostream> 

using namespace std;

struct Node
{
	int dato;
	 Node * der;
	 Node *izq;
	int altura ;
};


 Node*crearNodo(int);

 Node * insertarArbol(Node*, int);



void preOrder( Node *);
void posorden(Node *);
void inorden(Node *);



int altura( Node*);


 Node* Roatacionder( Node *);

 Node *Rotacionizq( Node *);

int FactorEquilibrio( Node *N);
int nodoizq(Node *& , int );

int nododer(Node *& , int );


void writeBinaryTree(Node *, ostream &);

int getHeight(Node *& );
Node * minValueNode(Node*);
Node* deleteNode(Node*, int);


#endif // !NODE_H
