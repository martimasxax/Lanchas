#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h> 
#include <mmsystem.h>
#include "lanchas.h"
using namespace std; 
//Jugador
string nombreBot = "Bot";

int ronda = 0;
int rondas = 5;
bool botJuega;

void gameOver() {
	cout << "el enemigo te ha derrotado\n";
	Sleep(1000);
	system("cls");
	cout << "  _____      ___       ___  ___   _____" << endl;
	Sleep(100);
	cout << " / ___ |    /   |     /   |/   | |  ___|" << endl;
	Sleep(100);
	cout << "| |        / /| |    / /|   /| | | |__" << endl;
	Sleep(100);
	cout << "| |  _    / ___ |   / / |__/ | | |  __|" << endl;
	Sleep(100);
	cout << "| |_| |  / /  | |  / /       | | | |___" << endl;
	Sleep(100);
	cout << "\_____/ /_/   |_| /_/        |_| |_____|" << endl;
	Sleep(100);
	cout << " _____   _     _   _____   _____" << endl;
	Sleep(100);
	cout << "/  _  \ | |   / / |  ___| |  _  \ " << endl;
	Sleep(100);
	cout << "| | | | | |  / /  | |__   | |_| |" << endl;
	Sleep(100);
	cout << "| | | | | | / /   |  __|  |  _  /" << endl;
	Sleep(100);
	cout << "| |_| | | |/ /    | |___  | | \ \ " << endl;
	Sleep(100);
	cout << "\_____/ |___/     |_____| |_|  \_\ " << endl;
	Sleep(100);
	cout << endl << endl;
	Sleep(10000);
	system("pause");
}
int numeroJugadores() {
	int num;
	cout << " Cuantos jugadores vais a paricipar?\n";
	cin >> num;
	return num;
}
bool BootJuega() {
	cout << "Quereis que juegue algun bot tambien? \n";
	cout << "[1] Si\n";
	cout << "[2] No\n";
	int botJuega;
	cin >> botJuega;
	if (botJuega == 1) {
		return true;
	}
	else {
		cout << "Partida sin bot comenzando\n";
		return false;
	}
}
void inicioNombre(Lanchas& Jugador) {

	string nombre;
	cout << "Bienvenido a Lanchas Racing\n";
	cout << "Dime con que nombre te inscribo\n";
	cin >> nombre;
	Jugador.setNombre(nombre);
}
bool ganado(Lanchas Jugador[], int mayorDist, int competidores) {
	for (int i = 0; i < competidores; i++) {
		if (Jugador[i].getDistRec() >= mayorDist) {
			Jugador[i].setDistRec(mayorDist);
			Jugador[i].setGanado(true);
		}
	}
	for (int i = 0; i < competidores; i++) {
		if (Jugador[i].getGanado() == true) {
			return true;
		}
		else {
			return false;
		}
	}
}
void nitro(Lanchas& Jugador) {
	int opcion = 0;
	int nitro;
	do {
		if (Jugador.getNombre()._Equal(nombreBot)) {
			if (rondas - 1 == ronda) {
				cout << Jugador.getNombre() << " usa el nitro en esta ronda\n";
				opcion = 1;
			}
			else {
				cout << Jugador.getNombre() << " no usa el nitro en esta ronda\n";
				opcion = 2;
			}
		}
		else {
			cout << "Vas a tirarte el nitro \n";
			cout << "[1] Si\n";
			cout << "[2] No\n";
			cin >> opcion;
		}

		if (opcion == 1) {
			Jugador.setNitro(true);
			nitro = rand() % 2;
			if (nitro == 1) {

				Jugador.calculoVelTurbo();
				Jugador.printStatusVelNitroBien();
			}

			else if (nitro == 0) {

				Jugador.calculoVelExp();
				Jugador.printStatusVelNitroMal();
			}

		}
		else if (opcion == 2) {
			cout << "No utilizas el nitro\n";
		}

		else { cout << "Ingresa una opcion correcta\n"; }
	} while (opcion != 1 && opcion != 2);
}  
void velocidad(Lanchas& Jugador) {

	Jugador.calculoDadoVel();
	Jugador.printStatusVel();

	if (Jugador.getNitro() == true) {
		nitro(Jugador);
	}
}
void distancia(Lanchas& Jugador) {
	Jugador.calculoDiscRec();
	Jugador.printStatusDiscRec();
}
void imprimirCampo(Lanchas jugador[], int mayorDist, int competidores) {
	for (int i = 0; i < competidores; i++) {
		cout << jugador[i].getNombre()+"\n";
		int espacios = jugador[i].getDistRec() / 5;
		for (int j = 0; j < espacios; j++) {
			cout << "=";
		}
		cout << "{=>";
			for (int k = 0; k < (mayorDist/5)-espacios; k++) {
				cout << " ";
			}
			cout << "|\n";
	}
	
}
void finalJuego(Lanchas jugador[], int competidores, int mayorDist) {
	bool ganado=false;
	for (int i = 0; i < competidores;i++) {
		if (jugador[i].getDistRec() > mayorDist) {
			cout << "El jugador " << jugador[i].getNombre() << "ha ganado.";
			ganado = true;
		}
	}
	if (ganado == false) {
		cout << "Nadie ha conseguido llegar a la meta en las 5 rondas";
		Sleep(5000);
		gameOver();
	}

}

int main() {

	srand(time(NULL));
	int mayorDist = 100;
	int numJug = numeroJugadores();
	bool bootJuega = BootJuega();
	if (bootJuega) {
		numJug += 1;
	}
	Lanchas* arrayLanchas = new Lanchas[numJug];
	if (bootJuega) {
		arrayLanchas[numJug - 1] = Lanchas(nombreBot, 0, 0, true, false);
		cout << arrayLanchas[numJug - 1].getNombre() << " juega tambien\n";
		for (int i = 0; i < numJug-1; i++) {
			arrayLanchas[i] = Lanchas();
		}
		for (int i = 0; i < numJug-1; i++) {
			inicioNombre(arrayLanchas[i]);
		}
	}
	else {
		for (int i = 0; i < numJug; i++) {
			arrayLanchas[i] = Lanchas();
		}
		for (int i = 0; i < numJug; i++) {
			inicioNombre(arrayLanchas[i]);
		}
	}
	while (ganado(arrayLanchas, mayorDist, numJug) == false || ronda<rondas) {
		
			for (int i = 0; i < numJug; i++) {
				velocidad(arrayLanchas[i]);
				distancia(arrayLanchas[i]);
			}
			imprimirCampo(arrayLanchas, mayorDist, numJug);
			ronda++;

		
	}
	finalJuego(arrayLanchas, numJug, mayorDist );

	return 0;
}