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

void trazarLinea(int inicio[2], int fin[2], string relleno) {
  int direccion;

  // Determinar dirección: [0] -> X | [1] -> Y.
  if (fin[0] - inicio[0] > 0) {
    direccion = 2; // Derecha
  } else if (fin[0] - inicio[0] < 0) {
    direccion = 4; // Izquierda
  } else if (fin[1] - inicio[1] > 0) {
    direccion = 3; // Abajo
  } else if (fin[1] - inicio[1] < 0) {
    direccion = 1; // Arriba
  } // Fin de dar dirección

  // Comenzar con los ciclos for de trazado
  switch (direccion) {
    case 1: // Arriba
      for(int x=inicio[0], y=inicio[1]; y >= fin[1]; y-=1) {
        gotoxy(x, y); cout << relleno;
      } // Fin de línea horizontal hacia arriba
    break;

    case 2: // Derecha
      for(int x=inicio[0], y=inicio[1]; x <= fin[0]; x+=1) {
        gotoxy(x, y); cout << relleno;
      } // Fin de línea horizontal hacia la derecha
    break;

    case 3: // Abajo
      for(int x=inicio[0], y=inicio[1]; y <= fin[1]; y+=1) {
        gotoxy(x, y); cout << relleno;
      } // Fin de línea horizontal hacia abajo
    break;

    case 4: // Izquierda
      for(int x=inicio[0], y=inicio[1]; x >= fin[0]; x-=1) {
        gotoxy(x, y); cout << relleno;
      } // Fin de línea horizontal hacia la izquierda
    break;

    default:
      system("cls"); cout << "Error con funcion trazarLinea.";
  } // Fin de dibujar la línea
} // Fin de trazar líneas horizontales