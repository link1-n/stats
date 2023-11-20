import pandas as pd

smaPeriod = 3

data = {'value': [10.0, 15.0, 20.0, 25.0, 12.0, 34.0, 67.0, 89.0, 111.0, 2.0]}
df = pd.DataFrame(data)

sma = df['value'].rolling(window=smaPeriod).mean()
ema = df['value'].ewm(span=3.0, adjust=False).mean()

print("actual")
print(df)

print("sma")
print(sma)

print("ema")
print(ema)
