#include<stdio.h>
#include<string.h>
#define MAX_ELEMENT 100



/*          Prioridad en Notacion Infija
----------------------------------------------------
esta prioridad se usa al momento de leer el caracter
de la cadena*/
int prioridad_infija(char a)
{
    if(a=='^')
        return 4;
    if( a=='*')
        return 2;
    if( a=='/')
        return 2;
    if( a=='+')
        return 1;
    if( a=='-')
        return 1;
    if(a=='(')
        return 5;
}

/*                 Prioridad en Pila
---------------------------------------------------
esta prioridad es usada para los elementos que se
encuentran en la pila 

Orden 
	^ 		MAYOR PRECEDENCIA
	*  /	MEDIANA PRECEDENCIA
	+  -	MENOR PRECEDENCIA

*/
int prioridad_pila(char a)
{
    if(a=='^')
        return 3;
    if( a=='*')
        return 2;
    if( a=='/')
        return 2;
    if( a=='+')
        return 1;
    if( a=='-')
        return 1;
    if(a=='(')
        return 0;
}
int main()
{
	char cadena[MAX_ELEMENT];
	
	printf("CONVERSION DE EXPRESIONES MATEMATICAS DE INFIJA A POSTFIJA\n\n");
        do
		{
        	printf("INGRESE EXPRESION:\n");
           	gets(cadena);
            	if(M!=NULL)
                 	destruir(M);
           	balanceoSimbolos(M,cad); //verificamos si los simbolos de agrupacion estan
        }while(M!=NULL);         //correctamente valanceados
}
