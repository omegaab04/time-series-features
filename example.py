import yfinance as yf
import pandas as pd
import matplotlib.pyplot as plt
import alpha

# --- Download Data ---
df = yf.download("AAPL", start="2022-01-01", end="2024-01-01", auto_adjust=True)

# --- Extract and Flatten Close Prices ---
close = df["Close"].squeeze()
close_list = close.tolist()

# --- Compute C-Accelerated Features ---
roll = alpha.rolling_mean(close_list, 10)
mom = alpha.momentum(close_list, 10)
z = alpha.zscore(close_list, 10)

# --- Print Last 5 Results ---
print("Rolling mean:", roll[-5:])
print("Momentum:", mom[-5:])
print("Z-score:", z[-5:])

# --- Plot ---
plt.plot(df.index, df["Close"], label="Close")
plt.plot(df.index, roll, label="Rolling Mean")
plt.plot(df.index, mom, label="Momentum")
plt.plot(df.index, z, label="Z-score")
plt.legend()
plt.show()