#include <stdio.h>

int main (){
	int vj1[13],vj2[13];



	//PRESENTACION DEL JUEGO
	printf("Bienvenido a nuestro juego. En los proximos minutos te enfrentaras a tu amigo en el escenario de una guerra mundial en la que seras responsable de llevar a tu coalicion al exito.\n");

	char cadNombre1[50],cadNombre2[50],cadFinal1[50],cadFinal2[50];
	int i;
	
	printf("Introduce tu nombre 1:\n");
	gets(cadNombre1);
	
	printf("Introduce tu nombre 2:\n");
	gets(cadNombre2);
	
	i=0;
    while (cadNombre1[i]!='\0'){
        cadFinal1[i]=cadNombre1[i];
        i++;
    }
    cadFinal1[i]='\0';
	i=0;
    while (cadNombre2[i]!='\0'){
        cadFinal2[i]=cadNombre2[i];
        i++;
    }
    cadFinal2[i]='\0';

	printf("%s y %s han de elegir un pais aliado del siguiente listado",cadFinal1,cadFinal2);
	printf("\n 1. EEUU \n 2. China \n 3. Rusia \n \n");
	printf("\n Comienza eligiendo %s... \n Introduzca 1 si quiere aliarse con EEUU, 2 con China o 3 con Rusia.\n",cadFinal1);
	
			
			//PRIMERA ELECCION J1
			
			
				scanf("%i", &vj1[0]);
			if (vj1[0]==1)
			printf("%s: Acabas de elegir a EEUU\n",cadFinal1);
			
			else if (vj1[0]==2)
			printf("%s: Acabas de elegir a China\n",cadFinal1);
			else printf("%s: Acabas de elegir a Rusia\n",cadFinal1);


			//PRIMERA ELECCION J2
			
		
				printf("\n \n Turno del segundo jugador  %s....\n Elige uno de los siguientes paises: \n",cadFinal2);
				if (vj1[0]==1)
			printf("2. China\n3. Rusia\n");
			else if (vj1[0]==2)
			printf("1. EEUU\n3. Rusia\n");
			else printf("1. EEUU\n2. China\n");
			
			scanf("%i", &vj2[0]);	
			if (vj2[0]==1)
			printf("%s: Acabas de elegir a EEUU\n",cadFinal2);
			
			else if (vj2[0]==2)
			printf("%s: Acabas de elegir a China\n",cadFinal2);
			else printf("%s: Acabas de elegir a Rusia\n",cadFinal2);	
			
			
			//SEGUNDA ELECCION J2
			
			printf("\n Muy bien...pero si queremos llevar la batalla a un nivel global necesitaremos mas aliados.\n Seguimos con el mecanismo de antes. Ahora elige primero el J2 %s.",cadFinal2);
			printf(" \n 1. Espana \n 2. Francia \n 3. Brasil \n");
			scanf("%i", &vj2[1]);
			if (vj2[1]==1)
			printf("J2: Acabas de elegir a Espana\n");
			else if (vj2[1]==2)
			printf(" %s: Acabas de elegir a Francia\n",cadFinal2);
			else printf("%s: Acabas de elegir a Brasil\n",cadFinal2);
			
		
			//Segunda eleccion J1
			
			printf("\n Le toca elegir de nuevo al jugador 1\n");
				if (vj2[1]==1)
			printf("2. Francia\n3. Brasil\n");
			else if (vj2[1]==2)
			printf("1. Espana\n3. Brasil\n");
			else printf("1. Espana\n2. Francia\n");
			scanf("%i", &vj1[1]);	
			if (vj1[1]==1)
			printf("%s: Acabas de elegir a Espana\n",cadFinal1);
			else if (vj1[1]==2)
			printf("%s: Acabas de elegir a Francia\n",cadFinal1);
			else printf("%s: Acabas de elegir a Brasil\n",cadFinal1);

			//RESUMEN EQUIPOS
			
			printf("\n Los equipos definitivos son:\n");
			if (vj1[0]==1)
			printf("%s: Juega con EEUU",cadFinal1);
			else if (vj1[0]==2)
			printf("%s: Juega con China",cadFinal1);
			else printf("%s: Juega con Rusia",cadFinal1);
			
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
				printf("\n Elige primero el jugador %s:\n",cadFinal1);
				scanf ("%i",&vj1[2]);
				switch (vj1[2])
				{
				case 1:printf ("%s:Has elegido añadir 300000 soldados a tu ejercito",cadFinal1);
				break;
				case 2:printf ("%s:Has añadido refuerzo maritimo a tu ejercito",cadFinal1);
				break;
				case 3:printf ("%s:Has elegido añadir apoyo aereo",cadFinal1);
				break;
				default:
				 printf ("Opcion incorrecta\n");}
				 
				 printf("\n Le toca elegir al segundo jugador %s",cadFinal2);

				scanf ("%d",&vj2[2]);
				switch (vj2[2])
				{
				case 1:printf ("%s:Has elegido añadir 300000 soldados a tu ejercito",cadFinal2);
				break;
				case 2:printf ("%s:Has añadido refuerzo maritimo a tu ejercito",cadFinal2);
				break;
				case 3:printf ("%s:Has elegido añadir apoyo aereo",cadFinal2);
				break;
				default:
				 printf ("Opcion incorrecta\n");
				}
				
				//3 MONEDAS

				printf("\n \n Por tres monedas puedes comprar: \n 1. Drones de defensa.\n 2. Satélite de apoyo gps\n 3. Bunqueres");
				printf("\n Elige el segundo jugador : %s\n",cadFinal2);
				scanf ("%i",&vj2[3]);
				
				switch (vj2[3])
				{
				case 1:printf ("%s:Has elegido comprar drones defensivos",cadFinal2);
				break;
				case 2:printf ("%s:Has comprado un satelite de apoyo gps",cadFinal2);
				break;
				case 3:printf ("%s:Has Distribuido bunqueres para proteccion entre tus aliados",cadFinal2);
				break;
				default:
				 printf ("Opcion incorrecta\n");
				}
				
				printf("\nElige primer jugador %s ",cadFinal1);
				scanf ("%i",&vj1[3]);
				switch (vj1[3])
				{
				case 1:printf ("%s:Has elegido comprar drones defensivos",cadFinal1);
				break;
				case 2:printf ("%s:Has comprado un satelite de apoyo gps",cadFinal1);
				break;
				case 3:printf ("%s:Has Distribuido bunqueres para proteccion entre tus aliados",cadFinal1);
				break;
				default:
				 printf ("Opcion incorrecta\n");
				}
				
				//1 MONEDA
				printf("\n Por dos monedas puedes comprar: \n 1. Enviar a niños y mujeres a la guerra.\n 2. Enviar espias a territorio enemigo\n 3. Personal sanitario en territorio enemigo ");
				printf("Elige primer el jugador :\n",cadFinal1);
				scanf ("%i",&vj1[4]);
				switch (vj1[4])
				{
				case 1:printf ("%s:Has elegido enviar a niños y mujeres a la guerra.",cadFinal1);
				break;
				case 2:printf ("%s:Has elegido enviar espias a territorio enemigo",cadFinal1);
				break;
				case 3:printf ("%s:Has distribuido personal sanitario en territorio enemigo",cadFinal1);
				break;
				default:
				 printf ("Opcion incorrecta\n");
				}
				printf("Turno del segundo jugador: %s\n",cadFinal2);
				scanf ("%i",&vj2[4]);
				switch (vj2[4])
				{
				case 1:printf ("%s:Has elegido enviar a niños y mujeres a la guerra.",cadFinal2);
				break;
				case 2:printf ("%s:Has elegido enviar espias a territorio enemigo",cadFinal2);
				break;
				case 3:printf ("%s:Has distribuido personal sanitario en territorio enemigo",cadFinal2);
				break;
				default:
			 printf ("Opcion incorrecta\n");}
				
					//PRIMERA RONDA DEL JUEGO
					
					printf ("Comienza el juego.....\n\n Buenas tardes %s, nuestro comandante nos ha avisado esta mañana de que se ha visionado un mensaje en el cielo que dos avionetas han dejado tras su paso. El mensaje dice asi'Nossos espioes estao seguros'. No estamos muy seguros de lo que dice asi que hemos decidido pedir ayuda a nuestros aliados",cadFinal1);
						if (vj1[1]==1){
						printf("\nNuestros aliados españoles no estan muy seguros de lo que pone, pero creen que pone que nuestros espias no esan a salvo");
							if (vj1[2]==1){
							printf ("\nEn consecuencia de esto mandaremos el regimiento de soldados del que disponemos");}
								if (vj2[3]==1){
								printf("\nLos drones de defensa del segundo jugador %s no han sido capaces de frenar la ofensiiva del %s",cadFinal2,cadFinal1);}
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

