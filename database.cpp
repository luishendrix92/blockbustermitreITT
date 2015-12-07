/*=================================================
    Manejo de base de datos de
    lectura y escritura con .txt.
==================================================*/
// Columnas de la tabla 'usuarios'
#define NOMBRE    0
#define CLAVE     1
#define ROL       2
#define CREDITO   3
// Columnas de la tabla 'membresías'
#define CLIENTE   0
#define EXPIR     1
#define RENTA1    2
#define RENTA2    3
#define RENTA3    4
// Columnas de la tabla 'películas'
#define ID        0
#define TITULO    1
#define YEAR      2
#define GENERO    3
#define STATUS    4
#define DURACION  5
#define PRECIO    6
#define STOCK     7
#define SINOP_L1  8
#define SINOP_L2  9
#define SINOP_L3  10
#define SINOP_L4  11

/* La siguiente  función emula el comportamiento de un query en SQL
que modifica un registro en una tabla de una base de datos:
UPDATE tabla SET campoModificado = valorNuevo WHERE campoBuscado = valorBuscado */

void modificarRegistro(
/* La tabla */      string archivo,
                    int campoModificado,
                    string valorNuevo,
/* Criterios de */  int campoBuscado,
/*   búsqueda.  */  string valorBuscado
                      ) {
  fstream tabla, memoria;
  string linea, lineaModificada;
  vector<string> registro;

  tabla.open(archivo.c_str(), ios::in);
  memoria.open("temporal.txt", ios::out);

  if (tabla.is_open()) {
    while(getline(tabla, linea)) {
      // Grabar celdas en el "registro"
      registro = separarLinea(linea, ';');
      if (registro[campoBuscado].compare(valorBuscado) == 0) {
        // Modificar el valor del record en el campo a modificar
        registro[campoModificado] = valorNuevo;
        lineaModificada = unirRegistro(registro, ";");
        /* Si los valores coinciden, meter la línea modificada al
        archivo temporal en vez de la original para modificarla */
        memoria << lineaModificada << endl;
      } else {
        memoria << linea << endl;
      } // Fin de modificar línea

      // Limpiar el vector para la siguiente iteración
      registro.clear();
    } // Fin copiar el registro a la cadena "linea"
    memoria.close(); tabla.close();

    // Borrar el original y renombrar el temporal como el original
    remove(archivo.c_str()); rename("temporal.txt", archivo.c_str());
  } else {
    db_error(archivo);
  } // Fin de comprobar si el archivo existe
} // Fin de modificar un registro en una tabla

/* La siguiente función emula el comportamiento de un query en SQL
que elimina registros que coinciden con el criterio de filtrado:
DELETE FROM tabla WHERE campoBuscado = valorBuscado;            */

void borrarRegistro(string archivo, int campoBuscado, string valorBuscado) {
  fstream tabla, memoria; string linea;
  vector<string> registro;

  tabla.open(archivo.c_str(), ios::in);
  memoria.open("temporal.txt", ios::out);

  if (tabla.is_open()) {
    while(getline(tabla, linea)) {
      // Grabar celdas en el "registro"
      registro = separarLinea(linea, ';');
      // Si el registro es el deseado, omitirlo para que no exista más
      if (!(registro[campoBuscado].compare(valorBuscado) == 0)) {
        memoria << linea << endl;
      } // Fin de omitir línea en el temporal

      // Limpiar el vector para la siguiente iteración
      registro.clear();
    } // Fin copiar el registro a la cadena "linea"
    memoria.close(); tabla.close();

    // Borrar el original y renombrar el temporal como el original
    remove(archivo.c_str()); rename("temporal.txt", archivo.c_str());
  } else {
    db_error(archivo);
  } // Fin de comprobar si el archivo existe
} // Fin de borrar registro de una tabla

/* La siguiente función emula el comportamiento de un query en SQL
que devuelve registros que coinciden con el criterio de filtrado:
SELECT FROM tabla WHERE campoFiltrado = valorFiltrado;          */

