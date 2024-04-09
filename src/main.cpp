#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <utility>
#include <vector>

#include "../include/api_command.h"
#include "../include/data_saver.h"
#include "../include/formatter_factory.h"
#include "../include/response_manager.h"

static std::string YAML_FILE_PATH = "api_config.YAML";
static std::string SAVE_FILE_NAME = "test.csv";

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <ticker> <api_key>\n";
    return 1;
  }

  // Command line inputs
  std::string ticker = argv[1];
  std::string api_key = argv[2];
  api_command_type requested_api_command_type = api_command_type::BalanceSheet;

  // Test queries
  std::vector<std::pair<std::string, std::string>> queries = {
      {"period", "annual"}, {"limit", "1"}, {"RandomWrongQueryTest", "hi"}};

  // Create and execute command
  std::unique_ptr<ApiCommand> curr = std::make_unique<ApiCommand>(
      ticker, api_key, queries, YAML_FILE_PATH, requested_api_command_type);
  nlohmann::json response = curr->execute();

  // Creating data formatter designed to format data depending on the use, note
  // this is where my development on this is going to halt as I am yet to
  // determine which format I wish to have for my project.
  auto formatter =
      FormatterFactory::createFormatter(requested_api_command_type);

  // Creating data saver to save data
  auto saver = std::make_unique<DataSaver>();

  // Using response manager to handle response
  ResponseManager manager(std::move(formatter), std::move(saver));
  manager.handleResponse(response, SAVE_FILE_NAME);
}
