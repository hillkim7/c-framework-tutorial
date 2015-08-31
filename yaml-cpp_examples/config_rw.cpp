// This source file is based on "https://code.google.com/p/yaml-cpp/wiki/Tutorial".

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "yaml-cpp/yaml.h"


int main()
{
  const char config_yaml[] = "config.yaml";
  YAML::Node config = YAML::LoadFile(config_yaml);

  if (config["lastLogin"]) {
    std::cout << "Last logged in: " << config["lastLogin"].as<int>() << "\n";
  }

  const std::string username = config["username"].as<std::string>();
  const std::string password = config["password"].as<std::string>();
  std::cout << "username: '" << username << "'" << std::endl;
  std::cout << "password: '" << password << "'" << std::endl;

  config["lastLogin"] = (int)time(0);

  std::ofstream fout(config_yaml);
  fout << config;

  return 0;
}

