#ifndef DIGISYS
#define DIGISYS

#define MAX_LEN 10

class DigiSys {
    public:
        DigiSys(const double num[], const double den[], const int num_len, const int den_len);
        DigiSys(const double gain, const double num[], const double den[], const int num_len, const int den_len);
        double update(double input);
    private:
        int mDenLen;
        int mNumLen;
        double mDenCoeffs[MAX_LEN];
        double mNumCoeffs[MAX_LEN];
        double mOutput[MAX_LEN] {0};
        double mInput[MAX_LEN] {0};
        double mGain = 1.;
};

#endif