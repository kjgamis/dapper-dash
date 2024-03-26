#include <iostream>

#include "Engine.h"
#include "Utils.h"

int main(int argc, char** argv) {

  if (argc > 1) {
    if (static_cast<std::string>(argv[1])  == "nom") {
      Engine engine;
      engine.run();
    }
  } else {
    std::cerr << "No arguments provided" << std::endl;
  }

  return 0;
}
