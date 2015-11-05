/*  Manejo de base de datos de
    lectura y escritura con .txt. 
================================================= */
#ifndef baseDeDatos
#define baseDeDatos
using namespace std;
  
fstream baseDatos;

void escribir(fstream& archivo, string nombreArchivo) {
	string nombreArchivo;
	archivo.open(nombreArchivo, ios::in);
	while (archivo.good()) {
		//
	} // Fin de leer cada línea
	archivo.close();
} // Fin de escribir en archivos
#endif