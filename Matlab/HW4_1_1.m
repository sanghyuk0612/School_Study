clc
%a = input('Enter a:'); 
%b = input('Enter b:');
a=5;
b=3;
n = 10;
fprintf('a = %5.3f b = %5.3f\n\n',a,b)
Inner = P_inner(a,b,n);
Outer = P_outer(a,b,n);
Ave = (Inner+Outer)/2
relErrInner = abs(Ave-((Inner+Ave)/2))/Ave
relErrOuter = abs(Ave-((Outer+Ave)/2))/Ave


