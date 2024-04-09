#ifndef STOCK_API_H
#define STOCK_API_H

#include <curl/curl.h>

#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

#include "api_endpoint.h"

class CallApi {
 public:
  // Makes api call and returns json object
  nlohmann::json makeApiCall(const ApiEndpoint& endpoint,
                             const std::string& ticker,
                             const std::string& api_key);

 private:
  // Callback for data received
  static size_t WriteCallback(void* contents, size_t size, size_t nmemb,
                              std::string* s);
};

#endif  // STOCK_API_H
