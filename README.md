# Windows DLL P13

by Héctor Gibrán González Leal and Pedro Fernando Villezca Garza

## Documentation

This dynamic library contains the following functions:

<b>1. int asciiBinaryToInt(char*)</b>, which takes any character array containing a valid number and returns its value as a base 10 integer.

<b>2. int asciiHEXToInt(char*)</b>, which takes any character array containing a hexadecimal number and returns its equivalent value as a base 10 integer.

<b>3. double asciiToDouble(char*)</b>, which takes any character array containing a real number and returns its value as a base 10 double.

## Usage

<b> Step 1:</b> Prepare your code to include the library with the following line:
<pre>HINSTANCE library; // You should preferrably define this globally</pre>
and then include it dynamically later in your code:
<pre>library = LoadLibrary("path/to/P13_DLL.dll");</pre>

<b> Step 2:</b> Define a data type corresponding to any function you want to include and create a pointer to it:
<pre>
typedef int (asciiBinaryToInt)(char*);
asciiBinaryToInt* ptrFuncBinaryToInt = 0;
</pre>

<b> Step 3:</b> Seek the function within the DLL with its corresponding pointer and use the function:
<pre>
ptrFuncBinaryToInt = (asciiBinaryToInt*) GetProcAddress(library ,"asciiBinaryToInt");
int result = (*ptrFuncBinaryToInt)(parameter);
</pre>

Repeat steps 2 and 3 for each function you would like to implement.

<b> Step 4:</b> Compile the dynamic library in the command line:
<pre>gcc -o P13_DLL.dll -s -shared P13_DLL.c -Wl,--subsystem,windows</pre>
Where P13_DLL.dll is the dynamic library to be generated and P13_DLL.c is the file that contains its code.

<b> Step 5:</b> Compile your code in the command line:
<pre>gcc -o P13_Ejec.exe -s P13_main.c -L. -lP13_DLL</pre>
Where P13_Ejec.exe is the executable file to be generated, P13_main.c is the file that contains your code, and P13_DLL is the name of the .dll file you generated previously.

<b> Step 6:</b> Run your code.
