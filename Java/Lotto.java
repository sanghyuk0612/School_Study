import java.util.*;
public class Lotto {
	public static void main(String[] args) {
		Vector<Integer> v = new Vector<Integer>();
		System.out.print("�̹��� ����� ��ȣ�� ");
		//�� 7������ ����
		for(int i=0; i<7; i++) { 
			//���ڸ� �̾Ƽ� n�� ����
			int n = (int)(Math.random()*45 + 1);
			
			while(v.indexOf(n) != (-1)) { 
				//���� �ߺ��� ���ڰ� �������� �ߺ����� ���� ���ڰ� ���ö����� �ٽ� ����
				n = (int)(Math.random()*45 + 1);
			}
			int j=0;
			while (j<v.size()) {
				if (n<v.get(j)) {
					//������������ �ֱ����� Ž���� ����
					v.add(j,n);
					break;
				}
				j++;
			}
			if (j==v.size()) {
				v.add(n);
			}
		}
		for(int k=0;k<7;k++) {
			System.out.print(v.get(k)+" ");
		}
	}
}

