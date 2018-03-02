/*IMPLEMENTACION DE LA LIBRERIA
	Autores: 
		Equipo: **Smitty Werberjagermanjensen**
		
			*Bernabe Cortes Juan Daniel
			*Cruz Vera Jesus Rodrigo
			*Hernandez Romero Ivan Alejandro

	DESCRIPCION DE PILA:
		Estructura de datos en la que se cumple: 
			los elementos se añaden y se remueven por un solo extremo			 
*/
//LIBRERIAS
#include<stdio.h>
#include<stdlib.h>
#include "SW.h"


//DEFINICION DE FUNCIONES
/*
	***void inicialize(pila *s)***
	
		Descripcion: Se inicializa  'pila' 
		Recibe: *s (Direccion a la pila)
		Devuelve: ----
		Observaciones: 's' es la direccion a la pila que el usuario a creado
*/

void initialize(pila *s)
{
	s->tope=NULL; //(*s).tope=NULL;
	return;
}


/*
	***void Push(pila *s, elemento e)***

		Descripcion: Funcion para introducir elementos a la pila 
		Recibe: 
			+'elemento e' Elementos que se ingresaran a la pila (Empilar) 
			+'pila *s' Direccion a la pila a operar
		Devuelve:----
		Observaciones: 
					El unico caso en el que exista un desbordamiento de
		 			la pila *s, es cuando ya no haya mas memoria en el sistema
*/
void Push(pila *s, elemento e)
{
	nodo *aux;
	aux=malloc(sizeof(nodo));
	if(aux!=NULL)
	{
		aux->e=e;//(*aux).e=e;
		aux->abajo=s->tope;//(*aux).abajo=//(*s).tope;
		s->tope=aux;//(*s).tope=aux;
	}
	else
	{
		printf("ERROR: Desbordamiento de PILA!!!!");
		exit(1);
	}
}
/*
	***elemento Pop(pila *s)***

		Descripcion: Funcion para extraer elementos de la pila
		Recibe:	*s (Direccion a la pila)
		Devuelve: elemento r (Elemento extraido de la pila)
		Observaciones: 
*/

elemento Pop(pila *s)
{
	elemento r;
	nodo *aux;
	if (s->tope==NULL) //if((*s).tope==NULL)
		printf("ERROR: Subdesbordamiento de PILA!!!!");
	r=s->tope->e; //r=(*(*s).tope).e;
	s->tope=s->tope->abajo;//(*(*s).tope).abajo
	free(aux);
	return r;
}
/*
	***void Push(pila *s, elemento e)***

		Descripcion: 
		Recibe:
		Devuelve:
		Observaciones:	
*/


/*
	***void Push(pila *s, elemento e)***

		Descripcion: 
		Recibe:
		Devuelve:
		Observaciones:	
*/
/*
	***void Push(pila *s, elemento e)***

		Descripcion: 
		Recibe:
		Devuelve:
		Observaciones:	
*/
/*
	***void Push(pila *s, elemento e)***

		Descripcion: 
		Recibe:
		Devuelve:
		Observaciones:	
*/
