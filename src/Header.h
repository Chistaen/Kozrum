#ifndef KOZRUM_HEADER_H
#define KOZRUM_HEADER_H

class Header
{
public:
    Header(std::mt19937_64* t_header, int t_level);
    void display();

private:
    std::mt19937_64* m_randomGenerator;
    int m_level;
};

#endif //KOZRUM_HEADER_H