vector<string> filtrarRegistros(
/* La tabla */        string archivo,
/* Criterios de */    int campoFiltrado,
/*   filtrado.  */    string valorFiltrado
                               ) {
  vector<string> registros;
  vector<string> registroTemporal;
  fstream tabla; string linea;

  tabla.open(archivo.c_str(), ios::in);
  if (tabla.is_open()) {
    while(getline(tabla, linea)) {
      // Grabar celdas en el "registro temporal"
      registroTemporal = separarLinea(linea, ';');
      // Si el registro cumple los criterios, meterlo al vector
      if (registroTemporal[campoFiltrado].compare(valorFiltrado) == 0) {
        registros.push_back(linea);
      } // Fin de omitir línea en el temporal

      // Limpiar registro temporal
      registroTemporal.clear();
    } // Fin de meter líneas del .txt al vector
    tabla.close();
  } else {
    db_error(archivo);
  } // Fin de comprobar si el archivo existe

  //if(registros.size() == 0) { registros.push_back("null"); }
  return registros;
} // Fin de descargar .txt por criterios en vector

/* La siguiente función emula el comportamiento de un query en SQL
que inserta un nuevo registro en una base de datos:
INSERT INTO tabla VALUES (nuevoRegistro)                        */

void insertarRegistro(string archivo, string nuevoRegistro) {
  fstream tabla;

  tabla.open(archivo.c_str(), ios::out | ios::app);
  /* Insertar */  tabla << nuevoRegistro << endl;
  tabla.close();
} // Fin de añadir datos a tabla

vector<vector<string> > descargarTabla(string archivo) {
  fstream tabla; string linea;
  vector<string> registroActual;
  vector<vector<string> > registros;

  tabla.open(archivo.c_str(), ios::in);
  if(tabla.is_open()) {
    while(getline(tabla, linea)) {
      if (linea.length() > 0) {
        registroActual = separarLinea(linea, ';');
        registros.push_back(registroActual);
      } // Fin de ver si no es una línea vacía
    } // Fin de meter líneas del .txt al vector
  } else {
    db_error(archivo);
  } // Fin de comprobar si el archivo existe

  return registros;
} // Fin de crear un arreglo 2D con todos los registros

string consultaRapida(
/* La tabla     */string archivo,
/* Criterios de */int campoBuscado,
/*   filtrado.  */string valorBuscado,
/* Consulta     */int campoConsultado
                     ) {
  vector<string> registroTemporal;
  fstream tabla; string linea, resultado = "null";

  tabla.open(archivo.c_str(), ios::in);
  if (tabla.is_open()) {
    while(getline(tabla, linea)) {
      // Grabar celdas en el "registro temporal"
      registroTemporal = separarLinea(linea, ';');
      /* Si el registro en el campo buscado
      coincide con nuestra búsqueda, devolver
      lo que haya en el campo consultado   */
      if (registroTemporal[campoBuscado].compare(valorBuscado) == 0) {
        resultado = registroTemporal[campoConsultado];
        break; // Finaliza la lectura del archivo
      } // Fin de omitir línea en el temporal

      // Limpiar registro temporal
      registroTemporal.clear();
    } // Fin de meter líneas del .txt al vector
    tabla.close(); return resultado;
  } else {
    db_error(archivo);
  } // Fin de comprobar si el archivo existe
} // Fin de consultar un campo a través de una búsqueda

/* ======================================================
|||||||||||    COMPLEMENTOS DE MENÚ LOGIN     |||||||||||
=======================================================*/

