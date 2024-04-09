// FormatterFactory.h

#ifndef FORMATTER_FACTORY_H
#define FORMATTER_FACTORY_H

#include <memory>

#include "api_command.h"
#include "interface_response_formatter.h"
#include "response_formatters.h"

// Factory pattern to create formatter for applicable api command
class FormatterFactory {
 public:
  static std::unique_ptr<InterfaceResponseFormatter> createFormatter(
      api_command_type type);
};

#endif  // FORMATTER_FACTORY_H
