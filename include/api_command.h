#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "api_spec_parser.h"
#include "call_api.h"

enum class api_command_type { CashFlow, BalanceSheet,KeyMetrics, DCF };

// class for api commands
class ApiCommand {
 public:
  // Constructor
  ApiCommand(const std::string& ticker, const std::string& api_key,
             const std::vector<std::pair<std::string, std::string>>& queries,
             std::string yaml_file_path, api_command_type type);
  virtual ~ApiCommand() {}
  virtual nlohmann::json execute();

 protected:
  static std::unordered_map<api_command_type, std::string>
      API_ENDPOINTS;  // API end points
  // Variables for each command
  nlohmann::json jsonData;     // temp value to be used when extracting data
  std::string ticker;          // Stock ticker
  std::string api_key;         // Api key
  CallApi api;                // Api object
  std::string yaml_file_path;  // path to yaml file
  api_command_type type;       // command type
  std::vector<std::pair<std::string, std::string>>
      queries;  // Additional queries for api command
};

#endif  // COMMAND_H
