/*  Manejo de base de datos de
    lectura y escritura con .txt. 
================================================= */
void modificarRecord(string archivo, string id, int campo, string valorNuevo) {
  fstream tabla, memoria;
  string linea;
  vector<string> record;

  tabla.open(archivo.c_str(), ios::in);
  memoria.open("temporal.txt", ios::out);

  if (tabla.is_open()) {
    while(getline(tabla, linea)) {
      // Grabar celdas en el "record"
      convertirLineaEnRecord(linea, record, 1);
      /* Meter el nuevo valor al archivo sólo si el valor del campo
      que quieres modificar coincide en la línea leída del archivo. */
      if (record[campo].compare(id) == 0) {
        memoria << valorNuevo << endl;
      } else {
        memoria << linea << endl;
      } // Fin de modificar línea

      // Limpiar el vector para la siguiente iteración
      record.clear();
    } // Fin copiar el record a la cadena "linea"
    memoria.close(); tabla.close();

    // Borrar el original y renombrar el temporal como el original
    remove(archivo.c_str()); rename("temporal.txt", archivo.c_str());
  } else {
    system("cls");
    cout << "Error de base de datos con: " << archivo;
    getch();
  } // Fin de comprobar si el archivo existe
} // Fin de modificar una record en una tabla

void borrarRecord(string archivo, string id, int campo) {
  fstream tabla, memoria;
} // Fin de borrar record de una tabla

void copiarTabla() {
  /* Función para copiar una tabla entera
  de la base de datos en un vector 1D o 2D */
} // Fin de descargar .txt en vector

/* VISUALIZACIÓN DE LAS 3 TABLAS EN LA BASE DE DATOS:

Nota: Ninguna celda deberá llevar acentos o puntos y comas ";"
ya que el ";" está reservado como separador de celda.

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
Nota: Si en la sinopsis alguna línea no es necesaria, ponerla vacía como en: /linea1;linea2;;/
en donde se puede ver que las líneas 3 y 4 están vacías, no como: /linea1;linea2;linea3;linea4/.

Tabla: USUARIOS (usuarios.txt)
--------------------------------------------------
|       [0]       |        [1]      |     [2]    |
==================================================
|     USUARIO     |    CONTRASEÑA   |  PERMISOS  |
|=================|=================|============|
| alfanumérico    | alfanumérico    |  empleado  |
| de 6 a 20 chars | de 6 a 20 chars |  cliente   |
==================================================

Tabla: MEMBRESÍAS (membresias.txt)
------------------------------------------------------------------------------------------------------------
|       [0]       |       [1]      |          [2]          |          [3]          |          [4]          |
============================================================================================================
|     CLIENTE     |   EXPIRACIÓN   |         RENTA 1       |         RENTA 2       |         RENTA 2       |
==================|================|=======================|=======================|=======================|
| alfanumérico    | fecha en forma | PELICULA |  ENTREGA   | PELICULA |  ENTREGA   | PELICULA |  ENTREGA   |
| de 6 a 20 chars | dd/mm/aaaa     |==========|============|==========|============|==========|============|
|                 |                | id 3dig  | fecha tipo | id 3dig  | fecha tipo | id 3dig  | fecha tipo |
|                 |                |          | dd/mm/aaaa |          | dd/mm/aaaa |          | dd/mm/aaaa |
============================================================================================================
|                 |                |  [2][0]  |   [2][1]   |  [3][0]  |   [3][1]   |  [4][0]  |   [4][1]   |
------------------------------------------------------------------------------------------------------------

FIN DE VISUALIZACIÓN DE BASE DE DATOS */