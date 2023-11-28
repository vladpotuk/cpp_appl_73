#include "functions.h"
#include <iostream>

void addLineAfterLastNonSpace(const std::string& inputFilename, const std::string& outputFilename) {
    
    FILE* inputFile;
    if (fopen_s(&inputFile, inputFilename.c_str(), "r") != 0) {
        std::cerr << "Error opening file: " << inputFilename << std::endl;
        return;
    }

    
    FILE* outputFile;
    if (fopen_s(&outputFile, outputFilename.c_str(), "w") != 0) {
        std::cerr << "Error opening file: " << outputFilename << std::endl;
        fclose(inputFile);
        return;
    }

   
    const int maxLines = 1000;
    char lines[maxLines][1024]; 

    int lineCount = 0;
    int lastNonSpaceLine = -1;  

    while (lineCount < maxLines && fgets(lines[lineCount], sizeof(lines[lineCount]), inputFile)) {
        if (strcspn(lines[lineCount], " \t\r\n") == strlen(lines[lineCount]) - 1) {
            lastNonSpaceLine = lineCount;
        }
        lineCount++;
    }

    
    for (int i = 0; i < lineCount; i++) {
        fprintf(outputFile, "%s", lines[i]);

        
        if (i == lastNonSpaceLine) {
            fprintf(outputFile, "------------\n");
        }
    }

    
    fclose(inputFile);
    fclose(outputFile);

    std::cout << "File modified and written to " << outputFilename << std::endl;
}
