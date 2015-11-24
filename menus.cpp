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
    string usuario, password;
    vector<string> usuarioEncontrado;
    // input 1 = Nombre de usuario | input 2 = Contraseña
    int input = 1; char tecla;

    while(tecla != 27) { // Tecla NO es 'ESC'
      tecla = getch();
      if(tecla == 0) { tecla = getch(); } else {
        if (tecla == 77 || tecla == 75) { // Derecha
          switch(input) {
            case 1:
              enfocarElemento("1_principal_login", 2);
              input = 2; break;
            case 2:
              enfocarElemento("1_principal_login", 3);
              input = 3; break;
            case 3:
              enfocarElemento("1_principal_login", 1);
              input = 1; break;
          } // Fin de enfocar inputs
        } else if (esAlfaNum(tecla) && input != 3) {
          cout << char(tecla);
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