/**
	Programa: Evaluaci�n de expresiones aritm�tica
	Autores: Equipo Smitty Werberjagermanjensen
	Versi�n: 1.0
	
	Descripci�n: Evaluaci�n de expresiones aritm�ticas mediante el uso de pilas
	Se usar� una estructura de datos tipo LIFO (Last In First Out)
	Se ingresa una expresion, el programa proceder� a:
		1.-Validar que el uso de par�ntesis (si los hay), sea correcto.
		2.-Pasar la expresion a notacion postfija
		2.-Evaluar la expresion y devolver el resultado
	
	Observaciones: Se podr� ingresar una expresion aritmetica que no sobrepase
	el l�mite establecido por la constante MAX_TAMANO (la cual se declarar� mas adelante)
*/

//Librerias
#include <stdio.h>
#include <stdlib.h> //Para el uso de exit()
#include "TADPilaDinSW.h" //Se utilizar� para hacer uso de una pila din�mica

//Definiciones
#define MAX_TAMANO 100 //Tama�o m�ximo de la expresion aritm�tica

//Definificion de funciones

boolean validar_parentesis(char *,int ); //Funcion que recibe un apuntador a caracter y un entero y valida el uso de par�ntesis, retornando TRUE o FALSE dependiendo el caso

//Programa principal
int main()
{
	int tamano_cadena_real; //Se usar� para almacenar el tama�o de la cadena
	
	
	return 0;
}

