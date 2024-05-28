#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED
#include "rlutil.h"

void jugar(char Actual_Campeon[],int Puntos_Act_Campeon[]){
    int ronda,Trufas_Totales_de_Jugador[2]={0},Trufas_Del_Turno_de_los_Jugadores[2]={0},Dirccion_de_trufas,PUNTOS_DE_VICTORIA[2]={0};
    int Barro[2]={0},Lanzamientos_x_Ronda[2]={0},Mayor_Lanzamiento[2],Oinks[2]={0},Mostrar_ronda=1;
    bool jugada,Empieza;
    char NombreP1[20],NombreP2[20];
    const int tamanioCaraDeDado = 6;
    int dados[tamanioCaraDeDado] = {};
    int cantidadDeDados = 2;
    int valorDeDadoJugador1[3] = {0}; // Vector para almacenar los valores de los dados del jugador 1
    int valorDeDadoJugador2[3] = {0}; // Vector para almacenar los valores de los dados del jugador 2
///PIDE EL NOMBRE.
    cout<<" INGRESE EL NOMBRE DEL JUGADOR 1: "<<endl;
    cargarCadena(NombreP1,20);
    cout<<" INGRESE EL NOMBRE DEL JUGADOR 2: "<<endl;
    cargarCadena(NombreP2,20);
    system("cls");
///Se Decide quien empieza
   Empieza=Quien_emppieza(NombreP1,NombreP2,dados, cantidadDeDados,valorDeDadoJugador1,valorDeDadoJugador2);
   system("pause");
   system("cls");
///EMPIEZAN LAS RONDAS
    for(ronda=0;ronda<10;ronda++){
        jugada=false;
        Lanzamientos_x_Ronda[0]=0;
        Lanzamientos_x_Ronda[1]=0;
        if(ronda%2==0){
            cout<<"Ronda "<<Mostrar_ronda<<endl;
        } else{cout<<"Ronda "<<Mostrar_ronda++<<endl;}
///SE TIRAN LOS DADOS
    while(jugada!=true){
        if(Empieza){Dirccion_de_trufas=orden1(ronda,NombreP1,NombreP2,Trufas_Totales_de_Jugador);}
            else{Dirccion_de_trufas=orden2(ronda,NombreP1,NombreP2,Trufas_Totales_de_Jugador);}
        tirarDados(dados, cantidadDeDados); /// <---ACA SE TIRAN LOS DADOS
        if(Dirccion_de_trufas==1){
        Trufas_Del_Turno_de_los_Jugadores[0]=Trufas_en_el_Turno(NombreP1,NombreP2,Empieza,valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,dados,Dirccion_de_trufas,Barro,Oinks,Trufas_Totales_de_Jugador);
        Trufas_Totales_de_Jugador[0]=Trufas_Del_Turno_de_los_Jugadores[0]+Trufas_Totales_de_Jugador[0];//cero es el ugador 1
        cout<<"SUMASTE: "<<Trufas_Del_Turno_de_los_Jugadores[0]<<" TRUFAS";
        Lanzamientos_x_Ronda[0]++;
        cout<<"|LANZAMIENTO #"<<Lanzamientos_x_Ronda[0]<<endl;
        Mayor_Cantidad_Lanzamientos(Lanzamientos_x_Ronda,Mayor_Lanzamiento);
        }
        else{
            Trufas_Del_Turno_de_los_Jugadores[1]=Trufas_en_el_Turno(NombreP1,NombreP2,Empieza,valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,dados,Dirccion_de_trufas,Barro,Oinks,Trufas_Totales_de_Jugador);
        Trufas_Totales_de_Jugador[1]=Trufas_Del_Turno_de_los_Jugadores[1]+Trufas_Totales_de_Jugador[1];//1 es el uador dos
        cout<<"SUMASTE: "<<Trufas_Del_Turno_de_los_Jugadores[1]<<" TRUFAS";
        Lanzamientos_x_Ronda[1]++;
        cout<<"|LANZAMIENTO #"<<Lanzamientos_x_Ronda[1]<<endl;
        Mayor_Cantidad_Lanzamientos(Lanzamientos_x_Ronda,Mayor_Lanzamiento);
        }

///PREGUNTA PARA FINALIZAR EL TURNO
        jugada=Fin_del_Turno(valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados);
        cantidadDeDados=Tercer_Dado(Trufas_Totales_de_Jugador,Barro);
        }
        system("cls");

    }
///FUNCION PARA MOSTRAR LOS HITO Y MOSTRAR AL GANADOR
    Asignar_Hitos(NombreP1,NombreP2,Trufas_Totales_de_Jugador,Oinks,Mayor_Lanzamiento,PUNTOS_DE_VICTORIA,Actual_Campeon,Puntos_Act_Campeon);

    system("pause");
    }


#endif // JUGAR_H_INCLUDED
