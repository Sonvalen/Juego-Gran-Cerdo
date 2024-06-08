#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED
#include "rlutil.h"

int jugar(string Actual_Campeon,int Puntos_Act_Campeon[],string NombreP1,string NombreP2){
    int ronda,Trufas_Totales_de_Jugador[2]={0},Trufas_Del_Turno_de_los_Jugadores[2]={0},Dirccion_de_trufas,PUNTOS_DE_VICTORIA[2]={0};
    int Barro[2]={0},Lanzamientos_x_Ronda[2]={0},Mayor_Lanzamiento[2]={0},Oinks[2],Mostrar_ronda=1,Ganador=0,Trufas_acumuladas_en_ronda[2];
    bool jugada,Empieza;
    const int tamanioCaraDeDado = 6;
    int dados[tamanioCaraDeDado] = {};
    int cantidadDeDados = 2;
    int valorDeDadoJugador1[3] = {0}; // Vector para almacenar los valores de los dados del jugador 1
    int valorDeDadoJugador2[3] = {0}; // Vector para almacenar los valores de los dados del jugador 2
///Se Decide quien empieza
   Empieza=Quien_emppieza(NombreP1,NombreP2,dados, cantidadDeDados,valorDeDadoJugador1,valorDeDadoJugador2);
   Oinks[0]={0};
   Oinks[1]={0};
   system("pause");
   system("cls");
///EMPIEZAN LAS RONDAS
    for(ronda=0;ronda<10;ronda++){
        jugada=false;
        Lanzamientos_x_Ronda[0]=0;
        Lanzamientos_x_Ronda[1]=0;
        Trufas_acumuladas_en_ronda[0]=0;
        Trufas_acumuladas_en_ronda[1]=0;
        if(ronda%2==0){
            cout<<"Ronda "<<Mostrar_ronda<<endl;
        } else{cout<<"Ronda "<<Mostrar_ronda++<<endl;}
///SE TIRAN LOS DADOS
    while(jugada!=true){
        if(Empieza){Dirccion_de_trufas=orden1(ronda,NombreP1,NombreP2,Trufas_Totales_de_Jugador);}
            else{Dirccion_de_trufas=orden2(ronda,NombreP1,NombreP2,Trufas_Totales_de_Jugador);}
        tirarDados(dados, cantidadDeDados); /// <---ACA SE TIRAN LOS DADOS
        if(Dirccion_de_trufas==1){
        Trufas_Del_Turno_de_los_Jugadores[0]=Trufas_en_el_Turno(NombreP1,NombreP2,Empieza,valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,dados,Dirccion_de_trufas,Barro,Oinks,Trufas_Totales_de_Jugador,Trufas_acumuladas_en_ronda);
        Trufas_acumuladas_en_ronda[0]=Trufas_acumuladas_en_ronda[0]+Trufas_Del_Turno_de_los_Jugadores[0];
        Trufas_Totales_de_Jugador[0]=Trufas_Del_Turno_de_los_Jugadores[0]+Trufas_Totales_de_Jugador[0];//cero es el Jugador 1
        cout<<"SUMASTE: "<<Trufas_Del_Turno_de_los_Jugadores[0]<<" TRUFAS";
        Lanzamientos_x_Ronda[0]++;
        cout<<"|LANZAMIENTO #"<<Lanzamientos_x_Ronda[0]<<endl;
        Mayor_Cantidad_Lanzamientos(Lanzamientos_x_Ronda,Mayor_Lanzamiento);
        }
        else{
        Trufas_Del_Turno_de_los_Jugadores[1]=Trufas_en_el_Turno(NombreP1,NombreP2,Empieza,valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,dados,Dirccion_de_trufas,Barro,Oinks,Trufas_Totales_de_Jugador,Trufas_acumuladas_en_ronda);
        Trufas_acumuladas_en_ronda[1]=Trufas_acumuladas_en_ronda[1]+Trufas_Del_Turno_de_los_Jugadores[1];
        Trufas_Totales_de_Jugador[1]=Trufas_Del_Turno_de_los_Jugadores[1]+Trufas_Totales_de_Jugador[1];//1 es el Jugador 2
        cout<<"SUMASTE: "<<Trufas_Del_Turno_de_los_Jugadores[1]<<" TRUFAS";
        Lanzamientos_x_Ronda[1]++;
        cout<<"|LANZAMIENTO #"<<Lanzamientos_x_Ronda[1]<<endl;
        Mayor_Cantidad_Lanzamientos(Lanzamientos_x_Ronda,Mayor_Lanzamiento);
        }
///PREGUNTA PARA FINALIZAR EL TURNO DEL JUGADOR
        jugada=Fin_del_Turno(valorDeDadoJugador1,valorDeDadoJugador2,cantidadDeDados,Dirccion_de_trufas);
        cantidadDeDados=Tercer_Dado(Trufas_Totales_de_Jugador,Barro);
        }
        system("cls");

    }
///FUNCION PARA MOSTRAR LOS HITO Y MOSTRAR AL GANADOR
    Ganador=Asignar_Hitos(NombreP1,NombreP2,Trufas_Totales_de_Jugador,Oinks,Mayor_Lanzamiento,PUNTOS_DE_VICTORIA,Actual_Campeon,Puntos_Act_Campeon);
    if(Ganador==1){return 1;}
    if(Ganador==2){return 2;}
    else{return 3;}
    system("pause");
    }


#endif // JUGAR_H_INCLUDED
