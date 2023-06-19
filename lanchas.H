#pragma once
#include <iostream>
using namespace std;

class Lanchas
{
private:
	int distRec;
	string nombre;
	int velocidad;
	bool nitro;
	bool ganado;

public:
	Lanchas();
	Lanchas(string pNombre, int pDistRec, int pVelocidad, bool pNitro, bool pGanado);

	int getDistRec();
	string getNombre();
	int getVelocidad();
	bool getNitro();
	bool getGanado();

	void setDistRec(int pDistRec);
	void setNombre(string pNombre);
	void setVelocidad(int pVelocidad);
	void setNitro(bool pNitro);
	void setGanado(bool pGanado);

	void printStatusDiscRec();
	void calculoDiscRec();
	void calculoVelTurbo();
	void calculoVelExp();
	void printStatusVel();
	void calculoDadoVel();
	void printStatusVelNitroBien();
	void printStatusVelNitroMal();
};
