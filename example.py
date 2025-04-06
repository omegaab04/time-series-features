import yfinance as yf
import pandas as pd
import alpha
import matplotlib.pyplot as plt

# Load historical prices
data = yf.download("AAPL", start="2022-01-01", end="2023-01-01")
close = data["Close"]

# Compute features
roll = alpha.rolling_mean(close, window=10)
mom = alpha.momentum(close, window=10)
z = alpha.zscore(close, window=10)

# Plot features
plt.figure(figsize=(12, 6))
plt.plot(close, label="Close Price")
plt.plot(roll, label="10-day Rolling Mean")
plt.plot(mom, label="Momentum (10)")
plt.plot(z, label="Z-score (10)")
plt.legend()
plt.title("AAPL Features")
plt.show()