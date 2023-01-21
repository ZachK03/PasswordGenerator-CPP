#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>

void CreateHeaderText(std::string text);
void CreateDividerText();
void CreateErrorText(std::string text);
bool GetBoolUserInput(std::string text);
bool GetRandomBool(double chance);

std::string CreatePassword(int lengthOfPassword, int numOfNums, int numOfSymbols);
char GetRandomElement(std::vector<char> vect);
int GetRandomIndex(std::vector<char> vect);
std::vector<char> AlphabetVect {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
std::vector<char> SymbolVect {'.','!','@','#','$','%','^','&','*','(',')','_','-','=','+','<','>','/','?',',',':',';','`','~'};
std::vector<char> NumbersVect {'1','2','3','4','5','6','7','8','9','0'};

int main() {
    srand(time(0));
    std::cout << "\n\n";
    CreateHeaderText("=-= Random Password Generator =-=");
    std::cout << "\n\n";
    bool isRunning = true;

    do {
        int lengthOfPassword;
        int numOfNums;
        int numOfSymbols;
        std::cout << "How long should the password be? ";
        std::cin >> lengthOfPassword;

        std::cout << "How many numbers should it use? ";
        std::cin >> numOfNums;

        std::cout << "How many symbols should it use? ";
        std::cin >> numOfSymbols;

        std::cout << "\nGenerating...\n";
        std::string generatedPassword = CreatePassword(lengthOfPassword, numOfNums, numOfSymbols);
        CreateHeaderText("Generated Password: " + generatedPassword);

        if(GetBoolUserInput("Generate another? Y/N\n")) {
            std::cout << "\n";
        } else {
            isRunning = false;
        }
    } while (isRunning);

    return 0;
}

std::string CreatePassword(int lengthOfPassword, int numOfNums, int numOfSymbols) {
    std::vector<char> passwordVect;
    std::vector<bool> changedIndices;
    std::string password;
    char character;
    int countSymbols = 0;
    int randIndex;
    for (int i = 0; i < lengthOfPassword; i++) {
        character = GetRandomElement(AlphabetVect);
        if(GetRandomBool(0.5)) {
            character = tolower(character);
        }
        passwordVect.push_back(character);
        changedIndices.push_back(false);
    }
    for(int i = 0; i < numOfNums; i++) {
        while (changedIndices[randIndex]) {
            randIndex = GetRandomIndex(passwordVect);
        }
        passwordVect[randIndex] = GetRandomElement(NumbersVect);
        changedIndices[randIndex] = true;
    }
    for(int i = 0; i < numOfSymbols; i++) {
        while (changedIndices[randIndex]) {
            randIndex = GetRandomIndex(passwordVect);
        }
        passwordVect[randIndex] = GetRandomElement(SymbolVect);
        changedIndices[randIndex] = true;
    }
    for (char letter : passwordVect)
    {
        password.push_back(letter);
    }
    return password;
}

char GetRandomElement(std::vector<char> vect) {
    int random = rand() % vect.size();
    return vect[random];
}

int GetRandomIndex(std::vector<char> vect) {
    return (rand() % vect.size());
}




void CreateHeaderText(std::string text) {
    for (int i = 0; i < text.size(); i++) {
        std::cout << "=";
    }
    std::cout << "\n" << text << "\n";
    for (int i = 0; i < text.size(); i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

void CreateDividerText() {
    for (int i = 0; i < 20; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

void CreateErrorText(std::string text) {
    std::string errorText = "[ERROR] : ";
    errorText += text;
    CreateHeaderText(errorText);
}

bool GetBoolUserInput(std::string text) {
    char input;
    while (toupper(input) != 'Y' && toupper(input) != 'N') {
        std::cout << text;
        std::cin >> input;
    }
    if(toupper(input) == 'Y') {
        return true;
    } else {
        return false;
    }
}

bool GetRandomBool(double chance) {
    int randomNum = rand() % 100;
    int compare = (chance * 100);
    if(randomNum < compare) {
        return true;
    }
    return false;
}