bool autenticar(string nombre, string clave) {
  // Arreglo 'usuario' -> [0] Nombre - [1] Clave
  fstream tablaUsuarios;   string linea;
  vector<string> registro; bool coinciden = false;

  tablaUsuarios.open("usuarios.txt", ios::in);
  if (tablaUsuarios.is_open()) {
    while(getline(tablaUsuarios, linea)) {
      registro = separarLinea(linea, ';');
      if (nombre.compare(registro[NOMBRE]) == 0 &&
          clave.compare(registro[CLAVE]) == 0
         ) { // Si coinciden nombre y clave
        coinciden = true; break;
      } // Fin de comparar registros
      registro.clear();
    } // Fin de meter líneas del .txt al vector
    tablaUsuarios.close();
  } else {
    db_error("usuarios.txt");
  } // Fin de comprobar si el archivo existe

  return coinciden;
} // Fin de autenticar usuarios

/* ======================================================
|||||||||||   COMPLEMENTOS DE MENÚ REGISTRO   |||||||||||
=======================================================*/

bool nombreDisponible(string nombre) {
  fstream tablaUsuarios;   string linea;
  vector<string> registro; bool disponible = true;

  tablaUsuarios.open("usuarios.txt", ios::in);
  if (tablaUsuarios.is_open()) {
    while(getline(tablaUsuarios, linea)) {
      registro = separarLinea(linea, ';');
      if (nombre.compare(registro[NOMBRE]) == 0) {
        disponible = false; break;
      } // Fin de comparar registros
      registro.clear();
    } // Fin de meter líneas del .txt al vector
    tablaUsuarios.close();
  } else {
    db_error("usuarios.txt");
  } // Fin de comprobar si el archivo existe

  return disponible;
} // Fin de si un nombre de usuario está libre para usar

/* ======================================================
|||||||||||  COMPLEMENTOS DE MENÚ MEMBRESÍAS  |||||||||||
=======================================================*/

bool realizarGasto(string usuario, int monto) {
  string dinero; int credito;

  // Consultar el crédito del usuario y almacenarlo
  dinero  = consultaRapida(
    "usuarios.txt", NOMBRE, usuario, CREDITO
  ); // Fin de almacenar crédito del usuario
  credito = atoi(dinero.c_str());
  dinero  = enteroATexto(credito);

  // Comprobar si se puede realizar la compra
  if (monto <= credito) {
    credito -= monto;
    // Actualizar la base de datos ya realizado el gasto
    modificarRegistro(
      "usuarios.txt", CREDITO, dinero, NOMBRE, usuario
    ); // Fin de restarle dinero al usuario
    return true;
  } else { // No le alcanzó
    return false;
  } // Fin de comprobar si tiene dinero
} // Fin de sustraer un gasto al crédito de un usuario

void nuevaMembresia(string usuario, string expiracion) {
  string nuevoMiembro;

  nuevoMiembro =  usuario    + ";" +
                  expiracion + ";" +
                  "null;null;null"; // Usuario afiliado

  insertarRegistro("membresias.txt", nuevoMiembro);
} // Fin de afiliar usuario a Blockbuster

bool tieneMembresia(string usuario) {
  fstream tablaMiembros;   string linea;
  vector<string> registro; bool afiliado = false;

  tablaMiembros.open("membresias.txt", ios::in);
  if (tablaMiembros.is_open()) {
    while(getline(tablaMiembros, linea)) {
      registro = separarLinea(linea, ';');
      if (usuario.compare(registro[CLIENTE]) == 0) {
        afiliado = true; break;
      } // Fin de comparar registros
      registro.clear();
    } // Fin de meter líneas del .txt al vector
    tablaMiembros.close();
  } else {
    db_error("membresias.txt");
  } // Fin de comprobar si el archivo existe

  return afiliado;
} // Fin de verificar si ya es miembro

/* ======================================================
|||||||||||    COMPLEMENTOS DE MENÚ CRÉDITO   |||||||||||
=======================================================*/

void abonarCredito(string beneficiario, int credito) {
  string creditoActual = consultaRapida(
    "usuarios.txt", NOMBRE, beneficiario, CREDITO
  ); // Fin de almacenar el crédito actual
  int creditoUsuario   = atoi(creditoActual.c_str());

  if (credito + creditoUsuario <= 9999) {
    credito += creditoUsuario;
    string nuevoCredito = enteroATexto(credito);
    modificarRegistro(
      "usuarios.txt", CREDITO, nuevoCredito, NOMBRE, beneficiario
    ); // Fin de abonar crédito al beneficiario
  } // Fin de evitar superar $9999.00
} // Fin de sumar crédito a un beneficiario

