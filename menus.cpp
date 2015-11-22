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
        switch(tecla) {
          case 77: // Derecha
            switch(input) {
              case 1:
                enfocarElemento("1_principal_login", 2);
                input = 2; break;
              case 2:
                enfocarElemento("1_principal_login", 1);
                input = 1; break;
            }
          break;

          case 75: // Izquierda
            switch(input) {
              case 1:
                enfocarElemento("1_principal_login", 2);
                input = 2; break;
              case 2:
                enfocarElemento("1_principal_login", 1);
                input = 1; break;
            }
          break;
        }
      }
    }

    getch(); dibujarMenu("1_principal");
  }

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