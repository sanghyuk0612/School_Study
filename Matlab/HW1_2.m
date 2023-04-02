%적도 반경과 극 반경 입력받기
r1 = input('적도 반경을 입력하세요: ');
r2 = input('극 반경을 입력하세요: ');
%d값 미리 계산해서 대입
d = acos(r2/r1);
%주어진 식 작성
surface = 2*pi*(r1*r1+(r2*r2)/sin(d)*log(cos(d)/(1-sin(d))));
surface_a = 4*pi*((r1+r2)/2)*((r1+r2)/2);

fprintf("회전 타원체의 표면적: %f\n",surface);
fprintf("근사화한 표면적: %f\n",surface_a);