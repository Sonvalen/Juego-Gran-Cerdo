#ifndef ORDEN_DE_JUEGO_H_INCLUDED
#define ORDEN_DE_JUEGO_H_INCLUDED
#include "rlutil.h"

int orden1(int ronda,char NombreP1[20], char NombreP2[20],int Trufas_Totales_de_Jugador[]){
    if(ronda%2==0||ronda==0){
        rlutil::locate(10,1);
        cout<<" TURNO DEL JUGADOR "<<NombreP1<<": "<<endl;
         rlutil::locate(40,1);
        cout<<" TRUFAS ACTUALES: "<<Trufas_Totales_de_Jugador[0]<<endl;
        return 1;//esto es para que el if de las trufas sepa a que juador darle los puntos
        }else{
        rlutil::locate(10,1);
        cout<<" TURNO DEL JUGADOR "<<NombreP2<<": "<<endl;
        rlutil::locate(40,1);
        cout<<" TRUFAS ACTUALES: "<<Trufas_Totales_de_Jugador[1]<<endl;
        return 2;//esto es para que el if de las trufas sepa a que juador darle los puntos
        }
}

int orden2(int ronda,char NombreP1[20], char NombreP2[20],int Trufas_Totales_de_Jugador[]){
    if(ronda%2==0||ronda==0){
        rlutil::locate(10,1);
        cout<<" TURNO DEL JUGADOR "<<NombreP2<<": "<<endl;
         rlutil::locate(40,1);
        cout<<" TRUFAS ACTUALES: "<<Trufas_Totales_de_Jugador[1]<<endl;
        return 2;//esto es para que el if de las trufas sepa a que juador darle los puntos
        }else{rlutil::locate(10,1);
            cout<<" TURNO DEL JUGADOR "<<NombreP1<<": "<<endl;
         rlutil::locate(40,1);
        cout<<" TRUFAS ACTUALES: "<<Trufas_Totales_de_Jugador[0]<<endl;
        return 1;//esto es para que el if de las trufas sepa a que juador darle los puntos
        }
}

bool Quien_emppieza(char NombreP1[], char NombreP2[],int dados[], int cantidadDeDados,int valorDeDadoJugador1[],int valorDeDadoJugador2[]){
    int sumaJugador1, sumaJugador2; //Suma de los dados de los jugadores para saber quien arranca
     cout<<" QUIEN EMPIEZA?"<<endl;
     while(true){
    // Tirar los dados del jugador 1
    cout<<" JUGADOR "<<NombreP1<<" TIRE LOS DADOS: "<<endl;
   system("pause");
    tirarDados(dados, cantidadDeDados);/// <---ACA SE TIRAN LOS DADOS
    for (int i = 0; i < cantidadDeDados; ++i) {
                    valorDeDadoJugador1[i] = dados[i];}
    // Mostrar resultados de los dados del jugador 1
    cout << "Valores de los dados del Jugador " << NombreP1 << endl <<": ";
    for (int i = 0; i < cantidadDeDados; ++i) {
    cout << valorDeDadoJugador1[i] << endl << " ";
    graficarDado(valorDeDadoJugador1 [i]) ;
    }
    cout << endl;

    cout<<" JUGADOR "<<NombreP2<<" TIRE LOS DADOS: "<<endl;
// Tirar los dados del jugador 2
    tirarDados(dados, cantidadDeDados);/// <---ACA SE TIRAN LOS DADOS
// Guardar los valores de los dados del jugador 2
    for (int i = 0; i < cantidadDeDados; ++i) {
        valorDeDadoJugador2[i] = dados[i];
        }system("pause") ;
// Mostrar resultados de los dados del jugador 2
    cout << "Valores de los dados del Jugador "<< NombreP2 << endl <<": ";
    for (int i = 0; i < cantidadDeDados; ++i) {
    cout << valorDeDadoJugador2[i] << endl << " ";
    graficarDado(valorDeDadoJugador2 [i]);

    }
    cout << endl;
// Acá van a ir las condiciones que se tienen que dar para saber quien comienza
// La suma de los valoresDeDadoJugador con mayor puntuacion gana y comienza el juego
// Si hay empate comienza el que haya obtenido el dado más alto ej: p1-> 4 + 4 = 8, p2-> 5 + 3 ganó p2 porque sacó un 5 que fué el nro más alto de los dados
// Si no se cumple ninguna de las dos condiciones anteriores se vuelve a lanzar los dados hasta que se cumpla alguna y arranque el juego

// Calcula la suma de los valores de los dados de cada jugador
    sumaJugador1 = valorDeDadoJugador1[0] + valorDeDadoJugador1[1];
    sumaJugador2 = valorDeDadoJugador2[0] + valorDeDadoJugador2[1];

// Verificar quién comienza
    if (sumaJugador1 > sumaJugador2) {
        cout << "Comienza el cerdito " << NombreP1 << "!" << endl;
        return true;}
        if (sumaJugador1 < sumaJugador2) {
        cout << "Comienza el cerdito " << NombreP2 << "!" << endl;
        return false;}
         else {
// Si hay empate en la suma de los dados, verifica el dado más alto
// Compara los valores de los dados de cada jugador
    if ((valorDeDadoJugador1[0] > valorDeDadoJugador1[1] && valorDeDadoJugador1[0] > valorDeDadoJugador2[0] && valorDeDadoJugador1[0] > valorDeDadoJugador2[1]) ||
        (valorDeDadoJugador1[1] > valorDeDadoJugador1[0] && valorDeDadoJugador1[1] > valorDeDadoJugador2[0] && valorDeDadoJugador1[1] > valorDeDadoJugador2[1])) {
        cout << "Comienza el cerdito " << NombreP1 << "!" << endl;
        return true;
        } else if ((valorDeDadoJugador2[0] > valorDeDadoJugador2[1] && valorDeDadoJugador2[0] > valorDeDadoJugador1[0] && valorDeDadoJugador2[0] > valorDeDadoJugador1[1]) ||
        (valorDeDadoJugador2[1] > valorDeDadoJugador2[0] && valorDeDadoJugador2[1] > valorDeDadoJugador1[0] && valorDeDadoJugador2[1] > valorDeDadoJugador1[1])) {
        cout << "Comienza el cerdito " << NombreP2 << "!" << endl;
        return false;}
        else { cout << "¡Hay un empate en la suma y en el dado más alto! ¡Vuelvan a tirar!" << endl;}
    }
    }

}

#endif // ORDEN_DE_JUEGO_H_INCLUDED
