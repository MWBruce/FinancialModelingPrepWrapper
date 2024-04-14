#include "../include/response_formatter.h"

// returns string of formatted data as created by accompanying formatData
// function defined by childeren
std::string ResponseFormatter::getFormattedData() {
  return formatted_Data;
}

void ResponseFormatter::formatData(const nlohmann::json& response) {
  formatted_Data = response.dump(4);
  // Going to format this based on what my honours project requires, not at the
  // point yet where I can determine, how I want my data formatted.
}