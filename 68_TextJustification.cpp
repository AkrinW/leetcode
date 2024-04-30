#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string a[7] ={"This", "is", "an", "example", "of", "text", "justification."};
    std::vector<std::string> words(a, a+7);
    int maxWidth = 16;
    std::vector<std::string> just;
    std::string b = "";
    int n = words.size();
    int start = 0;
    int stringlong = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        stringlong += words[i].size();
        if (stringlong + count> maxWidth) {
            int tmp = maxWidth - stringlong + words[i].size();//space count;
            if (count > 1) {
                int space = tmp / (count - 1);
                std::string sp(space, ' ');
                int x = tmp - space * (count - 1);//former
                int y = count - 1 - x; //later
                for (int j = 0; j < x; ++j) {
                    b += words[start+j];
                    b += (sp + ' ');
                }
                for (int j = 0; j < y; ++j) {
                    b += words[start+x+j];
                    b += sp;
                }
                b += words[i-1];
            } else {
                b += words[i-1];
                std::string sp(tmp, ' ');
                b += sp;
            }
            just.push_back(b);
            b = "";
            start = i;
            stringlong = 0;
            count = 0;
            --i;
        } else {
            ++count;
        }
    }
    std::string sp(maxWidth-stringlong-count+1,' ');
    for (int i = 0; i < count -1; ++i) {
        b += words[start+i];
        b += " ";
    }
    b += words[n-1];
    b += sp;
    just.push_back(b);
    for (int i =0; i < just.size();++i) {
        std::cout << just[i] << std::endl;
    }


    return 0;
}