%delta 값 입력받음
delta = input('enter delta: ');
% 가장 작은 n은 3
n =3;

A_n=n/2*sin(2*pi/n);
%A_n 최초 정의
B_n=n*tan(pi/n);
%B_n 최초 정의
A_error = (n+1)/2*sin(2*pi/(n+1))-A_n;
%A_error 최초정의
B_error = (n+1)*tan(pi/(n+1)) - B_n;
%A_error 최초정의

while abs(A_error) >= delta || abs(B_error) >= delta
    %while문 정의 A_error가 delta값보다 크거나
    %B_error가 delta값보다 크다면 while안을 계속 돌도록 정의
    A_n = n/2*sin(2*pi/n);
    %A_n 계산
    B_n = n*tan(pi/n);
    %B_n 계산
    n = n+1;
    %n증가부분
    A_error =(n+1)/2*sin(2*pi/(n+1)) - n/2*sin(2*pi/n);
    %A_error계산 지금 A_n+1값과 A_n+2의 차를 구함
    %n+2와 n+1의 차를 구하는 이유는 다음 조건문에 쓸
    %A_error의 값을 구하는 과정이기 때문이다.
    B_error =(n+1)*tan(pi/(n+1)) - n*tan(pi/n);
    %B_error계산 지금 B_n+1값과 B_n+2의 차를 구함
    
end
nstar=n;
%nstar 값 대입
fprintf("nstar = %d\n",nstar);
%nstar 값 출력
P_n = (A_n+B_n)/2;
%P_n값 대입
fprintf("P_n = %20.15f\n",P_n);
%P_n값 출력