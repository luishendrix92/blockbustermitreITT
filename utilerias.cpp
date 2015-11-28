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

vector<string> separarLinea(string linea, int separador) {
  // Declarar un string stream para extraer texto de éste 
  istringstream copia(linea);
  vector<string> record;
  string celda;

  switch (separador) {
    // Separadores: [1][";"] y [2][","]
    case 1:
      while (getline(copia, celda, ';')) {
        record.push_back(celda);
      } // Fin de grabar record en DB
    break;

    case 2:
      while (getline(copia, celda, ',')) {
        record.push_back(celda);
      } // Fin de grabar record en DB
    break;
  } // Fin de elegir separador
  
  return record;
} // Fin de separar texto y meterlo a un vector

string unirRegistro(vector<string> registro, string separador) {
  string linea = "";

  for(int i=0; i<registro.size(); i+=1) {
    linea += registro[i];
    if ((i+1)<registro.size()) {
        linea += separador;
    } // Fin de agregar separador excepto al último item del vector
  } // Fin de iterar el vector

  return linea;
} // Fin de unir un vector en una cadena

void trazarRectangulo(int x1, int y1, int x2, int y2, string relleno) {
  for (int renglon=y1; renglon <= y2; renglon+=1) {
    for(int x=x1, y=renglon; x <= x2; x+=1) {
      gotoxy(x, y); cout << relleno;
    } // Fin de trazar renglón
  } // Fin de trazar rectángulo
} // Fin de trazar líneas horizontales

string enteroATexto(int numero) {
  string numTexto = "";
  stringstream entero;
  
  entero << numero;
  numTexto += entero.str();
  
  return numTexto;
} // Convertir tipo "int" a "string"

string floatATexto(float numero) {
  string numTexto = "";
  stringstream flotante;
  
  flotante << numero;
  numTexto += flotante.str();
  
  return numTexto;
} // Convertir tipo "int" a "string"

bool esAlfaNum(char tecla) {
  return  ( // [A-Z] y [a-z] y [0-9] y [.-_]
    (tecla >= 65 && tecla <= 90) ||
    (tecla >= 48 && tecla <= 57) ||
    (tecla >= 97 && tecla <= 122) ||
    (tecla == 45 || tecla == 46 || tecla == 95)
  ); // Revisa rangos de caracteres ASCII
} // Fin de ver si una tecla es alfanumérica

bool esDireccional(char tecla) {
  return  ( // Tab, Izq, Der, Arr, Abj
    tecla == 77 || tecla == 75 ||
    tecla == 72 || tecla == 80 ||
    tecla == 9 /* Tab */
  ); // Fin de comprobar tecla
} // Fin de ver si una tecla es TAB o flecha

int obtenerDireccion(char tecla) {
  /* ROL DE DIRECCIONES
  =========================
  0: Derecha - 1: Izquierda
  2: Arriba - 3: Abajo   */
  int direccion;
  switch(tecla) {
    case 77: direccion = 0; break;
    case 9:  direccion = 0; break;
    case 75: direccion = 1; break;
    case 72: direccion = 2; break;
    case 80: direccion = 3; break;
    default: // No se dio tecla correcta
      system("cls"); cout << "Error de utileria";
  } // Fin de establecer dirección
  return direccion;
} // Fin de obtener una dirección