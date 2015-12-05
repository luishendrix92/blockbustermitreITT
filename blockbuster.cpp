#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <ctime>
//#include "color.h"
#include "utilerias.cpp"
#include "database.cpp"
#include "render.cpp"
#include "menus.cpp"

int main() {
  char tecla; int boton = 0, dir;
  int orden[4][2] = {{1,0},{1,0},{1,0},{1,0}};

  // Darle título a la ventana del programa
  SetConsoleTitle("Blockbuster: Rentas y Compras Online");
  // Renderizar intro y menú principal
  /*intro(280);*/ dibujarMenu("1_principal");

  // Manejo de teclas direccionales y 'ENTER'
  while (tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if(tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) { // Der-Izq-Tab
        // Desplazarse entre botones
        dir = obtenerDireccion(tecla);
        enfocarElemento("1_principal", orden[dir][boton]);
        boton = orden[dir][boton];
      } else if (tecla == 13) { // 'ENTER'
        switch(boton) {
          case 0: menu::registro(); boton=0; break;
          case 1: menu::login();    boton=0; break;
        } // Fin de lanzar menú adecuado
      } // Fin de reaccionar a teclas
    } // Fin de selección de tecla
  } // Fin de pedir tecla y terminar al presionar 'ESC'
  /*despedida();*/ system("cls"); return 0;
} // Fin del programa
