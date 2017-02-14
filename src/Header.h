#ifndef KOZRUM_HEADER_H
#define KOZRUM_HEADER_H

class Header {
public:
    Header();
    std::string generate();

private:
    std::mt19937_64 m_randomGenerator;
};

#endif //KOZRUM_HEADER_H
