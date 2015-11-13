#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <sstream>
//#include <math.h>
#include "color.h"
#include "utilerias.cpp"
#include "render.cpp"
#include "database.cpp"
//#include "secciones.cpp"

int main() {
  int opcion;

  // Darle título a la ventana del programa
  SetConsoleTitle("Blockbuster: Rentas y Compras Online");

  intro(280);
  dibujarMenu("1_principal");
  
  getch();
  system("cls");
} // Fin del programa