#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <sstream>
//#include <regex>

using namespace std;

void convertirLineaEnRecord(string linea, vector<string> &record, int separador) {
  // Crear una cadena para cada celda
  string celda;
  /* Declarar un string stream para
  extraer texto de éste */
  istringstream copia(linea);

  switch (separador) {
    // Separadores: [1][";"] y [2]["/"]
    case 1:
      while (getline(copia, celda, ';')) {
        record.push_back(celda);
      } // Fin de grabar record en DB
    break;

    case 2:
      while (getline(copia, celda, '/')) {
        record.push_back(celda);
      } // Fin de grabar record en DB
    break;
  } // Fin de elegir separador
} // Fin de separar texto y meterlo a un vector

void funcion() {
  vector<string> persona;
  string line = "Luis Felipe;Lopez Garay;Mexicana;23";

  convertirLineaEnRecord(line, persona, 1);

  cout << "Nombre: " << persona[0] << endl;
  cout << "Apellido: " << persona[1] << endl;
  cout << "Nacionalidad: " << persona[2] << endl;
  cout << "Edad: " << persona[3] << "a" << char(164) << "os" << endl;
} // Fin de función

void modificarRecord(string archivo, string id, int campo, string valorNuevo) {
  fstream tabla, memoria;
  string linea, celda;
  vector<string> record;

  tabla.open(archivo.c_str(), ios::in);
  memoria.open("temporal.txt", ios::out);

  if (tabla.is_open()) {
    while(getline(tabla, linea)) {
      // Grabar celdas en el "record"
      istringstream copia(linea);
      while (getline(copia, celda, ';')) {
        record.push_back(celda);
      } // Fin de grabar record en DB
      /* Meter el nuevo valor al archivo sólo si el valor del campo
      que quieres modificar coincide en la línea leída del archivo. */
      if (record[campo].compare(id) == 0) {
        memoria << valorNuevo << endl;
      } else {
        memoria << linea << endl;
      } // Fin de modificar línea

      // Limpiar el vector para la siguiente iteración
      record.clear();
    } // Fin copiar el record a la cadena "linea"
    memoria.close(); tabla.close();

    // Borrar el original y renombrar el temporal como el original
    remove(archivo.c_str()); rename("temporal.txt", archivo.c_str());
  } else {
    system("cls");
    cout << "Error de base de datos con: " << archivo;
    getch();
  } // Fin de comprobar si el archivo existe
} // Fin de modificar una record en una tabla

int main() {
  funcion();
  string modificado = "002;Straight Outta Compton;2015;Biografia;Estreno;147;240;3;En 1987, cinco jovenes, utilizando rimas brutalmente honestas y bases;musicales pesadas, expresan su frustracion y enojo sobre la vida en el;lugar mas peligroso de Estados Unidos utilizando el arma mas poderosa;que tenian: su musica.";
  modificarRecord("peliculas.txt", "002", 0, modificado);
} // Fin del programa