#ifndef RESPONSE_FORMATTER_H
#define RESPONSE_FORMATTER_H

#include <nlohmann/json.hpp>

// Abstract class for response formatters
class ResponseFormatter {
 public:
  virtual ~ResponseFormatter() {}
  virtual void formatData(const nlohmann::json& response);
  virtual std::string getFormattedData();

 protected:
  std::string formatted_Data;
};

#endif  // RESPONSE_FORMATTER_H