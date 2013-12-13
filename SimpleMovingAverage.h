#ifndef SIMPLEMOVINGAVERAGE_H_89EA84B4_92AE_4224_826F_C0976CE839DC
#define SIMPLEMOVINGAVERAGE_H_89EA84B4_92AE_4224_826F_C0976CE839DC

template<int N, typename T>
class SimpleMovingAverage
{

public:
    SimpleMovingAverage(T initValue = 0): m_N(N), m_p(0) {
        for (int i = 0; i < m_N; i++) {
            m_x[i] = initValue;
        }
    }

    ~SimpleMovingAverage() {}

    const T average(const T & x) {
        m_x[m_p] = x;

        if (m_N == ++m_p) {
            m_p = 0;
        }

        T sum = 0;

        for (int i = 0; i < m_N; i++) {
            sum += m_x[i];
        }

        return sum / m_N;
    }

    void reset(T initValue = 0) {
        m_p = 0;
        for (int i = 0; i < m_N; i++) {
            m_x[i] = initValue;
        }
    }

private:
    const int m_N;
    T m_x[N];
    int m_p;
};

#endif // #ifndef SIMPLEMOVINGAVERAGE_H_89EA84B4_92AE_4224_826F_C0976CE839DC
