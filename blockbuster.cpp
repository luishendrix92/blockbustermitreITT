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
  intro(280);
  dibujarMenu("1_principal");

  while (tecla != 27) {
    tecla = getch();
    if(tecla == 0) {
      tecla = getch();
    } else {
      switch(tecla) {
        case 77: // Derecha
          seleccionarBoton(2);
        break;

        case 75: // Izquierda
          seleccionarBoton(1);
        break;

        case 13: // ENTER
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