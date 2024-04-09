#include "../include/response_manager.h"

// Constructor recieves in formatter and saver to handle response
ResponseManager::ResponseManager(
    std::unique_ptr<InterfaceResponseFormatter> formatter,
    std::unique_ptr<DataSaver> saver)
    : formatter(std::move(formatter)), saver(std::move(saver)) {}

// Function handling response and then saving to specified file
void ResponseManager::handleResponse(const nlohmann::json& response,
                                     const std::string& saveFileName) {
  formatter->formatData(response);
  std::string formattedData = formatter->getFormattedData();
  saver->saveData(formattedData, saveFileName);
}