/* VISUALIZACIÓN DE LAS 3 TABLAS EN LA BASE DE DATOS:

Notas: Ninguna celda deberá llevar acentos o puntos y comas ";" ya que el ";" está
reservado como separador de celda. El separador "," se usará para sub-registros/arreglos.

Tabla: PELÍCULAS (peliculas.txt)
----------------------------------------------------------------------------------------------------------------
| [0] |   [1]  |  [2]  |   [3]   |   [4]   |    [5]   |   [6]  |  [7]  |                [8->11]                |
================================================================================================================
| ID  | TITULO |  AÑO  | GÉNERO  | STATUS  | DURACIÓN | PRECIO | STOCK |          PÁRRAFO DE SINOPSIS          |
======|========|=======|=========|=========|==========|========|=======|=======================================|
| 000 | string | aaaa  | Comedia | Estreno | minutos  | intgr  | intgr | LINEA 1 | LINEA 2 | LINEA 3 | LINEA 4 |
| 001 |        |       | Horror  | Remate  |          |        |       |=========|=========|=========|=========|
|     |        |       | Accion  | Normal  |          |        |       | string  | string  | string  | string  |
|     |        |       | Drama   |         |          |        |       |         |         |         |         |
|     |        |       | Sci-fi  |         |          |        |       |         |         |         |         |
================================================================================================================
|     |        |       |         |         |          |        |       |   [8]   |   [9]   |  [10]   |  [11]   |
----------------------------------------------------------------------------------------------------------------
Nota: Si en la sinopsis alguna línea no es necesaria, ponerla " " como en: /linea1;linea2; ; /
en donde se puede ver que las líneas 3 y 4 están vacías, no como: /linea1;linea2;linea3;linea4/.

Tabla: USUARIOS (usuarios.txt)
--------------------------------------------------------------
|       [0]       |        [1]      |     [2]    |    [3]    |
==============================================================
|     USUARIO     |    CONTRASEÑA   |  PERMISOS  |  CREDITO  |
|=================|=================|============|============
| alfanumérico    | alfanumérico    |  empleado  |  integer  |
| de 6 a 18 chars | de 6 a 18 chars |  cliente   |           |
==============================================================
Nota: Cuando se cree un usuario, inicializarlo con 0 (MXN).
Los empleados tendrán un valor en el campo CREDITO de "null".

Tabla: MEMBRESÍAS (membresias.txt)                         [2] -> [4] RENTA N => N películas rentadas (3)...
------------------------------------------------------------------------------------------------------------
|       [0]       |       [1]      |          [2]          |          [3]          |          [4]          |
============================================================================================================
|     CLIENTE     |   EXPIRACIÓN   |         RENTA 1       |         RENTA 2       |         RENTA 3       |
==================|================|=======================|=======================|=======================|
| alfanumérico    | fecha en forma | PELICULA |  ENTREGA   | PELICULA |  ENTREGA   | PELICULA |  ENTREGA   |
| de 6 a 20 chars | dd/mm/aaaa     |==========|============|==========|============|==========|============|
|                 |                | id 3dig  | fecha tipo | id 3dig  | fecha tipo | id 3dig  | fecha tipo |
|                 |                |          | dd/mm/aaaa |          | dd/mm/aaaa |          | dd/mm/aaaa |
============================================================================================================
|                 |                |  [2][0]  |   [2][1]   |  [3][0]  |   [3][1]   |  [4][0]  |   [4][1]   |
------------------------------------------------------------------------------------------------------------
Nota: Inicializar cada membresía en los campos del index [2] al [4] con el sub-arreglo "null,null".

FIN DE VISUALIZACIÓN DE BASE DE DATOS */
