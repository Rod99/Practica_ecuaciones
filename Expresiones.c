/**
	Programa: EvaluaciÃ³n de expresiones aritmÃ©tica
	Autores: Equipo Smitty Werberjagermanjensen
	VersiÃ³n: 1.0
	
	DescripciÃ³n: EvaluaciÃ³n de expresiones aritmÃ©ticas mediante el uso de pilas
	Se usarÃ¡ una estructura de datos tipo LIFO (Last In First Out)
	Se ingresa una expresion, el programa procederÃ¡ a:
		1.-Validar que el uso de parÃ©ntesis (si los hay), sea correcto.
		2.-Pasar la expresion a notacion postfija
		2.-Evaluar la expresion y devolver el resultado
	
	Observaciones: Se podrÃ¡ ingresar una expresion aritmetica que no sobrepase
	el lÃ­mite establecido por la constante MAX_TAMANO (la cual se declararÃ¡ mas adelante)
*/

//Librerias
#include <stdio.h>
#include <stdlib.h> //Para el uso de exit()
#include <string.h> //Para el uso de strlen()
#include "TADPilaDinSW.h" //Se utilizarÃ¡ para hacer uso de una pila dinÃ¡mica


//Definiciones
#define MAX_TAMANO 100 //TamaÃ±o mÃ¡ximo de la expresion aritmÃ©tica

//Definificion de funciones

boolean validar_parentesis(char *,int ); //Funcion que recibe un apuntador a caracter y un entero y valida el uso de parÃ©ntesis, retornando TRUE o FALSE dependiendo el caso

//Programa principal
int main()
{
	int tamano_cadena_real; //Se usarÃ¡ para almacenar el tamaÃ±o de la cadena
	char cadena[MAX_TAMANO]; //Arreglo que contendra la expresiÃ³n aritmÃ©tica
		
	//Leer cadena a evaluar
	scanf("%s",cadena);
	
	//Medir la longitud de la cadena
	tamano_cadena_real=strlen(cadena);

	if(validar_parentesis(cadena,tamano_cadena_real)==TRUE)//Valida que los parentesis estÃ©n escritos correctamente
	{
		printf("Los parentesis son correctos");
	}
	else
	{
		
		printf("Hay un error con los parentesis\n");
		exit(1); //Salir del programa con error
		
	}
	return 0;
}


boolean validar_parentesis(char *cadena,int tamano){
	
	int i;
	boolean resultado;
	
	//Se declara la pila a utilizar
	pila mi_pila;
	
	//Se declara el elemento que entrarÃ¡ a la pila
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
			}//Si el caracter es ) realizar un Pop a la pila		
		else {
		if(*(cadena+i)==')')
			{
				//Si se intenta extraer un elemento y la pila es vacia Error: P.g. (a+b)*c)
				if(Empty(&mi_pila))
				{
					resultado= FALSE;
				}
				else
				{
					e=Pop(&mi_pila);
				}
			}
		}
	}
	
	if(Empty(&mi_pila))
	{
		resultado = TRUE;
	}
	else
	{
		resultado = FALSE;
	}
	return resultado;
}
