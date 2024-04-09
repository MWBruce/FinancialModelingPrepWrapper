#include "../include/response_formatters.h"

void BalanceSheetFormatter::formatData(const nlohmann::json& response) {
  formatted_Data = response.dump(4);
  // Going to format this based on what my honours project requires, not at the
  // point yet where I can determine, how I want my data formatted.
}

void CashFlowFormatter::formatData(const nlohmann::json& response) {
  formatted_Data = response.dump(4);
  // Going to format this based on what my honours project requires, not at the
  // point yet where I can determine, how I want my data formatted.
}
