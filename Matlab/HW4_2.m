clc
disp('   n    Average visit (0,0)')
disp('---------------------------')
nTrials = 10000; % 총 10000번 실험 반복 
for n = 5:5:50  % n값을 5부터 5씩 증가 
    z = 0; % (0,0)을 방문한 횟수
    zsum = 0;
    for k=1:nTrials
        z = RandomWalk2D(n);
        zsum = zsum+z;
    end 
    Evg = zsum/nTrials;
    fprintf(' %3d         %6.2f\n',n,Evg)% 0,0을 몇번 방문했는지 출력 
end
fprintf('\n\n(Results based on %d trials)\n',nTrials)
