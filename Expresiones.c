/**
	Programa: Evaluación de expresiones aritmética
	Autores: Equipo Smitty Werberjagermanjensen
	Versión: 1.0
	
	Descripción: Evaluación de expresiones aritméticas mediante el uso de pilas
	Se usará una estructura de datos tipo LIFO (Last In First Out)
	Se ingresa una expresion, el programa procederá a:
		1.-Validar que el uso de paréntesis (si los hay), sea correcto.
		2.-Pasar la expresion a notacion postfija
		2.-Evaluar la expresion y devolver el resultado
	
	Observaciones: Se podrá ingresar una expresion aritmetica que no sobrepase
	el límite establecido por la constante MAX_TAMANO (la cual se declarará mas adelante)
*/

//Librerias
#include <stdio.h>
#include <stdlib.h> //Para el uso de exit()
#include <string.h> //Para el uso de strlen()
#include "TADPilaDinSW.h" //Se utilizará para hacer uso de una pila dinámica


//Definiciones
#define MAX_TAMANO 100 //Tamaño máximo de la expresion aritmética

//Definificion de funciones

boolean validar_parentesis(char *,int ); //Funcion que recibe un apuntador a caracter y un entero y valida el uso de paréntesis, retornando TRUE o FALSE dependiendo el caso

//Programa principal
int main()
{
	int tamano_cadena_real; //Se usará para almacenar el tamaño de la cadena
	char cadena[MAX_TAMANO]; //Arreglo que contendra la expresión aritmética
		
	//Leer cadena a evaluar
	scanf("%s",cadena);
	
	//Medir la longitud de la cadena
	tam_cadena_real=strlen(cadena);

	if(validar_parentesis(cadena,tam_cadena_real)==TRUE)//Valida que los parentesis estén escritos correctamente
	{
		
	}
	{
		
		printf("Hay un error con los paréntesis\n");
		exit(1); //Salir del programa con error
		
	}
	return 0;
}


boolean validar_parentesis(char *cadena,int tamano){
	
	int i;
	boolean resultado;
	
	//Se declara la pila a utilizar
	pila mi_pila;
	
	//Se declara el elemento que entrará a la pila
	elemento e;
	
	//Inicializacipon de "mi pila"
	Initialize(&mi_pila);
	
	for(i=0;i<tamano;i++)
	{
			//Si el caracter es ( introducirlo a la pila
		if(*(cadena+i)=='(')
			{
				e.c='(';
				Push(&mi_pila,e);
			}
		
		//Si el caracter es ) realizar un Pop a la pila		
		else if(*(cadena+i)==')')
			{
				//Si se intenta extraer un elemento y la pila es vacia Error: P.g. (a+b)*c)
				if(Empty(&mi_pila))
				{
					resultado= FALSE;
				
				}
				e=Pop(&mi_pila);
			}
	}
	
	resultado = TRUE;
	
	return resultado;
}
