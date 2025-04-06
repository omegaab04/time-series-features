import feature

def rolling_mean(series, window):
    return feature.rolling_mean(series.tolist(), window)

def momentum(series, window):
    return feature.momentum(series.tolist(), window)

def zscore(series, window):
    return feature.zscore(series.tolist(), window)