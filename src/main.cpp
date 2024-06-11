#include <iostream>
#include <string>

const std::string usage = "\n"
                          "Usage: paperpass [option] [parameters]\n"
                          "\n"
                          "Options:\n"
                          "\n"
                          "--help, -h\n"
                          "Display this help page.\n\n";

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (argv[1] == "--help" or argv[1] == "-h")
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