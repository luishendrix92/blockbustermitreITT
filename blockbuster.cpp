#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <sstream>
//#include <regex>
#include "render.cpp"
#include "database.cpp"

int main() {
  int opcion;

  intro();
  dibujaMenu("clientes");
  cin >> opcion;

  switch(opcion) {
    //
  } // Fin de elegir opciones

  getch();
} // Fin del programa
