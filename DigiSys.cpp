#include "DigiSys.h"

DigiSys::DigiSys(const double num[], const double den[], const int num_len, const int den_len) {

    mNumLen = num_len;
    mDenLen = den_len;
    
    for (size_t i = 0; i < mNumLen; i++) {
        mNumCoeffs[i] = num[i];
    }

    for (size_t i = 0; i < mDenLen; i++) {
        mDenCoeffs[i] = den[i]/den[0];
    }

    mGain /= den[0];
    
}

DigiSys::DigiSys(const double gain, const double num[], const double den[], const int num_len, const int den_len)
: DigiSys(num, den, num_len, den_len)
{
    mGain *= gain;
}

double DigiSys::update(double input) {

    // shift existing arrays
    for (size_t i = mNumLen-1; i > 0; i--) {
        mInput[i] = mInput[i-1];
    }
    for (size_t i = mDenLen-1; i > 0; i--) {
        mOutput[i] = mOutput[i-1];
    }

    // add measurement
    mInput[0] = input;

    // calculate new output
    mOutput[0] = 0;
    for (size_t i = 0; i < mNumLen; i++) {
        mOutput[0] += mNumCoeffs[i]*mInput[i];
    }
    mOutput[0] *= mGain;
    for (size_t i = 1; i < mDenLen; i++) {
        mOutput[0] += -mDenCoeffs[i]*mOutput[i];
    }

    return mOutput[0];

}
