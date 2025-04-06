This project looks at Rolling Means, Z-Scores and Momentum for some time series fun. 

---

Parameters for each method are ```prices``` and ```window```. 

- `rolling_mean(prices, window)`
- `momentum(prices, window)`
- `zscore(prices, window)`

To run locally you'll need to do this:

```bash
python3 setup.py build_ext --inplace
```

And for plots:

```bash
pip install yfinance pandas matplotlib
```

---

The code is called from Python. To run:

```python3```

Or if that doesn't work:

```python```

Here's an example of how to run this once you've called either ```python3``` or ```python```:

```python
import yfinance as yf
import alpha

# Here let's work with Apple:
df = yf.download("AAPL", start="2022-01-01", end="2024-01-01", auto_adjust=True)
close = df["Close"].squeeze().tolist()

# Computing signals and storing them in relevant variables:
roll = alpha.rolling_mean(close, 10)
mom = alpha.momentum(close, 10)
z = alpha.zscore(close, 10)

# Last 5 of each (otherwise you'll have a bunch of outputs given our time range here is two full years)
print("Rolling mean:", roll[-5:])
print("Momentum:", mom[-5:])
print("Z-score:", z[-5:])

```
Voila!

---

If you're fancy like that, try some plotting:

```python
import matplotlib.pyplot as plt
import pandas as pd

plt.plot(df.index, df["Close"], label="Close")
plt.plot(df.index, roll, label="Rolling Mean")
plt.plot(df.index, mom, label="Momentum")
plt.plot(df.index, z, label="Z-score")
plt.legend()
plt.show()
```

---
Play around with it.

---

MIT © Adam — Built for high-performance finance pipelines.
