// This source file is based on "https://code.google.com/p/yaml-cpp/wiki/Tutorial".

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "yaml-cpp/yaml.h"


int main()
{
  YAML::Node config = YAML::LoadFile("config_seq.yaml");
  const YAML::Node& modemCards = config["modemCards"];

  if (!modemCards)
  {
    std::cerr << "modemCards" << std::endl;
    return 0;
  }

  for (YAML::const_iterator it = modemCards.begin(); it != modemCards.end(); ++it)
  {
    const YAML::Node& card = *it;

    std::cout << "slot:" << card["slot"] << std::endl;
    std::cout << "ip:" << YAML::DoubleQuoted << card["ip"] << std::endl;
    std::cout << "type:" << card["type"] << std::endl;
  }

  return 0;
}

