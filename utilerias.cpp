/*  Pequeñas funciones que permiten
    realizar tareas útiles y repetitivas
================================================= */
using namespace std;

void gotoxy(int x, int y) {
  HANDLE hcon;  
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
  COORD dwPos;  
  dwPos.X = x;  
  dwPos.Y= y;  
  SetConsoleCursorPosition(hcon,dwPos);  
} // Fin de añadir GoToXY

bool encontrarTexto(string buscado, string dondeBuscar) {
  size_t encontrado;

  // Convertir las cadenas a minúsculas para evitar conflictos
  transform(buscado.begin(), buscado.end(), buscado.begin(), ::tolower);
  transform(dondeBuscar.begin(), dondeBuscar.end(), dondeBuscar.begin(), ::tolower);

  // Buscar la cadena "buscado" en "dondeBuscar"
  encontrado = dondeBuscar.find(buscado);

  return (encontrado!=string::npos) ? true : false;
} // Fin de buscar strings en otras