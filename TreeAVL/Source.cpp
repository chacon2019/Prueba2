

#include "Node.h"
#include "Archivo.h"

#include <iostream>

#define nullptr 0

using namespace std;


int main(){


	/*{
	//	Node *root = NULL;

	//	root = insertarArbol(root, 9);
	//	root = insertarArbol(root, 5);
	//	root = insertarArbol(root, 10);
	//	root = insertarArbol(root, 0);
	//	root = insertarArbol(root, 6);
	//	root = insertarArbol(root, 11);
	//	root = insertarArbol(root, -1);
	//	root = insertarArbol(root, 1);
	//	root = insertarArbol(root, 2);

	//	/* Primer arbol
	//	9
	//	/  \
	//	1    10
	//	/  \     \
	//	0    5     11
	//	/    /  \
	//	-1   2    6
	//	

	//	cout << "Preorden primer arbol antes de eliminar el 10 \n";
	//	preOrder(root);

	//	root = deleteNode(root, 10);

	//	/* eliminar el 10
	//	1
	//	/  \
	//	0    9
	//	/     /  \
	//	-1    5     11
	//	/  \
	//	2    6
	//	

	//	cout << "\nPreorden desues de eliminar el 10 \n";
	//	preOrder(root);

	//}*/



	Node *root = NULL;


	int op;

	do
	{
		cout << "\n1. Crear Arbol AVL \n";
		cout << "\n2. Borrar Dato Arbol AVL\n";
		cout << "\n3. Guardar en el archivo\n";
		cout << "\n4. Cargar del archivo\n";
		cout << "\n5. imprimir arbol\n";

		cin >> op;


		switch (op)
		{
		case 1:
			int dato;
			int dato2;
			cout << "Cuantos datos va ingresar ";
			cin >> dato;

			for (int i = 0; i < dato; i++)
			{
				cout << "ingrese dato : ";
				cin >> dato2;
				root = insertarArbol(root,dato2);
				agragardatos(dato2,root);				
			}
			guardar(root);
			break;

		case 2:
			int dato3;
			cout << "Dato a Eliminar : ";
			cin >> dato3;
			deleteNode(root, dato3);
			Eliminarenelarchivo(dato3);
			break;

		case 3:
			
			consultarinventario();
			/*cout << returndere(7,root);*/
			//cout << returizq(7, root);
			break;

		case 4:

			root = arbolarchivoamemoria();
			cout << "A R B O L  C A R G A D O . . ." << endl;
		
				break;
		case 5:
			cout << "\nPreOrden :\n";
			preOrder(root);
			cout << "\nPosOrden :\n";
			posorden(root);
			cout << "\nInOrden :\n";
			inorden(root);
			break;
		}



	} while (op!=6);




	









	



		

		



	system("pause");


	
}