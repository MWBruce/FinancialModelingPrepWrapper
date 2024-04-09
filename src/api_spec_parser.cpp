#include "../include/api_spec_parser.h"

// Creates parser as defined in file
ApiSpecParser::ApiSpecParser(const std::string& specFilePath) {
  parseSpecFile(specFilePath);
}

// Parses file
void ApiSpecParser::parseSpecFile(const std::string& specFilePath) {
  std::ifstream file(specFilePath);
  if (!file.is_open()) {
    throw std::runtime_error("File not found: " + specFilePath);
  }

  spec = YAML::LoadFile(specFilePath);
  std::string baseUrl = spec["servers"][0]["url"].as<std::string>();

  for (auto const& path : spec["paths"]) {
    std::string endpointPath = path.first.as<std::string>();
    std::string fullUrl = baseUrl + endpointPath;

    endpoints[endpointPath] = ApiEndpoint(fullUrl, "GET", {}, {});
  }
}

// Returns end point for api call
ApiEndpoint ApiSpecParser::getEndpointDetails(const std::string& endpointName) {
  if (endpoints.find(endpointName) == endpoints.end()) {
    throw std::runtime_error("Endpoint not found: " + endpointName);
  }
  return endpoints[endpointName];
}

// Checks if a query is valid to an api call
bool ApiSpecParser::isValidQuery(const std::string& endpointName,
                                 const std::string& queryName) {
  // Getting endpoint node
  auto endpointNode = spec["paths"][endpointName]["get"];

  // Checking endpoint exists
  if (!endpointNode || !endpointNode["parameters"]) {
    std::cout << "No 'get' method or 'parameters' field for " << endpointName
              << std::endl;
    return false;
  }

  std::vector<std::string> validQueries;
  bool isValid = false;

  // Checking if query is in endpoints request
  for (const auto& param : endpointNode["parameters"]) {
    if (param["in"] && param["in"].as<std::string>() == "query") {
      std::string paramName = param["name"].as<std::string>();
      validQueries.push_back(paramName);
      if (paramName == queryName) {
        isValid = true;
      }
    }
  }

  // Outputting valid queries for user
  if (!isValid) {
    std::cout << "Invalid query parameter: " << queryName << "\n";
    std::cout << "Valid query parameters for " << endpointName << " are: ";
    bool firstValidQuery = true;
    for (const auto& q : validQueries) {
      if (firstValidQuery) {
        firstValidQuery = !firstValidQuery;
      } else {
        std::cout << ", ";
      }

      std::cout << q;
    }
    std::cout << "\n";
  }

  return isValid;
}