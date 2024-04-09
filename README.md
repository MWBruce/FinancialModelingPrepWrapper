To Run:
 Please run "./run.sh" in your terminal

Note: The current implementation supports two API command types: api_command_type::BalanceSheet and api_command_type::CashFlow. This framework serves as a robust template designed for scalability. It can easily accommodate an expanding range of command types as needed in future developments. At this stage of my honors project, the balance sheet and cash flow formatters are in preliminary phases of development. The specific formatting details for these components are yet to be finalized due to the yet to be determined format/data required for my honours project. 


Project Structure:
main.cpp - 
    Main entry point for application. Currently runs through three additional query parameters (one incorrect one to test error handling given my aims to eventually make this open source).

api_spec_parser - 
    Responsible for parsing the YAML file that contains the API specifications to assist in the construction of api_endpoints.
api_endpoint - 
    Represents individual API endpoints. 
call_api -
    Handles the low-level API call operation. 
api_command - 
    Central command class responsible for executing API requests (Using both api_endpoint and api_spec_parser to construct/manage api calls and call_api to make the call itself)

formatter_factory - 
    A factory class responsible for creating instances of response formatters based on the specified command type. 
interface_response_formatter - 
    An abstract class that defines the structure for response formatters.
response_formatters - 
    A series of formatters (currently only balancesheet and cashflow) which inherit from the formatter interface to manage various api responses. As there might be over 100 different API calls I might change the file arrangement relating to these formatters.
data_saver - 
    A utility class designed to save formatted data to a file.
response_manager - 
    MCoordinates the formatting and saving of API response data using formatter and saver classes.


Adding New API Endpoints:
1. Modify the YAML file to include the new API endpoint (Ensuringing it adheres to OpenAPI format).
2. In the ApiCommand class, add the new endpoint to the API_ENDPOINTS mapping. This mapping is used to associate API command types with their corresponding endpoint URLs.
3. Should you require a unique formatter you may build one or you can use an existing one. 