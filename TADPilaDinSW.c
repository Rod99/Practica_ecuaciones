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
	***boolean Empty(pila s*)***

		Descripcion:Pregunta si la pila esta vacia 
		Recibe: int *s ("s" a operar)
		Devuelve:Si la pila esta vacia o tiene algo adentro (TRUE OR FALSE)
		Observaciones:	
*/
boolean Empty(pila *s)
{
	boolean r;
	if(s->tope==NULL)
	{
		r=TRUE;
	}	
	else
	{
		r=FALSE;
	}
	return r;	
}


/*
	***elemento top pila (pila *s)***

		Descripcion:tope (muestra el valor que esta hasta arriba de la pila sin extraerlo)
		Recibe: int *s ("s" a operar)
		Devuelve:elemento (ultimo elemento en entrar a la pila sin extraer dicho elemento)
		Observaciones:No se valida si la pila esta vacia antes de consultar al elemento del tope (causa error si esta esta vacia).
*/
elemento Top(pila *s)
{
	//Si el tope es NULL, se intenta Top de pla vacia 
	if(s->tope==NULL)
	{
		printf("\nERROR-e=Top(&s): Subdesbordamiento de la pila, no hay elementos en la pila");
		exit(1);
	}
	
	return s->tope->e;
}

/*
	***int size (pila *s)***

		Descripcion:tamaño de la pila (Numero de elementos que contiene la pila)
		Recibe:int  *s
		Devuelve:int (tamaño de la pila 0-> vacia , y el numero de elemento que la contiene 1->1, 2->2)
		Observaciones:s tiene la referencia a la pila
*/
int Size(pila *s)
{
	nodo *aux;
	int tam_pila=0;
	aux=s->tope;
	if(aux!=NULL)
	{
		tam_pila++;
		while(aux->abajo!=NULL)
		{
			tam_pila++;
			aux=aux->abajo;
		}
	}	
	return tam_pila;
}
/*
	***void destroy (pila*s)***

		Descripcion:Elimina a la pila (borra todos los elementos y la memoria de la pila)
		Recibe:int *s
		Devuelve:---
		Observaciones:	---
*/
void Destroy(pila *s)
{
	nodo *aux;
	if(s->tope!=NULL)
	{
		while(s->tope!=NULL)
		{				
			aux=s->tope->abajo;
			free(s->tope);
			s->tope=aux;
		}		
	}
	return;
}
