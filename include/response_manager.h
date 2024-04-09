#ifndef RESPONSE_MANAGER_H
#define RESPONSE_MANAGER_H

#include <memory>
#include <nlohmann/json.hpp>

#include "data_saver.h"
#include "interface_response_formatter.h"

class ResponseManager {
 public:
  // Constructor
  ResponseManager(std::unique_ptr<InterfaceResponseFormatter> formatter,
                  std::unique_ptr<DataSaver> saver);

  // Function to handle json response data
  void handleResponse(const nlohmann::json& response,
                      const std::string& saveFileName);

 private:
  // Private variables (the formatter and saver that the class encapsulates)
  std::unique_ptr<InterfaceResponseFormatter> formatter;
  std::unique_ptr<DataSaver> saver;
};

#endif  // RESPONSE_MANAGER_H