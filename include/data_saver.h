#ifndef DATA_SAVER_H
#define DATA_SAVER_H

#include <string>
#include <fstream>

#include "response_formatter.h"

// Object designed to save data to specified file name
class DataSaver {
 public:
  void saveData(const std::string& data, const std::string& filename);
};

#endif  // DATA_SAVER_H
