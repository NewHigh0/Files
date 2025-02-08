#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

void copyFileContentReverse(const std::string& sourceFile, const std::string& destFile) {
    std::ifstream inFile(sourceFile);
    if (!inFile.is_open()) {
        std::cout << "Error: Cannot open source file " << sourceFile << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inFile, line)) {
        lines.push_back(line);
    }
    inFile.close();

    std::ofstream outFile(destFile);
    if (!outFile.is_open()) {
        std::cout << "Error: Cannot open destination file " << destFile << std::endl;
        return;
    }

    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
        outFile << *it << std::endl;
    }

    std::cout << "File content has been copied!" << std::endl;
    outFile.close();
}

int main() {
    std::string sourceFileName = "source.txt";
    std::string destFileName = "destination.txt";

    // copyFileContent(sourceFileName, destFileName);

    copyFileContentReverse(sourceFileName, destFileName);

    return 0;
}