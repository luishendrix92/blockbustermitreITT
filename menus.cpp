namespace menu {
void comprar() {
  // quitar pelicula si 'stock = 0'
}

void credito() {
  // modificar o agregar dinero a la cuenta
}

void catalogo() {
  // elegir categoria
}

void registro() {
  // pide usuario, clave 2 veces, valida y guarda
  dibujarMenu("1_principal_registro");
  getch();
  dibujarMenu("1_principal");
}

void rentas() {
  // rentar películas
}

void membresias() {
  // capturar datos de usuario
}

void empleados() {
  system("cls");
  cout << "empleados" << endl;
}

void clientes(vector<string> usuario) {
  system("cls");
  cout << "clientes" << endl;
}

void login() {
  dibujarMenu("1_principal_login");
  // Variables para los valores del input
  string usuario, password; char tecla;
  vector<string> credenciales;
  /* input 0 => Usuario
     input 1 => Contraseña
     input 2 => Botón 'Entrar'
     orden => [0: der - 1: izq] */
  int input = 0, orden[2][3] = {{1,2,0},{2,0,1}};
  int direccion; /*0:der-1:izq*/ bool tienePermiso;

  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (tecla==77||tecla==75||tecla==9) { // Der-Izq-Tab
        direccion = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento("1_principal_login", orden[direccion][input]);
        input = orden[direccion][input];
        if (input==0){ usuario.clear(); }
        else if (input==1){ password.clear(); }
      } else if (esAlfaNum(tecla) // Tecla es alfanumérica
      && input != 2 // No es el botón 'Entrar'
      && usuario.length() < 18 && password.length() < 18) {
        switch(input) {
          case 0: // Usuario
            gotoxy(23,12); usuario += tecla; cout << usuario;
            gotoxy(23+usuario.length(),12); break;
          case 1: // Contraseña
            gotoxy(49,12); password += tecla; cout << password;
            gotoxy(49+password.length(),12); break;
        } // Fin de capturar datos
      } else if (tecla == 8 || tecla == 224) { // 'BCKSP'-'DEL'
        switch(input) {
          case 0: // Usuario
            enfocarElemento("1_principal_login", 0);
            usuario.clear(); break;
          case 1: // Contraseña
            enfocarElemento("1_principal_login", 1);
            password.clear(); break;
        } // Fin de resetear inputs actuales
      } else if (tecla == 13 && input == 2) {
        // Al presionar 'ENTER' validar y loguear
        tienePermiso = autenticar(usuario, password);
        if(tienePermiso) {
          vector<string> usuariosTemporales;
          usuariosTemporales = filtrarRegistros("usuarios.txt", 0, usuario);
          credenciales = separarLinea(usuariosTemporales[0], 1);

          if(credenciales[2].compare("empleado") == 0) {
            menu::empleados();
          } else if (credenciales[2].compare("cliente") == 0) {
            menu::clientes(credenciales);
          } // Fin de llevar al menú correspondiente

          credenciales.clear(); usuariosTemporales.clear();
        } // Fin de dar pase si tiene permiso
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("1_principal");
} // Fin de autenticar usuario
} // Fin de namespace menu::función