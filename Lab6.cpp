//Emma Bilhimer
//Mr. Busch Lab 6
/*Lab Name: Lab 6 Binary to Decimal Conversion
 Description: Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns with
appropriate headings. Here is a sample of the input and output:
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("BinaryIn.dat");

    if (!inputFile) {
        cout << "Cannot open file BinaryIn.dat." << endl;
        return 1;
    }

    cout << "Binary Number    Decimal Number" << endl;
    char c;
    int decimal = 0;
    bool isBinaryNumber = false;

    while (inputFile.get(c)) {
        if (c == '0' || c == '1') {
            decimal = decimal * 2 + (c - '0'); // this will convert character '0' or '1' to integer 0 or 1
            isBinaryNumber = true;
        } else if (c == ' ') {
            // this will ignore spaces between the binary numbers for the table
        } else {
            // sends as bad digit if binary digit is not found
            cout << "Bad digit on input" << endl;
            isBinaryNumber = false;
            decimal = 0;
        }

        if (c == '\n' || c == EOF) {
            if (isBinaryNumber) {
                cout << decimal << "            " << decimal << endl;
            }
            decimal = 0;
            isBinaryNumber = false;
        }
    }

    inputFile.close();
    return 0;
}

