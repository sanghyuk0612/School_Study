function result = mystery(L,R,f)
N=1000000;
hits = 0;
for k=1:N
    % 길이가L+R인 직사각형 임의의 위치에 균일 분포 난수 생성
    rx=L+(R-L)*rand;
    ry=rand;
    % 생성된 균일 분포 난수가 함수 안에 있는가?
    if ((1/sqrt(2*pi))*(exp(-(rx^2)/2)) >=ry)
        hits=hits+1;
    end
end
result = hits/N*(R-L)