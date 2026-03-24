#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// 生成测试文件的函数
void generateTestFile(int testNum, long long T, long long n) {
    std::ofstream file(std::to_string(testNum) + ".in");
    if (file.is_open()) {
        file << T << std::endl;
        for (int i = 0; i < T; ++i) {
            file << rand() % 1000000000000000000ll + 3 << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 测试用例1：10%的评测用例，T = 1, 3 ≤ n ≤ 10
    generateTestFile(1, 1, rand() % 8 + 3);

    // 测试用例2：40%的评测用例，1 ≤ T ≤ 10², 3 ≤ n ≤ 3 × 10³
    generateTestFile(2, rand() % 100 + 1, rand() % 3000 + 3);

    // 测试用例3：40%的评测用例，1 ≤ T ≤ 10², 3 ≤ n ≤ 3 × 10³
    generateTestFile(3, rand() % 100 + 1, rand() % 3000 + 3);

    // 测试用例4：所有评测用例，1 ≤ T ≤ 10⁵, 3 ≤ n ≤ 10¹⁸
    generateTestFile(4, rand() % 100000 + 1, rand() % 1000000000000000000ll + 3);

    // 测试用例5：所有评测用例，1 ≤ T ≤ 10⁵, 3 ≤ n ≤ 10¹⁸
    generateTestFile(5, rand() % 100000 + 1, rand() % 1000000000000000000ll + 3);
    cout<<"执行完毕\n";
    return 0;
}