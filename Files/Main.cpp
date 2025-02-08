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

void compareFiles(const std::string& file1Name, const std::string& file2Name) {
    std::ifstream file1(file1Name);
    if (!file1.is_open()) {
        std::cout << "Error: Cannot open first file " << file1Name << std::endl;
        return;
    }

    std::ifstream file2(file2Name);
    if (!file2.is_open()) {
        std::cout << "Error: Cannot open second file " << file2Name << std::endl;
        file1.close();
        return;
    }

    std::string line1, line2;
    int lineNumber = 1;
    bool filesMatch = true;
    bool file1Ended = false;
    bool file2Ended = false;

    while (true) {
        bool hasLine1 = static_cast<bool>(std::getline(file1, line1));
        bool hasLine2 = static_cast<bool>(std::getline(file2, line2));

        if (!hasLine1 && !hasLine2) {
            break;
        }

        if (!hasLine1 || !hasLine2 || line1 != line2) {
            filesMatch = false;
            std::cout << "Mismatch at line " << lineNumber << ":" << std::endl;

            if (hasLine1) {
                std::cout << "File 1: " << line1 << std::endl;
            }
            else {
                std::cout << "File 1: <end of file>" << std::endl;
            }

            if (hasLine2) {
                std::cout << "File 2: " << line2 << std::endl;
            }
            else {
                std::cout << "File 2: <end of file>" << std::endl;
            }
        }
        lineNumber++;
    }

    if (filesMatch) {
        std::cout << "Files are identical!" << std::endl;
    }

    file1.close();
    file2.close();
}

void analyzeFile(const std::string& sourceFile, const std::string& destFile) {
    std::ifstream inFile(sourceFile);
    if (!inFile.is_open()) {
        std::cout << "Error: Cannot open source file " << sourceFile << std::endl;
        return;
    }

    int totalChars = 0;
    int lines = 0;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    std::string line;

    while (std::getline(inFile, line)) {
        lines++;

        for (char c : line) {
            totalChars++;

            char lower = std::tolower(c);

            if (lower == 'a' || lower == 'e' || lower == 'i' ||
                lower == 'o' || lower == 'u' || lower == 'y') {
                vowels++;
            }
            else if (std::isalpha(c)) {
                consonants++;
            }
            else if (std::isdigit(c)) {
                digits++;
            }
        }
        totalChars++;
    }

    inFile.close();

    std::ofstream outFile(destFile);
    if (!outFile.is_open()) {
        std::cout << "Error: Cannot open destination file " << destFile << std::endl;
        return;
    }

    outFile << "Total characters: " << totalChars << "\n";
    outFile << "Total lines: " << lines << "\n";
    outFile << "Vowels: " << vowels << "\n";
    outFile << "Consonants: " << consonants << "\n";
    outFile << "Digits: " << digits << "\n";

    outFile.close();

    std::cout << "Statistics have been written to " << destFile << std::endl;
}

void caesarCipher(const std::string& sourceFile, const std::string& destFile, int shift) {
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

    char ch;
    while (inFile.get(ch)) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';

            ch = base + (ch - base + shift) % 26;

            if (ch < base) {
                ch += 26;
            }
        }
        outFile.put(ch);
    }

    std::cout << "File has been encrypted!" << std::endl;

    inFile.close();
    outFile.close();
}

int main() {
    std::string sourceFileName = "source.txt";
    std::string destFileName = "destination.txt";
    int shift = 3;

    // copyFileContent(sourceFileName, destFileName);

    // copyFileContentReverse(sourceFileName, destFileName);

    // processFile(sourceFileName, destFileName);

    // compareFiles(sourceFileName, destFileName);

    // analyzeFile(sourceFileName, destFileName);

    caesarCipher(sourceFileName, destFileName, shift);

    return 0;
}