#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

void printText(std::vector<char>& raw, std::vector<char>& encrypted);
void replaceSingleChar(std::vector<char>& input, char current, char target);
void printSecretMap(const std::map<char, char>& secretMap);
void encryptText(std::vector<char>& encryptedText, const std::map<char, char>& secretMap);

int main(){
    std::cout << "Hello world, cryptoApp!\n";

    const std::string inputText = "Stoi na stacji lokomotywa";
    
    const std::map<char, char> secretMap{
        {'a', 'b'},
        {'o', 'k'},
        {'f', 'q'}
    };
    
    std::vector<char> rawText(inputText.begin(), inputText.end());
    std::vector<char> encryptedText(inputText.begin(), inputText.end()); 
    
    printSecretMap(secretMap);

    printText(rawText, encryptedText);
    
    encryptText(encryptedText, secretMap);
    printText(rawText, encryptedText);
 

    return 0;
}

void printText(std::vector<char>& raw, std::vector<char>& encrypted){
    std::cout << "In:  ";
    std::copy(raw.begin(), raw.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << "\n";    
    std::cout << "Out: ";
    std::copy(encrypted.begin(), encrypted.end(), std::ostream_iterator<char>(std::cout, ""));
    std::cout << "\n";    
}

void replaceSingleChar(std::vector<char>& input, char current, char target){
    std::replace(input.begin(), input.end(), current, target);
}


void printSecretMap(const std::map<char, char>& secretMap){
    std::for_each(secretMap.begin(), secretMap.end(), [](const auto& p){
                std::cout << p.first << ":" << p.second << "\n"; 
            });
}

void encryptText(std::vector<char>& encText, const std::map<char, char>& sMap){
    std::for_each(sMap.begin(), sMap.end(), [&](auto& p){ 
                    replaceSingleChar(encText, p.first, p.second); 
                });
}


