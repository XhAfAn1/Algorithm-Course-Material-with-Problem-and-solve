#include <iostream>
using namespace std;

void computePrefixTable(string pattern, int lps[], int n) {
    int length = 0;
    int i = 1;
    lps[0] = 0;
    while (i < n) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string text, string pattern, int lps[]){
    int n = text.length();
    int m =pattern.length();
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            std::cout << "Found pattern at index " << i - j << std::endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}



int main() {
    string s="fox the quick brown fox jumps over the lazy dog fox";
    string p="fox";
    int n = p.length();
    int m =s.length();
    int lps[n];
    computePrefixTable(p, lps, n);
    kmp(s,p,lps);


    return 0;
}

