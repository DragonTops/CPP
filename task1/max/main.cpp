#include <iostream>
#include <fstream>
#include <queue>
#include <string>

struct argConf {
    bool lines = false;
    bool bytes = false;
    bool words = false;
    bool chars = false;
    bool anything = false;
};
argConf conf;

constexpr const int SimpleHash(const char* arg) {
    int ans = 0;
    int multiplyer = 1;
    for (int i = 0; arg[i] != '\0'; i++) {
        ans += multiplyer * (int)arg[i];
        multiplyer *= 10;
    }
    return (const int) ans;
}

int CountLines(char* filename) {
    std::ifstream file(filename);

    std::string stuff;
    getline(file, stuff, '\0');
    
    int ans = 1;
    for (int i = 0; i < stuff.length(); i++) {
        if (stuff.at(i) == '\n') {
            ans++;
        }
    }

    file.close();
    return ans;
}

int CountBytes(char* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    int ans = file.tellg();
    file.close();
    return ans;
}

int CountChars(char* filename) {
    std::ifstream file(filename);

    std::string stuff;
    getline(file, stuff, '\0');
    file.close();

    return stuff.length();
}

int CountWords(char* filename) {
    std::ifstream file(filename);

    std::istream_iterator<std::string> in{ file }, end;
    int ans = std::distance(in, end);
    file.close();
    return ans;
}

std::string ProcessFile(char* file) {
    std::string ans = std::string(file) + ":\n";

    if (conf.lines)
        ans += "-lines: " + std::to_string(CountLines(file)) + "\n";
    if (conf.bytes)
        ans += "-bytes: " + std::to_string(CountBytes(file)) + "\n";
    if (conf.chars)
        ans += "-chars: " + std::to_string(CountChars(file)) + "\n";
    if (conf.words)
        ans += "-words: " + std::to_string(CountWords(file)) + "\n";

    return ans;
}

int main(int argc, char** argv) {
    std::queue<char*> fileque;

    //Парсинг флагов
    for (int i = 1; i < argc; i++) {
        switch (SimpleHash(argv[i])) {
        case SimpleHash("-l"):
            conf.lines = true;
            conf.anything = true;
            break;
        case SimpleHash("--lines"):
            conf.lines = true;
            conf.anything = true;
            break;
        case SimpleHash("-c"):
            conf.bytes = true;
            conf.anything = true;
            break;
        case SimpleHash("--bytes"):
            conf.bytes = true;
            conf.anything = true;
            break;
        case SimpleHash("-w"):
            conf.words = true;
            conf.anything = true;
            break;
        case SimpleHash("--words"):
            conf.words = true;
            conf.anything = true;
            break;
        case SimpleHash("-m"):
            conf.chars = true;
            conf.anything = true;
            break;
        case SimpleHash("--chars"):
            conf.chars = true;
            conf.anything = true;
            break;

        }
        
        if (argv[i][0] != '-') {
            fileque.push(argv[i]);
        }
    }

    if (fileque.empty()) {
        std::cout << "No target file specifed!\nUsage: WordCount.exe [OPTION] filename [filename,.....]";
        return -1;
    }

    if (not conf.anything) {
        conf.bytes = true;
        conf.chars = true;
        conf.words = true;
        conf.lines = true;
    }

    std::string ans;
    do {
        char* file = fileque.front();

        ans += ProcessFile(file);
        fileque.pop();
    } while (not fileque.empty());

    std::cout << ans;
    return 0;
}
