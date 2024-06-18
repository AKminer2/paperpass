// Paperpass: A password manager for your terminal
// Copyright (C) 2024  Ari Kanbur

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
void printVersion();
void printCredits();

int main(int argc, char **argv)
{

    if (argc > 1)
    {
        
        // this is the option that the user inputs - paperpass [option] [parameters]
        const std::string option = argv[1];

        // print a help page
        if (strcmp(argv[1], "--help") == 0)
        {
            printUsage();
        }
        // --version
        else if (strcmp(argv[1], "--version") == 0)
        {
            printVersion();
        }
        else if (strcmp(argv[1], "--credits") == 0)
        {
            printCredits();
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

    return 0;
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

void printVersion()
{
    const std::string VERSION = (std::string)
                                "Paperpass v0.1.0  Copyright (C) 2024  Ari Kanbur\n"
                                "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
                                "This is free software, and you are welcome to redistribute it\n"
                                "under certain conditions; type `show c' for details.\n";

    std::cout << VERSION;
}

void printCredits()
{
    const std::string CREDITS = (std::string)
                                "Credit to the authors of the project and all who contributed on Github.\n"
                                "Authors:\n"
                                "Ari Kanbur (AKminer2)\n";

    std::cout << CREDITS;
}