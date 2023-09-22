//9) ƒано р€док.«ам≥нити у р€дку кожну латинську букву наступною про алфав≥ту(букв СzТ, СZТ зам≥нювати буквою СaТ, СAТ).Ќаприклад,
//р€док  УZebra has two colorsФ маЇ перетворитис€ на УAfcsb ibt uxp dpmpstФ.Ќаписати в≥дпов≥дну функц≥ю шифруванн€ р€дка.
#include <iostream>
#include <cstring>

void changeLine(char* str) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (std::isalpha(str[i])) { // ѕерев≥р€Їмо, чи символ Ї л≥терою
            char base = (std::isupper(str[i])) ? 'A' : 'a'; // ¬изначаЇмо базову л≥теру (A або a)
            str[i] = base + ((str[i] - base + 1) % 26); // «ам≥нюЇмо л≥теру на наступну за алфав≥том
        }
    }
}

int main() {
    char str[100];
    std::cout << "Enter the line: ";

    std::cin.getline(str, sizeof(str));

    changeLine(str);

    std::cout << "The resulting string: " << str << std::endl;

    return 0;
}



