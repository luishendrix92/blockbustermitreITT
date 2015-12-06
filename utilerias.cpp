/*=================================================
    Pequeñas funciones que permiten
    realizar tareas útiles y repetitivas
==================================================*/
using namespace std;

#define IZQ    75
#define DER    77
#define ARR    72
#define ABJ    80
#define TAB    9
#define ENTER  13
#define ESC    27
#define BCKSP  8
#define DEL    224

void gotoxy(int x, int y) {
  HANDLE hcon;
  hcon    = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD  dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon,dwPos);
} // Fin de añadir GoToXY

bool encontrarTexto(string buscado, string dondeBuscar) {
  size_t encontrado;

  // Convertir las cadenas a minúsculas para evitar conflictos
  transform(
    buscado.begin(), buscado.end(), buscado.begin(), ::tolower
  ); // Fin de convertir a minúsculas
  transform(
    dondeBuscar.begin(),dondeBuscar.end(),dondeBuscar.begin(),::tolower
  ); // Fin de convertir a minúsculas

  // Buscar la cadena "buscado" en "dondeBuscar"
  encontrado = dondeBuscar.find(buscado);
  return (encontrado!=string::npos) ? true : false;
} // Fin de buscar strings en otras

vector<string> separarLinea(string linea, char separador) {
  // Declarar un string stream para extraer texto de éste
  istringstream copia(linea);
  vector<string> registro;
  string celda;

  while (getline(copia, celda, separador)) {
    registro.push_back(celda);
  } // Fin meter cada cadena entre el separador al vector

  return registro;
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
  return  ( // [A-Z] y [a-z] y [0-9] y [.-_] | \w
    (tecla >= 65 && tecla <= 90) ||
    (tecla >= 48 && tecla <= 57) ||
    (tecla >= 97 && tecla <= 122) ||
    (tecla == 45 || tecla == 46 || tecla == 95)
  ); // Revisa rangos de caracteres ASCII
} // Fin de ver si una tecla es alfanumérica

bool esNumerica(char tecla) {
  return  ( // [0-9 | \d+]
    (tecla >= 48 && tecla <= 57)
  ); // Revisa rangos de caracteres ASCII
} // Fin de ver si una tecla es numérica

bool esDireccional(char tecla) {
  return  (
    tecla == IZQ  || tecla == DER ||
    tecla == ARR  || tecla == ABJ ||
    tecla == TAB
  ); // Fin de comprobar tecla
} // Fin de ver si una tecla es TAB o flecha

