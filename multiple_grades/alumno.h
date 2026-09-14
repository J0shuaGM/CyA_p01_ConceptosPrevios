// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 12/09/2026
// Archivo alumno.h: declaracion de la clase objeto alumno

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

class Alumno {
  public:
    //Constructores
    Alumno(const std::string& alu, std::vector<double> notas); //Constructor parametrizado por datos

    //Destructor
    ~Alumno() {}

    //Getters
    std::string getAlu(void) { return alu_; }
    std::vector<double> getNotas(void) { return notas_; }
    std::string getAlu(void) const { return alu_; }
    std::vector<double> getNotas(void) const { return notas_; }

    //Setters
    void setAlu(const std::string& alu) { alu_ = alu; }
    void setNota(std::vector<double> nota) { notas_ = nota; }
    void setNuevaNota(double nota) { notas_.push_back(nota); }

    //Metodos
    bool ComprobarDatos(const std::string& alu, double nota);
    bool ComprobarDatos(Alumno alumno);

    //Sobrecarga de operadores 
    friend std::ostream& operator<<(std::ostream& os, const Alumno& alumno);
    friend std::istream& operator>>(std::istream& is, Alumno& alumno);
    bool operator<(const Alumno& otro) const { return alu_ < otro.alu_; }
    bool operator==(const Alumno& otro) const { return alu_ == otro.alu_; }

  private:
    std::string alu_;
    std::vector<double> notas_;
};

#endif