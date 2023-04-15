a = input('Enter a:'); %a 변수 입력받음
b = input('Enter b:'); %b 변수 입력받음
n=3;
%다음P_inner값에서 지금 P_inner값을 빼서 그 값이 0.001보다 크면 계속 반복하도록 loop설정
while (P_inner(a,b,n+1)- P_inner(a,b,n) >0.001)  
    n=n+1; %n을 count해주는 함수
end
disp(n); %n이 몇일때 차이가 0.001보다 작은지 보여주는 함수
