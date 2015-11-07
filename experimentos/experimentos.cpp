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
  encontrado = dondeBuscar.find(buscado);

  return (encontrado!=string::npos);
} // Fin de buscar strings en otras

void gotoxy(int x, int y) {
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
} // Fin de añadir GoToXY

void reset(string seccion) {
  if (seccion.compare("resultados") == 0) {
    for (int i=1; i < 23; i+=1) {
      gotoxy(30, i);
      cout << "                                                ";
    } // Fin de llearlo de espacios blancos
  } else if (seccion.compare("input") == 0) {
    gotoxy(1, 1);
    cout << "                              ";
  } // Fin de selector múltiple
} // Fin de limpiar la parte de los resultados

int main() {
    system("cls");
    gotoxy(1,1);
    vector<string> pelis;
    string criterio = "";

    // Nuevas películas
    pelis.push_back("Los simpson");
    pelis.push_back("Los hermanos");
    pelis.push_back("Con amor en el tren");
    pelis.push_back("El amor es bello");
    pelis.push_back("La vida es bella");
    pelis.push_back("10 cosas que odio de ti");
    pelis.push_back("Viernes 13");
    pelis.push_back("V de Vendetta");
    pelis.push_back("El metodo");
    pelis.push_back("Caballero de la noche");
    pelis.push_back("Orient Express");
    pelis.push_back("Caballeros de la mesa redonda");

    while (true) {
      // Guarda la tecla presionada
      char tecla = getch();
      // Si se presiona backspace o delete, reiniciar el input
      if (tecla == 8 || tecla == 224) {
        criterio.clear();
        reset("input");
      } else {
        criterio += tecla;
      } // Fin de revisar teclas

      reset("resultados");

      // Buscar las pelìculas y mostrarlas en pantala
      for (int i=0, j=1; i < pelis.size(); i+=1) {
        if (encontrarTexto(criterio, pelis[i])) {
            gotoxy(30, j);
            cout << pelis[i] << endl;
            j += 1;
        } // Fin de mostrar peli si contiene el criterio
      } // Fin de búsqueda de películas

      gotoxy(1,1); cout << criterio;
      gotoxy(criterio.length()+1, 1);
    } // Fin de ciclo infinito
} // Fin de programa