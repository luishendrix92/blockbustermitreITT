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

int main() {
  int opcion;

  // Darle título a la ventana del programa
  SetConsoleTitle("Blockbuster: Rentas y Compras Online");

  intro();
  dibujarMenu("1_principal_registro");

  getch();
} // Fin del programa