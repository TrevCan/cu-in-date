#include <stdio.h>



int main(){


	char datos[2][10]  = {"30", "hola"};

	char x = 'g';
	// 'g' -> num
	// 'g' -> 103
	// '0' -> 48
	//

	x = 48;
	x = '0';

	printf("%d\n", x);
	// se imprime 0
	//

	// "hola"
	// esto es un char'h' 
	//  no se puede 'hola'
	//  '0' != 0
	//  char a un int
	

	printf("%s\n", datos[0] );
	printf("%s\n", datos[1] );
	return 0;

}


