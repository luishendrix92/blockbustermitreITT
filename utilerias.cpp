/*=================================================
    Pequeñas funciones que permiten
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
    case 13:  direccion = 0; break;
    case 9:  direccion = 0; break;
    case 75: direccion = 1; break;
    case 72: direccion = 2; break;
    case 80: direccion = 3; break;
    default: // No se dio tecla correcta
      system("cls"); cout << "Error de utileria";
  } // Fin de establecer dirección
  return direccion;
} // Fin de obtener una dirección

int elementoFecha(string elemento) {
  time_t ahora  = time(0);
  tm    *fecha  = localtime(&ahora);
  int    year   = 1900 + fecha->tm_year,
         mes    = fecha->tm_mon + 1,
         diaMes = fecha->tm_mday;

  if (elemento.compare("year") == 0) {
    // Año desde 1900 (+1900)
    return year;
  } else if (elemento.compare("mes") == 0) {
    // Número de meses desde Enero [0-11] (+1)
    return mes;
  } else if (elemento.compare("dia") == 0) {
    // Día del mes [1-31]
    return diaMes;
  } // Fin de revisar elemento
} // Fin de devolver componentes de fecha actual

/* ======================================================
|||||||||||   COMPLEMENTOS DE MENÚ CATÁLOGO    |||||||||||
========================================================*/

vector<vector<int> > paginacion(int cantElem, int maxElem) {
  vector<vector<int> > rolPaginas; int nPaginas;
  vector<int> pagina;

  if(cantElem % maxElem == 0) {
    // Cada página estará llena por igual
    nPaginas = cantElem / maxElem;
  } else {
    // Habrá una página extra
    nPaginas = (cantElem / maxElem) + 1;
  } // Fin de establecer número de páginas

  for (int i = 0; i < nPaginas; i+=1) {
    pagina.push_back(i*maxElem);
    if (i+1 == nPaginas) { // Única o última página
      pagina.push_back((i*maxElem) + (cantElem-(i*maxElem+1)));
    } else { // Las páginas anteriores
      pagina.push_back((i*maxElem) + (maxElem-1));
    } // Fin de verificar la última página
    rolPaginas.push_back(pagina); pagina.clear();
  } // Fin de crear nuevas páginas

  return rolPaginas;
} // Fin de manejar paginación vertical

string obtenerGenero(int id) {
  vector<string> generos;

  generos.push_back("Horror");     generos.push_back("Sci-Fi");
  generos.push_back("Drama");      generos.push_back("Aventura");
  generos.push_back("Accion");     generos.push_back("Biografia");
  generos.push_back("Comedia");    generos.push_back("Romance");
  generos.push_back("Documental"); generos.push_back("Estrenos");
  generos.push_back("En remate");

  return generos[id];
} // Fin de devolver la lista de generos