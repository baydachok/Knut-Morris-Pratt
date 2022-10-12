#include <iostream>
#include <vector>
using namespace std;
/**************************************
              LPS function
***************************************/
void lps_func(string txt, vector<int>& Lps) {
    Lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < txt.length()) {
        if (txt[i] == txt[len]) {
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else {
            if (len == 0) {
                Lps[i] = 0;
                i++;
                continue;
            }
            else {
                len = Lps[len - 1];
                continue;
            }
        }
    }
}
/**************************************
              KMP Function
***************************************/
void KMP(string pattern, string text) {
    int n = text.length();
    int m = pattern.length();
    vector<int>Lps(m);

    lps_func(pattern, Lps); // Ёта функци€ создает массив Lps.

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) { i++; j++; } // ≈сли есть совпадение, продолжайте.
        if (j == m) {
            cout << i - m << ' ';    // если j==m, то подтверждаетс€, что мы нашли шаблон, и мы выводим индекс
                                  // и обновите j как Lps последнего совпадающего символа.
            j = Lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {  // ≈сли есть несоответствие
            if (j == 0)          // ≈сли есть несоответствие, если j становитс€ 0, то просто увеличьте индекс i
                i++;
            else
                j = Lps[j - 1];  // ќбновить j как Lps последнего совпадающего символа
        }
    }
}
int main()
{
    string text = "ababcdabcb";
    string pattern = "abc";
    KMP(pattern, text);

    return 0;
}