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
    // pide usuario y clave
    dibujarMenu("1_principal_login");
    getch();
    dibujarMenu("1_principal");
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