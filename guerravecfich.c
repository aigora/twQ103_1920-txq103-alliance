#include <stdio.h>

int main (){
	int vj1[13],vj2[13],dado;
	FILE *pfichero;
	int turnos=0, i;
	 char cadenaNombre1[50],cadenaNombre2[50],nombre1[50],nombre2[50];
   

	// Abrir el fichero
	pfichero = fopen("turnos.txt", "w");
	// En el modo w -> Si el fichero existe, lo sobreescribe
	//              -> Si no existe, entonces lo crea
	if (pfichero == NULL) {
		printf("No se ha podido crear el fichero\n");
		return 0;
	

		//PRESENTACION DEL JUEGO
	printf("Bienvenido a nuestro juego. En los proximos minutos te enfrentaras a tu amigo en el escenario de una guerra mundial en la que seras responsable de llevar a tu coalicion al exito\n.");
	printf("Introduce tu nombre 1:\n");
    gets(cadenaNombre1);

    printf("Introduce tu nombre 2:\n");
    gets(cadenaNombre2);

    i=0;
    while (cadenaNombre1[i]!='\0'){
        nombre1[i]=cadenaNombre1[i];
        i++;
    }
    nombre1[i]='\0';
    i=0;
	printf(" %s y %s han de elegir un pais aliado del siguiente listado", nombre1,nombre2);
	printf("\n 1. EEUU \n 2. China \n 3. Rusia \n \n");
	printf("\n Comienza eligiendo %s... \n Introduzca 1 si quiere aliarse con EEUU, 2 con China o 3 con Rusia.\n",nombre1);
	
			
			//PRIMERA ELECCION J1
			
			
				scanf("%i", &vj1[0]);
			if (vj1[0]==1)
			printf("%s: Acabas de elegir a EEUU\n",nombre1);
			
			else if (vj1[0]==2)
			printf("%s: Acabas de elegir a China\n",nombre1);
			else printf("%s: Acabas de elegir a Rusia\n",nombre1);


			//PRIMERA ELECCION J2
			
		
				printf("\n \n Turno de %s....\n Elige uno de los siguientes paises: \n",nombre2);
				if (vj1[0]==1)
			printf("2. China\n3. Rusia\n");
			else if (vj1[0]==2)
			printf("1. EEUU\n3. Rusia\n");
			else printf("1. EEUU\n2. China\n");
			
			scanf("%i", &vj2[0]);	
			if (vj2[0]==1)
			printf("%s: Acabas de elegir a EEUU\n",nombre2);
			
			else if (vj2[0]==2)
			printf("J2: Acabas de elegir a China\n");
			else printf("J2: Acabas de elegir a Rusia\n");	
			fprintf(pfichero, "%d %d\n", vj1[0], vj2[0]); // 
			
			//SEGUNDA ELECCION J2
			
			printf("\n Muy bien...pero si queremos llevar la batalla a un nivel global necesitaremos mas aliados.\n Seguimos con el mecanismo de antes. Ahora elige primero el J2.");
			printf(" \n 1. Espana \n 2. Francia \n 3. Brasil \n");
			scanf("%i", &vj2[1]);
			if (vj2[1]==1)
			printf("J2: Acabas de elegir a Espana\n");
			else if (vj2[1]==2)
			printf("J2: Acabas de elegir a Francia\n");
			else printf("J2: Acabas de elegir a Brasil\n");
			
		
			//Segunda eleccion J1
			
			printf("\n Le toca elegir de nuevo al jugador 1\n");
				if (vj2[1]==1)
			printf("2. Francia\n3. Brasil\n");
			else if (vj2[1]==2)
			printf("1. Espana\n3. Brasil\n");
			else printf("1. Espana\n2. Francia\n");
			scanf("%i", &vj1[1]);	
			if (vj1[1]==1)
			printf("J1: Acabas de elegir a Espana\n");
			else if (vj1[1]==2)
			printf("J1: Acabas de elegir a Francia\n");
			else printf("J1: Acabas de elegir a Brasil\n");
				fprintf(pfichero, "%d %d\n", vj1[1], vj2[1]); // 
			//RESUMEN EQUIPOS
			
			printf("\n Los equipos definitivos son:\n");
			if (vj1[0]==1)
			printf("J1: Juega con EEUU");
			else if (vj1[0]==2)
			printf("J1: Juega con China");
			else printf("J1: Juega con Rusia");
			
			if (vj1[1]==1)
			printf(" y Espana\n");
			else if (vj1[1]==2)
			printf(" y Francia\n");
			else printf(" y Brasil\n");
			
			if (vj2[0]==1)
			printf("J2: Juega con EEUU");
			else if (vj2[0]==2)
			printf("J2: Juega con China");
			else printf("J2: Juega con Rusia");
			
			if (vj2[1]==1)
			printf(" y Espana\n");
			else if (vj2[1]==2)
			printf(" y Francia\n");
			else printf(" y Brasil\n");


				//ARMAMENTO
				//5 MONEDAS
				printf("\n \n La guerra esta a punto de empezar...\n Cada jugador dsipone de 10 monedas para comprar nuevos recursos de guerra.");
				printf("Por cinco monedas puedes comprar: \n 1. Regimiento de 300.000 soldados extra.\n 2. Flota de barcos (3 submarinos, dos acorazados y un portaaviones)\n 3. Apoyo aereo (15 cazas)");
				printf("\n Elige primero el jugador 1:\n");
				scanf ("%i",&vj1[2]);
				switch (vj1[2])
				{
				case 1:printf ("J1:Has elegido añadir 300000 soldados a tu ejercito");
				break;
				case 2:printf ("J1:Has añadido refuerzo maritimo a tu ejercito");
				break;
				case 3:printf ("J1:Has elegido añadir apoyo aereo");
				break;
				default:
				 printf ("Opcion incorrecta\n");}
				 
				 printf("\n Le toca elegir al jugador 2");

				scanf ("%d",&vj2[2]);
				switch (vj2[2])
				{
				case 1:printf ("J2:Has elegido añadir 300000 soldados a tu ejercito");
				break;
				case 2:printf ("J2:Has añadido refuerzo maritimo a tu ejercito");
				break;
				case 3:printf ("J2:Has elegido añadir apoyo aereo");
				break;
				default:
				 printf ("Opcion incorrecta\n");
				}
				fprintf(pfichero, "%d %d\n", vj1[2], vj2[2]); // 
				//3 MONEDAS

				printf("\n \n Por tres monedas puedes comprar: \n 1. Drones de defensa.\n 2. Satélite de apoyo gps\n 3. Bunqueres");
				printf("\n Elige primero el jugador 2:\n");
				scanf ("%i",&vj2[3]);
				
				switch (vj2[3])
				{
				case 1:printf ("J2:Has elegido comprar drones defensivos");
				break;
				case 2:printf ("J2:Has comprado un satelite de apoyo gps");
				break;
				case 3:printf ("J2:Has Distribuido bunqueres para proteccion entre tus aliados");
				break;
				default:
				 printf ("Opcion incorrecta\n");
				}
				
				printf("\nElige jugador 1");
				scanf ("%i",&vj1[3]);
				switch (vj1[3])
				{
				case 1:printf ("J1:Has elegido comprar drones defensivos");
				break;
				case 2:printf ("J1:Has comprado un satelite de apoyo gps");
				break;
				case 3:printf ("J1:Has Distribuido bunqueres para proteccion entre tus aliados");
				break;
				default:
				 printf ("Opcion incorrecta\n");
				}
				fprintf(pfichero, "%d %d\n", vj1[3], vj2[3]); // 
				//1 MONEDA
				printf("\n Por dos monedas puedes comprar: \n 1. Enviar a niños y mujeres a la guerra.\n 2. Enviar espias a territorio enemigo\n 3. Personal sanitario en territorio enemigo ");
				printf("Elige primero el jugador 1:\n");
				scanf ("%i",&vj1[4]);
				switch (vj1[4])
				{
				case 1:printf ("J1:Has elegido enviar a niños y mujeres a la guerra.");
				break;
				case 2:printf ("J1:Has elegido enviar espias a territorio enemigo");
				break;
				case 3:printf ("J1:Has distribuido personal sanitario en territorio enemigo");
				break;
				default:
				 printf ("Opcion incorrecta\n");
				}
				printf("Turno del jugador 2:\n");
				scanf ("%i",&vj2[4]);
				switch (vj2[4])
				{
				case 1:printf ("J2:Has elegido enviar a niños y mujeres a la guerra.");
				break;
				case 2:printf ("J2:Has elegido enviar espias a territorio enemigo");
				break;
				case 3:printf ("J2:Has distribuido personal sanitario en territorio enemigo");
				break;
				default:
			 printf ("Opcion incorrecta\n");}
			 fprintf(pfichero, "%d %d\n", vj1[4], vj2[4]); // 
				
					//PRIMERA RONDA DEL JUEGO
					
					printf ("Comienza el juego.....\n\n Buenas tardes J1, nuestro comandante nos ha avisado esta mañana de que se ha visionado un mensaje en el cielo que dos avionetas han dejado tras su paso. El mensaje dice asi'Nossos espioes estao seguros'. No estamos muy seguros de lo que dice asi que hemos decidido pedir ayuda a nuestros aliados");
						if (vj1[1]==1){
						printf("\nNuestros aliados españoles no estan muy seguros de lo que pone, pero creen que pone que nuestros espias no esan a salvo");
							if (vj1[2]==1){
							printf ("\nEn consecuencia de esto mandaremos el regimiento de soldados del que disponemos");}
								if (vj2[3]==1){
								printf("\nLos drones de defensa del jugador 2 no han sido capaces de frenar la ofensiiva del J1");}
								if (vj2[3]==2) {
								printf("\nEl radar GPS enemigo ha detectado a tus soldados y han sufrido una emboscada");}
								if (vj2[3]==3) { 
								printf("\nNuestros soldados han arrasado el territorio enemigo a pesar de los bunqueres donde la poblacon se ocultaba");}
							if (vj1[2]==2) {
							printf("En consecuencia mandaremos a la marina");}
								if (vj2[3]==1){
								printf("\nLos drones de defensa del jugador 2 han sido capaces de frenar la ofensiva maritima");}
								if (vj2[3]==2) {
								printf("\nEl radar GPS enemigo no ha podido detectar a los barcos.");}
								if (vj2[3]==3) { 
								printf("\nLos bunqueres no han tenido utilidad frente al ataque enemigo");}
							
							if (vj1[2]==3) {
							printf("En consecuencia mandaremos a nuestro ejercito del aire");}
								if (vj2[3]==1){
								printf("\nLos drones de defensa del jugador 2 hicieron algo de cara a los cazas, pero cayeron derrotados");}
								if (vj2[3]==2) {
								printf("\nEl radar GPS enemigo no ha podido detectar a cazas.");}
								if (vj2[3]==3) { 
								printf("\nLos bunqueres salvaron las vidas de el pueblo. Los cazas sufrieron un accidente mientras volvian hacia su base");}
								
							
							
						if (vj1[1]==2) { 
						printf("Nuestros aliados franceses no están muy seguros de lo que dice el mensaje");
						printf("\nTus generales te recomiendan no tomar una decision aun. No estas nada seguro de si empezar tu ofensiva ahora mismo.");
						printf("Decides tirar un dado para aclarar tus ideas. Si sale un numero para decides empezar lanzando tu la ofensiva.\n");
						printf("En cambio si sale un numero impar te mostraras a la espera de un posible ataque enemigo.");
						dado = rand() % 7+1;
						printf("Acabas de tirar el dado y te ha salido el número %d", dado);
						if (dado % 2 == 0) {
   						 printf("Es par. J1 empiezas atacando.");
   						 	if (vj1[2]==1){
							printf ("\nEn consecuencia de esto mandaremos el regimiento de soldados del que disponemos");}
								if (vj2[3]==1){
								printf("\nLos drones de defensa del jugador 2 no han sido capaces de frenar la ofensiiva del J1");}
								if (vj2[3]==2) {
								printf("\nEl radar GPS enemigo ha detectado a tus soldados y han sufrido una emboscada");}
								if (vj2[3]==3) { 
								printf("\nNuestros soldados han arrasado el territorio enemigo a pesar de los bunqueres donde la poblacon se ocultaba");}
							if (vj1[2]==2) {
							printf("En consecuencia mandaremos a la marina");}
								if (vj2[3]==1){
								printf("\nLos drones de defensa del jugador 2 han sido capaces de frenar la ofensiva maritima");}
								if (vj2[3]==2) {
								printf("\nEl radar GPS enemigo no ha podido detectar a los barcos.");}
								if (vj2[3]==3) { 
								printf("\nLos bunqueres no han tenido utilidad frente al ataque enemigo");}
							
							if (vj1[2]==3) {
							printf("En consecuencia mandaremos a nuestro ejercito del aire");}
								if (vj2[3]==1){
								printf("\nLos drones de defensa del jugador 2 hicieron algo de cara a los cazas, pero cayeron derrotados");}
								if (vj2[3]==2) {
								printf("\nEl radar GPS enemigo no ha podido detectar a cazas.");}
								if (vj2[3]==3) { 
								printf("\nLos bunqueres salvaron las vidas de el pueblo. Los cazas sufrieron un accidente mientras volvian hacia su base");}
								
  						} else {
   						 printf("Es impar. Es el el jugador quien comienza atacando");
   						 if (vj2[2]==1){
							printf ("\nEl jugador 2 manda el regimiento de soldados del que dispone");}
								if (vj1[3]==1){
								printf("\nLos drones de defensa del jugador 1 no han sido capaces de frenar la ofensiiva del J2");}
								if (vj1[3]==2) {
								printf("\nEl radar GPS enemigo ha detectado a tus soldados y han sufrido una emboscada");}
								if (vj1[3]==3) { 
								printf("\nLos soldados del jugador 2 no han realizado ningun daño ya que la poblacion se encontraba escondida en bunqueres");}
							if (vj2[2]==2) {
							printf("El J2 manda a la marina");}
								if (vj1[3]==1){
								printf("\nLos drones de defensa del jugador 1 han sido capaces de frenar la ofensiva maritima");}
								if (vj2[3]==2) {
								printf("\nEl radar GPS del J1 no ha podido detectar a los barcos.");}
								if (vj2[3]==3) { 
								printf("\nLos bunqueres no han tenido utilidad frente al ataque enemigo");}
							
							if (vj2[2]==3) {
							printf("En consecuencia mandaremos a nuestro ejercito del aire");}
								if (vj1[3]==1){
								printf("\nLos drones de defensa del jugador 1 hicieron algo de cara a los cazas, pero cayeron derrotados");}
								if (vj1[3]==2) {
								printf("\nEl radar GPS enemigo no ha podido detectar a cazas.");}
								if (vj1[3]==3) { 
								printf("\nLos bunqueres salvaron las vidas de el pueblo. Los cazas sufrieron un accidente mientras volvian hacia su base");}
								
   						 
  						}
						
					
					
					
					
					
					
					
						if (vj1[1]==3) {
						printf("Nuestros aliados brasileitos nos han traducido perfectamente el mensaje y nos comunican que nuestros espias estan a salvo");
						printf("Gracias a la traduccion del mensaje te quedas mucho más tranquilo y la tension se reduce. Sabes que tus espias estan a salvo y no \n");
						printf("decides atacar a tus enemigos. Sin embargo te llegan informaciones de que el J2 tiene en mente mandar una ofensiva");
						if (vj2[2]==1){
							printf ("\nEl jugador 2 manda el regimiento de soldados del que dispone");}
								if (vj1[3]==1){
								printf("\nLos drones de defensa del jugador 1 no han sido capaces de frenar la ofensiiva del J2");}
								if (vj1[3]==2) {
								printf("\nEl radar GPS enemigo ha detectado a tus soldados y han sufrido una emboscada");}
								if (vj1[3]==3) { 
								printf("\nLos soldados del jugador 2 no han realizado ningun daño ya que la poblacion se encontraba escondida en bunqueres");}
							if (vj2[2]==2) {
							printf("El J2 manda a la marina");}
								if (vj1[3]==1){
								printf("\nLos drones de defensa del jugador 1 han sido capaces de frenar la ofensiva maritima");}
								if (vj2[3]==2) {
								printf("\nEl radar GPS del J1 no ha podido detectar a los barcos.");}
								if (vj2[3]==3) { 
								printf("\nLos bunqueres no han tenido utilidad frente al ataque enemigo");}
							
							if (vj2[2]==3) {
							printf("En consecuencia mandaremos a nuestro ejercito del aire");}
								if (vj1[3]==1){
								printf("\nLos drones de defensa del jugador 1 hicieron algo de cara a los cazas, pero cayeron derrotados");}
								if (vj1[3]==2) {
								printf("\nEl radar GPS enemigo no ha podido detectar a cazas.");}
								if (vj1[3]==3) { 
								printf("\nLos bunqueres salvaron las vidas de el pueblo. Los cazas sufrieron un accidente mientras volvian hacia su base");}
								
   						 
  						}
						
						
						}
					
					
					
					


					
						
				
				
				
				
				}
	/0			
}
