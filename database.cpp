/*  Manejo de base de datos de
    lectura y escritura con .txt. 
================================================= */


/* VISUALIZACIÓN DE LAS 3 TABLAS EN LA BASE DE DATOS:

Nota: Ninguna celda deberá llevar acentos o puntos y comas ";"
ya que el ";" está reservado como separador de celda.

Tabla: PELÍCULAS (peliculas.txt)
===============================================================================================
| ID  | TITULO |  AÑO  | GÉNERO  | STATUS  | DURACIÓN |          PÁRRAFO DE SINOPSIS          |
======|========|=======|=========|=========|==========|=======================================|
| 000 | string | aaaa  | comedia | estreno | minutos  | LINEA 1 | LINEA 2 | LINEA 3 | LINEA 4 |
| 001 |        |       | horror  | remate  |          |=========|=========|=========|=========|
|     |        |       | accion  | normal  |          | string  | string  | string  | string  |
|     |        |       | drama   |         |          |         |         |         |         |
|     |        |       | sci-fi  |         |          |         |         |         |         |
===============================================================================================
Nota: Si en la sinopsis alguna línea no es necesaria, ponerla vacía como en: /linea1;linea2;;/
en donde se puede ver que las líneas 3 y 4 están vacías, no como: /linea1;linea2;linea3;linea4/.

Tabla: USUARIOS (usuarios.txt)
==================================================
|     USUARIO     |    CONTRASEÑA   |  PERMISOS  |
|=================|=================|============|
| alfanumérico    | alfanumérico    |  empleado  |
| de 6 a 20 chars | de 6 a 20 chars |  cliente   |
==================================================

Tabla: MEMBRESÍAS (membresias.txt)
============================================================================================================
|     CLIENTE     |   EXPIRACIÓN   |         RENTA 1       |         RENTA 2       |         RENTA 2       |
==================|================|=======================|=======================|=======================|
| alfanumérico    | fecha en forma | PELICULA |  ENTREGA   | PELICULA |  ENTREGA   | PELICULA |  ENTREGA   |
| de 6 a 20 chars | dd/mm/aaaa     |==========|============|==========|============|==========|============|
|                 |                | título   | fecha tipo | título   | fecha tipo | título   | fecha tipo |
|                 |                |          | dd/mm/aaaa |          | dd/mm/aaaa |          | dd/mm/aaaa |
============================================================================================================

FIN DE VISUALIZACIÓN DE BASE DE DATOS */