namespace menu {
void comprar() {
  // quitar pelicula si 'stock = 0'
}

void miCredito() {
  // modificar o agregar dinero a la cuenta
}

void catalogo() {
  dibujarMenu("2.4_catalogo_f1");
  getch();
  dibujarMenu("2_clientes");
}

void rentas() {
  // rentar películas
}

void membresias() {
  // capturar datos de usuario
}

void clientes(string usuario, string credito) {
  dibujarMenu("2_clientes");
  // Variables necesarias
  int dinero = atoi(credito.c_str()), opcion;

  while(true) {
    enfocarElemento("2_clientes", 0);
    cin >> opcion;
    if (opcion >= 1 && opcion <= 5) {
      switch(opcion) {
        case 1:
          menu::rentas();     break;
        case 2:
          menu::comprar();    break;
        case 3:
          menu::membresias(); break;
        case 4:
          menu::catalogo();   break;
        case 5:
          menu::miCredito();  break;
      } // Fin de lanzar menú correspondiente
    } else if (opcion == 6) {
      break; // Salir del ciclo infinito
    } else { // Opción inválida
      mostrarError("clientes_opcion_equivocada");
    } // Fin de comprobar error de capa 8
  } // Fin de ciclo infinito
} // Fin de menú de clientes

void empleados() {
  dibujarMenu("3_empleados");
  getch();
} // Fin de menú de empleados

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
      if (esDireccional(tecla)) { // Der-Izq-Tab
        direccion = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento("1_principal_login", orden[direccion][input]);
        input = orden[direccion][input];
        if (input == 0){ usuario.clear(); }
        else if (input == 1){ password.clear(); }
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
            menu::empleados(); break;
          } else if (credenciales[2].compare("cliente") == 0) {
            menu::clientes(credenciales[0], credenciales[3]);
            break; // Salir de la función
          } // Fin de llevar al menú correspondiente

          credenciales.clear(); usuariosTemporales.clear();
        } // Fin de dar pase si tiene permiso
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("1_principal");
} // Fin de autenticar usuario

void registro() {
  dibujarMenu("1_principal_registro");
  // Variables para los valores del input
  string usuario, clave, claveRepetida; char tecla;
  string nuevoUsuario; 
  /* input 0 => Usuario             input 1 => Contraseña
     input 2 => Repetir clave       input 3 => Btn 'Listo'
     orden => [0: der - 1: izq - 2: arr - 3: abj]       */
  int orden[4][4] = {{1,2,3,0},{3,0,1,2},{1,0,3,2},{1,0,3,2}};
  int direccion, input = 0; bool registroValido;

  while(tecla != 27) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) {
        direccion = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento("1_principal_registro", orden[direccion][input]);
        input = orden[direccion][input];
        switch(input) {
          case 0: usuario.clear(); break;
          case 1: clave.clear(); break;
          case 2: claveRepetida.clear(); break;
        } // Fin de limpiar cadenas
      } else if (esAlfaNum(tecla) // Tecla es alfanumérica
      && input != 3 // No es el botón 'Listo'
      && usuario.length() < 18 && clave.length() < 18
      && claveRepetida.length() < 18 /* Limitar longitud */) {
        switch(input) {
          case 0: // Usuario
            gotoxy(23,12); usuario += tecla; cout << usuario;
            gotoxy(23+usuario.length(),12); break;
          case 1: // Contraseña
            gotoxy(23,17); clave += tecla; cout << clave;
            gotoxy(23+clave.length(),17); break;
          case 2: // Repetir contraseña
            gotoxy(50,12); claveRepetida += tecla; cout <<claveRepetida;
            gotoxy(50+claveRepetida.length(),12); break;
        } // Fin de capturar datos
      } else if (tecla == 8 || tecla == 224) { // 'BCKSP'-'DEL'
        switch(input) {
          case 0: // Usuario
            enfocarElemento("1_principal_registro", 0);
            usuario.clear(); break;
          case 1: // Contraseña
            enfocarElemento("1_principal_registro", 1);
            clave.clear(); break;
          case 2: // Contraseña
            enfocarElemento("1_principal_registro", 2);
            claveRepetida.clear(); break;
        } // Fin de resetear inputs actuales
      } else if (tecla == 13 && input == 3) {
        // Al presionar 'ENTER' registrar al nuevo usuario
        registroValido = /* validar formulario */
          ( nombreDisponible(usuario) &&
            clave.compare(claveRepetida) == 0 &&
            usuario.length() >= 6 &&
            clave.length() >= 6 );

        // Si el formulario es válido, registrar usuario
        if (registroValido) {
          // Ensamblar el nuevo registro
          nuevoUsuario = usuario + ";" + clave + ";cliente;0";
          // Insertarlo en la base de datos
          insertarRegistro("usuarios.txt", nuevoUsuario);
          system("cls"); cout << "Registro completado";
        } else {
          system("cls"); cout << "Registro invalido";
        } // Fin de verificar el envío de datos
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("1_principal");
} // Fin de agregar nuevos clientes
} // Fin de namespace menu::función