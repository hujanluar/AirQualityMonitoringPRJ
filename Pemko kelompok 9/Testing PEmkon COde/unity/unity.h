#ifndef UNITY_H
#define UNITY_H

#include <stdint.h>

typedef void (*UnityTestFunction)(void);

void UnityBegin(const char* name);
int UnityEnd(void);
void UnityDefaultTestRun(UnityTestFunction Func, const char* FuncName, const int FuncLineNum);
void UnityAssertEqualNumber(int expected, int actual, const char* msg, const int line);
void UnityAssertEqualString(const char* expected, const char* actual, const char* msg, const int line);

#define UNITY_BEGIN() UnityBegin(__FILE__)
#define UNITY_END() UnityEnd()
#define RUN_TEST(func) UnityDefaultTestRun(func, #func, __LINE__)
#define TEST_ASSERT_EQUAL_UINT16(expected, actual) UnityAssertEqualNumber((expected), (actual), #expected, __LINE__)
#define TEST_ASSERT_EQUAL_UINT8(expected, actual) UnityAssertEqualNumber((expected), (actual), #expected, __LINE__)
#define TEST_ASSERT_EQUAL_INT32(expected, actual) UnityAssertEqualNumber((expected), (actual), #expected, __LINE__)
#define TEST_ASSERT_EQUAL_STRING(expected, actual) UnityAssertEqualString((expected), (actual), #expected, __LINE__)

#endif // UNITY_H
