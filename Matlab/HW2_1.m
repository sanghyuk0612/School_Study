N1=0;
n=input('정수 n 입력:');
B=n*2-1; %B 구하는 수식 활용하여 B 구하기
for k=1:n
    m=floor(sqrt(n^2-k^2));
    N1=N1+m;
end
rho_n=(4*(N1+B/2))/n^2; 
err=abs(pi-rho_n); 
fprintf('rho_n=%12.8f\n', rho_n);
fprintf('error=%12.8f\n', err);
