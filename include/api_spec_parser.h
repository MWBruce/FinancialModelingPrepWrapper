#ifndef API_SPEC_PARSER_H
#define API_SPEC_PARSER_H

#include <yaml-cpp/yaml.h>

#include <fstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "api_endpoint.h"

class ApiSpecParser {
 public:
  // Creates parser as defined in file
  ApiSpecParser(const std::string& specFilePath);

  // Returns end point for api call
  ApiEndpoint getEndpointDetails(const std::string& endpointName);

  // Checks if a query is valid to an api call
  bool isValidQuery(const std::string& endpointName,
                    const std::string& queryName);

 private:
  // Parses file
  void parseSpecFile(const std::string& specFilePath);

  // Storing spec
  YAML::Node spec;

  // Storing endpoints
  std::unordered_map<std::string, ApiEndpoint> endpoints;
};

#endif  // API_SPEC_PARSER_H
