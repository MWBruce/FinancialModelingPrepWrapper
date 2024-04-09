#ifndef INTERFACE_RESPONSE_FORMATTER_H
#define INTERFACE_RESPONSE_FORMATTER_H

#include <nlohmann/json.hpp>

// Abstract class for response formatters
class InterfaceResponseFormatter {
 public:
  virtual ~InterfaceResponseFormatter() {}
  virtual void formatData(const nlohmann::json& response) = 0;
  virtual std::string getFormattedData();

 protected:
  std::string formatted_Data;
};

#endif  // INTERFACE_RESPONSE_FORMATTER_H