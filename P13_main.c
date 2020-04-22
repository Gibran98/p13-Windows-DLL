/*
Autores: 
    Hector Gibran Gonzalez Leal [A01282778]
    Pedro Fernando Villezca Garza [A01282613]
Fecha: 24/abr/2020

Archivo que utiliza las funciones de la libreria dinamica
usando apuntadores a funciones

comandos:
    Compilar la libreria dinamica:
        gcc -o P13_DLL.dll -s -shared P13_DLL.c -Wl,--subsystem,windows
    Compilar el programa de aplicacion y generar el ejecutable:
        gcc -o P13_Ejec.exe -s P13_main.c -L. -lP13_DLL
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HINSTANCE hCodigoDll; //Apuntador a la libreria dll

typedef int (asciiBinaryToInt)(char*);
asciiBinaryToInt* ptrFuncBinaryToInt = 0;

typedef int (asciiHEXToInt)(char*);
asciiHEXToInt* ptrFuncHexToInt = 0;

typedef double (asciiToDouble)(char*);
asciiToDouble* ptrFuncToDouble = 0;

void main() {
    char *bin = "100101101";
    char *hex = "CAFE";
    char *dou = "3.14159";

	//Inclusion implicita: Realiza inclusion dinamica de la biblioteca
	if (hCodigoDll = LoadLibrary("P13_DLL.dll")) {

		if(ptrFuncBinaryToInt = (asciiBinaryToInt*) GetProcAddress(hCodigoDll ,"asciiBinaryToInt")) {
            printf("Resultado Binario = %d\n", (*ptrFuncBinaryToInt)(bin));
		} else {
			printf("Error al obtener la direccion del procedimiento binario!\n");
        }

        if(ptrFuncHexToInt = (asciiHEXToInt*) GetProcAddress(hCodigoDll ,"asciiHEXToInt")) {
            printf("Resultado Hexadecimal = %d\n", (*ptrFuncHexToInt)(hex));
		} else {
			printf("Error al obtener la direccion del procedimiento hexadecimal!\n");
        }

        if(ptrFuncToDouble = (asciiToDouble*) GetProcAddress(hCodigoDll ,"asciiToDouble")) {
            printf("Resultado Double = %lf\n", (*ptrFuncToDouble)(dou));
		} else {
			printf("Error al obtener la direccion del procedimiento double!\n");
        }
	} else
		printf("Biblioteca no localizada!\n");
	FreeLibrary(hCodigoDll);

// usar otra libreria

	getchar();
}