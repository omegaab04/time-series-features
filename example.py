import yfinance as yf
import pandas as pd
import alpha

# ✅ Step 1: Download data
df = yf.download("AAPL", start="2022-01-01", end="2024-01-01", auto_adjust=True)

# ✅ Step 2: Extract close column properly
close = df["Close"].squeeze()        # ← FLATTENED SERIES ✅
print("Type of close:", type(close)) # Should be Series

# ✅ Step 3: Convert to list
close_list = close.tolist()
print("First 5 values:", close_list[:5])

alpha.rolling_mean(close_list, 10)
alpha.momentum(close_list, 10)
alpha.zscore(close_list, 10)