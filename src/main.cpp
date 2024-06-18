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
    UNKNOWN_OPTION,
    BAD_ARG_COUNT,
    UNKNOWN_ARG
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
        // --credits
        else if (strcmp(argv[1], "--credits") == 0)
        {
            printCredits();
        }
        // show c or show w for GPLv3 license
        else if (strcmp(argv[1], "show") == 0)
        {
            if (argc == 3)
            {
                if (strcmp(argv[2], "c") == 0)
                {
                    
                }
                else if (strcmp(argv[2], "w") == 0)
                {
                    
                }
                else
                {
                    std::map<std::string,std::string> data;
                    data["option"] = "show";
                    data["arg"] = argv[2];
                    printError(UNKNOWN_ARG, data);
                }
            }
            else
            {
                std::map<std::string,std::string> data;
                data["option"] = "show";
                data["arg_count"] = "1";
                printError(BAD_ARG_COUNT, data);
            }
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
    const std::string usage = (std::string)
                              "\n"
                              "Usage: paperpass [option] [parameters]\n"
                              "\n"
                              "Options:\n"
                              "\n"
                              "--help, -h\n"
                              "Display this help page.\n\n"
                              "--version\n"
                              "Display the version.\n\n"
                              "--credits\n"
                              "Display credits.\n\n";

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
        std::cout << (std::string)
                     "\n"
                     "Error: Unknown Option: "+error_data["option"]+
                     "\n";
        printUsage();
        break;

        case BAD_ARG_COUNT:
        std::cout << (std::string)
                     "\n"
                     "Error: arguments to '"+error_data["option"]+"' are missing or too many were provided (expected "+error_data["arg_count"]+" value)\n"
                     "\n";
        break;

        case UNKNOWN_ARG:
        std::cout << (std::string)
                     "\n"
                     "Error: unknown or bad argument '"+error_data["arg"]+"' to the option '"+error_data["option"]+"'\n"
                     "\n";
        break;
    }
}

void printVersion()
{
    const std::string VERSION = (std::string)
                                "\n"
                                "Paperpass v0.1.0  Copyright (C) 2024  Ari Kanbur\n"
                                "This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
                                "This is free software, and you are welcome to redistribute it\n"
                                "under certain conditions; type `show c' for details.\n\n";

    std::cout << VERSION;
}

void printCredits()
{
    const std::string CREDITS = (std::string)
                                "\n"
                                "Credit to the authors of the project and all who contributed on Github.\n"
                                "(https://github.com/AKminer2/paperpass)\n\n"
                                "Authors:\n"
                                "Ari Kanbur (AKminer2)\n\n";

    std::cout << CREDITS;
}