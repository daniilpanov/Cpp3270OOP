#include <iostream>
#include <fstream>
#include <vector>

void process() {
    std::ifstream rfInput;
    rfInput.open("input.txt", std::ifstream::in);

    if (!rfInput.is_open()) {
        throw std::runtime_error("Cannot open the file!");
    }

    char c;
    std::vector<int> matrix;
    int current_number{__INT_MAX__};
    int rows{1};

    while (rfInput.get(c)) {
        if (c < '0' || c > '9') {
            if (c == '\n') {
                ++rows;
            }
            matrix.push_back(current_number);
            current_number = __INT_MAX__;
            continue;
        }
        if (current_number == __INT_MAX__) {
            current_number = c - '0';
        } else {
            current_number *= 10;
            current_number += c - '0';
        }
    }
    if (c >= '0' && c <= '9')
        matrix.push_back(current_number);
    rfInput.close();

    std::ofstream rfOutput;
    rfOutput.open("input.txt", std::ofstream::out);
    int cols{static_cast<int>(matrix.size() / rows)};

    std::cout << "Rows: " << rows << ", cols: " << cols << std::endl;

    for (int i{0}, iter_count{1}, all_iter_count{1}; i < rows; ++i) {
        for (int j{0}; j < cols; ++j, ++iter_count, ++all_iter_count) {
            std::cout << i << '-' << j << '-' << i * rows + j << std::endl;
            rfOutput << matrix.at(i * cols + j);
            if (iter_count % rows == 0) {
                if (all_iter_count < matrix.size()) {
                    iter_count = 0;
                    rfOutput << '\n';
                }
            } else {
                rfOutput << ' ';
            }
        }
    }
    rfOutput.flush();
    rfOutput.close();
    std::cout << "File is rewrote" << std::endl;
}

int main() {
    try {
        process();
    } catch (std::runtime_error &exc) {
        std::cerr << exc.what() << std::endl;
    }

    return 0;
}
