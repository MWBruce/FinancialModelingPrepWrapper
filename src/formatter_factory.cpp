// FormatterFactory.cpp

#include "../include/formatter_factory.h"

// Creates the relevant formatter for each api_command_type
std::unique_ptr<InterfaceResponseFormatter> FormatterFactory::createFormatter(
    api_command_type type) {
  switch (type) {
    case api_command_type::BalanceSheet:
      return std::make_unique<BalanceSheetFormatter>();
    case api_command_type::CashFlow:
      return std::make_unique<CashFlowFormatter>();
    default:
      throw std::runtime_error("Unsupported command type");
  }
}
