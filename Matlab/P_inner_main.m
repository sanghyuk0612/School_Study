
a = input('Enter a:');
b = input('Enter b:');
clc
fprintf('a = %5.3f b = %5.3f\n\n',a,b)
n=3;
while (P_inner(a,b,n+1)- P_inner(a,b,n) >0.001)
    n=n+1;
end
P_inner(a,b,100)
P_inner_q(3,5,100)