#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <map>
#include <algorithm>
#include <unordered_set>



// https://leetcode.com/problems/valid-sudoku/
namespace valid_sudoku{
    // use

    /*valid_sudoku::Solution valid_sudoku;
    std::vector<std::vector<char>> board = { std::vector<char>{ '5', '3', '.', '.', '7', '.', '.', '.', '.' }
                                            , std::vector<char>{ '6', '.', '.', '1', '9', '5', '.', '.', '.' }
                                            , std::vector<char>{ '.', '9', '8', '.', '.', '.', '.', '6', '.' }
                                            , std::vector<char>{ '8', '.', '.', '.', '6', '.', '.', '.', '3' }
                                            , std::vector<char>{ '4', '.', '.', '8', '.', '3', '.', '.', '1' }
                                            , std::vector<char>{ '7', '.', '.', '.', '2', '.', '.', '.', '6' }
                                            , std::vector<char>{ '.', '6', '.', '.', '.', '.', '2', '8', '.' }
                                            , std::vector<char>{ '.', '.', '.', '4', '1', '9', '.', '.', '5' }
                                            , std::vector<char>{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
    std::cout << valid_sudoku.isValidSudoku(board) << '\n';*/

    class Solution {
    public:
        bool isValidSudoku(std::vector<std::vector<char>>& board) {
            std::map<const char, std::size_t> chr_cnt = { {'1', 0},
                 {'2', 0},
                 {'3', 0},
                 {'4', 0},
                 {'5', 0},
                 {'6', 0},
                 {'7', 0},
                 {'8', 0},
                 {'9', 0}
            };
            
            // string check
            for (std::size_t i = 0; i < 9; ++i) {
                for (std::size_t j = 0; j < 9; ++j) {
                    if (board[i][j] != '.') {
                        ++chr_cnt[(board[i][j])];
                        if (chr_cnt[uint8_t(board[i][j])] == 2) {
                            return false;
                        }
                    }
                }
                //for (uint8_t i = 49; i < 58; ++i) {
                //    //chr_cnt[i] = 3;
                //    std::cout << chr_cnt[i] << " " << i << '\n';
                //}
                //std::cout << "---" << '\n';
                null_map(chr_cnt);
            }

            // column check
            for (std::size_t i = 0; i < 9; ++i) {
                for (std::size_t j = 0; j < 9; ++j) {
                    if (board[j][i] != '.') {
                        ++chr_cnt[(board[j][i])];
                        if (chr_cnt[uint8_t(board[j][i])] == 2) {
                            return false;
                        }
                    }
                }
                null_map(chr_cnt);
            }
            for (std::size_t y = 0; y < 3; ++y) {
                for (std::size_t x = 0; x < 3; ++x) {
                    for (std::size_t i = 0; i < 3; ++i) {
                        for (std::size_t j = 0; j < 3; ++j) {
                            if (board[y * 3 + i][x * 3 + j] != '.') {
                                ++chr_cnt[(board[y * 3 + i][x * 3 + j])];
                                if (chr_cnt[uint8_t(board[y * 3 + i][x * 3 + j])] == 2) {
                                    return false;
                                }
                            }
                        }
                    }
                    null_map(chr_cnt);
                }
                //for (uint8_t i = 49; i < 58; ++i) {
                //    //chr_cnt[i] = 3;
                //    std::cout << chr_cnt[i] << " " << i << '\n';
                //}
                //std::cout << "---" << '\n';
            }

            return true;
        }

        void null_map(std::map<const char, std::size_t>& chr_cnt) {
            for (uint8_t i = 49; i < 58; ++i) {
                chr_cnt[i] = 0;
            }
        }
    };
}

namespace Tinkoff {
    void task() {
        int i1, i2;
        std::cin >> i1;
        std::cin >> i2;
        std::cout << (i1 + i2);
    }

    namespace t3 {
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <map>

        bool isGood(std::string_view str_in) {
            if ((str_in.find('a') != str_in.npos) && (str_in.find('b') != str_in.npos) && (str_in.find('c') != str_in.npos) && (str_in.find('d') != str_in.npos)) {
                return true;
            }
            else {
                return false;
            }
        }

