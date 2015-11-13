/*  Manejo de base de datos de
    lectura y escritura con .txt. 
================================================= */

/* La siguiente función emula el comportamiento de un query en SQL
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
      registro = separarLinea(linea, 1);
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
    system("cls");
    cout << "Error de base de datos con: " << archivo; getch();
  } // Fin de comprobar si el archivo existe
} // Fin de modificar un registro en una tabla

/* La siguiente función emula el comportamiento de un query en SQL
que elimina registros que coinciden con el criterio de filtrado:
DELETE FROM tabla WHERE campoBuscado = valorBuscado; */

void borrarRegistro(string archivo, int campoBuscado, string valorBuscado) {
  fstream tabla, memoria;
  string linea;
  vector<string> registro;

  tabla.open(archivo.c_str(), ios::in);
  memoria.open("temporal.txt", ios::out);

  if (tabla.is_open()) {
    while(getline(tabla, linea)) {
      // Grabar celdas en el "registro"
      registro = separarLinea(linea, 1);
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
    system("cls");
    cout << "Error de base de datos con: " << archivo; getch();
  } // Fin de comprobar si el archivo existe
} // Fin de borrar registro de una tabla

/* La siguiente función emula el comportamiento de un query en SQL
que devuelve registros que coinciden con el criterio de filtrado:
SELECT FROM tabla WHERE campoFiltrado = valorFiltrado; */

vector<string> filtrarRegistros(
/* La tabla */        string archivo,
/* Criterios de */    int campoFiltrado,
/*   filtrado.  */    string valorFiltrado
                               ) {
  vector<string> registros;
  vector<string> registroTemporal;
  fstream tabla;
  string linea;

  tabla.open(archivo.c_str(), ios::in);
  if (tabla.is_open()) {
    while(getline(tabla, linea)) {
      // Grabar celdas en el "registro temporal"
      registroTemporal = separarLinea(linea, 1);
      // Si el registro cumple los criterios, meterlo al vector
      if (registroTemporal[campoFiltrado].compare(valorFiltrado) == 0) {
        registros.push_back(linea);
      } // Fin de omitir línea en el temporal

      // Limpiar registro temporal
      registroTemporal.clear();
    } // Fin de meter líneas del .txt al vector
    tabla.close();
  } else {
    system("cls");
    cout << "Error de base de datos con: " << archivo; getch();
  } // Fin de comprobar si el archivo existe

  return registros;
} // Fin de descargar .txt por criterios en vector

/* VISUALIZACIÓN DE LAS 3 TABLAS EN LA BASE DE DATOS:

Notas: Ninguna celda deberá llevar acentos o puntos y comas ";" ya que el ";" está
reservado como separador de celda. El separador "," se usará para sub-registros/arreglos.

Tabla: PELÍCULAS (peliculas.txt)
----------------------------------------------------------------------------------------------------------------
| [0] |   [1]  |  [2]  |   [3]   |   [4]   |    [5]   |   [6]  |  [7]  |                 [8]                   |
================================================================================================================
| ID  | TITULO |  AÑO  | GÉNERO  | STATUS  | DURACIÓN | PRECIO | STOCK |          PÁRRAFO DE SINOPSIS          |
======|========|=======|=========|=========|==========|========|=======|=======================================|
| 000 | string | aaaa  | Comedia | Estreno | minutos  | float  | intgr | LINEA 1 | LINEA 2 | LINEA 3 | LINEA 4 |
| 001 |        |       | Horror  | Remate  |          |        |       |=========|=========|=========|=========|
|     |        |       | Accion  | Normal  |          |        |       | string  | string  | string  | string  |
|     |        |       | Drama   |         |          |        |       |         |         |         |         |
|     |        |       | Sci-fi  |         |          |        |       |         |         |         |         |
================================================================================================================
|     |        |       |         |         |          |        |       | [8][0]  | [8][1]  | [8][2]  | [8][3]  |
----------------------------------------------------------------------------------------------------------------
Nota: Si en la sinopsis alguna línea no es necesaria, ponerla "null" como en: /linea1;linea2;null;null/
en donde se puede ver que las líneas 3 y 4 están vacías, no como: /linea1;linea2;linea3;linea4/.

Tabla: USUARIOS (usuarios.txt)
--------------------------------------------------------------
|       [0]       |        [1]      |     [2]    |    [3]    |
==============================================================
|     USUARIO     |    CONTRASEÑA   |  PERMISOS  |  CREDITO  |
|=================|=================|============|============
| alfanumérico    | alfanumérico    |  empleado  |  integer  |
| de 6 a 20 chars | de 6 a 20 chars |  cliente   |           |
==============================================================
Nota: Cuando se cree un usuario, inicializarlo con 0 (MXN).
Los empleados tendrán un valor en el campo CREDITO de "null".

Tabla: MEMBRESÍAS (membresias.txt)                         [2] -> [6] RENTA N => N películas rentadas (5)...
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
Nota: Inicializar cada membresía en los campos del index [2] al [6] con el sub-arreglo "null,null".

FIN DE VISUALIZACIÓN DE BASE DE DATOS */