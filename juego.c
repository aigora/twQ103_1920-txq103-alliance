#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RONDAS 8

struct jugador //Estructura jugador formada a partir del nombre (cadena]), decisiones (vector de enteros), y puntos (entero).  
{
  char nombre[50];
  int decisiones[RONDAS];
  int puntos;
};

struct juego //Estructura juego (ayudará al flujo del juego). Está formada a partir de ronda_actual (entero) y  turno_de (entero)
{
  struct jugador jugadores[2]; //El juego es para dos jugadores
  int ronda_actual;
  int turno_de;
};

//Funciones 

void get_input(int *input)  //Esta funcion imprime --> para indicar que el sistema esta esperando una decisión de parte del usuario
{
  printf("\n--> ");
  scanf("%d", input); //Escanea el valor (entero aportado por el usuario) 
}

void printear_jugador(struct juego juego) //Funcion con la estructura juego como parametro 
{
  printf("(%s)\n", juego.turno_de ? juego.jugadores[1].nombre : juego.jugadores[0].nombre); //Operador ternario 
}																							//Imprime el nombre del jugador 1 o el jugador 2 dependiendo 
																						    //del valor juego.turno_de

void printear_opciones(char *opciones_texto[], int opcion_elegida) // Funcion con dos parametros: una cadena de caracteres (para el texto), y un entero
{																	// y un entero que representará la opcion elegida (1, 2 o 3) 
  int i;
  for (i = 0; i < 3; i++)
  {
    if (opcion_elegida - 1 != i)
      printf("%d. %s\n", i + 1, opciones_texto[i]); // Este if garantiza que cuando la opcion_elegida sea 1,2 o 3, se elimine esa opcion
  }												 	// e imprime solo las otras dos opciones
}

int calcular_puntos(struct jugador jugador) //Funcion con la estructura jugador como parametro
{
  int puntos = 0;
  int puntos_por_decision[RONDAS * 3] = {2,3,1, //Puntos de las desiciones disponibles en la ronda 1. (decision 1: 2 puntos, decision 2: 3 puntos, decision 3: 1 pto)
  										5,6,3,  //Puntos de las desiciones disponibles en la ronda 2
										2,3,1,  //Puntos de las desiciones disponibles en la ronda 3
										2,3,5, // y asi sucesivamente
										2,3,1, 
										5,6,3,
										2,3,1,
										2,3,5};  //

  /* Para acceder a cada posicion del vector para poder ser luego sumadas y dar una puntuacion final, se sigue el siguiente patron
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
    .... y asi sucesivamente. En nuestro caso, tenemos 8 rondas y, por lo tanto, un vector con 24 elementos
  */
  int j = 0;
  int i; 
  for (i = 0; i < RONDAS; i++) //Bucle para ejecutar el algoritmo que representa el patron explicado anteriormente
  {
    switch (jugador.decisiones[i])
    {
    case 1: //Cuando la opcion del jugador es 1
      puntos += puntos_por_decision[((i + 1) * 1 + j) - 1]; // Suma
      break;
    case 2: // Cuando la opcion del jugador es 2
      puntos += puntos_por_decision[((i + 1) * 2 + j / 2) - 1];
      break;
    case 3: // Cuando la opciond del jugador es 3
      puntos += puntos_por_decision[((i + 1) * 3) - 1]; 
      break;

    default:
      break;
    }
    j += 2; // Suma 2 al valor j. 
  }

  return puntos;
}

void printear_bienvenida() //Funcion que no devuelve resultado que imprime la pantalla de presentacion y el menu inicial
{
  printf("-------------------------------------"
         "\n\tBienvenido a Alliance\n");
printf("-------------------------------------\n\n");
        printf("	  ..../--------|======[]    \n");
    	printf("	 ..../------------|        \n");
    	printf("	 /----------------------| \n");
   		 printf("	 (@) (@) (@) (@) (@) (@)/\n\n");
   		 
printf("Una simulacion de guerra para dos jugadores basada en la toma de decisiones\n\n");
   		 
  printf("Presione '1' para empezar partida.\n");
  printf("Presione cualquier otro caracter para salir  del programa.\n");
  
  
  
}

