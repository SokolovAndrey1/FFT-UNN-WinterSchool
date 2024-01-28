#include "test_common.hpp"

// Change to 1 to test function
#define DFT2_IMPLEMENTED 1
#define DFT4_IMPLEMENTED 1
#define DFT6_IMPLEMENTED 1
#define DFT8_IMPLEMENTED 0
#define DFT16_IMPLEMENTED 0
#define DFT32_IMPLEMENTED 0

class Dft : public ::testing::Test
{
public:
    std::vector<T32fc> source;
    std::vector<T32fc> reference;
    std::vector<T32fc> result;

    void prepareData(int length) {
        source.resize(length);
        reference.resize(length);
        result.resize(length);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(0.0f, 1.0f);

        for (int idx = 0; idx < length; ++idx) {
            source[idx].re = dist(gen);
            source[idx].im = dist(gen);

            reference[idx].re = 0.0f;
            reference[idx].im = 0.0f;
            result[idx].re = 0.0f;
            result[idx].im = 0.0f;
        }
    }
};

#if DFT2_IMPLEMENTED == 1
TEST_F(Dft, test_dft2)
{
    static constexpr int length = 2;
    static constexpr float threshold = 1e-2f;

    Dft::prepareData(length);

    refDftFwd(source.data(), reference.data(), length);

    dft2Fwd(source.data(), result.data());

    EXPECT_NEAR_VECTOR_VECTOR_COMPLEX(result, reference, threshold);
}
#endif

#if DFT4_IMPLEMENTED == 1
TEST_F(Dft, test_dft4)
{
    static constexpr int length = 4;
    static constexpr float threshold = 1e-2f;

    Dft::prepareData(length);

    refDftFwd(source.data(), reference.data(), length);

    dft4Fwd(source.data(), result.data());

    EXPECT_NEAR_VECTOR_VECTOR_COMPLEX(result, reference, threshold);
}
#endif

#if DFT6_IMPLEMENTED == 1
TEST_F(Dft, test_dft6)
{
    static constexpr int length = 6;
    static constexpr float threshold = 1e-1f;

    Dft::prepareData(length);

    refDftFwd(source.data(), reference.data(), length);

    dft6Fwd(source.data(), result.data());

    EXPECT_NEAR_VECTOR_VECTOR_COMPLEX(result, reference, threshold);
}
#endif

#if DFT8_IMPLEMENTED == 1
TEST_F(Dft, test_dft8)
{
    static constexpr int length = 8;
    static constexpr float threshold = 1e-2f;

    Dft::prepareData(length);

    refDftFwd(source.data(), reference.data(), length);

    dft8Fwd(source.data(), result.data());

    EXPECT_NEAR_VECTOR_VECTOR_COMPLEX(result, reference, threshold);
}
#endif

#if DFT16_IMPLEMENTED == 1
TEST_F(Dft, test_dft16)
{
    static constexpr int length = 16;
    static constexpr float threshold = 1e-1f;

    Dft::prepareData(length);

    refDftFwd(source.data(), reference.data(), length);
    dft16Fwd(source.data(), result.data());

    EXPECT_NEAR_VECTOR_VECTOR_COMPLEX(result, reference, threshold);
}
#endif

#if DFT32_IMPLEMENTED == 1
TEST_F(Dft, test_dft32)
{
    static constexpr int length = 32;
    static constexpr float threshold = 1e-1f;

    Dft::prepareData(length);

    refDftFwd(source.data(), reference.data(), length);
    dft32Fwd(source.data(), result.data());

    EXPECT_NEAR_VECTOR_VECTOR_COMPLEX(result, reference, threshold);
}
#endif