        void task3() {
            std::string str = "aabbccddbadd";
            int ssize;
            std::cin >> ssize;
            std::cin >> str;
            if (!isGood(str)) { std::cout << "-1"; return; }

            std::size_t min = -1;

            for (std::size_t i = 0; i != ssize - 1; ++i) {
                if (str[i] == str[i + 1]) { continue; };
                for (std::size_t j = 4; j < ssize - i; ++j) {
                    if(isGood(str.substr(i, j))){
                        if (j < min) {
                            min = j;
                        }
                        break;
                    }
                }
                if (min == 4) {
                    std::cout << min;
                }
            }

            std::cout << min;
        }

        int main() {
            task3();
            return 0;
        }

        
    }

    namespace t2 {
#include <iostream>

        int getTime() {
            int n = 7, m = 3, k = 2;
            int m_tmp = m, mod_k = 0;
            std::cin >> n >> m >> k;

            int time = 0;
            for (; n > 0;) {
                while (m_tmp >= k) {
                    if (mod_k) {
                        m_tmp -= mod_k;
                        mod_k = 0;
                    }
                    else {
                        m_tmp -= k;
                    }
                    n--;
                }
                mod_k = k - m_tmp;
                m_tmp = m;

                time++;
            }

            return time;
        }

        int lesGo() {
            std::cout << getTime() << std::endl;

            return 0;
        }
    }
    
    namespace t4 {
        
        int FindIndexOfElementEqualOne(std::vector<int>& array)
        {
            for (int i = 0; i < array.size(); i++)
            {
                if (array[i] == 1)
                {
                    return i;
                }
            }
            return -1;
        }

        int Task4(int n, std::vector<int>& array)
        {
            int maxBoringPrefix = 0;
            std::vector<int> count(200001);
            std::unordered_set<int> allNumbers;

                for (int i = 0; i < n; i++)
                {
                    count[array[i]]++;
                    allNumbers.insert(array[i]);
                    int maxCount = *max_element(count.begin(), count.end());

                    int isElementEqualOne = FindIndexOfElementEqualOne(count);

                    if (allNumbers.size() == 1)
                    {
                        maxBoringPrefix = i + 1;
                    }
                    else if (isElementEqualOne != -1)
                    {
                        bool isCountNumbersEqual = true;
                        int equalValue = -1;

                        for (int item : allNumbers)
                        {
                            if (equalValue == -1)
                            {
                                equalValue = count[item];
                            }
                            else if (count[item] != equalValue && item != isElementEqualOne)
                            {
                                isCountNumbersEqual = false;
                            }
                        }

                        if (isCountNumbersEqual)
                        {
                            maxBoringPrefix = i + 1;
                        }
                    }
                    else
                    {
                        bool isCountNumbersEqual = true;
                        int indexMax = distance(count.begin(), max_element(count.begin(), count.end()));
                        int equalValue = maxCount - 1;

                        for (int item : allNumbers)
                        {
                            if (count[item] != equalValue && (item != indexMax))
                            {
                                isCountNumbersEqual = false;
                            }
                        }

                        if (isCountNumbersEqual)
                        {
                            maxBoringPrefix = i + 1;
                        }
                    }
                }

            return maxBoringPrefix;

        }

        int main()
        {
            int n;
            std::cin >> n;
            std::vector<int> array(n);
            for (int i = 0; i < n; i++)
            {
                std::cin >> array[i];
            }

            std::cout << Task4(n, array) << std::endl;

            return 0;

        }
    }

    namespace t6 {

        using namespace std;
        const int MAXN = 100005;

        int n, t;
        int a[MAXN], b[MAXN];

#include <iostream>
#include <vector>

        using namespace std;

        int main() {
            int n = 4;
            std::cin >> n;
            int buf;
            vector<int> nums;
            for (int i = 0; i < n; ++i) {
                std::cin >> buf;
                nums.push_back(buf);
            }

            //vector<int> nums = { 1, 2, 3, -6 };


            int res = 0;
            for (int l = 0; l < n; ++l) {
                int r = l + 1;
                while (r < n) {
                    int s = 0;
                    for (int i = l; i <= r; ++i) {
                        s += nums[i];
                    }
                    if (s == 0) {
                        res += n - r;
                    }
                    r += 1;
                }
            }

            cout << res << endl;
            return 0;
        }
    }

}
