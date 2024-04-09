#include "../include/call_api.h"

nlohmann::json CallApi::makeApiCall(const ApiEndpoint& endpoint,
                                     const std::string& ticker,
                                     const std::string& api_key) {
  CURL* curl;
  CURLcode res;
  std::string readBuffer;

  std::string url = endpoint.getUrl();
  size_t tickerPos = url.find("{ticker}");

  // Replacing ticker place holder with user requested ticker
  if (tickerPos != std::string::npos) {
    url.replace(tickerPos, std::string("{ticker}").length(), ticker);
  }

  // Getting query params and appending to url
  auto queryParams = endpoint.getQueryParams();
  bool isFirstQueryParam = (url.find('?') == std::string::npos);
  for (const auto& param : queryParams) {
    url += (isFirstQueryParam ? "?" : "&") + param.first + "=" + param.second;
    isFirstQueryParam = false;
  }

  // Appending apikey
  url += (isFirstQueryParam ? "?apikey=" : "&apikey=") + api_key;

  // Printing out URL for checking
  // std::cout << "Request URL: " << url << std::endl;

  // Making curl request
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
      std::cerr << "CURL error: " << curl_easy_strerror(res) << "\n";
    }

    curl_easy_cleanup(curl);

    try {
      return nlohmann::json::parse(readBuffer);
    } catch (nlohmann::json::parse_error& e) {
      std::cerr << "JSON parse error: " << e.what() << '\n';
      return nlohmann::json();
    }
  } else {
    std::cerr << "Failed to initialize CURL.\n";
    return nlohmann::json();
  }
}

// Callback for data received
size_t CallApi::WriteCallback(void* contents, size_t size, size_t nmemb,
                               std::string* s) {
  size_t newLength = size * nmemb;
  try {
    s->append((char*)contents, newLength);
    return newLength;
  } catch (std::bad_alloc& e) {
    return 0;
  }
}
