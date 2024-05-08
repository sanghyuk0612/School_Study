% CSV 파일에서 데이터 불러오기
data = readtable('연보_국가_인천연수_충적_수위_시.csv'); % 파일 경로를 적절히 수정하세요.

% 날짜열을 datetime 형식으로 변환
data.obsrvn_ymdh = datetime(data.obsrvn_ymdh);

% 데이터 시각화
figure;
plot(data.obsrvn_ymdh, data.lev);
title('시계열 데이터');
xlabel('날짜');
ylabel('값');

% ARIMA 모델 적합
Mdl = arima(1,1,1); % ARIMA(1,1,1) 모델 설정
EstMdl = estimate(Mdl, data.lev); % ARIMA 모델 적합

% 모델을 사용하여 미래 값 예측
Horizon = 10; % 예측 기간
YF = forecast(EstMdl, Horizon); % 미래 값 예측

% 예측 시각화
future_dates = datetime(data.obsrvn_ymdh(end)) + caldays(1:Horizon); % 데이터의 마지막 날짜 이후의 날짜 생성
figure;
plot(data.obsrvn_ymdh, data.lev, 'b', future_dates, YF, 'r--');
title('ARIMA 모델을 사용한 미래 값 예측');
xlabel('날짜');
ylabel('값');
legend('실제 데이터', '예측 값');