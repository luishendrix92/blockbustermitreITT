#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include "ayudas.h"
#include "render.h"
//#include "database.h"

using namespace std;

int main() {
  int opcion;

  intro();
  dibujarMenu("clientes");
  cin >> opcion;

  switch(opcion) {
    //
  } // Fin de elegir opciones

  getch();
} // Fin del programa
