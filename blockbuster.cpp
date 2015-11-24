#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <sstream>
//#include "color.h"
#include "utilerias.cpp"
#include "render.cpp"
#include "database.cpp"
#include "menus.cpp"

int main() {
  char tecla; int boton = 1;

  system("cls");
  // Darle título a la ventana del programa
  SetConsoleTitle("Blockbuster: Rentas y Compras Online");
  // Renderizar intro y menú principal
  intro(280); dibujarMenu("1_principal");

  while (tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if(tecla == 0) { tecla = getch(); } else {
      switch(tecla) {
        case 77: // Derecha
          if (boton == 1) {
            enfocarElemento("1_principal", 2); boton = 2;
          } else if (boton == 2) {
            enfocarElemento("1_principal", 1); boton = 1;
          } break; // Fin de hacer toggle >
        case 75: // Izquierda
          if (boton == 2) {
            enfocarElemento("1_principal", 1); boton = 1;
          } else if (boton == 1) {
            enfocarElemento("1_principal", 2); boton = 2;
          } break; // Fin de hacer toggle <
        case 13: // 'ENTER'
          switch(boton) {
            case 1: menu::registro(); boton = 1;
              break;
            case 2: menu::login(); boton = 1;
              break;
          } break; // Fin de abrir menús
      } // Fin de detección de tecla
    } // Fin de selección de tecla
  } // Fin de ciclo principal

  despedida();
  system("cls");
} // Fin del programa