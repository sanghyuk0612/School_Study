import java.util.*;
public class Lotto {
	public static void main(String[] args) {
		Vector<Integer> v = new Vector<Integer>();
		System.out.print("이번주 행운의 번호는 ");
		//총 7개숫자 뽑음
		for(int i=0; i<7; i++) { 
			//숫자를 뽑아서 n에 넣음
			int n = (int)(Math.random()*45 + 1);
			
			while(v.indexOf(n) != (-1)) { 
				//만약 중복된 숫자가 뽑혔으면 중복되지 않은 숫자가 나올때까지 다시 뽑음
				n = (int)(Math.random()*45 + 1);
			}
			int j=0;
			while (j<v.size()) {
				if (n<v.get(j)) {
					//오름차순으로 넣기위해 탐색후 대입
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

