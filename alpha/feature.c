#include <math.h>
#include <stdlib.h>

// Rolling mean
void rolling_mean(double* data, int len, int window, double* result) {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        if (i >= window) sum -= data[i - window];
        sum += data[i];
        result[i] = (i + 1 < window) ? NAN : sum / window;
    }
}

// Momentum (price[t] - price[t-window])
void momentum(double* data, int len, int window, double* result) {
    for (int i = 0; i < len; i++) {
        result[i] = (i < window) ? NAN : data[i] - data[i - window];
    }
}

// Z-score (price - rolling_mean) / rolling_std
void zscore(double* data, int len, int window, double* result) {
    for (int i = 0; i < len; i++) {
        if (i + 1 < window) {
            result[i] = NAN;
            continue;
        }

        double sum = 0.0, sum_sq = 0.0;
        for (int j = i - window + 1; j <= i; j++) {
            sum += data[j];
            sum_sq += data[j] * data[j];
        }

        double mean = sum / window;
        double variance = (sum_sq / window) - (mean * mean);
        double std = sqrt(variance);
        result[i] = (std == 0.0) ? NAN : (data[i] - mean) / std;
    }
}