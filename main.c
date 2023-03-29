#include <stdio.h>
#include <string.h>

int tolower(int);

int in_range(int, int, int);

int main(){

	int n = 30;

	char matches[30][6][20];
	int matches_length = 0;

	char persona[6][20];

	char datos[30][6][20] = {
		{ "Femenino","Regina","22","Si","Pop","BAILE" }, 
		{ "Femenino","Valeria","34","No","Salsa","Americano" },
		{ "Femenino","Valentina","19","No","Reggueaton","Americano" },
		{ "Femenino","Fernanda","46","SI","Salsa","Soccer" },
		{ "Femenino","Sofia","29","SI","Pop","BAILE" },
		{ "Femenino","Maria ","48","No","Salsa","Basquet" },
		{ "Femenino","Gabriela","52","Si","Clasica","Basquet" },
		{ "Femenino","Alexa","21","No","Reggueaton","Americano" },
		{ "Femenino","Alejandra","38","No","Rock","Americano" },
		{ "Femenino","Mariana","47","Si","Salsa","Baile" },
		{ "Femenino","Patricia","52","Si","Salsa","Baile" },
		{ "Femenino","Natalia","54","Si","Pop","Baile" },
		{ "Femenino","Paola","25","Si","Corridos","Baile" },
		{ "Femenino","Daniela","27","Si","Pop","Soccer" },
		{ "Masculino","Alejandro","55","No","Rock","Soccer" },
		{ "Masculino","Santiago","28","Si","Corridos","Soccer" },
		{ "Masculino","Hernan","25","Si","Corridos","Soccer" },
		{ "Masculino","Carlos","46","Si","Clasica","Boxeo" },
		{ "Masculino","Alexander","19","No","Reggueaton","Boxeo" },
		{ "Masculino","Ricardo","25","No","Reggueaton","Americano" },
		{ "Masculino","Roberto","49","No","Salsa","Baile" },
		{ "Masculino","Maximiliano","57","si","Clasica","Baile" },
		{ "Masculino","Patricio","23","Si","Reggueaton","Soccer" },
		{ "Masculino","Alfredo","24","sI","Corridos","Basquet" },
		{ "Masculino","Mario","21","No","Rock","Americano" },
		{ "Masculino","Alberto","54","Si","Rock","Americano" },
		{ "Masculino","Edgar","35","No","Salsa","Americano" },
		{ "Masculino","Lorenzo","33","Si","Salsa","Soccer" },
		{ "Masculino","Andres","38","Si","Pop","Boxeo" },
		{ "Masculino","David","48","No","Pop","Baile" }
	};



//	for(int i = 0; i < 30; i++){
//
//		printf("Nombre: %s\n", datos[i][1] );
//
//	}

	char nombre[20];
	int edad = 0, edad_minima=0, edad_maxima=0;
	char qbuscas;
	char psexual;
	char uni;
	char sexo;

	printf("Bienvenido a MATCH!\n");	
	printf("Ingresa tu nombre:\t");	
	scanf("%s", nombre);
	strncpy(persona[1], nombre, 20);
	printf("Ingresa tu edad:\t");	
	scanf("%d", &edad);
	printf("Ingresa tu rango de edad preferido como min-max:\t");	
	scanf("%d-%d", &edad_minima, &edad_maxima);
//	sprintf(persona[2], "%d", edad);
	//strncpy(persona[0], edad, 20);
	printf("Ingresa tu sexo:\n\t");	
	printf("a) femenino\n\t");
	printf("b) masculino\n");
	scanf(" %c", &sexo);

	printf("Sexo es:  %c\n", sexo);

	//scanf("
	//			sprintf(persona[2], "%d", edad);
//	printf("Que buscas en la aplicacion?:\t\n");	
//	printf("a) amistad\n");
//	printf("b) pareja\n");
//	//printf(":\t");
//	scanf(" %c", &qbuscas);
//	if( qbuscas == 'b'){
		printf("Cual es tu preferencia sexual?:\n\t");
		printf("a) femenino\n\t");
		printf("b) masculino\n");
		scanf(" %c", &psexual);
		printf("Te gustaria que tu pareja tenga estudios universitarios?\n\t");
		printf("a) si\n\t");
		printf("b) no\n");
		scanf(" %c", &uni);
//	}

	char musica[20];
	printf("Que genero de musica escuchas?\n\t");
	scanf("%s", musica);
	char deporte[20];
	printf("Cual es tu deporte favorito?\n\t");
	scanf("%s", deporte);

	printf("INTEL:\n"\
			"nombre: %s\n"\
			"edad: %d\n"
			"sexo: %c\n"
			"Preferencia sexual: %c\n"
			"Gustaria Estudios Universitarios: %c\n"
			"Musica: %s\n"
			"Deporte: %s\n"
			"%d-%d\n",
			nombre, edad, sexo, psexual, uni, musica, deporte, edad_minima, edad_maxima);


	for(int i = 0; i < n; i++ ) {
		int match_caracteristicas = 0;
		//sexo
		//nombre
		//edad
		//universidad
		//genero musica
		//deporte

		//printf("%s\n", datos[i][0]);
		//
		// verificacion preferencia sexual
		if( (datos[i][0][0] == 'F' && psexual == 'a') || (datos[i][0][0] == 'M' && psexual == 'b') ){
			match_caracteristicas++;
		}

		int edad_dato=0;
		// parsing edad
		sscanf(datos[i][2], "%d", &edad_dato);
		// printf("ead: %d\n", edad_dato);
		if ( in_range(edad_dato, edad_minima, edad_maxima) ){
			match_caracteristicas++;
		}

		// uni clean up
		// converts 'sI' or 'si' or 'SI' or 'Si' to -> 'si'
		// converts 'nO' or 'no' or 'NO' or 'No' to -> 'no'
		char uni_dato_lower[2];
		uni_dato_lower[0] = tolower(datos[i][3][0]);
		uni_dato_lower[1] = tolower(datos[i][3][1]);
		
		if( (uni_dato_lower[0] == 's' && uni == 'a') || (uni_dato_lower[0] == 'n' && uni == 'b') ){
			match_caracteristicas++;
		}

		//genero musica
		//
		//
		// strings are equal
		if( !strncmp(datos[i][4], musica, 20) ){
			match_caracteristicas++;
		}


		// deporte
		if( !strncmp(datos[i][5], deporte, 20) ){
			match_caracteristicas++;
		}	


		if( match_caracteristicas >= 3 ){
			strncpy( matches[matches_length][0], datos[i][0], 20);
			strncpy( matches[matches_length][1], datos[i][1], 20);
			strncpy( matches[matches_length][2], datos[i][2], 20);
			strncpy( matches[matches_length][3], datos[i][3], 20);
			strncpy( matches[matches_length][4], datos[i][4], 20);
			strncpy( matches[matches_length][5], datos[i][5], 20);
			matches_length++;
		}

	}

	printf("***********\n");

	for(int i = 0; i < matches_length; i ++){
		printf("%s, ", matches[i][0]);
		printf("%s, ", matches[i][1]);
		printf("%s, ", matches[i][2]);
		printf("%s, ", matches[i][3]);
		printf("%s, ", matches[i][4]);
		printf("%s\n", matches[i][5]);

	}




	//	printf("nombre es: %s\n", nombre);



//	strncpy( matches[16][0], datos[16][0], 20);
//	printf("%s\n", matches[16][0]);
//	printf("%s\n", datos[16][0]);


//	printf("in range 3, 7, 9: %d\n", in_range(3, 7, 9) );
//	printf("in range 9, 7, 9: %d\n", in_range(9, 7, 9) );
	return 0;
}

int in_range(int value, int min, int max){
	return (value >= min && value <= max);

}
