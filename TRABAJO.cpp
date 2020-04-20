#include <stdio.h>

int main (){
	int vj1[13],vj2[13];
	

		//PRESENTACION DEL JUEGO
	printf("Bienvenido a nuestro juego. En los proximos minutos te enfrentaras a tu amigo en el escenario de una guerra mundial en la que seras responsable de llevar a tu coalicion al exito\n.");
	printf("Jugador 1 y Jugador 2 han de elegir un pais aliado del siguiente listado");
	printf("\n 1. EEUU \n 2. China \n 3. Rusia \n \n");
	printf("\n Comienza eligiendo jugador 1... \n Introduzca 1 si quiere aliarse con EEUU, 2 con China o 3 con Rusia.\n");
	
			
			//PRIMERA ELECCION J1
			
			
				scanf("%i", &vj1[0]);
			if (vj1[0]==1)
			printf("J1: Acabas de elegir a EEUU\n");
			
			else if (vj1[0]==2)
			printf("J1: Acabas de elegir a China\n");
			else printf("J1: Acabas de elegir a Rusia\n");


			//PRIMERA ELECCION J2
			
		
				printf("\n \n Turno del jugador 2....\n Elige uno de los siguientes paises: \n");
				if (vj1[0]==1)
			printf("2. China\n3. Rusia\n");
			else if (vj1[0]==2)
			printf("1. EEUU\n3. Rusia\n");
			else printf("1. EEUU\n2. China\n");
			
			scanf("%i", &vj2[0]);	
			if (vj2[0]==1)
			printf("J2: Acabas de elegir a EEUU\n");
			
			else if (vj2[0]==2)
			printf("J2: Acabas de elegir a China\n");
			else printf("J2: Acabas de elegir a Rusia\n");	
			
			
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
								
							
							
							if (vj1[1]==2) { 
							printf("Nuestros aliados franceses no están muy seguros de lo que dice el mensaje");}
					
					
					
					
					
					
					
							if (vj1[1]==3) {
							printf("Nuestros aliados brasileitos nos han traducido perfectamente el mensaje y nos comunican que nuestros espias estan a salvo");}
					
					
					
					


					
						
				
				
				
				
				}
				
}

