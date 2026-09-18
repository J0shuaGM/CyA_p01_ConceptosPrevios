// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Joshua Gomez Marrero 
// Correo: alu0101477398@ull.edu.es
// Fecha: 12/09/2026
// Archivo cliente.cc: contiene la funcion main del programa

#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "tools.h"
#include "alumno.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string nombre_fichero = argv[1];
  std::ifstream fichero_entrada(nombre_fichero);
  std::set<Alumno> listado;
  if (!fichero_entrada.is_open()) {
    std::cerr << "El fichero de entrada no se ha podido abrir" << std::endl;
    std::exit(EXIT_FAILURE);
  } else {
    LeerDatos(fichero_entrada, listado);
    fichero_entrada.close();
  }
  ImprimirListado(listado);
  std::cout << std::endl;
  std::string avg = argv[2];
  if(argc == 3 && avg == "--avg") {
    std::set<Alumno> avg = AvgNota(listado);
    ImprimirListado(avg);
  }
  int opcion;
  std::cout << "¿Desea introducir mas alumnos? 1 = SI/2 = NO: " << std::endl;
  std::cin >> opcion; 
  if(opcion == 1) {
    std::cout << "Introduzca alu y nota o pulse CTRL + D para finalizar" << std::endl;
    LeerDatos(std::cin, listado);
    std::cin.clear();
    std::cout << std::endl;
    ImprimirListado(listado);
    std::cout << std::endl;
    std::set<Alumno> avg = AvgNota(listado);
    ImprimirListado(avg);
  } else if(opcion == 2) {
    return 0; 
  } else {
    std::cerr << "Opcion incorrecta" << std::endl;
    return 1;
  }
  return 0;
}