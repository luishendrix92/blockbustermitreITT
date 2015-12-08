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
    tecla == IZQ || tecla == DER ||
    tecla == ARR || tecla == ABJ ||
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

void finalFantasy(float velocidad) {
  /* Melodía creada con una tabla de frecuencias
  y una aplicación de piano para el smartphone */
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
  /* Melodía creada con una tabla de frecuencias
  y una aplicación de piano para el smartphone */
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

/*=======================================================
|||||||||||    COMPLEMENTOS DE RENDERIZADO    |||||||||||
=======================================================*/

void dibujarBordes() {
  int tamHorizontal = 78, tamVertical = 23;

  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, (tamVertical-1)); cout<<"_";
  } // Borde inferior
  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, 3); cout<<"_";
  } // Borde de titulo inferior
  for(int x = 3; x < tamHorizontal; x+=1) {
    gotoxy(x, 1); cout<<"_";
  } // Borde de titulo superior
  for(int y = 2; y < tamVertical; y+=1) {
    gotoxy((tamHorizontal-1), y); cout<<"|";
  } // Borde lateral derecho
  for(int y = 2; y < tamVertical; y+=1) {
    gotoxy(3, y); cout<<"|";
  } // Borde lateral izquierdo
} // Fin de dibujar bordes (función de alta importancia)

void prepararMensaje(string cabecera) {
  gotoxy(14,8);  cout<<"__________________________"<<
                         "__________________________";
  gotoxy(15,19); cout<<"_________________________"<<
                       "_________________________";
  for(int y = 9; y <= 19; y+=1) {
    gotoxy(14, y); cout<<"|";
  } // Borde lateral izquierdo
  for(int y = 9; y <= 19; y+=1) {
    gotoxy(65, y); cout<<"|";
  } // Borde lateral derecho

  // Tapar con espacios lo que haya debajo
  for(int y = 9; y <= 18; y += 1) {
    gotoxy(15,y);
    cout<<"                          "<<
          "                        ";
  } // Fin de llenar con espacios
  gotoxy(35,10); cout << cabecera;
  // Renderizado del botón de entendido
  gotoxy(41,16); cout<<"===============";
  gotoxy(41,17); cout<<"|| ENTENDIDO ||";
  gotoxy(41,18); cout<<"===============";
} // Fin de bordes para aviso/error

void db_error(string archivo) {
  system("cls"); system("color 4F"); // Pantalla roja
  dibujarBordes();
  // Libro ASCII: www.chris.com/ascii/index.php?art=objects/books
  gotoxy(10,13); cout<<"              .__=\\__                  .__==__,"              ;
  gotoxy(10,14); cout<<"            jf'      ~~=\\,         _=/~'      `\\,"           ;
  gotoxy(10,15); cout<<"        ._jZ'            `\\q,   /=~             `\\__"        ;
  gotoxy(10,16); cout<<"       j5(/                 `\\./                  V\\\\,"     ;
  gotoxy(10,17); cout<<"     .Z))' _____              |             .____, \\)/\\"     ;
  gotoxy(10,18); cout<<"    j5(K=~~     ~~~~\\=_,      |      _/=~~~~'    `~~+K\\\\,"  ;
  gotoxy(10,19); cout<<"  .Z)\\/                `~=L   |  _=/~                 t\\ZL"  ;
  gotoxy(10,20); cout<<" j5(_/.__/===========\\__   ~q |j/   .__============___/\\J(N,";
  gotoxy(10,21); cout<<"4L#XXXL_________________XGm, \\P  .mXL_________________JXXXW8L";
  // Renderizado de Texto
  gotoxy(30,2);  cout << "MENSAJE DE ERROR";
  gotoxy(10,5);  cout<<"Hubo un error al intentar abrir un archivo de texto para la";
  gotoxy(10,6);  cout<<"extraccion o insercion de informacion. Asegurese que en la";
  gotoxy(10,7);  cout<<"carpeta donde instalo este programa exista un archivo con el";
  gotoxy(10,8);  cout<<"nombre correcto: [              ]";
  gotoxy(10,10); cout<<"Presione cualquier tecla para salir del programa";
  // Imprimir el nombre del archivo problemático
  gotoxy(28,8);  cout << archivo; gotoxy(58,10);
  Beep(400,800); getch();
} // Fin de función render de alta importancia
