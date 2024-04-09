#include "../include/data_saver.h"

// Outputs data string to file
void DataSaver::saveData(const std::string& data, const std::string& filename) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Unable to open file: " + filename);
  }
  file << data;
  file.close();
}