% 초기값 설정
x = 1;
% 뉴턴 메소드 시작
fprintf('interation            ');
fprintf('근사해\n');
n = 1;
for i = 0:9
    % 함수 값과 도함수 값 계산
    f = exp(-x) - x;
    fPrime = -exp(-x) - 1;
    % 다음 근사해 계산
    x1 = x - f/fPrime;
    x = x1;
    fprintf('%6.d%22.6f\n', n,x1);
    n = n+1;
end
