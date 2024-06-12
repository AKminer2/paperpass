#include <iostream>
#include <string>
#include <cstring>
#include <map>

// an enum of all the error types
enum ErrorType
{
    UNKNOWN_OPTION
};

void printUsage();
void printError(ErrorType error, std::map<std::string,std::string> data);

int main(int argc, char **argv)
{

    if (argc > 1)
    {
        
        // this is the option that the user inputs - paperpass [option] [parameters]
        std::string option = argv[1];

        // print a help page
        if (strcmp(argv[1], "--help") == 0)
        {
            printUsage();
        }

        // unknown option error
        else
        {
            std::map<std::string,std::string> data;
            data["option"] = option;

            printError(UNKNOWN_OPTION, data);
        }
    }
    else
    {
        // if no option is supplied, simply print the help page
        printUsage();
    }
}

// print a help page
void printUsage()
{
    const std::string usage = "\n"
                              "Usage: paperpass [option] [parameters]\n"
                              "\n"
                              "Options:\n"
                              "\n"
                              "--help, -h\n"
                              "Display this help page.\n\n";

    std::cout << usage;
}

/* 
* print an error with an error type.
* error_data holds a map containing information such as the option
* the way error_data is read depends on the error type.
*/
void printError(
    ErrorType error, 
    std::map<std::string,std::string> error_data
    )
{

    switch (error)
    {
        case UNKNOWN_OPTION:
        const std::string UNKNOWN_OPTION_ERROR_MESSAGE = (std::string)
                                                         "\n"
                                                         "Error: Unknown Option: "+error_data["option"]+
                                                         "\n";
                                                         

        std::cout << UNKNOWN_OPTION_ERROR_MESSAGE;
        printUsage();
        break;
    }
}
