function P=P_inner(a, b, n)
innerSum = 0; % 변수 초기화
theta=(2*pi)/n; %theta값 정의
for k=1:n %반복문 선언부분
    xk=a*cos(k*theta);%x좌표 계산
    yk=b*sin(k*theta);%x좌표 계산
    xkp1=a*cos((k+1)*theta);%그 다음 x좌표 계산
    ykp1=b*sin((k+1)*theta);%그 다음 y 좌표 계싼
    dk= sqrt((xkp1 - xk)*(xkp1 - xk) + (ykp1 - yk)*(ykp1 - yk));  % (xk, yk)와 (xkp1, ykp1)의 거리
    innerSum= innerSum + dk; % innerSum변수에 구한 두 점 사이의 거리를 대입
end
P = innerSum; %계산이 끝난 innerSum을 P에 대입후 P반환