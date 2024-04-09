#ifndef API_ENDPOINT_H
#define API_ENDPOINT_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class ApiEndpoint {
 public:
  // Default Constructor
  ApiEndpoint();

  // Constructor
  ApiEndpoint(const std::string& url, const std::string& httpMethod,
              const std::unordered_map<std::string, std::string>& headers,
              const std::unordered_map<std::string, std::string>& queryParams);

  // Returns base url
  const std::string& getUrl() const;

  // Return queries to be added to url
  const std::unordered_map<std::string, std::string>& getQueryParams() const;

  // Allows for additional queries to be added to api call
  void addValidatedQueryParameters(
      const std::pair<std::string, std::string>& query);

 private:
  std::string url;
  std::string httpMethod;
  std::unordered_map<std::string, std::string> headers;
  std::unordered_map<std::string, std::string> queryParams;
};

#endif  // API_ENDPOINT_H
