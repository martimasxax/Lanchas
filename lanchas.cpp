#include <iostream>
#include "lanchas.h"
using namespace std;

// Constructores
Lanchas::Lanchas() {
    distRec = 0;
    velocidad = 0;
    nitro = true;
    nombre = "Jugador";
    ganado = false;
}

Lanchas::Lanchas(string pNombre, int pDistRec, int pVelocidad, bool pNitro, bool pGanado) {
    distRec = pDistRec;
    velocidad = pVelocidad;
    nombre = pNombre;
    nitro = pNitro;
    ganado = pGanado;
}

// Getters
int Lanchas::getDistRec() {
    return distRec;
}

string Lanchas::getNombre() {
    return nombre;
}

int Lanchas::getVelocidad() {
    return velocidad;
}

bool Lanchas::getNitro() {
    return nitro;
}

bool Lanchas::getGanado() {
    return ganado;
}

// Setters
void Lanchas::setDistRec(int pDistRec) {
    distRec = pDistRec;
}

void Lanchas::setNombre(string pNombre) {
    nombre = pNombre;
}

void Lanchas::setVelocidad(int pVelocidad) {
    velocidad = pVelocidad;
}

void Lanchas::setNitro(bool pNitro) {
    nitro = pNitro;
}

void Lanchas::setGanado(bool pGanado) {
    ganado = pGanado;
}

// Métodos propios
void Lanchas::printStatusDiscRec() {
    cout << "El jugador " << getNombre() << " va a una velocidad de " << getVelocidad() << " m/s y ya ha avanzado " << getDistRec() << " m\n";
}

void Lanchas::calculoDiscRec() {
    setDistRec(getDistRec() + getVelocidad());
}

void Lanchas::calculoVelTurbo() {
    setVelocidad(getVelocidad() * 2);
}

void Lanchas::calculoVelExp() {
    setVelocidad(getVelocidad() / 2);
}

void Lanchas::printStatusVel() {
    cout << getNombre() << " vas a una velocidad de " << getVelocidad() << " m/s\n";
}

void Lanchas::calculoDadoVel() {
    int dado = 1 + rand() % 6;
    setVelocidad(getVelocidad() + dado);
}

void Lanchas::printStatusVelNitroBien() {
    cout << getNombre() << " todo ha salido bien, ahora tu velocidad es " << getVelocidad() << "\n";
}

void Lanchas::printStatusVelNitroMal() {
    cout << getNombre() << " ha salido mal el nitro ahora tu velocidad es " << getVelocidad() << "\n";
}
