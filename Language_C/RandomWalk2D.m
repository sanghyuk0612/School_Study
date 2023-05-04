function z = RandomWalk2D(n)
% n is a positive integer.
% Simulates a 2D random walk that continues until
% the absolute value of the x-coordinate or y-coordinate of the robot
% is equal to n.
% x and y are row vectors with the property that (x(k),y(k)) is the
% location of the robot after k hops, k=1:length(x).

% Initialize the hop counter and current location...
k = 0; xc = 0; yc = 0;
z = 0;%초기값 지정
% The random walk...
while abs(xc)<n && abs(yc)< n
    % Robot at (xc,yc), simulate a single hop...
    
    r = rand(1);
    if r <= .25
        yc = yc+1; % Hop North
    elseif r<=.50
        xc = xc+1; % Hop East
    elseif r < .75
        yc = yc-1; % Hop South
    else
        xc = xc-1; % Hop West
    end
    % Save the new location...
    if (xc == 0 && yc == 0)
        z= z+1;
    end
    k = k+1; x(k) = xc; y(k) = yc;
end