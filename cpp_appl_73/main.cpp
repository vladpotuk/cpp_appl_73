#include "functions.h"

int main() {
    const std::string inputFilename = "input.txt";
    const std::string outputFilename = "output_modified.txt";

    addLineAfterLastNonSpace(inputFilename, outputFilename);

    return 0;
}
