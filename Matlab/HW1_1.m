%L값과 R값 입력받기 
L = input('L = '); 
R = input('R = ');
% result 값 초기화
result = 0;
%간소화하기위해 L값과 R값을 2*Pi로 나눈 나머지를 대입
L = mod(L,2*pi);
R = mod(R,2*pi);

if R<L 
    %나눈 나머지가 R이 더 크다면 L과 R 사이에 2*N*pi가 있다는 뜻과 같으므로
    %최댓값은 항상 1이다. (N은 임의의 정수)
    result = 1;
elseif R*L == 0
    %R이나 L이 2*pi로 나누어 떨어진다면 L이나 R은 0이므로 최댓값은 항상 1이다.
    result = 1;
else
    %그 외의 경우는 직접 대입해서 확인
    if cos(L)<cos(R)
        result = cos(R);
    else
        result = cos(L);
    end
end
%구한 최댓값 출력
fprintf('최댓값 : %g\n',result);