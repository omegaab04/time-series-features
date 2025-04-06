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
plt.figure(figsize=(14, 8))
plt.plot(close.index, close, label="Close Price", linewidth=1.5)
plt.plot(close.index, roll, label="10-day Rolling Mean", linestyle="--")
plt.plot(close.index, mom, label="10-day Momentum", linestyle=":")
plt.plot(close.index, z, label="10-day Z-score", linestyle="-.")

plt.title("AAPL - C-Accelerated Feature Signals", fontsize=14)
plt.xlabel("Date")
plt.ylabel("Price / Signal")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()