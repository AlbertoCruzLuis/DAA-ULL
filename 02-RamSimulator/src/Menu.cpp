#include "Menu.hpp"

#include "Memory.hpp"

Menu::Menu(RamMachine ramMachine) {
  char option;
  while (option != 'x') {
    showOptions();
    std::cout << "Elige una opcion: ";
    std::cin >> option;
    system("clear");
    switch (option) {
      case 'r':
        ramMachine.showRegisterOfMemory();
        break;
      case 't':  // Traza
        break;
      case 'e':
        ramMachine.execute();
        break;
      case 's':
        ramMachine.desensamblador();
        break;
      case 'i':
        ramMachine.showInputTape();
        break;
      case 'o':
        ramMachine.showOutputTape();
        break;
      case 'h':
        showHelp();
        break;

      case 'x':  // Salir
        break;

      default:
        break;
    }
  }
}

void Menu::showOptions() {
  std::cout << ">h\n";
  std::cout << "r: ver los registros\n";
  std::cout << "t: traza\n";
  std::cout << "e: ejecutar\n";
  std::cout << "s: desensamblador\n";
  std::cout << "i: ver cinta de entrada\n";
  std::cout << "o: ver cinta de salida\n";
  std::cout << "h: ayuda\n";
  std::cout << "x: salir\n";
  std::cout << ">\n";
}

void Menu::showHelp() {
  std::cout << "> Ayuda\n";
  std::cout << "Opcion r: Muestra el contenido de los registros.\n";
  std::cout << "Opcion t: Hace un pequeño recorrido del codigo.\n";
  std::cout << "Opcion e: Ejecuta el programa ram.\n";
  std::cout << "Opcion s: Transforma el codigo a codigo maquina.\n";
  std::cout << "Opcion i: Nos muestra el contenido de la cinta de entrada.\n";
  std::cout << "Opcion o: Nos muestra el contenido de la cinta de salida.\n";
}