int obtenerDireccion(char tecla) {
  /* ROL DE DIRECCIONES
  =========================
  0: Derecha - 1: Izquierda
  2: Arriba  - 3: Abajo  */
  int direccion;
  switch(tecla) {
    case DER:   direccion = 0; break;
    case ENTER: direccion = 0; break;
    case TAB:   direccion = 0; break;
    case IZQ:   direccion = 1; break;
    case ARR:   direccion = 2; break;
    case ABJ:   direccion = 3; break;
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

  if (elemento.compare("year")       == 0) {
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

string asteriscos(string texto) {
  short int numAsteriscos = texto.length();
  string asteriscos;

  for (int i = 0; i < numAsteriscos; i+=1) {
    asteriscos += "*";
  } // Fin de agregar n asteriscos

  return asteriscos;
} // Fin de convertir texto en asteriscos

string fechaDeHoy() {
  string fecha;

  fecha += enteroATexto(elementoFecha("dia") ) + "/";
  fecha += enteroATexto(elementoFecha("mes") ) + "/";
  fecha += enteroATexto(elementoFecha("year"));

  return fecha;
} // Fin de devolver fecha en formato DD/MM/AAAA

int diferenciaFechas(string f1, string f2) {
  int diferencia;
  vector<string> fecha1 = separarLinea(f1, '/'),
                 fecha2 = separarLinea(f2, '/');

  diferencia = ( (atoi(fecha2[2].c_str())*365)  // Año 2
                +(atoi(fecha2[1].c_str())*31 )  // Mes 2
                +(atoi(fecha2[0].c_str()))   )- // Día 2
               ( (atoi(fecha1[2].c_str())*365)  // Año 1
                +(atoi(fecha1[1].c_str())*31 )  // Mes 1
                +(atoi(fecha1[0].c_str()))   ); // Día 1

  return diferencia;
} // Fin de calcular la diferencia en días

string sumarMeses(string fecha, short int meses) {
  string nuevaFecha;
  vector<string> fechaInicial = separarLinea(fecha, '/');
  int dia  = atoi(fechaInicial[0].c_str()),
      mes  = atoi(fechaInicial[1].c_str()),
      year = atoi(fechaInicial[2].c_str());

  if (mes + meses > 12) { // Hay aumento de año
    short int difYears = (meses - (12-mes)) / 12;
    if (meses % 12 != 0) {
      year += (difYears + 1);
      mes = (meses - (12 * difYears)) - (12 - mes);
    } else {
      year += meses / 12;
    } // Fin de comprobar aumento de 12 meses, 24, 36... etc
  } else {
    mes += meses; // Sumar los meses
  } // Fin de sumar meses sin pasarse de diciembre

  if (dia > 28 && mes == 2) { // Si es Febrero 28, 29... etc
    dia = 28;
  } // Fin de controlar año bisiesto

  nuevaFecha += enteroATexto(dia) + "/";
  nuevaFecha += enteroATexto(mes) + "/";
  nuevaFecha += enteroATexto(year);

  return nuevaFecha;
} // Fin de devolver nueva fecha mas 'n' meses

string mesTexto(string mes) {
  int mesNum = atoi(mes.c_str());

  switch(mesNum) {
    case 1:  return "Enero";      break;
    case 2:  return "Febrero";    break;
    case 3:  return "Marzo";      break;
    case 4:  return "Abril";      break;
    case 5:  return "Mayo";       break;
    case 6:  return "Junio";      break;
    case 7:  return "Julio";      break;
    case 8:  return "Agosto";     break;
    case 9:  return "Septiembre"; break;
    case 10: return "Octubre";    break;
    case 11: return "Noviembre";  break;
    case 12: return "Diciembre";  break;
    default: return "null";
  } // Fin de devolver el mes en cadena
} // Fin de convertir mes numérico a textual

string cuandoExpira(int duracion) {
  string fechaExpiracion;

  fechaExpiracion = sumarMeses(fechaDeHoy(), duracion);

  return fechaExpiracion;
} // Fin de fecha de expiración de membresía nueva

/*=======================================================
|||||||||||   COMPLEMENTOS DE MENÚ CATÁLOGO   |||||||||||
=======================================================*/

vector<vector<int> > paginacion(int cantElem, int maxElem) {
  vector<vector<int> > rolPaginas;
  vector<int> pagina; int nPaginas;

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
  string genero;

  switch(id) {
    case 0:  genero = "Horror";     break;
    case 1:  genero = "Sci-Fi";     break;
    case 2:  genero = "Drama";      break;
    case 3:  genero = "Aventura";   break;
    case 4:  genero = "Accion";     break;
    case 5:  genero = "Biografia";  break;
    case 6:  genero = "Comedia";    break;
    case 7:  genero = "Romance";    break;
    case 8:  genero = "Documental"; break;
    case 9:  genero = "Estrenos";   break;
    case 10: genero = "En remate";  break;
  } // Fin de devolver el género en cadena
  return genero;
} // Fin de devolver la lista de generos

/*=======================================================
|||||||||||      MELODÍAS CON Beep(Hz,s)      |||||||||||
=======================================================*/

void marchaImperial() {
  // Crédito de la canción en console::beep() ->
  // social.technet.microsoft.com/wiki/contents/articles/
  // 20989.music-from-the-command-line-performed-by-powershell.aspx
  Beep(440,500) ;
  Beep(440,500) ;
  Beep(440,500) ;
  Beep(349,350) ;
  Beep(523,150) ;
  Beep(440,500) ;
  Beep(349,350) ;
  Beep(523,150) ;
  Beep(440,1000);
  Beep(659,500) ;
  Beep(659,500) ;
  Beep(659,500) ;
  Beep(698,350) ;
  Beep(523,150) ;
  Beep(415,500) ;
  Beep(349,350) ;
  Beep(523,150) ;
  Beep(440,1000);
} // Fin de canción de Star Wars

void finalFantasy(float velocidad) {
  Beep(987,(200 * velocidad));  // B5
  Beep(987,(200 * velocidad));  // B5
  Beep(987,(200 * velocidad));  // B5
  Beep(987,(800 * velocidad));  // B5
  Beep(787,(700 * velocidad));  // G5
  Beep(880,(600 * velocidad));  // A5
  Beep(987,(400 * velocidad));  // B5
  Beep(880,(150 * velocidad));  // A5
  Beep(987,(1100 * velocidad)); // B5
} // Fin de 'victory fanfare'

void lostWoods() {
  Beep(698,200);  // F5
  Beep(880,200);  // A5
  Beep(987,450);  // B5
  Beep(698,200);  // F5
  Beep(880,200);  // A5
  Beep(987,450);  // B5
  Beep(698,200);  // F5
  Beep(880,200);  // A5
  Beep(987,200);  // B5
  Beep(1318,200); // E6
  Beep(1174,550); // D6
  Beep(987,200);  // B5
  Beep(1046,200); // C6
  Beep(987,200);  // B5
  Beep(783,200);  // G5
  Beep(659,700);  // E5
  Beep(587,200);  // D5
  Beep(659,200);  // E5
  Beep(783,200);  // G5
  Beep(659,700);  // E5
} // Fin de Lost Woods TLOZ
