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
  // Darle título a la ventana del programa
  SetConsoleTitle("Blockbuster: Rentas y Compras Online");

  int opcion;

  intro();
  dibujarMenu("clientes");
  cin >> opcion;

  switch(opcion) {
    //
  } // Fin de elegir opciones
  modificarRecord("peliculas.txt", "002", 1, "Straight outta compton");
} // Fin del programa
