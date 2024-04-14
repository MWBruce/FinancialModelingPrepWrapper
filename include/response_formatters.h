#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

#include "response_formatter.h"

// Formatter for balance sheet
class BalanceSheetFormatter : public ResponseFormatter {
 public:
  // Format function to format the balancesheet json data
  void formatData(const nlohmann::json& response) override;
};

// Formatter for cash flow
class CashFlowFormatter : public ResponseFormatter {
 public:
  // Format function to format the cashflow json data
  void formatData(const nlohmann::json& response) override;
};

class DefaultFormatter : public ResponseFormatter {
 public:
  // Format function to format the cashflow json data
  void formatData(const nlohmann::json& response) override;
};