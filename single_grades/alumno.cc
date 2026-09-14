// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 12/09/2026
// Archivo alumno.cc: definicion de la clase objeto alumno

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "alumno.h"

Alumno::Alumno(const std::string& alu, double nota) {
  alu_ = alu; 
  notaMax_ = nota;
}

bool Alumno::ComprobarDatos(const std::string& alu, double nota) {
  if (alu.size() != 13 || alu.substr(0, 3) != "alu") {
    std::cerr << "El alu introducido no es correcto" << std::endl;
    return false;
  }
  for (int i = 3; i < alu.size(); i++) {
    if (!std::isdigit(static_cast<unsigned char>(alu[i]))) {
      std::cerr << "El alu introducido no es correcto" << std::endl;
      return false;
    }
  }
  if (nota < 0 || nota > 10) {
    std::cerr << "La nota introducida es menor a 0 o mayor a 10" << std::endl;
    return false;
  }

  return true;
}

std::ostream& operator<<(std::ostream& os, const Alumno& alumno) {
  os << alumno.alu_ << " " << alumno.notaMax_ << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Alumno& alumno) {
  std::string alu;
  double nota;
  is >> alu >> nota;
  alumno.setAlu(alu);
  alumno.setNota(nota);
  return is;
}