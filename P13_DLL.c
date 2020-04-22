/*
Autores: 
    Hector Gibran Gonzalez Leal [A01282778]
    Pedro Fernando Villezca Garza [A01282613]
Fecha: 24/abr/2020

Archivo para la libreria dinamica con las funciones
para convertir diferentes tipos de numeros
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define DllExport __declspec(dllexport)

//funcion que recibe un numero binario como string y regresa el valor decimal 
//de ese numero en un entero
DllExport int asciiBinaryToInt(char *s) {
    int res = 0, exp=0;

    for(int i=strlen(s)-1; i>=0; i--) {
        if(s[i] == '1') 
            res += pow(2, exp);
        exp++;
    }
    return res;
}

//funcion que recibe un numero hexadecimal como string y regresa el valor 
//decimal de ese numero en un entero
DllExport int asciiHEXToInt(char *s) {
    int res=0, exp=0, currDigit, currLength=0;

    while(currLength < strlen(s) && ((s[currLength] >= '0' && 
        s[currLength] <= '9') || (s[currLength] >= 'A' && 
        s[currLength] <= 'F') || (s[currLength] >= 'a' && 
        s[currLength] <= 'f'))) {

        currLength++;
    }

    for(int i=currLength-1; i>=0; i--) {
        if(s[i] >= '0' && s[i] <= '9') 
            currDigit = s[i] - 48;
        else if(s[i] >= 'A' && s[i] <= 'F') 
            currDigit = s[i] - 55;
        else if(s[i] >= 'a' && s[i] <= 'f') 
            currDigit = s[i] - 87;
        else 
            return res;
        
        res += (currDigit * pow(16, exp));
        exp++;
    }
    return res;
}

//funcion que recibe un numero double como string y regresa el valor de ese 
//numero en un double
DllExport double asciiToDouble(char *s) {
    double whole=0, decimal=0;
    int exp=0, point=0, currDigit, negative=0;

    while(point<strlen(s) && s[point] != '.')
        point++;

    //getting the whole part
    for(int i=point-1; i>=0; i--) {
        if(s[i] == '-')
            negative = 1;
        else if(s[i] >= '0' &s[i] <= '9') {
            currDigit = s[i] - 48;
            whole += currDigit * pow(10, exp);
        }
        exp++;        
    }

    exp=1;
    //getting the decimal part
    for(int i=point+1; i<strlen(s); i++) {
        currDigit = s[i] - 48;
        decimal += currDigit / (pow(10, exp));
        exp++;
    }

    if(negative)
        return -1*(whole+decimal);
    return whole+decimal;
}