/**
	Libreria: Cabecera de TAD Pila de manera DinÃ¡mica
	Autores: Equipo Smitty Werberjagermanjensen
	VersiÃ³n: 1.0
	
	DescripciÃ³n: Pila o Stack
	Se usarÃ¡ una estructura de datos tipo LIFO (Last In First Out)
	Se aÃ±aden los datos y se extraen por un solo extremo
	Al extremo de la pila se le llama tope
	
	Observaciones: Se harÃ¡ uso de una pila dinÃ¡mica, la cuÃ¡l apartarÃ¡ memoria
	cada que sea necesario. Para esta implementaciÃ³n se usarÃ¡n nodos, los cuales
	estarÃ¡n relacionados entre si mediante apuntadores, modelando asÃ­ una pila.
*/

//Definir constantes booleanas
#define TRUE 1
#define FALSE 0

//DefiniciÃ³n de tipos de datos

typedef unsigned char boolean;

//Definir un elemento (El cual estarÃ¡ modelado por una estructura)

typedef struct elemento
{
	char c;
}elemento;

//DefiniciÃ³n de nodo, el cual serÃ¡ utilizado para guardar un elemento y la direcciÃ³n del nodo que estÃ¡ debajo

typedef struct nodo
{
	elemento e;
	struct nodo *abajo;
	
}nodo;

//DefiniciÃ³n de la pila, la cuÃ¡l almacenarÃ¡ las direcciones del nodo que se encuentra en el extremo llamado tope
typedef struct pila
{
	nodo *tope;
}pila;

//DefiniciÃ³n de funciones
void Initialize(pila *s);			//Inicializa la pila (la prepara para su uso)
void Push(pila *s, elemento e);		//Empila un elemento 'e' en la pila
elemento Pop (pila *s);				//Desempila un elemento 'e' en la pila
boolean Empty(pila *s);				//Pregunta si la pila estÃ¡ vacÃ­a
elemento Top(pila *s);				//Pregunta por el elemento que se encuentra en el tope de la pila, pero no lo saca
int Size(pila *s);					//Pregunta por el nÃºmero de elementos que hay en la pila
void Destroy(pila *s); //Libera el espacio de memoria utilizado por la pila y los elementos que contenga
