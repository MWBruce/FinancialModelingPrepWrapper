#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <utility>
#include <vector>

#include "../include/api_command.h"
#include "../include/data_saver.h"
#include "../include/formatter_factory.h"
#include "../include/response_manager.h"

// YAML config file location
const std::string YAML_FILE_PATH = "api_config.YAML";

// Save file location
const std::string SAVE_FILE_NAME = "test.csv";

// Api command type
const api_command_type REQUESTED_API_COMMAND_TYPE = api_command_type::DCF;

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <ticker> <api_key>\n";
    return 1;
  }

  // Command line inputs
  std::string ticker = argv[1];
  std::string api_key = argv[2];


  // Test queries (could probably make these their own object but probably not necessary at the moment)
  std::vector<std::pair<std::string, std::string>> queries = {
      {"period", "annual"}, {"limit", "1"}, {"RandomWrongQueryTest", "hi"}};

  // Create and execute command
  std::unique_ptr<ApiCommand> curr = std::make_unique<ApiCommand>(
      ticker, api_key, queries, YAML_FILE_PATH, REQUESTED_API_COMMAND_TYPE);
  nlohmann::json response = curr->execute();

  // Creating data formatter designed to format data depending on the use, note
  // this is where my development on this is going to halt as I am yet to
  // determine which format I wish to have for my project.
  auto formatter =
      FormatterFactory::createFormatter(REQUESTED_API_COMMAND_TYPE);

  // Creating data saver to save data
  auto saver = std::make_unique<DataSaver>();

  // Using response manager to handle response
  ResponseManager manager(std::move(formatter), std::move(saver));
  manager.handleResponse(response, SAVE_FILE_NAME);
}
