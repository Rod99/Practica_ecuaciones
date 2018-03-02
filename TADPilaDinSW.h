/**
	Libreria: Cabecera de TAD Pila de manera Din�mica
	Autores: Equipo Smitty Werberjagermanjensen
	Versi�n: 1.0
	
	Descripci�n: Pila o Stack
	Se usar� una estructura de datos tipo LIFO (Last In First Out)
	Se a�aden los datos y se extraen por un solo extremo
	Al extremo de la pila se le llama tope
	
	Observaciones: Se har� uso de una pila din�mica, la cu�l apartar� memoria
	cada que sea necesario. Para esta implementaci�n se usar�n nodos, los cuales
	estar�n relacionados entre si mediante apuntadores, modelando as� una pila.
*/

//Definir constantes booleanas
#define TRUE 1
#define FALSE 0

//Definici�n de tipos de datos

typedef unsigned char boolean;

//Definir un elemento (El cual estar� modelado por una estructura)

typedef struct elemento
{
	//El tipo de dato que el usuario requiera
	
}elemento;

//Definici�n de nodo, el cual ser� utilizado para guardar un elemento y la direcci�n del nodo que est� debajo

typedef struct nodo
{
	elemento e;
	struct nodo *abajo
	
}nodo;

//Definici�n de la pila, la cu�l almacenar� las direcciones del nodo que se encuentra en el extremo llamado tope
typedef struct pila
{
	nodo *tope;
}pila;

//Definici�n de funciones
void Initialize(pila *s);			//Inicializa la pila (la prepara para su uso)
void Push(pila *s, elemento e);		//Empila un elemento 'e' en la pila
elemento Pop (pila *s);				//Desempila un elemento 'e' en la pila
boolean Empty(pila *s);				//Pregunta si la pila est� vac�a
elemento Top(pila *s);				//Pregunta por el elemento que se encuentra en el tope de la pila, pero no lo saca
int Size(pila *s);					//Pregunta por el n�mero de elementos que hay en la pila
void Destroy(pila *s);				//Libera el espacio de memoria utilizado por la pila y los elementos que contenga
