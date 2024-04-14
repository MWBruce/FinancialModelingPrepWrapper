# clear

mkdir -p build

g++ src/main.cpp src/call_api.cpp src/api_endpoint.cpp src/api_spec_parser.cpp src/api_command.cpp src/response_formatter.cpp src/response_formatters.cpp src/formatter_factory.cpp src/data_saver.cpp src/response_manager.cpp -lcurl -lyaml-cpp -o build/stockApp

API_KEY=$(cat API_KEY.txt)

./build/stockApp AAPL "$API_KEY"

rm -rf build
