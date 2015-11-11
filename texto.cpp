#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <sstream>
//#include <regex>

using namespace std;

int main() {
  #define ENTER 13
  #define TAB 9
  #define ARRIBA 72
  #define ABAJO 80
  #define IZQ 75
  #define DER 77
  #define ESC 27

  char tecla;

  cout << "Presiona una tecla: " << endl;

  while(tecla != ESC) {
    tecla = getch();
    if(tecla == 0) {
      tecla = getch();
    } else {
      switch(tecla) {
        case ENTER:
          cout << "Enter" << endl;
        break;
        
        case TAB:
          cout << "Tab" << endl;
        break;
        
        case ARRIBA: // También "H"
          cout << "Arriba" << endl;
        break;
        
        case ABAJO: // También "P"
          cout << "Abajo" << endl;
        break;
        
        case IZQ: // También "K"
          cout << "Izquierda" << endl;
        break;
        
        case DER: // También "M"
          cout << "Derecha" << endl;
        break;
      } // Fin de SWITCH
    } // Fin de IF
  } // Fin de WHILE
}// Fin del programa