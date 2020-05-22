#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TURNOS 8

struct jugador
{
  char nombre[50];
  int decisiones[TURNOS];
  int puntos;
};

struct juego
{
  struct jugador jugadores[2];
  int turno_actual;
  int turno_de;
};

void get_input(int *input)
{
  printf("\n--> ");
  scanf("%d", input);
}

void printear_jugador(struct juego juego)
{
  printf("(%s)\n", juego.turno_de ? juego.jugadores[1].nombre : juego.jugadores[0].nombre);
}

void printear_opciones(char *opciones_texto[], int opcion_elegida)
{
  int i;
  for (i = 0; i < 3; i++)
  {
    if (opcion_elegida - 1 != i)
      printf("%d. %s\n", i + 1, opciones_texto[i]);
  }
}

int calcular_puntos(struct jugador jugador)
{
  int puntos = 0;
  int puntos_por_decision[TURNOS * 3] = {2,3,1,
  										5,6,3,
										2,3,1,
										2,3,5,
										2,3,1,
										5,6,3,
										2,3,1,
										2,3,5};

  /*
    1.  1 * 1     = 1
    2.  1 * 2     = 2
    3.  1 * 3     = 3
    4.  2 * 1 + 2 = 4
    5.  2 * 2 + 1 = 5
    6.  2 * 3     = 6
    7.  3 * 1 + 4 = 7 
    8.  3 * 2 + 2 = 8
    9.  3 * 3     = 9
    10. 4 * 1 + 6 = 10
    11. 4 * 2 + 3 = 11
    12. 4 * 3     = 12
    13. 5 * 1 + 8 = 13
    14. 5 * 2 + 4 = 14
    15. 5 * 3     = 15
  */
  int j = 0;
  int i; 
  for (i = 0; i < TURNOS; i++)
  {
    switch (jugador.decisiones[i])
    {
    case 1:
      puntos += puntos_por_decision[((i + 1) * 1 + j) - 1];
      break;
    case 2:
      puntos += puntos_por_decision[((i + 1) * 2 + j / 2) - 1];
      break;
    case 3:
      puntos += puntos_por_decision[((i + 1) * 3) - 1];
      break;

    default:
      break;
    }
    j += 2;
  }

  return puntos;
}

void printear_bienvenida()
{
  printf("-------------------------------------"
         "\n\tBienvenido a Alliance\n"
         "-------------------------------------\n"
		 "Insertar descripcion juego\n\n");
  printf("Presione '1' para empezar partida.\n");
  printf("Presione cualquier otro caracter para salir  del programa.\n");
}


int main()
{

  FILE *prompts;
  char prompt[300];

  prompts = fopen("Enunciados.txt", "r");


  int input;
  int i = 0;
  char cadNombre1[50], cadNombre2[50]; 
  
  int eleccion;
  printear_bienvenida();
  scanf("%d", &eleccion);
  
    
  if (eleccion != 1)
    return 0;	
  
  printf("Introduce tu nombre 1:\n");
    scanf("%s", cadNombre1);
    
    printf("Introduce tu nombre 2:\n");
    scanf("%s", cadNombre2);
    
  struct jugador jugador1, jugador2;
  strcpy(jugador1.nombre, cadNombre1);
  strcpy(jugador2.nombre, cadNombre2);
  
  struct juego juego;
  juego.jugadores[0] = jugador1;
  juego.jugadores[1] = jugador2;
  juego.turno_actual = 1;
  juego.turno_de = 0;
	
  char *opciones[][TURNOS] = {
      {"EEUU", "Russia", "China"},
      {"Espana", "Brasil", "Francia"},
      {"Regimiento de 300.000 soldados extra", "Flota de barcos (3 submarinos, 2 acorazados y 1 portaaviones)", "Apoyo aereo (15 cazas)"},
	  {"Ninos y mujeres", "Espias", "Personal sanitario"},
	  {"Retrasas a tus tropas y cedes terreno al enemigo", "Ofreces tu rendicion inmediata", "Te arriesgas y atacas con todas las fuerzas a tu disposicion"},
	  {"Inviertes en equipamiento especializado para el frio para tu personal de guerra", "Aprovechas las condiciones climaticas y atacas", "Inviertes en infraestructura y mantienes a tu pueblo y recursos en buenas condiciones"},
	  {"Reforzar el adoctrinamiento de tus tropas", "Tratar de acabar con su vida para evitar en lo posible traspaso de informacion", "Decides no hacer nada. Tampoco era tan importante"},
	  {"Ofrecer descanso a los veteranos", "Organizas un nuevo reclutamiento", "No es momento para sentirse debil. Estan sirviendo a la patria"}};

  
  while (juego.turno_actual <= TURNOS)
  {
  
    system("cls");

    
    printf("[Turno %d]\n", juego.turno_actual);

    
    fgets(prompt, 300, prompts);
    printf("%s\n", prompt);

   
    printear_jugador(juego);
    
    printear_opciones(opciones[juego.turno_actual - 1], 0);
	get_input(&input);
    
    if ((input!=1) && (input!=2) && (input!=3)) {
    	 do {
    	 	char c;         
			while ((c = getchar()) != '\n' && c != EOF) {        
			};
    	printf("Opcion no valida\n");
		printear_opciones(opciones[juego.turno_actual - 1], 0);
		get_input(&input);
    	
	} while ((input != 1) && (input != 2) && (input != 3)); 
	
	}
   
    
    juego.jugadores[juego.turno_de].decisiones[juego.turno_actual - 1] = input;

    
    juego.turno_de = !juego.turno_de;

    
    system("cls");

    
    printear_jugador(juego);
    
    int input2=input;
    
    printear_opciones(opciones[juego.turno_actual - 1], input2);
	get_input(&input);
	
	if((input2==input) || ((input != 1) && (input != 2) && (input != 3))) {
		
		do {
			char c;         
			while ((c = getchar()) != '\n' && c != EOF) {        
			};
    	printf("Opcion no valida\n");
		printear_opciones(opciones[juego.turno_actual - 1], input2);
		get_input(&input);
    	
		} while ((input2==input) || ((input != 1) && (input != 2) && (input != 3)));
	
		
	}
    
    juego.jugadores[juego.turno_de].decisiones[juego.turno_actual - 1] = input;

    
    juego.turno_actual++;
  }
  
   printf("%s: [ ", juego.jugadores[0].nombre);
  int j; 
  for (j = 0; j < TURNOS; j++)
    printf("%d ", juego.jugadores[0].decisiones[j]);
  printf("] pts: %d\n", calcular_puntos(juego.jugadores[0]));
  printf("%s: [ ", juego.jugadores[1].nombre);
  
  int k; 
  for (k = 0; k < TURNOS; k++)
    printf("%d ", juego.jugadores[1].decisiones[k]);
  printf("] pts: %d\n", calcular_puntos(juego.jugadores[1]));
  
  juego.jugadores[0].puntos = calcular_puntos(juego.jugadores[0]);
  juego.jugadores[1].puntos = calcular_puntos(juego.jugadores[1]);
  
  if (juego.jugadores[0].puntos>juego.jugadores[1].puntos) {
  	printf("\n %s ha ganado", juego.jugadores[0].nombre);
  } else if(juego.jugadores[1].puntos>juego.jugadores[0].puntos) {
  	printf("\n %s ha ganado", juego.jugadores[1].nombre);
  } else {
  	printf("\n La guerra ha quedado en empate.");
  }
  
  return 0;
}
