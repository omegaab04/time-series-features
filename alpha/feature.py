import feature

def rolling_mean(series, window):
    return feature.rolling_mean(series, window)

def momentum(series, window):
    return feature.momentum(series, window)

def zscore(series, window):
    return feature.zscore(series, window)