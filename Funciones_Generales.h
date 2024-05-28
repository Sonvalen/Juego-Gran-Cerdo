#ifndef FUNCIONES_GENERALES_H_INCLUDED
#define FUNCIONES_GENERALES_H_INCLUDED


void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

void tirarDados(int dados[], int cantidadDeDados) {
    for (int i = 0; i < cantidadDeDados; ++i) {
        dados[i] = rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6
    }
}
void graficarDado(int numero) {
    switch(numero) {
        case 1:
            cout << " ------ " << endl;
            cout << "|      |" << endl;
            cout << "|   *  |" << endl;
            cout << "|      |" << endl;
            cout << " ------ " << endl;
            break;
        case 2:
             cout << " ------ " << endl;
            cout << "|*     |" << endl;
            cout << "|      |" << endl;
            cout << "|     *|" << endl;
            cout << " ------ " << endl;
            break;
        case 3:
             cout << " ------ " << endl;
            cout << "| *    |" << endl;
            cout << "|   *  |" << endl;
            cout << "|     *|" << endl;
            cout << " ------ " << endl;
            break;
        case 4:
             cout << " ------ " << endl;
            cout << "| *  * |" << endl;
            cout << "|      |" << endl;
            cout << "| *  * |" << endl;
            cout << " ------ " << endl;
            break;
        case 5:
            cout << " ------ " << endl;
            cout << "| *  * |" << endl;
            cout << "|   *  |" << endl;
            cout << "| *  * |" << endl;
            cout << " ------ " << endl;
            break;
        case 6:
            cout << " ------ " << endl;
            cout << "| *  * |" << endl;
            cout << "| *  * |" << endl;
            cout << "| *  * |" << endl;
            cout << " ------ " << endl;
            break;
    }
}

#endif // FENCIONES_GENERALES_H_INCLUDED
