#include "mock_mq135.h"

static float mock_ppm = 0.0f;

void mock_mq135_set_ppm(float ppm) {
    mock_ppm = ppm;
}

float mock_mq135_read_ppm(void) {
    return mock_ppm;
}
