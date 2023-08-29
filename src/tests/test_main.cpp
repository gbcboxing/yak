#include "test_preprocessor.hpp"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  auto result = RUN_ALL_TESTS();
#ifdef _WIN32
  (void)getchar();
#endif
  return result;
}
