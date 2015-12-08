namespace menu {
void tutorial() {
  dibujarMenu("2.1_tutorial_f1");
  esperarRespuesta("2.1_tutorial_f2");
  esperarRespuesta("2_clientes");
  system("color 1F");
} // Fin de rentar películas

/* =======================================================
|||||||||||           B U S C A D O R          |||||||||||
========================================================*/
void opcionesPelicula(
  int i, vector<string> pelicula, string usuario
) { // Fin de recibir datos del menú anterior
  subMenuOpciones(i);
  int dir, btn = 0; char tecla; string expir;
  int orden[4][3] = {{1,2,0},{2,0,1},{2,0,1},{1,2,0}};
  bool rentaExitosa, compraExitosa, accion = false;

  while(tecla != ESC && tecla != ARR && tecla != ABJ) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) {
        dir = obtenerDireccion(tecla);
        enfocarElemento(
          "submenu_opciones", orden[dir][btn], i
        ); // Fin de enfocar inputs
        btn = orden[dir][btn];
      } else if (tecla == ENTER) {
        switch(btn) {
          case 0: // Sinopsis
            mostrarSinopsis(pelicula);
            break;

          case 1: // Rentar
            rentaExitosa = rentarPelicula(
              pelicula[ID], usuario
            ); // Fin de ver si se concretó

            if(rentaExitosa) {
              expir = cuandoExpira(1); // En 1 mes
              mostrarAviso(
                "renta_pelicula", expir, "2.2_buscador_f2"
              ); // Fin de mostrar aviso de éxito
            } else {
              mostrarError("renta_fallida");
            } // Fin de desplegar mensajes
            break;

          case 2: // Comprar
            compraExitosa = comprarPelicula(
              pelicula[ID], usuario
            ); // Fin de ver si se concretó la renta
            if(compraExitosa) {
              mostrarAviso("compra_pelicula");
            } else {
              mostrarError(
                "compra_fallida", "peli_busc", usuario,
                atoi(pelicula[PRECIO].c_str())
              ); // Fin de mostrar error
            } // Fin de desplegar mensajes
            break;
        } // Fin de lanzar sub-menú
        tecla  = ESC; // Salir del sub-menú
        accion = true;
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  
  if (!accion) { limpiarZona("resultados"); }
} // Fin de mostrar submenú al dar ENTER

void listado(
  vector<vector<string> > resultados, string usuario
) { // Fin de recibir datos del menú anterior
  dibujarMenu("2.2_buscador_f2");
  /*-------------------------------------------------*/
  #define INICIO   0
  /*-------------------------------------------------*/
  char tecla; int puntero = 0, dir,
  nPeliculas = resultados.size(); 
  /*------------- FIN DE VARIABLES NECESARIAS -------*/

  detallesDeLaPelicula( // Enviar el 1er resultado
    unirRegistro(resultados[0], ";"), "listado"
  ); // Fin de mostrar los detalles de la 1era
  listarResultados(resultados);

  while(tecla != ESC) { // Tecla NO es 'ESC'
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) {
        dir = obtenerDireccion(tecla);
        switch(dir) {
          case 2: // Arriba
            if (puntero == INICIO) {
              /* Primer película en la lista, te lleva a
              la última película del listado          */
              puntero  = nPeliculas - 1;
            } else { /* La película no la primera */
              puntero -= 1;
            } // Fin de actuar conforme al puntero
            break;
          case 3: // Abajo
            if (puntero == nPeliculas - 1) {
              /* Última película en la lista, te lleva a
              la primera película del listado         */
              puntero  = INICIO;
            } else { /* La película no la última */
              puntero += 1;
            } // Fin de actuar conforme al puntero
            break;
        } // Fin de controlar flechas
        // Localizar y enfocar  el puntero '>'
        detallesDeLaPelicula(
          unirRegistro(resultados[puntero],";"),"listado"
        ); // Fin de mostrar los detalles de película
        moverCursor(puntero);
      } else if (tecla == ENTER) {
        /*sub*/menu::opcionesPelicula(// Enviar el cursor
          puntero, resultados[puntero], usuario
        ); // Fin de mostrar las 3 opciones
        detallesDeLaPelicula(
          unirRegistro(resultados[puntero],";"),"listado"
        ); // Fin de mostrar los detalles de película
        listarResultados(resultados);
        moverCursor(puntero);
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("2.2_buscador");
} // Fin de manejar resultados de búsqueda

void buscador(string usuario) {
  dibujarMenu("2.2_buscador");
  int dir, input = 0; char tecla; string peliBuscada;
  vector<vector<string> > peliculas, resultados;
  int orden[4][2] = {{1,0},{1,0},{1,0},{1,0}};

  #define MAX    13
  #define INI_Y  6

  // Descargar toda la tabla 'Películas'
  peliculas = descargarTabla("peliculas.txt");
  int nPeliculas = peliculas.size();

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) {
        dir = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento(
          "2.2_buscador", orden[dir][input]
        ); // Fin de enfocar inputss
        input = orden[dir][input];
        switch(input) {
          case 0: peliBuscada.clear(); break;
        } // Fin de resetear inputs
      } else if ((esAlfaNum(tecla)||tecla==32) && input != 1) {
        if (peliBuscada.length() < 59) {
          gotoxy(6,2); // Ir a la raíz del input
          peliBuscada += tecla;
          cout << peliBuscada;

          // Mostrar las que coincidan con el criterio
          limpiarZona("resultados");
          for (int i=0, encontradas=0; i<nPeliculas; i+=1) {
            string titulo = peliculas[i][TITULO];
            if(encontrarTexto(peliBuscada, titulo)) {
              gotoxy(6, INI_Y + encontradas);
              cout << titulo;
              encontradas += 1;
            } // Fin de evaluar coincidencia
            if(encontradas == MAX) { break; }
          } // Fin de mostrar hasta 13 películas

          gotoxy(6 + peliBuscada.length(), 2);
        } // Fin de no sobrepasarse de 59 caracteres
      } else if (tecla == BCKSP || tecla == DEL) {
        // Limpiar cuadros de texto
        enfocarElemento("2.2_buscador", input);
        switch(input) {
          case 0: peliBuscada.clear();       break;
        } // Fin de resetear inputs actuales
      } else if (tecla == ENTER) {
        if(peliBuscada.length()) {
          for (int i = 0, j=0; i < nPeliculas; i += 1) {
            string titulo = peliculas[i][TITULO];
            if(encontrarTexto(peliBuscada, titulo)) {
              resultados.push_back(peliculas[i]);
              j = j + 1; // Aumentar contador
            } // Fin de evaluar coincidencia
            if(j == MAX) { break; } // Limitar a 13
          } // Fin de meter resultados en el arreglo
          if(resultados.size()) {
            menu::listado(resultados, usuario);
            resultados.clear();
          } // Fin de prevenir arreglo vacío
        } else { // No se especificó criterio
          //
        } // Fin de evitar enviar algo sin criterio
        peliBuscada.clear();    input = 0 ;
        enfocarElemento("2.2_buscador", 0);
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("2_clientes");
} // Fin de busqueda en tiempo real

/* =======================================================
|||||||||||         M E M B R E S Í A S        |||||||||||
========================================================*/
void membresiasControl(string usuario) {
  dibujarMenu("2.3_membresias_ctrl");
  char tecla; int dir, duracionMemb = 6, btn = 0;
  int orden[4][3] = {{1,2,0},{2,0,1},{1,0,0},{1,0,0}};

  #define COSTO_RENOV 250

  mostrarDetallesMembresia(usuario);

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) {
        dir = obtenerDireccion(tecla);
        enfocarElemento(
          "2.3_membresias_ctrl", orden[dir][btn]
        ); // Fin de enfocar inputs
        btn = orden[dir][btn];
      } else if (tecla == ENTER) {
        switch(btn) {
          case 0: // Devolver películas
            /* Por falta de tiempo no completamos esto
            así que decidimos devolver las 3 películas */
            devolverPeliculas(usuario);
            mostrarAviso("pelis_devueltas");
            mostrarDetallesMembresia(usuario);
            btn = 0;
            break;
          case 1: // Darse de baja
            darDeBaja(usuario);
            mostrarAviso("baja_miembro");
            tecla = ESC; // Salir
            break;
          case 2: // Renovar membresía
            if (realizarGasto(usuario, COSTO_RENOV)) {
              // Si se pudo cobrar, arenovar
              renovarMembresia(usuario);
              mostrarAviso("renov_exitosa");
            } else { // No tiene suficiente dinero
              mostrarError(
                "compra_fallida","suscr",usuario,COSTO_RENOV
              ); // Fin de mensaje de error
            } // Fin de comprobar gasto exitoso
            dibujarMenu("2.3_membresias_ctrl");
            mostrarDetallesMembresia(usuario);
            btn = 0;
            break;
        } // Fin de lanzar sub-menú
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
} // Fin de panel de control de membresía

void membresiasAfiliacion(string usuario) {
  dibujarMenu("2.3_membresias_afil");
  char tecla; int dir, duracionMemb = 6, boton = 3;
  int orden[4][2] = {{3,4},{3,4},{3,4},{3,4}};

  #define INFO       1
  #define CONTRATO   2
  #define COSTO_MEMB 250

  string expiracion = cuandoExpira(duracionMemb);
  mostrarAviso("expiracion_membresia", expiracion);

  while(tecla != ESC) { // Paso 2
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (tecla == ENTER) {
        enfocarElemento("2.3_membresias_afil", INFO);
        break; // Pasar al siguiente paso
      } // Fin de esperar 'ENTER'
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'

  while(tecla != ESC) { // Paso 3
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (tecla == 13) { // 'ENTER'
        enfocarElemento("2.3_membresias_afil", CONTRATO);
        break; // Pasar al siguiente paso
      } // Fin de esperar 'ENTER'
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'

  while(tecla != ESC) { // Paso 4
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (tecla == ENTER) {
        switch(boton) {
          case 3: // Afiliarme
            if (realizarGasto(usuario, COSTO_MEMB)) {
              // Si se pudo cobrar, afiliarse
              nuevaMembresia(usuario, expiracion);
              mostrarAviso("suscripcion_exitosa", usuario);
              finalFantasy(0.7);
            } else { // No tiene suficiente dinero
              mostrarError(
                "compra_fallida","suscr",usuario,COSTO_MEMB
              ); // Fin de mensaje de error
            } break; // Fin de comprobar gasto exitoso
        } // Fin de presionar botón
        tecla = ESC; // Volver al menú clientes
      } else if (esDireccional(tecla)) {
        dir = obtenerDireccion(tecla);
        enfocarElemento(
          "2.3_membresias_afil", orden[dir][boton]
        ); // Fin de enfocar botones
        boton = orden[dir][boton];
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
} // Fin de complemento menu::membresias

void membresias(string usuario) {
  int dir, btn = 0; char tecla;
  int orden[4][2] = {{1,0},{1,0},{1,0},{1,0}};

  if (tieneMembresia(usuario)) {
     menu::membresiasControl(usuario);
     tecla = ESC; // Previene opción de afiliarse
  } else { // No está afiliado aún
    dibujarMenu("2.3_membresias_nuevo");
  } // Fin de revisar si ya está afiliado

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) {
        dir = obtenerDireccion(tecla);
        enfocarElemento(
          "2.3_membresias_nuevo", orden[dir][btn]
        ); // Fin de enfocar inputs
        btn = orden[dir][btn];
      } else if (tecla == ENTER) {
        switch(btn) {
          case 0: // Afiliarme
            menu::membresiasAfiliacion(usuario);
            tecla = ESC; // Volver al menú anterior
          break;

          case 1: // Reglas
            dibujarMenu("2.3_membresias_reglas");
            tecla = 0; // Para entrar en el ciclo
            while(tecla != ENTER) {
              tecla = getch();
              if (tecla == ENTER) {
                dibujarMenu("2.3_membresias_nuevo");
                btn = 0; // Resetear elección
              } // Fin de aceptar
            } // Fin de esperar tecla ENTER
          break;
        } // Fin de lanzar sub-menú
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("2_clientes");
} // Fin de suscribirse a membresía

/* =======================================================
|||||||||||           C R É D I T O            |||||||||||
========================================================*/
void abonar(string usuario) {
  dibujarMenu("2.5_credito_f2");
  int dir, input = 0, abono = 0; char tecla;
  bool paraDonar = false; string beneficiario, monto;
  int orden[4][5] = {{3,3,3,4,0}, {4,0,1,2,3},
  {3,4,0,2,1}, {2,2,3,0,1}};

  // Mostrar el usuario y su crédito en pantalla
  mostrarCredito(usuario); gotoxy(37,10);

  while (tecla != ESC) {
    tecla = getch();
    if(tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla) || (tecla == ENTER &&
         (input != 4 && input != 3 && input != 2))) {
        dir = obtenerDireccion(tecla);
        /* Prevenir el enfoque del campo de texto
        'beneficiario' si no se ha marcado esa opción */
        if (!paraDonar && orden[dir][input] == 1) {
          input = orden[dir][input];
        } // Fin de comprobar el checkbox
        enfocarElemento(
          "2.5_credito_f2", orden[dir][input]
        ); // Fin de enfocar inputs
        input = orden[dir][input];
        switch(input) {
          case 0: monto.clear();         break;
          case 1: beneficiario.clear();  break;
        } // Fin de resetear inputs
      } else if (esAlfaNum(tecla) &&
      input != 2 && input != 3 & input != 4)       {
        switch(input) {
          case 0: // Cuadro de texto: Monto abonado
            if (monto.length() < 4 && esNumerica(tecla)) {
              gotoxy(37,10); monto += tecla; cout << monto;
              gotoxy(37+monto.length(),10);
            } break;
          case 1: // Cuadro de texto: Beneficiario
            if (beneficiario.length() < 18) {
              gotoxy(52,10); beneficiario += tecla;
              cout << beneficiario;
              gotoxy(52+beneficiario.length(),10);
            } break;
        } // Fin de capturar datos
      } else if (tecla == BCKSP || tecla == DEL)    {
        // Limpiar cuadros de texto
        enfocarElemento("2.5_credito_f2", input);
        switch(input) {
          case 0: monto.clear();         break;
          case 1: beneficiario.clear();  break;
        } // Fin de resetear inputs
      } else if (tecla == ENTER) { // 'ENTER'
        switch(input) {
          case 2: // Checkbox 'Regalar Crédito'
            activarBeneficiario(paraDonar);
            paraDonar = !paraDonar;
            if (paraDonar) {
              orden[0][0]=1; orden[0][1]=3; orden[0][2]=3;
              orden[0][3]=4; orden[0][4]=0;
              input = 1; // Beneficiario
              enfocarElemento("2.5_credito_f2", input);
            } else {
              orden[0][0]=3; orden[0][1]=3; orden[0][2]=3;
              orden[0][3]=4; orden[0][4]=0;
            } // Fin de moverse al 'beneficiario'
            beneficiario.clear();        break;

          case 3: // Botón 'Abonar'
            abono = atoi(monto.c_str());
            bool benefExiste, esEmpleado;

            if (!monto.length() || abono == 0) {
              mostrarAviso(
                "form_invalido", "monto", "2.5_credito_f2"
              ); // Fin de error, formulario inválido
            } // Fin de notificar abono $0

            // Ver si el abono es para regalar o no
            if (paraDonar && abono > 0) {
              if (!beneficiario.length()) {
                mostrarAviso(
                  "form_invalido","benef","2.5_credito_f2"
                ); // Fin de error, formulario inválido
              } else {
                benefExiste = consultaRapida(
                  "usuarios.txt", NOMBRE, beneficiario, NOMBRE
                ).compare(beneficiario) == 0;
                esEmpleado  = consultaRapida(
                  "usuarios.txt", NOMBRE, beneficiario, ROL
                ).compare("empleado")   == 0;

                if (benefExiste && !esEmpleado) {
                  abonarCredito(beneficiario, abono);
                  mostrarAviso("abono_regalo", beneficiario);
                  paraDonar = false;
                } else { // El beneficiario no tiene cuenta
                  mostrarError("benef_error");
                } // Fin de ver si el beneficiario existe
              } // Fin de pedir un beneficiario
            } else if (abono > 0) {
              // El crédito es para el usuario
              abonarCredito(usuario, abono);
            } // Fin de ver a quién abonar el crédito

            mostrarCredito(usuario);

            /* Si hubo algún error a la hora de abonar
            a un beneficiario, pedirlo de nuevo, si no,
            lhaya que resetear todos los campos */
            if (paraDonar) {
              input = 1;
              activarBeneficiario(false);
              gotoxy(37,10); cout<<monto;
            } else { // Proceso exitoso
              input = 0;
              abono = 0;
              monto.clear();
            } // Fin de limpiar lo necesario

            enfocarElemento("2.5_credito_f2", input);
            beneficiario.clear();
          break;

          case 4: // Botón 'Cancelar'
            tecla = ESC; break; // Salir
        } // Fin de asignar comportamiento a botones
      } // Fin de reaccionar a teclas
    } // Fin de selección de tecla
  } // Fin de pedir tecla y terminar al presionar 'ESC'
} // Fin de abonar a mi cuenta o la de otros

void miCredito(string usuario) {
  dibujarMenu("2.5_credito");
  int orden[4][2] = {{1,0},{1,0},{1,0},{1,0}};
  int dir, boton = 0; char tecla;

  // Mostrar el usuario y su crédito en pantalla
  mostrarCredito(usuario); gotoxy(39,10);

  while (tecla != ESC) {
    tecla = getch();
    if(tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) {
        // Desplazarse entre botones
        dir = obtenerDireccion(tecla);
        enfocarElemento("2.5_credito", orden[dir][boton]);
        boton = orden[dir][boton];
      } else if (tecla == ENTER) {
        switch(boton) {
          case 0: menu::abonar(usuario);      boton=0;
          tecla = ESC;                        break;
          case 1: tecla = ESC;                break;
        } // Fin de lanzar menú adecuado
      } // Fin de reaccionar a teclas
    } // Fin de selección de tecla
  } // Fin de pedir tecla y terminar al presionar 'ESC'
  dibujarMenu("2_clientes");
} // Fin de manejar dinero en la cuenta

/* =======================================================
|||||||||||          C A T Á L O G O           |||||||||||
========================================================*/
void opcionesEnCatalogo(string idPeli, string usuario) {
  ventanaOpciones(idPeli);
  int dir, boton = 1; char tecla; string expir;
  int precioPeli = atoi(consultaRapida(
    "peliculas.txt", ID, idPeli, PRECIO
  ).c_str()); // Fin de almacenar el precio
  bool rentaExitosa, compraExitosa;
  int orden[4][3] = {{1,2,0},{1,0,1},{2,0,0},{2,0,0}};

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) {
        // Desplazarse entre botones
        dir = obtenerDireccion(tecla);
        enfocarElemento(
          "ventana_opciones", orden[dir][boton]
        ); // Fin de enfocar elemento
        boton = orden[dir][boton];
      } else if (tecla == ENTER) {
        switch(boton) {
          case 2: // Rentar
            rentaExitosa=rentarPelicula(idPeli, usuario);

            if(rentaExitosa) {
              expir = cuandoExpira(1); // En 1 mes
              mostrarAviso(
                "renta_pelicula", expir, "null"
              ); // Fin de mensaje de éxito
            } else {
              mostrarError("renta_fallida", "catalogo");
            } break; // Fin de desplegar mensajes

          case 1: // Comprar
            compraExitosa = comprarPelicula(
              idPeli, usuario
            ); // Fin de ver si se concretó la renta
            if(compraExitosa) {
              mostrarAviso("compra_pelicula", "catalogo");
            } else {
              mostrarError(
                "compra_fallida", "catalogo", usuario,
                precioPeli
              ); // Fin de mostrar error
            } break; // Fin de desplegar mensajes
        } // Fin de lanzar sub-menú
        tecla = ESC; // Salir
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("2.4_catalogo_f2");
} // Fin de ventana con opciones

void catalogoFrame2(string usuario, int gnrId) {
  dibujarMenu("2.4_catalogo_f2");
  /*-------------------------------------------------*/
  #define GENERO   3
  #define FILAS    11
  #define INICIO   0
  #define LISTA    0
  #define PUNTEROS 1
  /*-------------------------------------------------*/
  vector<string> peliculas ; /* Tabla filtrada */
  vector<string> peliActual;
  string genero = obtenerGenero(gnrId);
  peliculas = filtrarRegistros(
    "peliculas.txt", GENERO, genero
  ); // Consulté la dB para traer las pelis del género
  int puntero = 0, direccion, pagActual = 0; char tecla;
  /*------------- FIN DE VARIABLES NECESARIAS ------------*/

  // Poner género en el título del menú
  gotoxy(41,2); cout << genero; gotoxy(4,4);

  // Mostrar las películas en pantalla
  if (peliculas.size() > 0) { // Hay películas
    // Desplegar la primera página
    mostrarPagina(peliculas, pagActual);
    detallesDeLaPelicula(peliculas[puntero]);
    
    vector<vector<int> > pags = paginacion(
      peliculas.size(), FILAS
    ); // Fin de obtener rol de páginas

    // Manejo de teclas 'ESC', Arriba', 'Abajo' y 'ENTER'
    while(tecla != ESC) { // Tecla NO es 'ESC'
      tecla = getch(); int direccion;
      if (tecla == 0) { tecla = getch(); } else {
        if (esDireccional(tecla))  {
          int final = pags[pags.size()-1][1];
          direccion = obtenerDireccion(tecla);

          switch(direccion) {
            case 0: // Derecha
            case 3: // Abajo
              if (puntero == final)                     {
                limpiarZona("2.4_catalogo_f2", LISTA);
                /* Última película en la lista, te lleva a
                la primera página y película del listado */
                puntero = INICIO; pagActual = 0;
                mostrarPagina(peliculas, pagActual);
              } else if (puntero == pags[pagActual][1]) {
                limpiarZona("2.4_catalogo_f2", LISTA);
                /* Última película en la página, te lleva
                a la primer peli del menú siguiente    */
                puntero = pags[pagActual + 1][0];
                pagActual += 1;
                mostrarPagina(peliculas, pagActual);
              } else                                    {
                /* La película no es ni la primera
                ni la última en la lista        */
                limpiarZona("2.4_catalogo_f2", PUNTEROS);
                puntero += 1;
              } // Fin de actuar conforme al puntero
            break;

            case 1: // Izquierda
            case 2: // Arriba
              if (puntero == 0)                         {
                limpiarZona("2.4_catalogo_f2", LISTA);
                /* Primer película en la lista, te lleva a
                la última película y a la última página */
                puntero=final; pagActual = pags.size()-1;
                mostrarPagina(peliculas, pagActual);
              } else if (puntero == pags[pagActual][0]) {
                limpiarZona("2.4_catalogo_f2", LISTA);
                /* Primer película en la página, te lleva
                a la última peli del menú anterior     */
                puntero = pags[pagActual-1][1];
                pagActual -= 1;
                mostrarPagina(peliculas, pagActual);
              } else                                    {
                /* La película no es ni la primera
                ni la última en la lista        */
                limpiarZona("2.4_catalogo_f2", PUNTEROS);
                puntero -= 1;
              } // Fin de actuar conforme al puntero
            break;
          } // Fin de controlar flechas
          // Localizar y enfocar  el puntero '>'
          detallesDeLaPelicula(peliculas[puntero]);
          moverPuntero(puntero, pagActual)        ;
        } else if (tecla == ENTER) {
          peliActual=separarLinea(peliculas[puntero], ';');
          menu::opcionesEnCatalogo(peliActual[ID],usuario);
          mostrarPagina(peliculas, pagActual)             ;
          detallesDeLaPelicula(peliculas[puntero])        ;
          limpiarZona("2.4_catalogo_f2", PUNTEROS)        ;
          moverPuntero(puntero, pagActual)                ;
        } // Fin de reaccionar a teclas
      } // Fin de detectar tecla válida
    } // Fin de ciclar hasta presionar 'ESC'
  } else { // No hay películas
    mostrarError("lista_vacia");
  } // Fin de ver si hay películas

  dibujarMenu("2.4_catalogo_f1");
} // Fin de detalles de películas

void catalogo(string usuario) {
  dibujarMenu("2.4_catalogo_f1");
  // Variables para los valores del input
  char tecla; int dir, boton = 0;
  /*-------------------------------------------------*\
  |  0 => Horror    3  => Aventura    6 => Comedia    |
  |  1 => Sci-Fi    4  => Acción      7 => Romance    |
  |  2 => Drama     5  => Biografía   8 => Documental |
  |  9 => Estrenos  10 => En remate                   |
  \*-------------------------------------------------*/
  int orden[4][11] = {{1,2,3,4,5,6,7,8,9,10,0},
  {10,0,1,2,3,4,5,6,7,8,9},{5,9,9,10,8,0,1,3,4,6,7},
  {5,6,7,7,8,9,9,10,10,1,3}};

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if (esDireccional(tecla)) { // Der-Izq-Tab
        // Desplazarse entre botones
        dir = obtenerDireccion(tecla);
        enfocarElemento(
          "2.4_catalogo_f1", orden[dir][boton]
        ); // Fin de enfocar elemento
        boton = orden[dir][boton];
      } else if (tecla == ENTER) {
        menu::catalogoFrame2(usuario, boton);
        boton = 0; // Re-Enfocar el primer botón
        enfocarElemento("2.4_catalogo_f1", 0);
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("2_clientes");
} // Fin de catálogo de películas

/* =======================================================
|||||||||||      C R E D E N C I A L E S       |||||||||||
========================================================*/
void clientes(string usuario) {
  dibujarMenu("2_clientes"); int opcion;

  while(true) {
    enfocarElemento("2_clientes", 0);
    cin >> opcion;
    if (opcion >= 1 && opcion <= 5) {
      switch(opcion) {
        case 1: menu::tutorial();           break;
        case 2: menu::buscador(usuario);    break;
        case 3: menu::membresias(usuario);  break;
        case 4: menu::catalogo(usuario);    break;
        case 5: menu::miCredito(usuario);   break;
      } // Fin de lanzar menú correspondiente
    } else if (opcion == 6) {
      break; // Salir del ciclo infinito
    } else { // Opción inválida
      mostrarError("opcion_equivocada");
    } // Fin de comprobar error de capa 8
  } // Fin de ciclo infinito
} // Fin de menú de clientes

void empleados() {
  dibujarMenu("3_empleados");
  getch();
} // Fin de menú de empleados

/* =======================================================
|||||||||||   L O G - I N  /  R E G I S T R O  |||||||||||
========================================================*/
void login() {
  dibujarMenu("1_principal_login");
  // Variables para los valores del input
  string usuario, password, credenciales; char tecla;
  int input = 0, // Selector de botón o caja de texto
      orden[4][3] = {{1,2,0},{2,0,1},{2,0,1},{1,2,0}},
      dir /* Dirección */; bool tienePermiso;

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if ( /* Direccional o ENTER sin estar en el botón */
        esDireccional(tecla) ||
        (tecla == ENTER && input != 2)
      ) {  /* Direccional o ENTER sin estar en el botón */
        dir = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento(
          "1_principal_login", orden[dir][input]
        ); // Fin de enfocar inputs
        input = orden[dir][input];
        // Limpiar cadenas de texto
        switch(input) {
          case 0: usuario.clear();           break;
          case 1: password.clear();          break;
        } // Fin de limpiar cadenas
      } else if (esAlfaNum(tecla) && input != 2 ){
        switch(input) {
          case 0: // Usuario
            if (usuario.length() < 18)  {
              gotoxy(23,12);
              usuario += tecla; cout << usuario;
              gotoxy(23+usuario.length(),12);
            } break;
          case 1: // Contraseña
            if (password.length() < 18) {
              gotoxy(49,12);
              password += tecla;
              cout << asteriscos(password);
              gotoxy(49+password.length(),12);
            } break;
        } // Fin de capturar datos
      } else if (tecla == BCKSP || tecla == DEL) {
        // Resetea y re-enfoca el cuadro de texto
        enfocarElemento("1_principal_login", input);
        switch(input) {
          case 0: usuario.clear();   break;
          case 1: password.clear();  break;
        } // Fin de resetear inputs actuales
      } else if (tecla == ENTER && input == 2)   {
        // Al presionar 'ENTER' validar y loguear
        tienePermiso = autenticar(usuario, password);
        if(tienePermiso) {
          credenciales = consultaRapida(
            "usuarios.txt", NOMBRE, usuario, ROL
          ); // Fin de almacenar el rol del usuario

          if (credenciales        == "empleado") {
            menu::empleados();       break;
          } else if (credenciales == "cliente")  {
            menu::clientes(usuario); break;
          } // Fin de llevar al menú correspondiente
        } else { // No tiene permiso
          mostrarError("login_fallo");
          usuario.clear(); password.clear();
          input = 0;
          enfocarElemento("1_principal_login", input);
        } // Fin de dar pase si tiene permiso
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("1_principal");
} // Fin de autenticar usuario

void registro() {
  dibujarMenu("1_principal_registro");
  // Variables para los valores del input
  string usuario, clave, claveRepetida, nuevoUsuario;
  /* input 0 => Usuario             input 1 => Contraseña
     input 2 => Repetir clave       input 3 => Btn 'Listo'
     orden   => [0: der - 1: izq - 2: arr - 3: abj]     */
  int orden[4][4] = {{1,2,3,0},{3,0,1,2},{1,0,3,2},{1,0,3,2}},
      dir, input = 0; bool registroValido; char tecla;

  while(tecla != ESC) {
    tecla = getch();
    if (tecla == 0) { tecla = getch(); } else {
      if ( /* Direccional o ENTER sin estar en el botón */
        esDireccional(tecla) ||
        (tecla == ENTER && input != 3)
      ) {  /* Direccional o ENTER sin estar en el botón */
        dir = obtenerDireccion(tecla);
        // Enfocar y resetear inputs
        enfocarElemento(
          "1_principal_registro", orden[dir][input]
        ); // Fin de enfocar inputs
        input = orden[dir][input];
        switch(input) {
          case 0: usuario.clear();       break;
          case 1: clave.clear();         break;
          case 2: claveRepetida.clear(); break;
        } // Fin de resetear inputs
      } else if (esAlfaNum(tecla) && input != 3) {
        switch(input) {
          case 0: // Usuario
            if (usuario.length() < 18) {
              gotoxy(23,12);
              usuario += tecla;
              cout << usuario;
              gotoxy(23+usuario.length(),12);
            } break;
          case 1: // Contraseña
            if (clave.length() < 18) {
              gotoxy(23,17);
              clave += tecla;
              cout << asteriscos(clave);
              gotoxy(23+clave.length(),17);
            } break;
          case 2: // Repetir contraseña
            if (claveRepetida.length() < 18) {
              gotoxy(50,12);
              claveRepetida += tecla;
              cout << asteriscos(claveRepetida);
              gotoxy(50+claveRepetida.length(),12);
            } break;
        } // Fin de capturar datos
      } else if (tecla == BCKSP || tecla == DEL) {
        // Limpiar cuadros de texto
        enfocarElemento("1_principal_registro", input);
        switch(input) {
          case 0: usuario.clear();       break;
          case 1: clave.clear();         break;
          case 2: claveRepetida.clear(); break;
        } // Fin de resetear inputs actuales
      } else if (tecla == ENTER && input == 3) {
        registroValido = (
          nombreDisponible(usuario) &&
          clave.compare(claveRepetida) == 0 &&
          usuario.length() >= 6 &&
          clave.length() >= 6
        ); // Fin de validar formulario

        // Si el formulario es válido, registrar usuario
        if (registroValido) {
          // Ensamblar el nuevo registro
          nuevoUsuario = usuario + ";"+clave+";cliente;0";
          // Insertarlo en la base de datos
          insertarRegistro("usuarios.txt", nuevoUsuario);
          mostrarAviso("registro_exitoso", usuario);
          finalFantasy(0.7);
          break; // Salir de este menú
        } else if (!nombreDisponible(usuario)) {
          input = 0; usuario.clear();
          mostrarError("nombre_no_disp", usuario);
        } else if (clave.compare(claveRepetida) != 0) {
          input = 1            ;
          clave.clear()        ;
          claveRepetida.clear();
          mostrarAviso(
            "form_invalido","claves","1_principal_registro"
          ); // Fin de error, formulario inválido
          enfocarElemento("1_principal_registro", 2);
        } else if (usuario.length()<6 || clave.length()<6) {
          mostrarAviso(
            "form_invalido", "inseg","1_principal_registro"
          ); // Fin de error, formulario inválido
          if(usuario.length() < 6 && clave.length() < 6) {
            input = 0    ;
            clave.clear(); usuario.clear();
            claveRepetida.clear()         ;
            enfocarElemento("1_principal_registro", 1);
            enfocarElemento("1_principal_registro", 2);
          } else if (clave.length() < 6) {
            input = 1    ;
            clave.clear(); claveRepetida.clear();
            enfocarElemento("1_principal_registro", 2);
          } else { // Usuario de corta longitud
            input = 0; usuario.clear();
          } // Fin de corregir lo que se necesite
        } // Fin de verificar el envío de datos

        // Mostrar datos conservados y corregir invalidez
        gotoxy(23,12); cout << usuario      ;
        gotoxy(23,17); cout << clave        ;
        gotoxy(50,12); cout << claveRepetida;
        enfocarElemento("1_principal_registro", input);
      } // Fin de reaccionar a teclas
    } // Fin de detectar tecla válida
  } // Fin de ciclar hasta presionar 'ESC'
  dibujarMenu("1_principal");
} // Fin de agregar nuevos clientes
} // Fin de namespace menu::función