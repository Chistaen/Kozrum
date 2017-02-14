#ifndef KOZRUM_HEADER_H
#define KOZRUM_HEADER_H

class Header {
public:
    Header();
    void generate();
    void setLevel(int t_level);

private:
    std::mt19937_64 m_randomGenerator;
    int m_level;
};

#endif //KOZRUM_HEADER_H
