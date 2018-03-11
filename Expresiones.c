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
void De_infija_a_postfija(char * ,int ,char *,boolean *);//Funcion que recibe dos apuntado a caracter y un entero, pasando la expresion dada a notacion postfija y posteriormente evaluandola
int precedencia_de_operadores(char );
boolean Es_Operador(char );
//Programa principal
int main()
{
	int tamano_cadena_real; //Se usarÃ¡ para almacenar el tamaÃ±o de la cadena
	char cadena[MAX_TAMANO]; //Arreglo que contendra la expresiÃ³n aritmÃ©tica
	char postfija[MAX_TAMANO];
	boolean variables[26];
	//Leer cadena a evaluar
	scanf("%s",cadena);
	
	//Medir la longitud de la cadena
	tamano_cadena_real=strlen(cadena);

	if(validar_parentesis(cadena,tamano_cadena_real)==TRUE)//Valida que los parentesis estÃ©n escritos correctamente
	{
		puts("Los parentesis son correctos\n");
		
		De_infija_a_postfija(cadena,tamano_cadena_real,postfija,variables);
		
		puts(postfija);
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
					printf("Hay un error en los parentesis");
					exit(1);
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

void De_infija_a_postfija(char *cadena ,int longitud,char * postfija,boolean *variables)
{
	int i,aux=0;
	char pos;
	//Se declara la pila a utilizar
	pila mi_pila;
	
	//Se declara el elemento que entrarÃ¡ a la pila
	elemento e;
	
	//Inicializacipon de "mi pila"
	Initialize(&mi_pila);
	
	for(i =0;i<longitud;i++)
	{
		pos = *(cadena+i);
		if(('A' <= pos) && (pos <= 'Z')) //Si el valor de la cadena es una variable, se irá directo a la cadena postfija
		{
			*(postfija+aux) = pos;
			aux++;
			*(variables+(pos-'A')) = TRUE;
		}
		else
		{
			if(pos == '(')
			{
				e.c = '(';
				Push(&mi_pila, e);
			}
			else
			{
				if(pos == ')')
				{
					while((e.c = Pop(&mi_pila).c)!= '(')
					{
						*(postfija+aux) = e.c;
						aux++;
					}
				}
				else
				{
					if(Es_Operador(pos))
					{
						while(Empty(&mi_pila)!=TRUE && Es_Operador(Top(&mi_pila).c) && precedencia_de_operadores(pos)<=precedencia_de_operadores(Top(&mi_pila).c))
						{
							*(postfija+aux) = Pop(&mi_pila).c;
							aux++;
						}
						
						e.c = pos;
						Push(&mi_pila, e);
					}
				}
				
			}
		}
	}
	while(Empty(&mi_pila)!= TRUE)
				{
					*(postfija+aux) = Pop(&mi_pila).c;
					aux++;
				}
	Destroy(&mi_pila);
	*(postfija+aux) = '\0' ;//Se agrega fin de cadena para evitar que se imprima simbolos raros
	return;
}

int precedencia_de_operadores(char operador)
{
	int valor_precedencia;
	switch(operador)
	{
		case '^':
			valor_precedencia = 3;
			break;
		case '*':
			valor_precedencia = 2;
			break;
		case '/':
			valor_precedencia = 2;
			break;
		case '+':
			valor_precedencia = 1;
			break;
		case '-':
			valor_precedencia = 1;
			break;
		default: valor_precedencia = 0;
	}
	
	return valor_precedencia;
}

boolean Es_Operador(char caracter)
{
	boolean es_o_no = FALSE;
	if(caracter == '+'||caracter == '-'||caracter == '*'||caracter == '/'||caracter == '^')
	{
		es_o_no = TRUE;
	}
	
	return es_o_no;
}
