#include "../include/api_endpoint.h"

// Default Constructor
ApiEndpoint::ApiEndpoint() : url(""), httpMethod("GET") {}

// Constructor
ApiEndpoint::ApiEndpoint(
    const std::string& url, const std::string& httpMethod,
    const std::unordered_map<std::string, std::string>& headers,
    const std::unordered_map<std::string, std::string>& queryParams)
    : url(url),
      httpMethod(httpMethod),
      headers(headers),
      queryParams(queryParams) {}

// Returns base url
const std::string& ApiEndpoint::getUrl() const { return url; }

// Return queries to be added to url
const std::unordered_map<std::string, std::string>&
ApiEndpoint::getQueryParams() const {
  return queryParams;
}

// Allows for additional queries to be added to api call
void ApiEndpoint::addValidatedQueryParameters(
    const std::pair<std::string, std::string>& query) {
  queryParams[query.first] = query.second;
}