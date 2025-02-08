#include <iostream>
#include <fstream>
#include <string>

void copyFileContent(const std::string& sourceFile, const std::string& destFile) {
    std::ifstream inFile(sourceFile);
    if (!inFile.is_open()) {
        std::cout << "Error: Cannot open source file " << sourceFile << std::endl;
        return;
    }

    std::ofstream outFile(destFile);
    if (!outFile.is_open()) {
        std::cout << "Error: Cannot open destination file " << destFile << std::endl;
        inFile.close();
        return;
    }

    std::string line;

    while (std::getline(inFile, line)) {
        outFile << line << std::endl;
    }

    std::cout << "File content has been copied!" << std::endl;

    inFile.close();
    outFile.close();
}

int main() {
    std::string sourceFileName = "source.txt";
    std::string destFileName = "destination.txt";

    copyFileContent(sourceFileName, destFileName);

    return 0;
}