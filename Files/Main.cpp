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

void processFile(const std::string& sourceFile, const std::string& destFile) {
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
    int lastLineWithoutSpace = -1;
    int currentLine = 0;
    std::string allContent;

    while (std::getline(inFile, line)) {
        if (line.find(' ') == std::string::npos) {
            lastLineWithoutSpace = currentLine;
        }
        allContent += line + '\n';
        currentLine++;
    }

    inFile.clear();
    inFile.seekg(0);

    currentLine = 0;
    std::string dashLine(12, '-');

    while (std::getline(inFile, line)) {
        outFile << line << std::endl;

        if (currentLine == lastLineWithoutSpace) {
            outFile << dashLine << std::endl;
        }
        currentLine++;
    }

    if (lastLineWithoutSpace == -1) {
        outFile << dashLine << std::endl;
    }

    std::cout << "File has been processed successfully!" << std::endl;

    inFile.close();
    outFile.close();
}

int main() {
    std::string sourceFileName = "source.txt";
    std::string destFileName = "destination.txt";

    // copyFileContent(sourceFileName, destFileName);

    // copyFileContentReverse(sourceFileName, destFileName);

    processFile(sourceFileName, destFileName);

    return 0;
}