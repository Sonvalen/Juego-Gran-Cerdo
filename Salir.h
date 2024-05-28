#ifndef SALIR_H_INCLUDED
#define SALIR_H_INCLUDED
///SALIR DE LA APLICACION DEL JUEGO
int Salir(int salir){
    char opc;
    while(true){
    cout<<"-----------------------------"<<endl;
    cout<<"  DESEA CERRAR EL JUEGO?"<<endl;
    cout<<" (precione s para SI/ precione n para NO)"<<endl;
    cin>>opc;
    if(opc=='s'){
        salir=0;
        return salir;
    }
    if(opc=='n'){
        return 1;
    }
    else{rlutil::setColor(rlutil::LIGHTRED);
    cout<<"    OPCION INCORRECTA "<<endl;}
    rlutil::setColor(rlutil::WHITE);
    system("pause");
    system("cls");
    }
}

#endif // SALIR_H_INCLUDED