int main()
{

   FILE *enunciados;
  char enunciado[300];

  enunciados = fopen("Enunciados.txt", "r"); //apertura fichero y guardado en una variable enunciados


  int input;
  int i = 0;
  char cadNombre1[50], cadNombre2[50]; 
  
  int eleccion;
  printear_bienvenida();
  scanf("%d", &eleccion);
  
    
  if (eleccion != 1)
    return 0;	
  
  printf("Nombre del jugador 1: \n");
    scanf("%s", cadNombre1);
    
    printf("Nombre del jugador 2:\n");
    scanf("%s", cadNombre2);
    
  struct jugador jugador1, jugador2;
  strcpy(jugador1.nombre, cadNombre1);
  strcpy(jugador2.nombre, cadNombre2);
  
  struct juego juego;
  juego.jugadores[0] = jugador1; 
  juego.jugadores[1] = jugador2;
  juego.ronda_actual = 1;
  juego.turno_de = 0; 
	
  char *opciones[][RONDAS] = { //Matriz de 8x3 con los textos correspondientes a las opciones de cada ronda. 
      {"EEUU", "Russia", "China"},
      {"Espana", "Brasil", "Francia"},
      {"Regimiento de 300.000 soldados extra", "Flota de barcos (3 submarinos, 2 acorazados y 1 portaaviones)", "Apoyo aereo (15 cazas)"},
	  {"Ninos y mujeres", "Espias", "Personal sanitario"},
	  {"Retrasas a tus tropas y cedes terreno al enemigo", "Ofreces tu rendicion inmediata", "Te arriesgas y atacas con todas las fuerzas a tu disposicion"},
	  {"Inviertes en equipamiento especializado para el frio para tu personal de guerra", "Aprovechas las condiciones climaticas y atacas", "Inviertes en infraestructura y mantienes a tu pueblo y recursos en buenas condiciones"},
	  {"Reforzar el adoctrinamiento de tus tropas", "Tratar de acabar con su vida para evitar en lo posible traspaso de informacion", "Decides no hacer nada. Tampoco era tan importante"},
	  {"Ofrecer descanso a los veteranos", "Organizas un nuevo reclutamiento", "No es momento para sentirse debil. Estan sirviendo a la patria"}};

  
  while (juego.ronda_actual <= RONDAS) // Bucle que mantiene el flujo del juego
  {
  
    system("cls"); //Limpia la consola

    
    printf("[Ronda %d]\n", juego.ronda_actual); //Imprime la ronda actual

    
    fgets(enunciado, 300, enunciados); // Guarda en la variable enunciado (Cadena de carácteres) los enunciados del fichero en orden secuencial
    printf("%s\n", enunciado); // Imprime el enunciado corrrespondiente a la ronda actual. 

   
    printear_jugador(juego); //Imprime el nombre o apodo del jugador al que le toca jugar 
    						// juego.turno_de = 0 --> imprime jugador 1; juego.turno_de = 1 --> imprime jugador 2
    
    printear_opciones(opciones[juego.ronda_actual - 1], 0); // opciones[juego.ronda_actual - 1] ya que ronda_actual comienza en 1 y no en 0
    													  	//int 0 --> para que se impriman las 3 opciones (ya que es la primera eleccion de la ronda). 
															//Puede ponerse de entero cualquier numero distinto de 1, 2 o 3 para que se impriman las 3 opciones
	get_input(&input);  // Se ejecuta la funcion get_input para obtener una decision del jugador y guardarla en la variable input                               
    
    if ((input!=1) && (input!=2) && (input!=3)) { // Si la desicion dada por el jugador es diferente de 1,2 o 3, el juego debe repetir la solicitud
    	 do {
    	 	char c;         
			while ((c = getchar()) != '\n' && c != EOF) {        
			};  //Se garantiza que el juego no se trabe en caso de que el jugador introduzca un char en lugar de un int
    	printf("Opcion no valida\n"); 
		printear_opciones(opciones[juego.ronda_actual - 1], 0); //printea nuevamente las opciones disponibles
		get_input(&input); 
    	
	} while ((input != 1) && (input != 2) && (input != 3)); 
	
	}
   
    juego.jugadores[juego.turno_de].decisiones[juego.ronda_actual - 1] = input; // Guarda la desicion dada por el jugador (input) en el vector de decisiones

    juego.turno_de = !juego.turno_de; // Cambia juego.turno_de = 0 por juego.turno_de = 1; y viceversa
    								  // De esta forma procede a jugar el otro jugador
    
    system("cls"); //Limpia la consola

    printear_jugador(juego); // Imprime el jugador a quien le toca dependiendo del valor de juego.turno_de
    
    int input2=input;
    
    printear_opciones(opciones[juego.ronda_actual - 1], input2); //input2 = decision tomada por el jugador que jugo primero en la ronda actual
    															 //De esta forma se elimina la opcion correspondiente y se imprimen las dos restantes
	get_input(&input); //Se solicita decision del jugador y se guarda nuevamente en la variable input
	
	if((input2==input) || ((input != 1) && (input != 2) && (input != 3))) { // Se debe repetir la solicitud al jugador en caso de:
		do { 																//su eleccion sea igual a la del jugador que jugo primero en la ronda o distinta de 1, 2, 3
			char c;         
			while ((c = getchar()) != '\n' && c != EOF) {        
			}; //Se garantiza que el juego no se trabe en caso de que el jugador introduzca un char en lugar de un int
    	printf("Opcion no valida\n");
		printear_opciones(opciones[juego.ronda_actual - 1], input2); //Se imprimen nuevamente las opciones disponibles
		get_input(&input); //Se guarda el valor dado en la variable input
    	
		} while ((input2==input) || ((input != 1) && (input != 2) && (input != 3))); 
	
		
	}
    
    juego.jugadores[juego.turno_de].decisiones[juego.ronda_actual - 1] = input; //Se guarda la desicion tomada (input) en el vector de decisiones del jugador que acaba de jugar

    
    juego.ronda_actual++; //Suma uno a la ronda_actual, lo cual mantiene al bucle en marcha. 
    					  //juego_turno de se mantiene con el valor actual
    					  //De esta forma el jugador1 comienza en la ronda 1, pero luego el jugador 2 comienza en la ronda 2. Y asi sucesivamente.
  }
  
   printf("%s: [ ", juego.jugadores[0].nombre); 
  int j; 
  for (j = 0; j < RONDAS; j++)
    printf("%d ", juego.jugadores[0].decisiones[j]);
  printf("] pts: %d\n", calcular_puntos(juego.jugadores[0])); //Este bucle permite obtener la puntuacion final del jugador1 utilizando
  															  //la funcion calcular puntos explicada arriba (se toma en cuenta los valores del vector decisiones) 
 
  int k; 
  printf("%s: [ ", juego.jugadores[1].nombre); 
  for (k = 0; k < RONDAS; k++)
    printf("%d ", juego.jugadores[1].decisiones[k]);
  printf("] pts: %d\n", calcular_puntos(juego.jugadores[1])); //Este bucle permite obtener la puntuacion final del jugador1 utilizando
  															  //la funcion calcular puntos explicada arriba (se toma en cuenta los valores del vector decisiones)
  
  juego.jugadores[0].puntos = calcular_puntos(juego.jugadores[0]);
  juego.jugadores[1].puntos = calcular_puntos(juego.jugadores[1]);
  
  if (juego.jugadores[0].puntos>juego.jugadores[1].puntos) { //Este bucle imprime un mensaje final dependiendo de si gano el jugador 1, el jugador 2 o si la partida ha quedado en empate
  	printf("\n %s ha ganado", juego.jugadores[0].nombre);
  } else if(juego.jugadores[1].puntos>juego.jugadores[0].puntos) {
  	printf("\n %s ha ganado", juego.jugadores[1].nombre);
  } else {
  	printf("\n La guerra ha quedado en empate.");
  }
  
  return 0;
}
