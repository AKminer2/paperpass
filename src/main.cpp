#include <iostream>
#include <string>
#include <cstring>

const std::string usage = "\n"
                          "Usage: paperpass [option] [parameters]\n"
                          "\n"
                          "Options:\n"
                          "\n"
                          "--help, -h\n"
                          "Display this help page.\n\n";

void printUsage();

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            printUsage();
        }
    }
    else
    {
        printUsage();
    }
}

void printUsage()
{
    std::cout << usage;
}