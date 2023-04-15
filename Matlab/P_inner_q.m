function P=P_inner_q(a, b, n)
innerSum = 0;% 변수 초기화
theta=(2*pi)/n;%theta값 정의
thetaSum=0;% 변수 초기화
k=1; %k 초기값 설정
while (thetaSum < pi/2)
    xk=a*cos(k*theta);%x좌표 계산
    yk=b*sin(k*theta);%x좌표 계산
    xkp1=a*cos((k+1)*theta);%그 다음 x좌표 계산
    ykp1=b*sin((k+1)*theta);%그 다음 y 좌표 계싼
    dk= sqrt((xkp1 - xk)*(xkp1 - xk) + (ykp1 - yk)*(ykp1 - yk));  % (xk, yk)와 (xkp1, ykp1)의 거리
    innerSum= innerSum + dk; % innerSum변수에 구한 두 점 사이의 거리를 대입
    thetaSum = thetaSum+theta; %thetaSum에 지금까지 계산한 델타값을 더해준다.
    k= k+1; % k에 1을 더해 다음 루프 계산
end
P = 4*innerSum; %마지막에 4를 곱해서 마무리 계산 후 P에 대입후 반환 

