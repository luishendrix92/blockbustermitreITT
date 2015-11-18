#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <sstream>
#include "color.h"
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
            seleccionarBoton(2);
          } else if (boton == 2) {
            seleccionarBoton(1);
          } // Fin de hacer toggle >
        break;

        case 75: // Izquierda
          if (boton == 2) {
            seleccionarBoton(1); boton = 1;
          } else if (boton == 1) {
            seleccionarBoton(2); boton = 2;
          } // Fin de hacer toggle <
        break;

        case 13: // 'ENTER'
          switch(boton) {
            case 1: menu::login();
            break;
            case 2: menu::registro();
            break;
          } // Fin de abrir menús
        break;
      } // Fin de detección de tecla
    } // Fin de selección de tecla
  } // Fin de ciclo principal
  
  system("cls");
} // Fin del programa