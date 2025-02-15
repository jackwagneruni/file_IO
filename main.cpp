#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main(){
    std::ifstream inFile;
    std::string currentLine;
    std::stringstream converter;
    std::stringstream ss;
    int num1, num2, sum;
    std::string sNum1, sNum2, text;

    inFile.open("data.csv");

    while (getline(inFile, currentLine)) {
        // Clear the stringstreams
        ss.clear();
        ss.str("");
        converter.clear();
        converter.str("");

        // Load the line into stringstream for parsing
        ss.str(currentLine);

        // Read first integer
        getline(ss, sNum1, ',');
        // Read second integer
        getline(ss, sNum2, ',');
        // Read text (default delimiter is newline)
        getline(ss, text);

        // Convert numbers using the converter stream
        converter << sNum1;
        converter >> num1;
        converter.clear();
        converter.str("");

        converter << sNum2;
        converter >> num2;

        // Compute sum
        sum = num1 + num2;

        // Print text sum times
        for (int i = 0; i < sum; i++) {
            std::cout << text << " ";
        }
        std::cout << std::endl;
    }

    inFile.close();
} // end main
