import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.tsa.arima.model import ARIMA
from statsmodels.graphics.tsaplots import plot_acf, plot_pacf
import statsmodels.api as sm
import numpy as np


# CSV 파일 불러오기
def plot_acf_pacf(data, lags=20):
    # ACF 계산
    acf = sm.tsa.acf(data, nlags=lags)
    
    # PACF 계산
    pacf = sm.tsa.pacf(data, nlags=lags)
    
    # ACF 그래프
    plt.figure(figsize=(12, 6))
    plt.subplot(121)
    plt.stem(acf)
    plt.xlabel('Lag')
    plt.ylabel('ACF')
    plt.title('Autocorrelation Function (ACF)')
    plt.grid(True)
    
    # PACF 그래프
    plt.subplot(122)
    plt.stem(pacf)
    plt.xlabel('Lag')
    plt.ylabel('PACF')
    plt.title('Partial Autocorrelation Function (PACF)')
    plt.grid(True)
    
    plt.tight_layout()
    plt.show()

data = pd.read_csv('연보_국가_인천연수_충적_수질_시.csv')

# 날짜 데이터를 인덱스로 설정 (datetime 형식이라면 parse_dates 옵션 사용 가능)
data['obsrvn_ymdh'] = pd.to_datetime(data['obsrvn_ymdh'])
data.set_index('obsrvn_ymdh', inplace=True)

# 'ec' 열의 시계열 데이터 확인
lev_data = data['ec']
print(lev_data.head())

# 'ec' 열의 시계열 데이터 시각화
# plt.figure(figsize=(10, 6))
# plt.plot(lev_data, label='Actual')
# plt.title('Time Series Data for ec')
# plt.xlabel('Date')
# plt.ylabel('ec')
# plt.legend()
# plt.show()

after_2015 = lev_data[data.index.year >= 2015]
# plt.plot(after_2015)
# plt.show()

# #이동 평균 스무딩
window_size = 7
smoothed_data = after_2015.rolling(window=window_size).mean()
# plt.figure(figsize=(10, 6))
# plt.plot(after_2015, label='Original')
# plt.plot(smoothed_data, label='Smoothed')
# plt.title('Moving Average Smoothing')
# plt.xlabel('Date')
# plt.ylabel('Value')
# plt.legend()
# plt.show()
# 데이터를 훈련 세트와 테스트 세트로 분할합니다.
train_ratio = 0.95  # 훈련 세트의 비율을 설정합니다.
train_size = int(len(smoothed_data) * train_ratio)

train_data = after_2015[:train_size]  # 훈련 세트는 데이터의 앞부분입니다.
test_data = after_2015[train_size:]   # 테스트 세트는 데이터의 나머지 부분입니다.

model = ARIMA(train_data, order=(1,2,1))
model_fit = model.fit()

# 테스트 세트 예측
start_idx = len(train_data)
end_idx = start_idx + len(test_data) - 1
forecast_values = model_fit.predict(start=start_idx, end=end_idx)

# 예측 결과 시각화

plt.figure(figsize=(10, 5))
plt.plot(smoothed_data, label='Actual')
plt.plot(test_data.index, forecast_values, label='Forecast', color='red')
plt.title('ARIMA Forecast')
plt.xlabel('Date')
plt.ylabel('Value')
plt.legend()
plt.grid(True)
plt.show()

# 예측 결과 평가
mse = np.mean((test_data - forecast_values) ** 2)
print("Mean Squared Error (MSE):", mse)
# # 지수평활법 스무딩
# alpha = 0.2  # smoothing parameter
# smoothed_data = after_2015.ewm(alpha=alpha).mean()

# # 시각화
# plt.figure(figsize=(10, 6))
# plt.plot(after_2015, label='Original')
# plt.plot(smoothed_data, label='Smoothed')
# plt.title('Exponential Smoothing')
# plt.xlabel('Date')
# plt.ylabel('Value')
# plt.legend()
# plt.show()

#1차 차분 2차 차분
diff_1 = smoothed_data.diff().dropna()
# plt.plot(diff_1)
# plt.show()
diff_2 = diff_1.diff().dropna()
# plt.plot(diff_2)
# plt.show()

# plot_acf_pacf(after_2015,200)
#ACF와 PACF 구하기
# plot_acf(smoothed_data,lags=2)
# plt.title('Autocorrelation Function (ACF)')
# plt.show()

# PACF plot 그리기
# plot_pacf(smoothed_data, lags=20)
# plt.title('Partial Autocorrelation Function (PACF)')
# plt.show()
# # ARIMA 모델 피팅
# ARIMA 모델 생성
model = ARIMA(smoothed_data, order=(1, 2, 1))

# ARIMA 모델 학습
model_fit = model.fit()

# 예측
forecast_steps = 60  # 예측할 기간을 설정합니다. 이 예제에서는 10일을 예측합니다.
forecast = model_fit.forecast(steps=forecast_steps)

# 예측 결과 시각화
plt.figure(figsize=(10, 5))
plt.plot(smoothed_data, label='Actual')
plt.plot(smoothed_data.index[-1] + pd.to_timedelta(np.arange(1, forecast_steps + 1), unit='D'), forecast, label='Forecast', color='red')
plt.title('ARIMA Forecast')
plt.xlabel('Date')
plt.ylabel('Value')
plt.legend()
plt.grid(True)
plt.show()
# model = ARIMA(after_2015, order=(0, 2, 1))  # ARIMA(p, d, q) 에 따라 order 설정
# fit_model = model.fit()

# # 예측하기
# forecast_steps = 100
# forecast = fit_model.forecast(steps=forecast_steps)  # 예측할 기간(steps) 설정
# print("Forecast:", forecast)

# # 예측 결과 그래프로 그리기
# plt.figure(figsize=(10, 6))
# plt.plot(after_2015, label='Actual')
# plt.plot(fit_model.fittedvalues, color='red', label='Fitted')
# forecast_index = pd.date_range(start=after_2015.index[-1], periods=forecast_steps+1)[1:]
# plt.plot(forecast_index, forecast, color='green', label='Forecast')
# plt.title('ARIMA Model Forecast')
# plt.xlabel('Date')
# plt.ylabel('ec')
# plt.legend()
# plt.show()