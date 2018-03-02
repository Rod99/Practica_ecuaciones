/**
	Libreria: Cabecera de TAD Pila de manera Dinámica
	Autores: Equipo Smitty Werberjagermanjensen
	Versión: 1.0
	
	Descripción: Pila o Stack
	Se usará una estructura de datos tipo LIFO (Last In First Out)
	Se añaden los datos y se extraen por un solo extremo
	Al extremo de la pila se le llama tope
	
	Observaciones: Se hará uso de una pila dinámica, la cuál apartará memoria
	cada que sea necesario. Para esta implementación se usarán nodos, los cuales
	estarán relacionados entre si mediante apuntadores, modelando así una pila.
*/

//Definir constantes booleanas
#define TRUE 1
#define FALSE 0

//Definición de tipos de datos

typedef unsigned char boolean;

//Definir un elemento (El cual estará modelado por una estructura)

typedef struct elemento
{
	//El tipo de dato que el usuario requiera
	
}elemento;

//Definición de nodo, el cual será utilizado para guardar un elemento y la dirección del nodo que está debajo

typedef struct nodo
{
	elemento e;
	struct nodo *abajo
	
}nodo;

//Definición de la pila, la cuál almacenará las direcciones del nodo que se encuentra en el extremo llamado tope
typedef struct pila
{
	nodo *tope;
}pila;

//Definición de funciones
void Initialize(pila *s);			//Inicializa la pila (la prepara para su uso)
void Push(pila *s, elemento e);		//Empila un elemento 'e' en la pila
elemento Pop (pila *s);				//Desempila un elemento 'e' en la pila
boolean Empty(pila *s);				//Pregunta si la pila está vacía
elemento Top(pila *s);				//Pregunta por el elemento que se encuentra en el tope de la pila, pero no lo saca
int Size(pila *s);					//Pregunta por el número de elementos que hay en la pila
void Destroy(pila *s);				//Libera el espacio de memoria utilizado por la pila y los elementos que contenga
