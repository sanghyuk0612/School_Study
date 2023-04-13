function P=P_inner_q(a, b, n)
innerSum = 0;
theta=(2*pi)/n;
thetaSum=0;
k=1;
while (thetaSum < pi/2)
    xk=a*cos(k*theta);
    yk=b*sin(k*theta);
    xkp1=a*cos((k+1)*theta);
    ykp1=b*sin((k+1)*theta);
    dk= sqrt((xkp1 - xk)*(xkp1 - xk) + (ykp1 - yk)*(ykp1 - yk));  % (xk, yk)와 (xkp1, ykp1)의 Euclidean 거리
    innerSum= innerSum + dk;
    thetaSum = thetaSum+theta;
    k= k+1;
end
P = 4*innerSum;