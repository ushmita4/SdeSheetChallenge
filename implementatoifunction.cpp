int atoi(string str) {
    bool isNegative = 0;
    if (str[0] == '-') {
        isNegative = 1;
    }

    int number = 0;
    for (int i = 0; i < str.size(); i++) {

        if (str[i] >= '0'&& str[i] <= '9') {
            int digit = (char) str[i] - '0';
            number = number * 10 + digit;
        }
    }

    if (isNegative) {
        number *= -1;
    }

    return number;
}
