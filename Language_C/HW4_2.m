clc
disp('   n    Average visit (0,0)')
disp('---------------------------')
nTrials = 10000; % �� 10000�� ���� �ݺ� 
for n = 5:5:50  % n���� 5���� 5�� ���� 
    z = 0; % (0,0)�� �湮�� Ƚ��
    zsum = 0;
    for k=1:nTrials
        z = RandomWalk2D(n);
        zsum = zsum+z;
    end 
    Evg = zsum/nTrials;
    fprintf(' %3d         %6.2f\n',n,Evg)% 0,0�� ��� �湮�ߴ��� ��� 
end
fprintf('\n\n(Results based on %d trials)\n',nTrials)