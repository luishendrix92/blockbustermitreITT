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

void trazarRectangulo(int x1, int y1, int x2, int y2, string relleno) {
  for (int renglon=y1; renglon <= y2; renglon+=1) {
    for(int x=x1, y=renglon; x <= x2; x+=1) {
      gotoxy(x, y); cout << relleno;
    } // Fin de trazar renglón
  } // Fin de trazar rectángulo
} // Fin de trazar líneas horizontales