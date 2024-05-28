#ifndef RONDA_H_INCLUDED
#define RONDA_H_INCLUDED
#include "rlutil.h"
///FINALIZAR TURNO
bool Fin_del_Turno(int valorDeDadoJugador1[],int valorDeDadoJugador2[],int cantidadDeDados){
    bool Respuesta=false;
    char opc;
    int preguntar=0;

    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador2[i]==1){preguntar++;}
    else{preguntar--;}}
    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador1[i]==1){preguntar++;}
    else{preguntar--;}}
    if(preguntar==cantidadDeDados){
        rlutil ::anykey() ;
        return true;
        }else{while(Respuesta!=true){
            cout<<"  DESEA TERMINAR SU TURNO: "<<endl;
            cout<<" (precione s para SI/ precione n para NO)"<<endl;
            cin>>opc;
             system("cls");
            if(opc=='s'){return true;}
            if(opc=='n'){return false;}
            else{rlutil::setColor(rlutil::LIGHTRED);
                cout<<"   OPCION INCORRECTA "<<endl;
                rlutil::setColor(rlutil::WHITE);}
        }}
}

///MOSTRAR DADOS Y PUNTOS EN ESA TURNO

int Trufas_en_el_Turno(char NombreP1[],char NombreP2[],bool Empieza,int valorDeDadoJugador1[],int valorDeDadoJugador2[],int cantidadDeDados,int dados[],int Dirccion_de_trufas,int Barro[],int Oinks[],int Trufas_Totales_de_Jugador[]){
    int sumaDeDados=0;
    if(Dirccion_de_trufas==1){
        for (int i = 0; i < cantidadDeDados; ++i) {
                valorDeDadoJugador1[i] = dados[i];}
        cout << "Valores de los dados del Cerdito "<<NombreP1 << ": " << endl ;
        for (int i = 0; i < cantidadDeDados; ++i) {
        cout << valorDeDadoJugador1[i] << " " << endl;
        graficarDado(valorDeDadoJugador1 [i]) ;}
        sumaDeDados= valorDeDadoJugador1[0] + valorDeDadoJugador1[1]+valorDeDadoJugador1[2];
        ///aca tengo que poner la llamada para la funcion barro  o doble puntos
        sumaDeDados=Oinkss(valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,sumaDeDados,Oinks);
        sumaDeDados=Barros(valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,Barro,sumaDeDados,Trufas_Totales_de_Jugador);
        return sumaDeDados;
        }
    else{
        for (int i = 0; i < cantidadDeDados; ++i) {
        valorDeDadoJugador2[i] = dados[i];}
        cout << "Valores de los dados del Cerdito "<<NombreP2 <<": " << endl;
        for (int i = 0; i < cantidadDeDados; ++i) {
        cout << valorDeDadoJugador2[i] << " " << endl;
        graficarDado(valorDeDadoJugador2 [i]) ;}

        sumaDeDados= valorDeDadoJugador2[0] + valorDeDadoJugador2[1]+valorDeDadoJugador2[2];
        ///aca tengo que poner la llamada para la funcion barro  o doble puntos
        sumaDeDados=Oinkss(valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,sumaDeDados,Oinks);
        sumaDeDados=Barros(valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,Barro,sumaDeDados,Trufas_Totales_de_Jugador);
        return sumaDeDados;
    }

}

#endif // RONDA_H_INCLUDED
