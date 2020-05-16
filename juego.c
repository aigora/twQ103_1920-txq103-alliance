#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TURNOS 3

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
  printf("(%s)\n", juego.turno_de ? juego.jugadores[0].nombre : juego.jugadores[1].nombre);
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

  // int *puntos_por_decision[][TURNOS] = {
  //     {10, 8, 9}, {5, 3, 5}, {10, 9, 9}};

  // for (int i = 0; i < 13; i++)
  // {
  //   puntos += puntos_por_decision[turno_actual - 1][jugador.decisiones[i] - 1];
  // }

  return puntos;
}

int main()
{
  FILE *enunciados;
  char enunciado[300];

  enunciados = fopen("enunciados.txt", "r");

  int input;
  int i = 0;
  
  char cadNombre1[50], cadNombre2[50], cadFinal1[50], cadFinal2[50]; 
  
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

  struct jugador jugador1, jugador2;
  strcpy(jugador1.nombre, cadFinal1);
  strcpy(jugador2.nombre, cadFinal2);

  struct juego juego;
  juego.jugadores[0] = jugador1;
  juego.jugadores[1] = jugador2;
  juego.turno_actual = 1;
  juego.turno_de = 0;

  char *opciones[][TURNOS] = {
      {"EEUU", "Russia", "China"},
      {"Espana", "Brasil", "Francia"},
      {"Regimiento de 300.000 soldados extra", "Flota de barcos (3 submarinos, 2 acorazados y 1 portaaviones)", "Apoyo aereo (15 cazas)"}};

  while (juego.turno_actual <= TURNOS)
  {

    system("cls");


    printf("[Turno %d]\n", juego.turno_actual);

    fgets(enunciado, 300, enunciados);
    printf("%s\n", enunciado);


    printear_jugador(juego);

    printear_opciones(opciones[juego.turno_actual - 1], 0);


    get_input(&input);

   
    juego.jugadores[juego.turno_de].decisiones[juego.turno_actual - 1] = input;

 
    juego.turno_de = !juego.turno_de;


    system("cls");


    printear_jugador(juego);

 
    printear_opciones(opciones[juego.turno_actual - 1], input);


    get_input(&input);

    juego.jugadores[juego.turno_de].decisiones[juego.turno_actual - 1] = input;

    juego.turno_actual++; 
  }

  return 0;
}
