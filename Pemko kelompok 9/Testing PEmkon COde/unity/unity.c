#include "unity.h"
#include <stdio.h>
#include <string.h>

void UnityBegin(const char* name) {
    (void)name;
}

int UnityEnd(void) {
    return 0;
}

void UnityDefaultTestRun(UnityTestFunction Func, const char* FuncName, const int FuncLineNum) {
    printf("Running %s at line %d...\n", FuncName, FuncLineNum);
    Func();
}

void UnityAssertEqualNumber(int expected, int actual, const char* msg, const int line) {
    if (expected != actual) {
        printf("FAIL: %s at line %d: Expected %d, Got %d\n", msg, line, expected, actual);
    } else {
        printf("PASS: %s at line %d\n", msg, line);
    }
}

void UnityAssertEqualString(const char* expected, const char* actual, const char* msg, const int line) {
    if (strcmp(expected, actual) != 0) {
        printf("FAIL: %s at line %d: Expected \"%s\", Got \"%s\"\n", msg, line, expected, actual);
    } else {
        printf("PASS: %s at line %d\n", msg, line);
    }
}
