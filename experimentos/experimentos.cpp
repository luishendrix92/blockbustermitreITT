#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

int main() {
    vector<string> pelis;
    size_t encontrado;
    // Criterio de búsqueda
    string criterio = "";
    // Nuevas películas
    pelis.push_back("Los simpson");
    pelis.push_back("Los hermanos");
    pelis.push_back("Con amor en el tren");
    pelis.push_back("El amor es bello");

    while (true) {
      char tecla = getch();
      if (tecla == 8) {
        criterio.clear();
        cout << "Backspace" << endl;
      }
      if (tecla != 8) criterio += tecla;
      for (int i = 0; i < pelis.size(); i+=1) {
        encontrado = pelis[i].find(criterio);
        if (encontrado!=string::npos) {
            cout << pelis[i] << endl;
        }
      }
      cout << "-----------------------------" << endl;
      cout << criterio << endl;
      cout << "-----------------------------" << endl;
    }
    
    /*cout << "Resultados de busqueda:" << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < pelis.size(); i+=1) {
        encontrado = pelis[i].find(criterio);
        if (encontrado!=string::npos) {
            cout << pelis[i] << endl;
        }
    }*/
}