x = 1;% 초기값 설정
fprintf('interation            ');%사용자가 보기 편하게 하기 위해 출력
fprintf('근사해\n');%사용자가 보기 편하게 하기 위해 출력
n = 1; %몇번째인지 확인해주는 변수
for i = 0:9
    f = exp(-x) - x;% 함수 값 계산
    fPrime = -exp(-x) - 1;% 도함수 값 계산 
    x1 = x - f/fPrime; % 다음 근사해 계산
    x = x1; % 다음 근사해값을 x에 새로 대입 
    fprintf('%6.d%22.6f\n', n,x); %구한 근사치를 출력
    n = n+1;
end
