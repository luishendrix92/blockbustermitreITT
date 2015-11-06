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

bool encontrarTexto(string buscado, string dondeBuscar) {
  size_t encontrado;

  // Convertir las cadenas a minúsculas para evitar conflictos
  transform(buscado.begin(), buscado.end(), buscado.begin(), ::tolower);
  transform(dondeBuscar.begin(), dondeBuscar.end(), dondeBuscar.begin(), ::tolower);

  // Buscar la cadena "buscado" en "dondeBuscar"
  encontrado = pelis[i].find(criterio);

  return (encontrado!=string::npos) ? true : false;
} // Fin de buscar strings en otras

int main() {
    vector<string> pelis;
    size_t encontrado;
    // Criterio de búsqueda
    string criterio = "";
    // Nuevas películas

    while (true) {
      // Guarda la tecla presionada
      char tecla = getch();
      // Si se presiona backspace, reiniciar el input
      if (tecla == 8) {
        criterio.clear();
        cout << "Backspace" << endl;
      } else {
        criterio += tecla;
      }
      // Buscar las pelìculas y mostrarlas en pantala
      for (int i = 0; i < pelis.size(); i+=1) {
        // Convertir el ltítulo de la película a minúsculas
        transform(pelis[i].begin(), pelis[i].end(), pelis[i].begin(), ::tolower);

        encontrado = pelis[i].find(criterio);
        if (encontrado!=string::npos) {
            cout << pelis[i] << endl;
        }
      } // Fin de búsqueda
      // Delimitador
      cout << "-----------------------------" << endl;
      cout << criterio << endl;
      cout << "-----------------------------" << endl;
    } // Fin de ciclo infinito
}
