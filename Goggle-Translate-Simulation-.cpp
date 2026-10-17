#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class GoogleTranslate {
private:
    map<string, string> dictionary;

public:
    GoogleTranslate() {
        dictionary["hello"] = "مرحبا";
        dictionary["google"] = "جوجل";
        dictionary["code"] = "برمجة";
        dictionary["computer"] = "حاسوب";
    }

    string translateSentence(const string& sentence) {
        stringstream ss(sentence);
        string word, result = "";
        
        while (ss >> word) {
            if (dictionary.find(word) != dictionary.end()) {
                result += dictionary[word] + " ";
            } else {
                result += "[" + word + "] ";
            }
        }
        return result;
    }
};

int main() {
    GoogleTranslate translator;
    string input = "hello google computer code";
    cout << "Original: " << input << endl;
    cout << "Translated: " << translator.translateSentence(input) << endl;
    return 0;
}
