#include "../include/api_command.h"

// API Endpoints map which returns the appropriate api name for the api command type entered
std::unordered_map<api_command_type, std::string> ApiCommand::API_ENDPOINTS = {
    {api_command_type::BalanceSheet, "/balance-sheet-statement/{ticker}"},
    {api_command_type::CashFlow, "/cash-flow-statement/{ticker}"},
    {api_command_type::KeyMetrics, "/key-metrics/{ticker}"},
    {api_command_type::DCF, "/discounted-cash-flow/{ticker}"},
    {api_command_type::HistoricalDividends, "/historical-price-full/stock_dividend/{ticker}"},
};

// Constructor
ApiCommand::ApiCommand(
    const std::string& tick, const std::string& key,
    const std::vector<std::pair<std::string, std::string>>& q,
    std::string yaml_file_path, api_command_type type)
    : ticker(tick),
      api_key(key),
      queries(q),
      yaml_file_path(yaml_file_path),
      type(type) {}

// Executes the command
nlohmann::json ApiCommand::execute() {
  auto it = API_ENDPOINTS.find(type);
  if (it == API_ENDPOINTS.end()) {
    std::cout << "No command found" << std::endl;
    return nlohmann::json{};
  }
  std::string command_type_string = it->second;

  // Intitialising Parser (can probably be inherited)
  ApiSpecParser parser(yaml_file_path);
  ApiEndpoint endpoint = parser.getEndpointDetails(command_type_string);

  // Ensuring query is valid
  for (const auto& query : queries) {
    if (parser.isValidQuery(command_type_string, query.first)) {
      endpoint.addValidatedQueryParameters(query);
    }
  }

  // Making api call and displaying first 3000 chars
  return api.makeApiCall(endpoint, ticker, api_key);
}