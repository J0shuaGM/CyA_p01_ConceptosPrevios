// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Contenedores asociativos
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 12/09/2026
// Archivo tools.cc: contiene las definiciones de las clases declaradas en tools.h

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "tools.h"

/**
 * @brief Funcion que asegura el correcto uso de la linea de ejecucion
 * @param argc Entero que contiene el numero de argumentos pasados por linea de ejecucion
 * @param argv Array que contiene los argumentos pasados por linea de ejecucion
*/
void Usage(int argc, char* argv[]) {
  switch (argc) {
    case 2: {
      std::string parametro = argv[1];
      if (parametro == "--help") {
        std::cout << "El programa se encarga de gestionar las calificaciones obtenidas por diferentes alumnos. "
                  << "Para poder ejecutarlo, es necesario un fichero .txt que contenga los datos de la siguiente manera:"
                  << std::endl;
        std::cout << "aluXXXXXXXXXX nota" << std::endl;
        std::exit(EXIT_SUCCESS);
      }
      break;
    }
    default: {
      std::cerr << argv[0] << ": Modo de empleo: ./p01_single_grades grades.txt" << std::endl;
      std::cout << "Pruebe " << argv[0] << " --help para obtener mas informacion" << std::endl;
      std::exit(EXIT_SUCCESS);
    }
    case 3: {
      break;
    }
  }
}

void LeerDatos(std::istream& fichero_entrada, std::set<Alumno>& listado) {
  std::string alu;
  double nota;

  while (fichero_entrada >> alu >> nota) {
    Alumno temp_alumno(alu, std::vector<double>{nota});
    if(temp_alumno.ComprobarDatos(alu, nota)) {
      auto busqueda = listado.find(temp_alumno);
      if (busqueda != listado.end()) {
        Alumno alumno_existente = *busqueda;
        alumno_existente.setNuevaNota(nota);
        listado.erase(busqueda);
        listado.insert(alumno_existente);
      } else {
        listado.insert(temp_alumno);
      }
    }
  }
}

void ImprimirListado(const std::set<Alumno>& listado) {
  for(auto alumno : listado) {
    std::cout << alumno;
  }
}

std::set<Alumno> AvgNota(std::set<Alumno> listado) {
  std::set<Alumno> listado_avg;
  for (const auto& alumno : listado) {
    const std::vector<double> notas = alumno.getNotas();
    double suma{0.0};
    for (const double nota : notas) {
      suma += nota;
    }
    const double avg = suma / static_cast<double>(notas.size());
    std::vector<double> nota_promedio{avg};
    listado_avg.insert(Alumno(alumno.getAlu(), nota_promedio));
  }
  return listado_avg;
}