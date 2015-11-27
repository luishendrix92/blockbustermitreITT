namespace menu {
  void empleados() {
    // modificar y agregar peliculas
  }

  void comprar() {
    // quitar pelicula si 'stock = 0'
  }

  void credito() {
    // modificar o agregar dinero a la cuenta
  }

  void catalogo() {
    // elegir categoria
  }

  void principal() {
    // dar opcion crear cuenta o hacer login
  }

  void registro() {
    // pide usuario, clave 2 veces, valida y guarda
    dibujarMenu("1_principal_registro");
    getch();
    dibujarMenu("1_principal");
  }

  void login() {
    dibujarMenu("1_principal_login");
    // Variables para los valores del input
    string usuario, password; char tecla;
    vector<string> usuarioEncontrado;
    /* input 0 => Usuario
       input 1 => Contraseña
       input 2 => Botón Log-In
       orden => [0: der - 1: izq] */
    int input = 0, orden[2][3] = {{1,2,0},{2,0,1}};
    int direccion; // 0: der - 1: izq

    while(tecla != 27) { // Tecla NO es 'ESC'
      tecla = getch();
      if (tecla == 0) { tecla = getch(); } else {
        if (tecla == 77 || tecla == 75) { // Izq-Der
          direccion = obtenerDireccion(tecla);
          // Enfocar y resetear inputs
          enfocarElemento("1_principal_login", 
          orden[direccion][input]);
          if (input==0){ usuario.clear(); }
          else if (input==1){ password.clear(); }
          input = orden[direccion][input];
        } else if (esAlfaNum(tecla)
          && input != 2 // No el botón
          && usuario.length() < 18
          && password.length() < 18) {
          switch(input) {
            case 0: // Usuario
              gotoxy(23,12); usuario += tecla;
              cout << usuario;
              gotoxy(23+usuario.length(),12); break;
            case 1: // Contraseña
              gotoxy(49,12); password += tecla;
              cout << password;
              gotoxy(49+password.length(),12); break;
          } // Fin de capturar datos
        } else if (tecla == 13) { // 'ENTER'
          // Grabar datos
        } // Fin de reaccionar a teclas
      } // Fin de detectar tecla válida
    } // Fin de ciclar hasta presionar 'ESC'
    dibujarMenu("1_principal");
  } // Fin de autenticar usuario

  void menuClientes() {
    // elegir opciones de cliente
  }

  void rentas() {
    // rentar películas
  }

  void membresias() {
    // capturar datos de usuario
  }
} // Fin de namespace menu::función