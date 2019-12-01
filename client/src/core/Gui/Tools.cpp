//
// Created by guigui on 11/13/19.
//

#include "Tools.hpp"

sf::Vector2f RType::centerX(sf::Vector2u screenSize, int width, sf::Vector2<float> initialPos) {
    initialPos.x = screenSize.x / 2 - width / 2;
    return initialPos;
}

sf::Vector2f RType::centerY(sf::Vector2u screenSize, int height, sf::Vector2f initialPos) {
    initialPos.y = screenSize.y / 2 - height / 2;
    return initialPos;
}

sf::Vector2f RType::linePos(sf::Vector2u screenSize, int height, sf::Vector2<float> initialPos, int factor, int pos) {
    initialPos.y = (screenSize.y / ((factor + 1)) * pos) - height / 2;
    return initialPos;
}

sf::Vector2f RType::colPos(sf::Vector2u screenSize, int width, sf::Vector2<float> initialPos, int factor, int pos) {
    initialPos.x = (screenSize.x / ((factor + 1)) * pos) - width / 2;
    return initialPos;
}

std::string RType::stringToHex(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i) {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

std::string RType::hexToString(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();
    if (len & 1) throw std::invalid_argument("odd length");

    std::string output;
    output.reserve(len / 2);
    for (size_t i = 0; i < len; i += 2) {
        char a = input[i];
        const char* p = std::lower_bound(lut, lut + 16, a);
        if (*p != a) throw std::invalid_argument("not a hex digit");

        char b = input[i + 1];
        const char* q = std::lower_bound(lut, lut + 16, b);
        if (*q != b) throw std::invalid_argument("not a hex digit");

        output.push_back(((p - lut) << 4) | (q - lut));
    }
    return output;
}