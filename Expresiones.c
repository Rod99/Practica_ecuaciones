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
#include "TADPilaDinSW.h" //Se utilizará para hacer uso de una pila dinámica

//Definiciones
#define MAX_TAMANO 100 //Tamaño máximo de la expresion aritmética

//Definificion de funciones

boolean validar_parentesis(char *,int ); //Funcion que recibe un apuntador a caracter y un entero y valida el uso de paréntesis, retornando TRUE o FALSE dependiendo el caso

//Programa principal
int main()
{
	int tamano_cadena_real; //Se usará para almacenar el tamaño de la cadena
	
	
	return 0;
}

