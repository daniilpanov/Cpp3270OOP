#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

void process() {
    std::ifstream rfInput;
    rfInput.open("input.txt", std::ifstream::in);

    if (!rfInput.is_open()) {
        throw std::runtime_error("Cannot open the file!");
    }

    char c;
    std::map<char, long int> sym_count;
    std::stringstream resstr;

    while (rfInput.get(c)) {
        if (c >= '0' && c <= '9') {
            continue;
        }
        resstr << c;
        if (!sym_count.contains(c)) {
            sym_count[c] = 1;
        } else {
            ++sym_count[c];
        }
    }

    rfInput.close();

    std::cout << "------" << std::endl;
    std::cout << "Counting symbols..." << std::endl;
    for (auto& kv : sym_count) {
        if (kv.first == '\n') {
            std::cout << "\\n";
        } else if (kv.first == '\r') {
            std::cout << "\\r";
        } else {
            std::cout << kv.first;
        }
        std::cout << " was found " << kv.second << " times" << std::endl;
    }
    std::cout << "------" << std::endl;

    std::ofstream rfOutput;
    rfOutput.open("input.txt", std::ofstream::out);

    if (!rfOutput.is_open()) {
        throw std::runtime_error("Cannot rewrite the file!");
    }

    rfOutput << resstr.rdbuf();
    rfOutput.flush();
    rfOutput.close();

    std::cout << "File is rewrote" << std::endl;
}

int main() {
    try {
        process();
    } catch (std::exception& exc) {
        std::cerr << exc.what() << std::endl;
    }

    return 0;
}
